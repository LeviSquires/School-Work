#############################################################################
# Makefile for building: cards program
#############################################################################

####### Compiler, tools and options

CXX           = cl
CXXFLAGS      = -EHsc -c -Od -W4
LINK          = link
LINKFLAGS     =  -OUT: 
TARGET        = assignment07.exe

OBJECTS = assignment07.obj functions.obj date.obj

$(TARGET) : $(OBJECTS)
	$(LINK) $(OBJECTS) $(LINKFLAGS)$(TARGET)
	
assignment07.obj : assignment07.cpp
	$(CXX) $(CXXFLAGS)  assignment07.cpp 
	
functions.obj : functions.cpp
	$(CXX) $(CXXFLAGS)  functions.cpp
	
date.obj : date.cpp
	$(CXX) $(CXXFLAGS)  date.cpp

clean:
	del *.obj *.exe
