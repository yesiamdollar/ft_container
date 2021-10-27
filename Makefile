NAME= exec

SRCS=main.cpp

ALL: $(NAME)

$(NAME): $(SRCS) tools/iterator_traits.hpp
	clang++ $(SRCS) -o $(NAME)