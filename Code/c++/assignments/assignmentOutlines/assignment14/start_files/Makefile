#############################################################################
# Makefile for building: date_test program
#############################################################################

####### Compiler, tools and options

CXX           = g++
CXXFLAGS      = -c -O2 -Wall
LINK          = g++
TARGET        = date_test
LINKFLAGS     =  -o$(TARGET)

OBJECTS = test.o date.o functions.o

$(TARGET) : $(OBJECTS)
	$(LINK) $(OBJECTS) $(LINKFLAGS)
	
test.o : test.cpp
	$(CXX) $(CXXFLAGS)  test.cpp 
	
date.o : date.cpp
	$(CXX) $(CXXFLAGS)  date.cpp

functions.o : functions.cpp
	$(CXX) $(CXXFLAGS)  functions.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
