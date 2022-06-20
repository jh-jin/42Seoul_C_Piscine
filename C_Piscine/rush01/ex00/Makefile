CC = gcc
WFLAGS = -Wall -Wextra -Werror
TARGET = rush01_exe
OBJECTS = init.o util.o board.o check.o rush01.o

$(TARGET) : $(OBJECTS)
	$(CC) $(WFLAGS) -o $(TARGET) $(OBJECTS)
all : $(TARGET)
init.o : init.c
	$(CC) $(WFLAGS) -c -o init.o init.c
util.o : util.c
	$(CC) $(WFLAGS) -c -o util.o util.c
board.o : board.c
	$(CC) $(WFLAGS) -c -o board.o board.c
check.o : check.c
	$(CC) $(WFLAGS) -c -o check.o check.c
rush01.o : rush01.c
	$(CC) $(WFLAGS) -c -o rush01.o rush01.c
clean :
	rm *.o
fclean : clean
	rm $(TARGET)
re : fclean all
