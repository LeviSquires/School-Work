###########################
# Makefile for factors program
###########################

CPP = cl
CPP_FLAGS = -O2 -c -EHsc -W4
LINK = link
LINK_FLAGS = /OUT: 
TARGET = factors.exe
OBJ_FILES = main.obj functions.obj

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

main.obj : main.cpp
	$(CPP) $(CPP_FLAGS) main.cpp

functions.obj : functions.cpp
	$(CPP) $(CPP_FLAGS) functions.cpp
 
clean:
	del $(TARGET) $(OBJ_FILES)
	

