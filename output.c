/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:35:30 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/02 15:35:44 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_segment_content(t_segment *segment)
{
	t_format_type	type;

	type = segment->fmt_type;
	if (segment->seg_type == SEG_TEXT)
		ft_putstr_fd(segment->content, STDOUT_FILENO);
	else if (type == TYPE_CHAR || type == TYPE_PERCENT)
		ft_putchar_fd(segment->value.c, STDOUT_FILENO);
	else if (type == TYPE_POINTER)
		ft_putpointer_fd(segment->value.ptr, STDOUT_FILENO);
	else if (type == TYPE_INT || type == TYPE_UINT)
		ft_putnbr_fd(segment->value.i, STDOUT_FILENO);
	else if (type == TYPE_HEX_LOWER)
		ft_puthex_fd(segment->value.i, STDOUT_FILENO);
    else if (type == TYPE_HEX_UPPER)
        ft_puthex_fd(segment->value.i, STDOUT_FILENO);
}

void	output(t_list *segment_list)
{
	t_list		*node;
	t_segment	*segment;

	node = segment_list;
	while (node != NULL)
	{
		segment = node->content;
		print_segment_content(segment);
		node = node->next;
	}
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