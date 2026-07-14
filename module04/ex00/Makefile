NAME = ex00

DEPDIR := .deps
OBJDIR := obj

SRC = $(wildcard src/*.cpp)
SRCFILES := $(notdir $(SRC))
OBJ = $(SRCFILES:%.cpp=$(OBJDIR)/%.o)
DEPFILES := $(SRCFILES:%.cpp=$(DEPDIR)/%.d)

CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	$(CPP) $(DEPFLAGS) $(FLAGS) -c $< -o $@

$(DEPDIR): ; @mkdir -p $@
$(OBJDIR): ; @mdkir -p $@

clean:
	rm -f $(OBJ) $(DEPFILES)
	rm -rf $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEPFILES):
include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re