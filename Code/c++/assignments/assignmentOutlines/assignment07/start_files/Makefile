#############################################################################
# Makefile for building: cards program
#############################################################################

####### Compiler, tools and options

CXX           = cl
CXXFLAGS      = -EHsc -c -Od -W4
LINK          = link
LINKFLAGS     =  -OUT: 
TARGET        = date_test.exe

OBJECTS = test.obj functions.obj

$(TARGET) : $(OBJECTS)
	$(LINK) $(OBJECTS) $(LINKFLAGS)$(TARGET)
	
test.obj : test.cpp
	$(CXX) $(CXXFLAGS)  test.cpp 
	
functions.obj : functions.cpp
	$(CXX) $(CXXFLAGS)  functions.cpp

clean:
	del *.obj *.exe
