#!/bin/bash
# exXX/{src,include} の構成を sub/exXX にフラット化し、Makefile を作り直す。
# 使い方: ex00 ex01 ... があるディレクトリ(root)で実行する
#   bash flatten.sh

set -e
shopt -s nullglob

DEST="sub"

# 1. sub ディレクトリを作る
mkdir -p "$DEST"

found=0
for dir in ex[0-9][0-9]/; do
	ex="${dir%/}"
	out="$DEST/$ex"
	found=1

	# 2. sub/exXX を作る
	mkdir -p "$out"

	# 3. .cpp / .hpp (テンプレート用の .tpp も) をコピー
	files=( "$ex"/src/*.cpp "$ex"/include/*.hpp "$ex"/include/*.tpp )
	if [ ${#files[@]} -eq 0 ]; then
		echo "skip: $ex (ファイルなし)"
		continue
	fi
	cp "${files[@]}" "$out"/

	# 4. #include "../include/XX.hpp" や "include/XX.hpp" を "XX.hpp" に修正
	#    (macOS と Linux の sed の差を避けるため一時ファイル経由で書き換え)
	for f in "$out"/*.cpp "$out"/*.hpp "$out"/*.tpp; do
		sed 's|^\([[:space:]]*#[[:space:]]*include[[:space:]]*\)"\(\.\./\)\{0,1\}include/\([^"]*\)"|\1"\3"|' \
			"$f" > "$f.tmp" && mv "$f.tmp" "$f"
	done

	# 5. Makefile を作り直す (プログラム名 = exXX、ソースは明示的に列挙)
	srcs=""
	for f in "$out"/*.cpp; do
		srcs="$srcs $(basename "$f")"
	done
	srcs="${srcs# }"

	sed -e "s|__NAME__|$ex|" -e "s|__SRC__|$srcs|" > "$out/Makefile" <<'EOF'
NAME = __NAME__

DEPDIR := .deps
OBJDIR := obj

SRC = __SRC__
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
DEPFILES := $(SRC:%.cpp=$(DEPDIR)/%.d)

CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -Wpedantic
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR)
	$(CPP) $(DEPFLAGS) $(FLAGS) -c $< -o $@

$(DEPDIR): ; @mkdir -p $@
$(OBJDIR): ; @mkdir -p $@

clean:
	rm -f $(OBJ) $(DEPFILES)
	rm -rf $(DEPDIR)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEPFILES):
-include $(DEPFILES)

.PHONY: all clean fclean re
EOF

	echo "done: $ex -> $out"
done

if [ "$found" -eq 0 ]; then
	echo "exXX ディレクトリが見つかりません。root で実行してください。" >&2
	exit 1
fi
