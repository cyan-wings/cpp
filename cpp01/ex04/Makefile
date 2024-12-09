NAME = ex04

all: $(NAME)

$(NAME):
	g++ -Wall -Wextra -Werror -std=c++98 main.cpp -o $@

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re