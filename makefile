SRCS = init_data.c main.c execution.c str_utils.c

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=thread
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	clear


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all 
