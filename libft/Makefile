CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h


SRC_FILES = ft_utils.c ft_fd.c ft_is.c ft_itoa.c ft_malloc.c \
            ft_mem.c ft_split.c ft_str_1.c ft_str_2.c ft_utils2.c

BONUS_FILES = ft_bonus.c ft_2_bonus.c

OBJS = $(SRC_FILES:.c=.o)
OBJS_BONUS = $(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	touch .bonus

bonus: .bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) .bonus

re: fclean all

.PHONY: all clean fclean re 
