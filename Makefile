CC = cc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -MMD -MP
LIBS = 

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o main $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d) main
