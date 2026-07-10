NAME = ex01

DEPDIR := .deps

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
DEPFILES := $(SRC:%.cpp=$(DEPDIR)/%.d)

CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPDIR)/%.d | $(DEPDIR)
	$(CPP) $(DEPFLAGS) $(FLAGS) -O3 -c $< -o $@

$(DEPDIR): ; @mkdir -p $@

clean:
	rm -f $(OBJ) $(DEPFILES)
	rm -rf $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEPFILES):
include $(wildcard $(DEPFILES))

.PHONY = all clean fclean re