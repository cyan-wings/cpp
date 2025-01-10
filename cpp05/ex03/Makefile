CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
IFLAGS = -I.

NAME = Interns
SRCS = AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Bureaucrat.cpp Intern.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(IFLAGS) -c $<

clean:
	rm -rf *_shrubbery
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean

