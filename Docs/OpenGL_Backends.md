# SDL2 OpenGL backends

| Plugin | Renderer | GUI backend |
| --- | --- | --- |
| Appeal_SDL2_Legacy_OpenGL_Graphics | OpenGL 2.1 fixed function | ImGui OpenGL 2 |
| Appeal_SDL2_Modern_OpenGL_Graphics | OpenGL 3.3 core, GLSL, VAO/VBO/EBO | ImGui OpenGL 3 |

The previous Appeal_SDL2_Graphics project was renamed locally to the legacy name, including its DLL, Makefile, manifest, setup scripts, editor entry points, test drivers, and documentation references. The original repository history and GitHub remote remain intact. The modern copy is a new local Git repository without commits or a remote. No GitHub repositories were renamed or published.

## Basic: choose a plugin

Default `Setup/Config` continues selecting Legacy for compatibility. Select Modern before opening any windows or loading GPU resources:

```
Add_Dynamic_Module Graphics Appeal_SDL2_Modern_OpenGL_Graphics
```

`Setup/Modern_Graphics` contains that selection. `Examples/Graphics/Modern_OpenGL` is a standalone shader demo. Existing game/editor scripts use the same Graphics commands; change their Graphics plugin selection to use the modern backend. Selecting a backend reloads Graphics, so do this before initializing its windows and assets. Do not switch renderers in the middle of an active game.

Both plugins expose the same Graphics exports, including sprite animation, meshes, cameras, GUI controls/editors, fullscreen, and the native Video texture bridge. Core mode does not silently fall back to compatibility mode if a driver cannot create an OpenGL 3.3 core context.

## Basic: load a shader

```
Graphics Load_Shader Surface Modern_OpenGL/Default.shader
Graphics Set_Shader Cube Surface
```

Paths are relative to `Resources/Graphics/Shaders`. Shader programs apply to sprites and mesh assets. `Wire` retains its special wireframe behavior. Unassigned shaders use the built-in lit/unlit textured/color program. Rectangles, text, and ImGui select their own shader paths so an asset's custom shader cannot leak into overlays.

The editable default program is equivalent to the built-in default. Load it explicitly when you want to edit it. Calling Load_Shader again invalidates that file's cached programs in existing contexts and recompiles it; compilation failure reports an error. If called before any window exists, compilation is deferred until use.

## Advanced: SDL2_GL_Test-compatible configuration

The reference project remains unchanged. Its Default.Config, GLSL 140 Default.vs, and Default.fs have been loaded and rendered by the new plugin in a core context. Appeal's editable default uses GLSL 330 core:

```
Set_GL_Version 3 3
Init_Shader GL_VERTEX_SHADER "Vertex Shader" "Default.vs"
Init_Shader GL_FRAGMENT_SHADER "Fragment Shader" "Default.fs"
Set_Attribute_Data LVertexPos3D 0 3 "GLfloat"
Set_Attribute_Data texCoord 1 2 "GLfloat"
Set_Attribute_Data a_Normal 2 3 "GLfloat"
Set_Attribute_Data a_Color 3 4 "GLfloat"
Build
Get_Uniform_Location u_MVP
Done
```

Shader source paths are relative to the config file. `Set_GL_Version` declares a minimum supported context version; it cannot change the active window's context. Unknown commands, unsupported stages/layouts, missing source files, compiler failures, and link failures are errors. Build happens after reading both stages so attribute bindings are installed before linking. Driver logs include the source/config name.

The interleaved vertex layout is fixed across the renderer:

| Attribute | Location | Type |
| --- | --- | --- |
| LVertexPos3D | 0 | vec3 position |
| texCoord | 1 | vec2 UV |
| a_Normal | 2 | vec3 normal |
| a_Color | 3 | vec4 RGBA |

Automatic uniforms are `u_MVP` (projection times model/view), `u_ModelView`, `u_Texture` (texture unit 0), `u_Textured`, and `u_Lit`. Unused uniforms may be optimized out. Locations are cached per linked program. The default shader uses a normal matrix for nonuniform scaling, directional diffuse/ambient lighting for meshes, and unlit color/texture output for sprites/overlays. Custom shaders can implement their own lighting using those inputs. Arbitrary game-defined uniform setters are not added in this pass.

## Resource ownership and rendering

Projection/view/model transforms and hierarchy stacks are CPU data. No removed matrix-stack, lighting, or immediate-mode OpenGL calls remain in the modern plugin. Quads become indexed triangles; contiguous mesh triangles sharing a material are uploaded/drawn together. This initial renderer streams draw batches into vertex/index buffers; persistent mesh-buffer caching and skeletal animation are separate work.

Each SDL GL context owns its own VAO/buffers/program cache. Textures and ImGui font resources are shared through SDL's context sharing. GPU objects are deleted with their owning context current, before that context is destroyed. Editor viewports have color and depth attachments. Closing the original native window rebinds GUI platform state to a surviving window. Close/reopen creates fresh GPU resources.

## Globals

No script globals were added. Existing Graphics window, animation, and GUI globals retain their meanings.

## Build and validation

Use `make -f Makefile -j4` in each plugin project. SDL/ImGui SDKs were copied into the new plugin's ignored `.deps` directory. The new renderer resolves OpenGL entry points through SDL, without adding a GLEW dependency. Linux builds use SDL development packages and the ImGui docking sources; runtime validation in this change was performed on Windows with an OpenGL 3.3 core context.

Run `python Tests/Modern_OpenGL_Tests.py` for sprite/mirroring/animation pixels, GUI previews, editor framebuffer/input/fullscreen, lit 3D transforms, custom/reference shaders, compiler/linker errors, video texture uploads, multi-window rendering, and close/reopen checks. `Tests/Graphics_Animation_Tests.ps1 -CheckRendering` verifies the renamed legacy plugin. Full FFmpeg playback/audio synchronization was also exercised with the modern plugin through the Appeal host.

Framebuffer tests read the presented front buffer on both tested backends. Contents of a back buffer after swapping are not portable.
