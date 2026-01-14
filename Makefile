NAME = gnl

CC = cc
CFLAGS = 
OBJDIR = obj

SRCS_MANDATORY = get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c  utils.c liste_chainer.c  main.c

OBJS_MANDATORY = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS_MANDATORY))

all: $(NAME)

$(NAME): $(OBJS_MANDATORY)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_MANDATORY)

# Compilation des .c en .o
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
