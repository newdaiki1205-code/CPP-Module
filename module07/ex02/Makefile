NAME = ex02

DEPDIR := .deps
OBJDIR := obj

SRC = $(wildcard src/*.cpp)
SRCFILES := $(notdir $(SRC))
OBJ = $(SRCFILES:%.cpp=$(OBJDIR)/%.o)
DEPFILES := $(SRCFILES:%.cpp=$(DEPDIR)/%.d)

CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -Wpedantic
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d
#LDFLAGS =

#SANITIZE = -fsanitize=undefined,address -g -fno-omit-frame-pointer

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(LDFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(CPP) $(DEPFLAGS) $(FLAGS) -c $< -o $@

$(DEPDIR): ; @mkdir -p $@
$(OBJDIR): ; @mkdir -p $@

#mac: fclean
#	$(MAKE) CPP=clang++ FLAGS="$(FLAGS) $(SANITIZE)" LDFLAGS="$(SANITIZE)"

clean:
	rm -f $(OBJ) $(DEPFILES)
	rm -rf $(DEPDIR)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEPFILES):
include $(wildcard $(DEPFILES))

.PHONY: all clean fclean re mac
