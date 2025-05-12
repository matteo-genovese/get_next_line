# Variabili
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 -g
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

# Regola predefinita
all: main

# Regola per compilare il codice sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per compilare il programma principale
main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

# Regola per eseguire il programma con Valgrind
valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all -s ./main

# Regola per pulire i file oggetto e i file eseguibili
clean:
	rm -f $(OBJ) main

re:	clean all

.PHONY: all clean valgrind re
