NAME = magic

HEADER = AMateria.hpp Character.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Cure.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_FILES = main.cpp AMateria.cpp Character.cpp Ice.cpp MateriaSource.cpp Cure.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I.


clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
