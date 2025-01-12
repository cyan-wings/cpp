CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
IFLAGS = -I.

NAME_MAIN = main
NAME_TEST = test

SRCS_MAIN = main.cpp
SRCS_TEST = test.cpp Zombie.cpp

OBJS_MAIN = $(SRCS_MAIN:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)

all: $(NAME_MAIN) $(NAME_TEST)

$(NAME_MAIN): $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) -o $(NAME_MAIN) $(OBJS_MAIN)

$(NAME_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $(NAME_TEST) $(OBJS_TEST)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $<

clean:
	rm -rf $(OBJS_MAIN) $(OBJS_TEST)

fclean: clean
	rm -rf $(NAME_MAIN) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean
