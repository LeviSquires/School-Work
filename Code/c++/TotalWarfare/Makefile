###########################
# Makefile for total warfare program
###########################

CPP = cl
CPP_FLAGS = -c -EHsc
LINK = link

TARGET = totalwar.exe
LINK_FLAGS = /OUT:$(TARGET) 
OBJ_FILES = war.obj weapons.obj 

$(TARGET) : $(OBJ_FILES)
	$(LINK) $(LINK_FLAGS) $(OBJ_FILES)

war.obj : war.cpp
	$(CPP) $(CPP_FLAGS) war.cpp

weapons.obj : weapons.cpp
	$(CPP) $(CPP_FLAGS) weapons.cpp
	
clean:
	del -f *.obj $(TARGET)
	

