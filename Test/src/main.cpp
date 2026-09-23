#include <iostream>

bool Muted = false;

// Turn Debug On or Off
extern "C" void Debug(bool Enable)
{
	std::cout << "Debug " << Enable << std::endl;
}

extern "C" void Set_Paths(std::string Resources)
{
	std::cout << "Set_Paths " << Resources << std::endl;
}

extern "C" void Add_Window(std::string Name, std::string Title, int Width, int Height)
{
	std::cout << "Add_Window " << Name << " " << Title << " " << Width << " " << Height << std::endl;
}

extern "C" void Add_Full_Screen_Window(std::string Name, int Monitor)
{
	std::cout << "Add_Full_Screen_Window " << Name << " " << Monitor << std::endl;
}

extern "C" void Delete_Window(std::string Name)
{
	std::cout << "Delete_Window " << Name << std::endl;
}

extern "C" void Close_All()
{
	std::cout << "Close_All" << std::endl;
}

extern "C" void Show(std::string Name)
{
	std::cout << "Show " << Name << std::endl;
}

extern "C" void Hide(std::string Name)
{
	std::cout << "Hide " << Name << std::endl;
}

extern "C" void Set_Focus(std::string Name)
{
	std::cout << "Set_Focus " << Name << std::endl;
}

extern "C" void Set_Monitor(std::string Name, int Monitor)
{
	std::cout << "Set_Monitor " << Name << " " << Monitor << std::endl;
}

extern "C" void Set_FPS(int Frames)
{
	std::cout << "Set_FPS " << Frames << std::endl;
}

extern "C" void Set_Window_Icon(std::string Name, std::string File)
{
	std::cout << "Set_Window_Icon " << Name << " " << File << std::endl;
}

extern "C" void Set_View_Port(std::string Window, int X, int Y, int W, int H)
{
	std::cout << "Set_View_Port " << Window << " " << X << " " << Y << " " << W << " " << H << std::endl;
}

extern "C" void Set_Perspective(std::string Window, float Fovy, float Near, float Far)
{
	std::cout << "Set_Perspective " << Window << " " << Fovy << " " << Near << " " << Far << std::endl;
}

extern "C" void Set_Ortho(std::string Window, float Left, float Right, float Bottom, float Top, float Near, float Far)
{
	std::cout << "Set_Ortho " << Window << " " << Left << " " << Right << " " << Bottom << " " << Top << " " << Near << " " << Far << std::endl;
}

extern "C" void Set_Camera_Location(std::string Window, float X, float Y, float Z)
{
	std::cout << "Set_Camera_Location " << Window << " " << X << " " << Y << " " << Z << std::endl;
}

extern "C" void Set_Camera_Orientation(std::string Window, float Yaw, float Pitch, float Roll)
{
	std::cout << "Set_Camera_Orientation " << Window << " " << Yaw << " " << Pitch << " " << Roll << std::endl;
}

extern "C" void Move_Camera(std::string Window, float X, float Y, float Z)
{
	std::cout << "Move_Camera " << Window << " " << X << " " << Y << " " << Z << std::endl;
}

extern "C" void Rotate_Camera(std::string Window, float Yaw, float Pitch, float Roll)
{
	std::cout << "Rotate_Camera " << Window << " " << Yaw << " " << Pitch << " " << Roll << std::endl;
}

extern "C" void Update_Camera(std::string Window)
{
	std::cout << "Update_Camera " << Window << std::endl;
}

extern "C" void Load_Shader(std::string Name, std::string File)
{
	std::cout << "Load_Shader " << Name << " " << File << std::endl;
}

extern "C" void Load_Texture(std::string Name, std::string File)
{
	std::cout << "Load_Texture " << Name << " " << File << std::endl;
}

extern "C" void Load_Font(std::string Name, std::string File, int Size)
{
	std::cout << "Load_Font " << Name << " " << File << " " << Size << std::endl;
}

extern "C" void Load_Mesh(std::string Name, std::string File)
{
	std::cout << "Load_Mesh " << Name << " " << File << std::endl;
}

extern "C" void Load_Asset(std::string Name, std::string File)
{
	std::cout << "Load_Asset " << Name << " " << File << std::endl;
}

extern "C" void Free_Texture(std::string Name)
{
	std::cout << "Free_Texture " << Name << std::endl;
}

extern "C" void Free_Asset(std::string Name)
{
	std::cout << "Free_Asset " << Name << std::endl;
}

extern "C" void Set_Texture(std::string Name, std::string Texture)
{
	std::cout << "Set_Texture " << Name << " " << Texture << std::endl;
}

extern "C" void Set_Shader(std::string Name, std::string Shader)
{
	std::cout << "Set_Shader " << Name << " " << Shader << std::endl;
}

extern "C" void Set_Location(std::string Name, float X, float Y, float Z)
{
	std::cout << "Set_Location " << Name << " " << X << " " << Y << " " << Z << std::endl;
}

extern "C" void Set_Orientation(std::string Name, float Yaw, float Pitch, float Roll)
{
	std::cout << "Set_Orientation " << Name << " " << Yaw << " " << Pitch << " " << Roll << std::endl;
}

extern "C" void Set_Scale(std::string Name, float X, float Y, float Z)
{
	std::cout << "Set_Scale " << Name << " " << X << " " << Y << " " << Z << std::endl;
}

extern "C" void Move_Asset(std::string Name, float X, float Y, float Z)
{
	std::cout << "Move_Asset " << Name << " " << X << " " << Y << " " << Z << std::endl;
}

extern "C" void Rotate_Asset(std::string Name, float Yaw, float Pitch, float Roll)
{
	std::cout << "Rotate_Asset " << Name << " " << Yaw << " " << Pitch << " " << Roll << std::endl;
}

extern "C" void Set_Active_Asset(std::string Name)
{
	std::cout << "Set_Active_Asset " << Name << std::endl;
}

extern "C" void Rotate_Active_Yaw_Input(int Value)
{
	std::cout << "Rotate_Active_Yaw_Input " << Value << std::endl;
}

extern "C" void Move_Active_Forward_Input(int Value)
{
	std::cout << "Move_Active_Forward_Input " << Value << std::endl;
}

extern "C" void Draw_Text(std::string Font, std::string Text, float X, float Y)
{
	std::cout << "Draw_Text " << Font << " " << Text << " " << X << " " << Y << std::endl;
}

extern "C" void Draw_Rect(std::string Name, float X, float Y, float W, float H, int R, int G, int B, int A)
{
	std::cout << "Draw_Rect " << Name << " " << X << " " << Y << " " << W << " " << H << " " << R << " " << G << " " << B << " " << A << std::endl;
}

extern "C" void GUI_Begin(std::string Name)
{
	std::cout << "GUI_Begin " << Name << std::endl;
}

extern "C" void GUI_Begin_Fullscreen(std::string Name)
{
	std::cout << "GUI_Begin_Fullscreen " << Name << std::endl;
}

extern "C" void GUI_End_Window()
{
	std::cout << "GUI_End_Window" << std::endl;
}

extern "C" void GUI_Text(std::string Name, std::string Text)
{
	std::cout << "GUI_Text " << Name << " " << Text << std::endl;
}

extern "C" void GUI_Label_Text(std::string Name, std::string Text)
{
	std::cout << "GUI_Label_Text " << Name << " " << Text << std::endl;
}

extern "C" void GUI_Bullet_Text(std::string Name, std::string Text)
{
	std::cout << "GUI_Bullet_Text " << Name << " " << Text << std::endl;
}

extern "C" void GUI_Separator()
{
	std::cout << "GUI_Separator" << std::endl;
}

extern "C" void GUI_Separator_Text(std::string Text)
{
	std::cout << "GUI_Separator_Text " << Text << std::endl;
}

extern "C" void GUI_Same_Line()
{
	std::cout << "GUI_Same_Line" << std::endl;
}

extern "C" void GUI_New_Line()
{
	std::cout << "GUI_New_Line" << std::endl;
}

extern "C" void GUI_Spacing()
{
	std::cout << "GUI_Spacing" << std::endl;
}

extern "C" void GUI_Indent(int Pixels)
{
	std::cout << "GUI_Indent " << Pixels << std::endl;
}

extern "C" void GUI_Unindent(int Pixels)
{
	std::cout << "GUI_Unindent " << Pixels << std::endl;
}

extern "C" void GUI_Group_Begin(std::string Name)
{
	std::cout << "GUI_Group_Begin " << Name << std::endl;
}

extern "C" void GUI_Group_End()
{
	std::cout << "GUI_Group_End" << std::endl;
}

extern "C" void GUI_Button(std::string Name, std::string Text)
{
	std::cout << "GUI_Button " << Name << " " << Text << std::endl;
}

extern "C" void GUI_New_Game_Project_Button(std::string Name, std::string Text, std::string Name_Input, std::string Picker)
{
	std::cout << "GUI_New_Game_Project_Button " << Name << " " << Text << " " << Name_Input << " " << Picker << std::endl;
}

extern "C" void GUI_New_Level_Project_Button(std::string Name, std::string Text, std::string Game_Input, std::string Level_Input, std::string Picker)
{
	std::cout << "GUI_New_Level_Project_Button " << Name << " " << Text << " " << Game_Input << " " << Level_Input << " " << Picker << std::endl;
}

extern "C" void GUI_Small_Button(std::string Name, std::string Text)
{
	std::cout << "GUI_Small_Button " << Name << " " << Text << std::endl;
}

extern "C" bool GUI_Button_Clicked(std::string Name)
{
	std::cout << "GUI_Button_Clicked " << Name << std::endl;
	return false;
}

extern "C" void Set_GUI_Button_Function(std::string Name, std::string Function)
{
	std::cout << "Set_GUI_Button_Function " << Name << " " << Function << std::endl;
}

extern "C" void GUI_Slider_Int(std::string Name, std::string Text, int Value, int Min, int Max)
{
	std::cout << "GUI_Slider_Int " << Name << " " << Text << " " << Value << " " << Min << " " << Max << std::endl;
}

extern "C" int GUI_Slider_Int_Value(std::string Name)
{
	std::cout << "GUI_Slider_Int_Value " << Name << std::endl;
	return 0;
}

extern "C" bool GUI_Slider_Int_Changed(std::string Name)
{
	std::cout << "GUI_Slider_Int_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Slider_Float(std::string Name, std::string Text, float Value, float Min, float Max)
{
	std::cout << "GUI_Slider_Float " << Name << " " << Text << " " << Value << " " << Min << " " << Max << std::endl;
}

extern "C" float GUI_Float_Value(std::string Name)
{
	std::cout << "GUI_Float_Value " << Name << std::endl;
	return 0.0f;
}

extern "C" bool GUI_Float_Changed(std::string Name)
{
	std::cout << "GUI_Float_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Drag_Int(std::string Name, std::string Text, int Value, int Min, int Max, int Speed)
{
	std::cout << "GUI_Drag_Int " << Name << " " << Text << " " << Value << " " << Min << " " << Max << " " << Speed << std::endl;
}

extern "C" void GUI_Drag_Float(std::string Name, std::string Text, float Value, float Min, float Max, float Speed)
{
	std::cout << "GUI_Drag_Float " << Name << " " << Text << " " << Value << " " << Min << " " << Max << " " << Speed << std::endl;
}

extern "C" void GUI_Input_Text(std::string Name, std::string Text, std::string Value)
{
	std::cout << "GUI_Input_Text " << Name << " " << Text << " " << Value << std::endl;
}

extern "C" void GUI_Input_Text_Multiline(std::string Name, std::string Text, std::string Value, int Width, int Height)
{
	std::cout << "GUI_Input_Text_Multiline " << Name << " " << Text << " " << Value << " " << Width << " " << Height << std::endl;
}

extern "C" void GUI_Set_Text_Value(std::string Name, std::string Value)
{
	std::cout << "GUI_Set_Text_Value " << Name << " " << Value << std::endl;
}

extern "C" std::string GUI_Text_Value(std::string Name)
{
	std::cout << "GUI_Text_Value " << Name << std::endl;
	return "";
}

extern "C" bool GUI_Text_Changed(std::string Name)
{
	std::cout << "GUI_Text_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Input_Int(std::string Name, std::string Text, int Value)
{
	std::cout << "GUI_Input_Int " << Name << " " << Text << " " << Value << std::endl;
}

extern "C" void GUI_Input_Float(std::string Name, std::string Text, float Value)
{
	std::cout << "GUI_Input_Float " << Name << " " << Text << " " << Value << std::endl;
}

extern "C" int GUI_Int_Value(std::string Name)
{
	std::cout << "GUI_Int_Value " << Name << std::endl;
	return 0;
}

extern "C" bool GUI_Int_Changed(std::string Name)
{
	std::cout << "GUI_Int_Changed " << Name << std::endl;
	return false;
}

extern "C" void Set_GUI_Slider_Int_Function(std::string Name, std::string Function)
{
	std::cout << "Set_GUI_Slider_Int_Function " << Name << " " << Function << std::endl;
}

extern "C" void GUI_Checkbox(std::string Name, std::string Text, int Value)
{
	std::cout << "GUI_Checkbox " << Name << " " << Text << " " << Value << std::endl;
}

extern "C" int GUI_Checkbox_Value(std::string Name)
{
	std::cout << "GUI_Checkbox_Value " << Name << std::endl;
	return 0;
}

extern "C" bool GUI_Checkbox_Changed(std::string Name)
{
	std::cout << "GUI_Checkbox_Changed " << Name << std::endl;
	return false;
}

extern "C" void Set_GUI_Checkbox_Function(std::string Name, std::string Function)
{
	std::cout << "Set_GUI_Checkbox_Function " << Name << " " << Function << std::endl;
}

extern "C" void GUI_Radio_Button(std::string Name, std::string Text, int Option)
{
	std::cout << "GUI_Radio_Button " << Name << " " << Text << " " << Option << std::endl;
}

extern "C" void GUI_Combo(std::string Name, std::string Text, std::string Items, int Value)
{
	std::cout << "GUI_Combo " << Name << " " << Text << " " << Items << " " << Value << std::endl;
}

extern "C" void GUI_List_Box(std::string Name, std::string Text, std::string Items, int Value)
{
	std::cout << "GUI_List_Box " << Name << " " << Text << " " << Items << " " << Value << std::endl;
}

extern "C" void GUI_File_Picker(std::string Name, std::string Text, std::string Root, std::string Start)
{
	std::cout << "GUI_File_Picker " << Name << " " << Text << " " << Root << " " << Start << std::endl;
}

extern "C" void GUI_File_Picker_Select(std::string Name, std::string Path)
{
	std::cout << "GUI_File_Picker_Select " << Name << " " << Path << std::endl;
}

extern "C" void GUI_File_Picker_Set_Start(std::string Name, std::string Start)
{
	std::cout << "GUI_File_Picker_Set_Start " << Name << " " << Start << std::endl;
}

extern "C" void GUI_Selectable(std::string Name, std::string Text, int Selected)
{
	std::cout << "GUI_Selectable " << Name << " " << Text << " " << Selected << std::endl;
}

extern "C" int GUI_Selection_Value(std::string Name)
{
	std::cout << "GUI_Selection_Value " << Name << std::endl;
	return 0;
}

extern "C" std::string GUI_Selection_Text(std::string Name)
{
	std::cout << "GUI_Selection_Text " << Name << std::endl;
	return "";
}

extern "C" bool GUI_Selection_Changed(std::string Name)
{
	std::cout << "GUI_Selection_Changed " << Name << std::endl;
	return false;
}

extern "C" std::string GUI_File_Picker_Current(std::string Name)
{
	std::cout << "GUI_File_Picker_Current " << Name << std::endl;
	return "";
}

extern "C" std::string GUI_File_Picker_Selected(std::string Name)
{
	std::cout << "GUI_File_Picker_Selected " << Name << std::endl;
	return "";
}

extern "C" std::string GUI_File_Picker_Selected_Path(std::string Name)
{
	std::cout << "GUI_File_Picker_Selected_Path " << Name << std::endl;
	return "";
}

extern "C" std::string GUI_File_Picker_Selected_Relative(std::string Name)
{
	std::cout << "GUI_File_Picker_Selected_Relative " << Name << std::endl;
	return "";
}

extern "C" bool GUI_File_Picker_Selected_Is_Directory(std::string Name)
{
	std::cout << "GUI_File_Picker_Selected_Is_Directory " << Name << std::endl;
	return false;
}

extern "C" bool GUI_File_Picker_Changed(std::string Name)
{
	std::cout << "GUI_File_Picker_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Music_Picker(std::string Name, std::string Text, std::string Root, std::string Start)
{
	std::cout << "GUI_Music_Picker " << Name << " " << Text << " " << Root << " " << Start << std::endl;
}

extern "C" std::string GUI_Music_Picker_Selected_Title(std::string Name)
{
	std::cout << "GUI_Music_Picker_Selected_Title " << Name << std::endl;
	return "";
}

extern "C" std::string GUI_Music_Picker_Selected_Path(std::string Name)
{
	std::cout << "GUI_Music_Picker_Selected_Path " << Name << std::endl;
	return "";
}

extern "C" bool GUI_Music_Picker_Changed(std::string Name)
{
	std::cout << "GUI_Music_Picker_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Playlist(std::string Name, std::string Text, std::string File_Path)
{
	std::cout << "GUI_Playlist " << Name << " " << Text << " " << File_Path << std::endl;
}

extern "C" void GUI_Playlist_Load(std::string Name, std::string File_Path)
{
	std::cout << "GUI_Playlist_Load " << Name << " " << File_Path << std::endl;
}

extern "C" void GUI_Playlist_Add(std::string Name, std::string Title, std::string File_Path)
{
	std::cout << "GUI_Playlist_Add " << Name << " " << Title << " " << File_Path << std::endl;
}

extern "C" void GUI_Playlist_Clear(std::string Name)
{
	std::cout << "GUI_Playlist_Clear " << Name << std::endl;
}

extern "C" int GUI_Playlist_Item_Count(std::string Name)
{
	std::cout << "GUI_Playlist_Item_Count " << Name << std::endl;
	return 0;
}

extern "C" bool GUI_Playlist_Changed(std::string Name)
{
	std::cout << "GUI_Playlist_Changed " << Name << std::endl;
	return false;
}

extern "C" void GUI_Progress_Bar(std::string Name, float Fraction, std::string Text)
{
	std::cout << "GUI_Progress_Bar " << Name << " " << Fraction << " " << Text << std::endl;
}

extern "C" void GUI_Tooltip(std::string Text)
{
	std::cout << "GUI_Tooltip " << Text << std::endl;
}

extern "C" void GUI_Tree_Node(std::string Name)
{
	std::cout << "GUI_Tree_Node " << Name << std::endl;
}

extern "C" void GUI_Tree_End()
{
	std::cout << "GUI_Tree_End" << std::endl;
}

extern "C" void GUI_Tab_Bar_Begin(std::string Name)
{
	std::cout << "GUI_Tab_Bar_Begin " << Name << std::endl;
}

extern "C" void GUI_Tab_Bar_End()
{
	std::cout << "GUI_Tab_Bar_End" << std::endl;
}

extern "C" void GUI_Tab_Item_Begin(std::string Name)
{
	std::cout << "GUI_Tab_Item_Begin " << Name << std::endl;
}

extern "C" void GUI_Tab_Item_End()
{
	std::cout << "GUI_Tab_Item_End" << std::endl;
}

extern "C" void GUI_Menu_Bar_Begin()
{
	std::cout << "GUI_Menu_Bar_Begin" << std::endl;
}

extern "C" void GUI_Menu_Bar_End()
{
	std::cout << "GUI_Menu_Bar_End" << std::endl;
}

extern "C" void GUI_Menu_Begin(std::string Name)
{
	std::cout << "GUI_Menu_Begin " << Name << std::endl;
}

extern "C" void GUI_Menu_End()
{
	std::cout << "GUI_Menu_End" << std::endl;
}

extern "C" void GUI_Menu_Item(std::string Name, std::string Text)
{
	std::cout << "GUI_Menu_Item " << Name << " " << Text << std::endl;
}

extern "C" void Set_GUI_Function(std::string Name, std::string Function)
{
	std::cout << "Set_GUI_Function " << Name << " " << Function << std::endl;
}

extern "C" void Set_GUI_Visible(bool Visible)
{
	std::cout << "Set_GUI_Visible " << Visible << std::endl;
}

extern "C" void Set_GUI_Docking(bool Enable)
{
	std::cout << "Set_GUI_Docking " << Enable << std::endl;
}

extern "C" void Toggle_GUI()
{
	std::cout << "Toggle_GUI" << std::endl;
}

extern "C" void GUI_End()
{
	std::cout << "GUI_End" << std::endl;
}

extern "C" void Render()
{
	std::cout << "Render" << std::endl;
}

extern "C" void Update()
{
	std::cout << "Update" << std::endl;
}

extern "C" void Wait_Until_Close(std::string Window)
{
	std::cout << "Wait_Until_Close " << Window << std::endl;
}

extern "C" bool Window_Open(std::string Window)
{
	std::cout << "Window_Open " << Window << std::endl;
	return false;
}