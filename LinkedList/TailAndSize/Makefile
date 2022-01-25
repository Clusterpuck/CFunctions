CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = testList.o linkedlist.o
EXEC = testList

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean
endif

ifdef VALG
CFLAGS += -g
VALG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

testList.o : testList.c linkedlist.h linkedlist.o 
	$(CC) -c testList.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h 
	$(CC) -c linkedlist.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)


