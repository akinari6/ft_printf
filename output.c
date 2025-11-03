/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:35:30 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 13:56:33 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_segment_content(t_segment *segment, bool is_bonus)
{
	t_format_type	type;

	type = segment->fmt_type;
	if (segment->seg_type == SEG_TEXT)
		return (write_and_count_str(segment->content));
	else if (type == TYPE_CHAR)
		return (print_character(segment, is_bonus));
	else if (type == TYPE_PERCENT)
		return (write_and_count_char(segment->value.c));
	else if (type == TYPE_STRING)
		return (print_string(segment, is_bonus));
	// if (segment->seg_type == SEG_TEXT)
	// 	ft_putstr_fd(segment->content, STDOUT_FILENO);
	// else if (type == TYPE_CHAR)
	// 	ft_putchar_fd(segment->value.c, STDOUT_FILENO);
	// else if (type == TYPE_POINTER)
	// 	ft_putpointer_fd(segment->value.ptr, STDOUT_FILENO);
	// else if (type == TYPE_INT || type == TYPE_UINT)
	// 	ft_putnbr_fd(segment->value.i, STDOUT_FILENO);
	// else if (type == TYPE_HEX_LOWER)
	// 	ft_puthex_fd(segment->value.i, STDOUT_FILENO);
	// else if (type == TYPE_HEX_UPPER)
	//     ft_puthex_fd(segment->value.i, STDOUT_FILENO);
	// else if (type == TYPE_PERCENT)
	// 	ft_putchar_fd(segment->value.c, STDOUT_FILENO);
	return (0);
}

int	output(t_list *segment_list, bool is_bonus)
{
	int			total;
	t_list		*node;
	t_segment	*segment;

	total = 0;
	node = segment_list;
	while (node != NULL)
	{
		segment = node->content;
		total += print_segment_content(segment, is_bonus);
		node = node->next;
	}
	return (total);
}

// #include <stdio.h>
// void print_segment(t_segment *segment);

// void test_output(char *fmt, ...)
// {
//     va_list ap;
//     va_start(ap, fmt);

//     t_list *segment_list = parse(fmt, ap);
//     output(segment_list);

//     t_list *node = segment_list;
//     while(node != NULL)
//     {
//         print_segment(node->content);
//         node = node->next;
//     }
// }

// int main()
// {
//     test_output("abcd%c123%sABC%p+++%d@@@%%", 'F', "|||||", "address", 42);
// }
