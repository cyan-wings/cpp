CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

INCDIR = includes
SRCDIR = srcs
OBJDIR = objs

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))

EXEC = ScavTrap

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re