NAME = philo

SRCS = clear.c error.c init.c init2.c main.c messages.c philo_helper.c routine.c simulation.c time.c utils.c 

RM = rm -f
CC = cc 
CFLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 
re : fclean all

.PHONY: all fclean clean re