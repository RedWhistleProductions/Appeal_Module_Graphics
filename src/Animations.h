#pragma once
#include "Named_List.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <memory>
#include <stdexcept>

namespace Bananas {
struct Animation_Frame {
    std::string Graphic;
    int X = 0, Y = 0, Width = 0, Height = 0;
};

enum class Completion { Loop, Hold, Reset };

struct Animation {
    Named_List<Animation_Frame> Frames;
    double FPS = 0;
    Completion Mode = Completion::Loop;
    Animation() = default;
    Animation(const Animation&) = delete;
    Animation& operator=(const Animation&) = delete;
};

// Named_List owns its nodes and must not be shallow-copied. Shared pointers
// keep animation nodes stable, while each Animations instance owns its clips.
class Animations {
public:
    Named_List<std::shared_ptr<Animation>> Sequences;
    std::function<void(Animations&)> On_Complete;
    virtual ~Animations() = default;
    Animations() = default;
    Animations(const Animations&) = delete;
    Animations& operator=(const Animations&) = delete;

    std::shared_ptr<Animation> Find(const std::string& Name) const {
        auto Node = Sequences.Start;
        for(int I = 0; I < Sequences.Nodes; ++I, Node = Node->Next_Node)
            if(Node->Name == Name) return Node->Value;
        return {};
    }
    bool Select(const std::string& Name) {
        if(!Find(Name)) return false;
        if(Current_Name() == Name) return true;
        Sequences.Find(Name);
        Restart();
        return true;
    }
    void Reset() {
        if(!Sequences.Start) return;
        Sequences.Go_To(1);
        Restart();
    }
    std::string Current_Name() const {
        return Sequences.Current ? Sequences.Current->Name : "";
    }
    int Frame_Index() const {
        return Sequences.Current ? Sequences.Current->Value->Frames.Current_Node - 1 : -1;
    }
    bool Set_FPS(const std::string& Name, double FPS) {
        auto Clip = Find(Name);
        if(!Clip || !std::isfinite(FPS) || FPS < 0) return false;
        Clip->FPS = FPS;
        return true;
    }
    bool Set_Mode(const std::string& Name, const std::string& Mode) {
        auto Clip = Find(Name);
        if(!Clip) return false;
        if(Mode == "Loop") Clip->Mode = Completion::Loop;
        else if(Mode == "Hold") Clip->Mode = Completion::Hold;
        else if(Mode == "Reset") Clip->Mode = Completion::Reset;
        else return false;
        return true;
    }
    void Set_Render_Context(double Time, double Window_FPS, std::uint64_t Cycle) {
        Now = Time; Fallback_FPS = Window_FPS; Render_Cycle = Cycle; Has_Context = true;
    }
    virtual const Animation_Frame* Paste(int X, int Y, int Z) = 0;
    virtual void Update() {
        if(!Has_Context || !Sequences.Current || (Has_Cycle && Last_Cycle == Render_Cycle)) return;
        Last_Cycle = Render_Cycle;
        Has_Cycle = true;
        if(!Started) { Last_Time = Now; Started = true; return; }
        double Delta = std::max(0.0, Now - Last_Time);
        Last_Time = Now;
        if(Finished) return;
        auto Clip = Sequences.Current->Value;
        double FPS = Clip->FPS > 0 ? Clip->FPS : Fallback_FPS;
        if(FPS <= 0 || Clip->Frames.Nodes == 0) return;
        Accumulator += Delta;
        double Steps = std::floor(Accumulator * FPS + 1e-9);
        if(Steps < 1) return;
        Accumulator = std::max(0.0, Accumulator - Steps / FPS);
        int Index = Frame_Index();
        int Count = Clip->Frames.Nodes;
        if(Clip->Mode == Completion::Loop) {
            int Advance = static_cast<int>(std::fmod(Steps, static_cast<double>(Count)));
            Clip->Frames.Go_To((Index + Advance) % Count + 1);
        } else if(Steps < Count - Index) {
            Clip->Frames.Go_To(Index + static_cast<int>(Steps) + 1);
        } else {
            Clip->Frames.Last();
            Finished = true;
            if(Clip->Mode == Completion::Reset) Reset();
            if(On_Complete) On_Complete(*this);
        }
    }
protected:
    void Store(const std::string& Name, std::shared_ptr<Animation> Clip) {
        const std::string Selected = Current_Name();
        if(Find(Name)) {
            Sequences.Find(Name);
            Sequences.Current->Value = std::move(Clip);
        } else Sequences.Add_Node(Name, std::move(Clip));
        if(!Selected.empty()) Sequences.Find(Selected);
        if(Selected.empty() || Selected == Name) Restart();
    }
    const Animation_Frame* Current_Frame() const {
        return Sequences.Current && Sequences.Current->Value->Frames.Current
            ? &Sequences.Current->Value->Frames.Current->Value : nullptr;
    }
private:
    void Restart() {
        Sequences.Current->Value->Frames.Go_To(1);
        Started = false; Finished = false; Accumulator = 0;
    }
    double Now = 0, Last_Time = 0, Accumulator = 0, Fallback_FPS = 60;
    std::uint64_t Render_Cycle = 0, Last_Cycle = 0;
    bool Has_Context = false, Has_Cycle = false, Started = false, Finished = false;
};

class Animations_2D : public Animations {
public:
    bool Load(const std::string& Name, const std::string& Graphic,
              int Sheet_Width, int Sheet_Height, int Width, int Height,
              int First, int Count) {
        if(Name.empty() || Width <= 0 || Height <= 0 || First < 0 || Count <= 0 ||
           Sheet_Width <= 0 || Sheet_Height <= 0 ||
           Sheet_Width % Width || Sheet_Height % Height) return false;
        const int Columns = Sheet_Width / Width;
        const long long Total = static_cast<long long>(Columns) * (Sheet_Height / Height);
        if(static_cast<long long>(First) + Count > Total) return false;
        auto Clip = std::make_shared<Animation>();
        for(int I = 0; I < Count; ++I) {
            Animation_Frame Frame;
            Frame.Graphic = Graphic;
            Frame.X = ((First + I) % Columns) * Width;
            Frame.Y = ((First + I) / Columns) * Height;
            Frame.Width = Width; Frame.Height = Height;
            Clip->Frames.Add_Node(std::to_string(I), Frame);
        }
        Clip->Frames.Go_To(1);
        Store(Name, Clip);
        return true;
    }
    const Animation_Frame* Paste(int, int, int) override {
        Update();
        return Current_Frame();
    }
};

// 3D pose loading/evaluation is deliberately left abstract until its data
// format is defined; it inherits the same selection and timing contract.
class Animations_3D : public Animations {};

class Part {
public:
    float X = 0, Y = 0, Z = 0;
    float Turn = 0, Tilt = 0, Pitch = 0;
    std::shared_ptr<Animations> Animation_Player;
    bool Pasted = false;
    void Move(int New_X, int New_Y, int New_Z) { X = New_X; Y = New_Y; Z = New_Z; }
    void Rotate(float New_Turn, float New_Tilt, float New_Pitch) {
        Turn = New_Turn; Tilt = New_Tilt; Pitch = New_Pitch;
    }
    const Animation_Frame* Paste() {
        Pasted = true;
        return Animation_Player ? Animation_Player->Paste(static_cast<int>(X), static_cast<int>(Y), static_cast<int>(Z)) : nullptr;
    }
    const Animation_Frame* Paste(int New_X, int New_Y, int New_Z) {
        Move(New_X, New_Y, New_Z);
        return Paste();
    }
};
} // namespace Bananas
