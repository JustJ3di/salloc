CC = gcc
CFLAGS = -Wall -Wextra -O2

OBJ = main.o 

program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f *.o program