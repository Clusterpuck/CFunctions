CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = testharness.o linkedlist.o
EXEC = testHarness

ifdef DEBUG
CFLAGS += -D DEBUG
endif

ifdef VALG
CFLAGS += -g
VALG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

testharness.o : testharness.c linkedlist.c linkedlist.h 
	$(CC) -c testharness.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h 
	$(CC) -c linkedlist.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)


