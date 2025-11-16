NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       parse.c \
       parse_split_segments.c \
       parse_create_list.c \
       parse_var_arg.c \
       parse_options.c \
       output.c \
       print_plain.c \
       print_with_options.c \
       format_character.c \
       format_string.c \
       format_pointer.c \
       format_int.c \
       format_hex.c \
       format_num_utils.c \
       convert_to_hex.c \
       write_and_count.c \
       free.c \
       ft_atoi.c \
       ft_isdigit.c \
       ft_itoa.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_lstadd_back.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstiter.c \
       ft_lstlast.c \
       ft_lstmap.c \
       ft_lstnew.c \
       ft_lstsize.c

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

# テスト用（オプション）
test: $(NAME)
	$(CC) $(CFLAGS) test.c $(NAME) -o test_printf
	./test_printf

.PHONY: all clean fclean re test