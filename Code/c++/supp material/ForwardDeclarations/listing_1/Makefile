#Forward Declaration code Makefile (Windows)

CPP			= cl 
CPP_FLAGS	= -EHsc -c -W4
LINK		= link
TARGET		= demo_game.exe
LINK_FLAGS	= /OUT:$(TARGET)
OBJECTS		= main.obj chesspiece.obj square.obj

$(TARGET): $(OBJECTS)
	$(LINK) $(LINK_FLAGS) $(OBJECTS)

main.obj: main.cpp
	$(CPP) $(CPP_FLAGS) main.cpp

chesspiece.obj: chesspiece.cpp
	$(CPP) $(CPP_FLAGS) chesspiece.cpp

square.obj: square.cpp
	$(CPP) $(CPP_FLAGS) square.cpp

clean:
	del -F $(OBJECTS) $(TARGET)
	