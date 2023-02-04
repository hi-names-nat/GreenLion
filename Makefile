# Makefile generated by MakefileGenerator.cs
# *DO NOT EDIT*

UNREALROOTPATH = /software/unreal5.10
GAMEPROJECTFILE =/home/natalie/Repos/Unreal/GreenLion/GreenLion.uproject

TARGETS = \
	GreenLion-Linux-DebugGame  \
	GreenLion-Linux-Shipping  \
	GreenLion \
	GreenLionEditor-Linux-DebugGame  \
	GreenLionEditor-Linux-Shipping  \
	GreenLionEditor \
	UnrealEditor-Linux-DebugGame  \
	UnrealEditor-Linux-Shipping  \
	UnrealEditor \
	UnrealGame-Linux-DebugGame  \
	UnrealGame-Linux-Shipping  \
	UnrealGame\
	configure

BUILD = bash "$(UNREALROOTPATH)/Engine/Build/BatchFiles/Linux/Build.sh"
PROJECTBUILD = "$(UNREALROOTPATH)/Engine/Binaries/ThirdParty/DotNet/6.0.302/linux/dotnet" "$(UNREALROOTPATH)/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool.dll"

all: StandardSet

RequiredTools: CrashReportClient-Linux-Shipping CrashReportClientEditor-Linux-Shipping ShaderCompileWorker UnrealLightmass EpicWebHelper-Linux-Shipping

StandardSet: RequiredTools UnrealFrontend GreenLionEditor UnrealInsights

DebugSet: RequiredTools UnrealFrontend-Linux-Debug GreenLionEditor-Linux-Debug


GreenLion-Linux-DebugGame:
	 $(PROJECTBUILD) GreenLion Linux DebugGame  -project="$(GAMEPROJECTFILE)" $(ARGS)

GreenLion-Linux-Shipping:
	 $(PROJECTBUILD) GreenLion Linux Shipping  -project="$(GAMEPROJECTFILE)" $(ARGS)

GreenLion:
	 $(PROJECTBUILD) GreenLion Linux Development  -project="$(GAMEPROJECTFILE)" $(ARGS)

GreenLionEditor-Linux-DebugGame:
	 $(PROJECTBUILD) GreenLionEditor Linux DebugGame  -project="$(GAMEPROJECTFILE)" $(ARGS)

GreenLionEditor-Linux-Shipping:
	 $(PROJECTBUILD) GreenLionEditor Linux Shipping  -project="$(GAMEPROJECTFILE)" $(ARGS)

GreenLionEditor:
	 $(PROJECTBUILD) GreenLionEditor Linux Development  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealEditor-Linux-DebugGame:
	 $(BUILD) UnrealEditor Linux DebugGame  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealEditor-Linux-Shipping:
	 $(BUILD) UnrealEditor Linux Shipping  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealEditor:
	 $(BUILD) UnrealEditor Linux Development  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealGame-Linux-DebugGame:
	 $(BUILD) UnrealGame Linux DebugGame  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealGame-Linux-Shipping:
	 $(BUILD) UnrealGame Linux Shipping  -project="$(GAMEPROJECTFILE)" $(ARGS)

UnrealGame:
	 $(BUILD) UnrealGame Linux Development  -project="$(GAMEPROJECTFILE)" $(ARGS)

configure:
	xbuild /property:Configuration=Development /verbosity:quiet /nologo "$(UNREALROOTPATH)/Engine/Source/Programs/UnrealBuildTool/UnrealBuildTool.csproj"
	$(PROJECTBUILD) -projectfiles -project="\"$(GAMEPROJECTFILE)\"" -game -engine 

.PHONY: $(TARGETS)