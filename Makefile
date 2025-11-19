CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = example.o 

program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ)

example.o: example.c
	$(CC) $(CFLAGS) -c example.c


clean:
	rm -f *.o program