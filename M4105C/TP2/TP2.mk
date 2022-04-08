##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TP2
ConfigurationName      :=Debug
WorkspacePath          :=/users/info/etu-s4/renardn/m4105C_projet/M4105C/M4105C
ProjectPath            :=/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=RENARD Nathan
Date                   :=08/04/22
CodeLitePath           :=/users/info/etu-s4/renardn/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TP2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyThresholdDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyRotateDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyHistogram.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix): MyImage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyImage.cpp$(DependSuffix) -MM MyImage.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2/MyImage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyImage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix): MyImage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyImage.cpp$(PreprocessSuffix) MyImage.cpp

$(IntermediateDirectory)/MyThresholdDialog.cpp$(ObjectSuffix): MyThresholdDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyThresholdDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyThresholdDialog.cpp$(DependSuffix) -MM MyThresholdDialog.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2/MyThresholdDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyThresholdDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyThresholdDialog.cpp$(PreprocessSuffix): MyThresholdDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyThresholdDialog.cpp$(PreprocessSuffix) MyThresholdDialog.cpp

$(IntermediateDirectory)/MyRotateDialog.cpp$(ObjectSuffix): MyRotateDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyRotateDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyRotateDialog.cpp$(DependSuffix) -MM MyRotateDialog.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2/MyRotateDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyRotateDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyRotateDialog.cpp$(PreprocessSuffix): MyRotateDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyRotateDialog.cpp$(PreprocessSuffix) MyRotateDialog.cpp

$(IntermediateDirectory)/MyHistogram.cpp$(ObjectSuffix): MyHistogram.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyHistogram.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyHistogram.cpp$(DependSuffix) -MM MyHistogram.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/users/info/etu-s4/renardn/m4105C_projet/M4105C/TP2/MyHistogram.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyHistogram.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyHistogram.cpp$(PreprocessSuffix): MyHistogram.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyHistogram.cpp$(PreprocessSuffix) MyHistogram.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


