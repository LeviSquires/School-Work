###########################
# Makefile for factors program
###########################

CPP = cl
CPP_FLAGS = -O2 -c -EHsc -W4
LINK = link
LINK_FLAGS = /OUT: 
TARGET = assignment05.exe
OBJ_FILES = assignment05.obj 

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

assignment05.obj : assignment05.cpp
	$(CPP) $(CPP_FLAGS) assignment05.cpp

clean:
	del $(TARGET) $(OBJ_FILES)
	

