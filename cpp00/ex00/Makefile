NAME = megaphone

all: $(NAME)

$(NAME):
	g++ -g -O2 -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o $@

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
