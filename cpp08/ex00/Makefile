NAME = easy_find

CC := c++
CPPFLAGS := -Wall -Werror -Wextra
SRC := main.cpp
OBJS := $(SRC:%.cpp=%.o)

RM := rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -I. -c $< -o $@

clean:
	rm -fr $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
