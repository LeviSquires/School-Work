###########################
# Makefile for craps program
###########################

CPP = cl
CPP_FLAGS = -c -EHsc
LINK = link
LINK_FLAGS = /OUT: 
TARGET = bonuscraps.exe 
OBJ_FILES = bonuscraps.obj randgen.obj 

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS)$(TARGET) $(OBJ_FILES)

bonuscraps.obj : bonuscraps.cpp
	$(CPP) $(CPP_FLAGS) bonuscraps.cpp
randgen.obj : randgen.cpp
	$(CPP) $(CPP_FLAGS) randgen.cpp


clean:
	del *.obj *.exe
	

