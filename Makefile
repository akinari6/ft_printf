NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       parse.c \
       parse_split_segments.c \
       parse_create_list.c \
       parse_var_arg.c \
       output.c \
       print_plain.c \
       prints.c \
       convert_to_hex.c \
       write_and_count.c \
       free.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_itoa.c \
       ft_putchar_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_strdup.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_lstadd_back.c \
       ft_lstclear.c \
       ft_lstiter.c \
       ft_lstlast.c \
       ft_lstnew.c \
       ft_lstdelone.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test