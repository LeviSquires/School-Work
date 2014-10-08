###########################
# Makefile for critter program
###########################

CPP = cl
CPP_FLAGS = -c -EHsc
LINK = link
LINK_FLAGS = /OUT: 
TARGET = critter.exe
OBJ_FILES = critter.obj functions.obj main.obj randgen.obj

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

critter.obj : critter.cpp
	$(CPP) $(CPP_FLAGS) critter.cpp

functions.obj : functions.cpp
	$(CPP) $(CPP_FLAGS) functions.cpp


main.obj : main.cpp
	$(CPP) $(CPP_FLAGS) main.cpp
	
randgen.obj : randgen.cpp
	$(CPP) $(CPP_FLAGS) randgen.cpp
	
	
clean:
	del *.obj *.exe
	

