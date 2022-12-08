#OBJS specifies which files to compile as part of the project
OBJS = ui_test.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = ui_test.o

CFLAGS := `sdl2-config --libs --cflags` -Wall -lSDL2

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) $(CFLAGS) -o $(OBJ_NAME)
