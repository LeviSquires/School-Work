###########################
# Makefile for craps program
###########################

CPP = cl
CPP_FLAGS = -c -EHsc
LINK = link
LINK_FLAGS = /OUT: 
TARGET = craps.exe 
OBJ_FILES = craps.obj randgen.obj 

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

craps.obj : craps.cpp
	$(CPP) $(CPP_FLAGS) craps.cpp
randgen.obj : randgen.cpp
	$(CPP) $(CPP_FLAGS) randgen.cpp


clean:
	del *.obj *.exe
	

