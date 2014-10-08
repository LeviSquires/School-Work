###########################
# Makefile for factors program
###########################

CPP = cl
CPP_FLAGS = -O2 -c -EHsc -W4
LINK = link
LINK_FLAGS = /OUT: 
TARGET = assignment04.exe
OBJ_FILES = assignment04.obj functions.obj

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

assignment04.obj : assignment04.cpp
	$(CPP) $(CPP_FLAGS) assignment04.cpp

functions.obj : functions.cpp
	$(CPP) $(CPP_FLAGS) functions.cpp
 
clean:
	del $(TARGET) $(OBJ_FILES)
	

