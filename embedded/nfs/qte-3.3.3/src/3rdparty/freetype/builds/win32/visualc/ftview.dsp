# Microsoft Developer Studio Project File - Name="ftview" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ftview - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ftview.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ftview.mak" CFG="ftview - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ftview - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ftview - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/DEV/freetype", KAOAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ftview - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "demos/obj/ftview/release"
# PROP Intermediate_Dir "demos/obj/ftview/release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\freetype\include\\" /I "demos\graph" /I "demos\graph\win32" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "FT_FLAT_COMPILE" /D "DEVICE_WIN32" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib lib\freetype200b8.lib /nologo /subsystem:console /machine:I386
# Begin Special Build Tool
TargetPath=.\demos\obj\ftview\release\ftview.exe
TargetName=ftview
SOURCE="$(InputPath)"
PostBuild_Cmds=echo copy $(TargetPath) .\demos\bin\$(TargetName).exe	copy $(TargetPath) .\demos\bin\$(TargetName).exe
# End Special Build Tool

!ELSEIF  "$(CFG)" == "ftview - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ftview___Win32_Debug"
# PROP BASE Intermediate_Dir "ftview___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "demos/obj/ftview/debug"
# PROP Intermediate_Dir "demos/obj/ftview/debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\freetype\include\\" /I "demos\graph" /I "demos\graph\win32" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "FT_FLAT_COMPILE" /D "DEVICE_WIN32" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib lib\freetype200b8_D.lib /nologo /subsystem:console /debug /machine:I386 /out:"demos/obj/ftview/debug/ftview_D.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=.\demos\obj\ftview\debug\ftview_D.exe
TargetName=ftview_D
SOURCE="$(InputPath)"
PostBuild_Cmds=echo copy $(TargetPath) .\demos\bin\$(TargetName).exe	copy $(TargetPath) .\demos\bin\$(TargetName).exe
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "ftview - Win32 Release"
# Name "ftview - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\demos\src\common.c
# End Source File
# Begin Source File

SOURCE=.\demos\src\ftview.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\grblit.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\grdevice.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\grfont.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\grinit.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\grobjs.c
# End Source File
# Begin Source File

SOURCE=.\demos\graph\win32\grwin32.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
