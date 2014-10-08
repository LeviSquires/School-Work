#############################################################################
# Makefile for building: list program
#############################################################################

####### Compiler, tools and options

CXX           = cl
CXXFLAGS      = -EHsc -c -Od -W3
LINK          = link
LINKFLAGS     =  -OUT: 
TARGET        = list.exe

OBJECTS = main.obj

$(TARGET) : $(OBJECTS)
	$(LINK) $(OBJECTS) $(LINKFLAGS)$(TARGET)
	
main.obj : main.cpp
	$(CXX) $(CXXFLAGS)  main.cpp
	
	
clean:
	del $(TARGET) $(OBJECTS) *.bak
