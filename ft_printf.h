/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:42 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 23:38:19 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PERCENT '%'
# define SPECS "cspdiuxX%"

void	print_full_segment(void *seg_ptr);

typedef enum e_segment_type
{
	SEG_TEXT,
	SEG_FORMAT
}					t_segment_type;

typedef enum e_format_type
{
	TYPE_CHAR = 'c',
	TYPE_STRING = 's',
	TYPE_POINTER = 'p',
	TYPE_INT = 'd',
	TYPE_IINT = 'i',
	TYPE_UINT = 'u',
	TYPE_HEX_LOWER = 'x',
	TYPE_HEX_UPPER = 'X',
	TYPE_PERCENT = '%',
	TYPE_NONE = 0
}					t_format_type;

typedef union u_value
{
	void			*ptr;
	long long		i;
	unsigned long long ui;
	int				c;
	char			*s;
}					t_value;

typedef struct s_segment
{
	t_segment_type	seg_type;
	char			*content;
	t_format_type	fmt_type;
	t_value			value;
}					t_segment;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// printf
int					ft_printf(const char *format, ...);

// parse
t_list				*parse(char const *format, va_list *ap);
char				**split_format_to_segments(const char *format);
t_list				*create_list(char **segments);
t_list				*parse_var_args(t_list *segment_list, va_list *ap);

// output
int					output(t_list *segment_list);
int					write_and_count_str(char *str);
int					write_and_count_char(char c);

int					print_text(char *str);
int					print_percent(void);

int print_char(t_segment *segment);
int					print_string(t_segment *segment);
int					print_pointer(t_segment *segment);
int					print_int(t_segment *segment);
int					print_uint(t_segment *segment);
int	print_hex(t_segment *segment);
int	print_large_hex(t_segment *segment);

// free
void				free_segment(void *segment_ptr);

// string
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *s);
char				*ft_itoa(long long n);
char	*ft_uitoa(unsigned long long n);
int						ft_atoi(const char *nptr);

// convert
char				*pointer_to_hex(void *ptr);
char				*decimal_to_hex(unsigned long long number);
char	*decimal_to_large_hex(unsigned long long number);

// char type
int					ft_isdigit(int c);

// put
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// list
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif