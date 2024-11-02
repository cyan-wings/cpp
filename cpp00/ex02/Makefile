CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

INCDIR = includes
SRCDIR = srcs
OBJDIR = objs

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))

EXEC = Account

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

test:
	bash -c 'diff <(./Account | cut -c17-) <(cut -c17- 19920104_091532.log)'

.PHONY: all clean fclean re test