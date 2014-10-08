################################
#  Windows Makefile for A* Algorithm
################################

COMPILER = cl
COMPILE_FLAGS = -EHsc -c -Zi -I/c++/tclap-1.2.1/include -DCPP_11
TARGET = astar.exe
LINKER = link
LINK_FLAGS = /OUT:$(TARGET)
OBJ_FILES = cell.obj main.obj board.obj randgen.obj path.obj


$(TARGET): $(OBJ_FILES)
	$(LINKER) $(LINK_FLAGS) $(OBJ_FILES)

cell.obj: cell.cpp
	$(COMPILER) $(COMPILE_FLAGS) cell.cpp

main.obj : main.cpp
	$(COMPILER) $(COMPILE_FLAGS) main.cpp

board.obj : board.cpp
	$(COMPILER) $(COMPILE_FLAGS) board.cpp
	
randgen.obj : randgen.cpp
	$(COMPILER) $(COMPILE_FLAGS) randgen.cpp

path.obj : path.cpp
	$(COMPILER) $(COMPILE_FLAGS) path.cpp


clean:
	del $(OBJ_FILES) $(TARGET) *.bak /F
	
