NAME= exec

SRCS=main.cpp

HDRS= containers/vector.hpp tools/iterator.hpp tools/iterator_traits.hpp \
		tools/reverse_iterator.hpp tools/type_traits.hpp

OBJS=	$(SRCS:.cpp=.o)

ALL: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	clang++ $(SRCS) -o $(NAME) -g #-fsanitize=address

