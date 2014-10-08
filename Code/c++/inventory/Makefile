###########################
# Makefile for inventory program
###########################

CPP = cl
CPP_FLAGS = -c -EHsc
LINK = link
LINK_FLAGS = /OUT: 
TARGET = inventory.exe
OBJ_FILES = inventory.obj functions.obj

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

inventory.obj : inventory.cpp
	$(CPP) $(CPP_FLAGS) inventory.cpp

functions.obj : functions.cpp
	$(CPP) $(CPP_FLAGS) functions.cpp

clean:
	del *.obj *.exe
	

