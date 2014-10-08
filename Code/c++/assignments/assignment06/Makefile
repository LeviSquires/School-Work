#############################################################################
# Makefile for building: cards program
#############################################################################

####### Compiler, tools and options

CXX           = cl
CXXFLAGS      = -EHsc -c -Od -W4
LINK          = link
LINKFLAGS     =  -OUT: 
TARGET        =cards.exe

OBJECTS = cards.obj randgen.obj functions.obj

$(TARGET) : $(OBJECTS)
	$(LINK) $(OBJECTS) $(LINKFLAGS)$(TARGET)
	
cards.obj : cards.cpp
	$(CXX) $(CXXFLAGS)  cards.cpp 
	
randgen.obj : randgen.cpp
	$(CXX) $(CXXFLAGS)  randgen.cpp

functions.obj : functions.cpp
	$(CXX) $(CXXFLAGS)  functions.cpp

clean:
	del $(OBJECTS) $(TARGET)
