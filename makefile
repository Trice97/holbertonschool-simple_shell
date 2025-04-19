# Nom de l'exécutable
NAME = shell_program

# Liste des fichiers sources
SRC = main.c _setenv.c path_dirs.c path_list.c _unsetenv.c

# Objets générés à partir des sources
OBJ = $(SRC:.c=.o)

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -pedantic

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJ)

# Règle pour tout nettoyer
fclean: clean
	rm -f $(NAME)

# Recompile tout proprement
re: fclean $(NAME)

# Ne pas considérer ces règles comme des fichiers
.PHONY: all clean fclean re
