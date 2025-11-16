/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:35:30 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 18:46:35 by aktsuji          ###   ########.fr       */
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
	else if (type == TYPE_POINTER)
		return (print_pointer(segment, is_bonus));
	else if (type == TYPE_INT || type == TYPE_UINT || type == TYPE_IINT)
		return (print_int(segment, is_bonus));
	else if (type == TYPE_HEX_LOWER)
		return (print_hex(segment, false, is_bonus));
	else if (type == TYPE_HEX_UPPER)
		return (print_hex(segment, true, is_bonus));
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
