# Animations

The module, Test plugin, and SDL2 plugin expose the same fixed-argument commands.
The SDL2 implementation supports 2D grid sprite sheets. Create a window before
loading a sheet. Files are relative to `Resources/Graphics/Sprites/`, including
when `Set_Paths` changes the resources root. ZIP archives and animation JSON are
not loaded directly; extract the original PNG once.

| Command | Arguments after `Graphics` and the command name | Result |
| --- | --- | --- |
| `Load_Animation` | `Name Animation File Width Height First Count` | 1 on success, 0 on failure |
| `Set_Animation` | `Name Animation` | 1 on success, 0 if not found |
| `Reset_Animation` | `Name` | Returns to the first loaded animation and its first frame |
| `Set_Animation_FPS` | `Name Animation FPS` | 1 on success, 0 for invalid input |
| `Set_Animation_Mode` | `Name Animation Mode` | 1 on success, 0 for invalid input |
| `Rotate` | `Name Turn Tilt Pitch` | Stores orientation, in degrees |
| `Paste` | `Name X Y Z` | Stores integer coordinates and submits the asset for rendering |
| `Animation_Frame` | `Name` | Zero-based frame position within the selected animation; -1 if absent |
| `Current_Animation` | `Name` | Selected animation name; empty string if absent |

Width, Height, First, and Count are integers. Cells must exactly tile the sheet,
with no margins or spacing. First is a zero-based sheet index, numbered left to
right then top to bottom; Count is positive. Invalid ranges leave the existing
animation unchanged. Reloading a named animation replaces it in place and resets
it if active. The first loaded animation is the default; load Standing first.
Different animations for one asset may use different sheets.

```text
Graphics Add_Window Main "Animations" 800 600
Graphics Set_FPS 60
Graphics Load_Animation Adam Standing Examples/Characters/Adam/Adam_Movement.png 64 64 0 8
Graphics Load_Animation Adam Walking Examples/Characters/Adam/Adam_Movement.png 64 64 8 8
Graphics Set_Animation_FPS Adam Standing 7
Graphics Set_Animation_FPS Adam Walking 10
Graphics Set_Scale Adam 3 3 1
Graphics Rotate Adam 0 0 0
Graphics Paste Adam 176 204 0
Graphics Wait_Until_Close Main
Graphics Close_All
```

An asset is not displayed by Load_Animation alone. Paste submits it to the
existing retained renderer: it remains visible and animates on subsequent Render
calls, including the loop inside Wait_Until_Close. Paste does not swap buffers or
create a second event loop. Rotate stores orientation without submitting an asset.
For 2D sprites, Tilt is the in-plane rotation (the existing Roll axis). Turn maps
to Yaw and Pitch retains its existing mesh meaning; neither tilts a 2D sprite
into a 3D surface. Z is stored but the current 2D renderer does not depth-sort
sprites. Negative X scale mirrors sprites using the existing scale behavior.

FPS defaults to zero, meaning use the existing Graphics Set_FPS rate (currently
shared by the plugin's windows). Positive animation FPS overrides that rate;
negative or nonfinite values are rejected. Playback uses monotonic elapsed time,
catches up after delayed renders, and advances at most once per Render cycle even
when several windows display the asset. It starts at frame zero on the first
render after loading, switching, or resetting. Re-selecting the current animation
does not restart it. Queries do not advance playback.

Completion modes are case-sensitive:

- `Loop` (default): wrap around continuously.
- `Hold`: finish the last frame's duration and remain on it.
- `Reset`: finish the sequence and return to the first loaded animation.

The C++ completion hook `On_Complete` supports further state-driven decisions.
It runs once at completion of Hold/Reset sequences; repeating a loop does not
invoke it. Changing a completed sequence's mode alone does not restart playback;
reset it or select another animation first.

Use expression syntax to check results, for example
`Print (Graphics Load_Animation Adam Standing sheet.png 64 64 0 8)` or
`Set_Var Frame (Graphics Animation_Frame Adam)`.
The Test plugin logs calls and returns predictable sample values; it does not
load graphics or simulate playback.

## C++ implementation and scope

`src/Animations.h` defines the Animations base, Animations_2D, an abstract
Animations_3D extension point, and Part. The animation collection is a Named_List
whose nodes own animations with Named_List frame collections. These lists are
not shallow-copied. Each loaded asset has independent playback state; atlas
textures are cached and shared by path. Free_Asset releases that asset's player;
cached textures remain until explicitly freed or the last window closes.
Closing the last window clears animation players with their GPU resources.
Set_Texture detaches animation playback and returns an asset to static rendering.

Part keeps Move and both Paste overloads in C++; Appeal exposes only Rotate and
Paste with integer coordinates. Existing Set_Location, Set_Orientation, and
other legacy commands remain available. An abstract Animations_3D reserves the
shared interface; 3D clip loading, multipart Actor composition, and collision
detection are not implemented by this change.

The SDL plugin build uses the shared headers in its parent module's `src/`
directory. Build the module, Test plugin, and SDL plugin together when updating
this API. In the Appeal checkout run `Tests/Graphics_Animation_Tests.ps1` for
deterministic playback tests and real Appeal/Test/SDL smoke checks. The optional
`-CheckRendering` flag runs the Windows/OpenGL framebuffer regression as well.
