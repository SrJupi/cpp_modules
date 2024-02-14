NAME = fragtrap

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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
