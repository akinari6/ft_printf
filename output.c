/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:35:30 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 23:38:26 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_segment_content(t_segment *segment)
{
	t_format_type	type;

	type = segment->fmt_type;
	if (segment->seg_type == SEG_TEXT)
		return (write_and_count_str(segment->content));
	else if (type == TYPE_CHAR)
		return (print_char(segment));
	else if (type == TYPE_PERCENT)
		return (write_and_count_char(segment->value.c));
	else if (type == TYPE_STRING)
		return (print_string(segment));
	else if (type == TYPE_POINTER)
		return (print_pointer(segment));
	else if (type == TYPE_INT || type == TYPE_IINT)
		return (print_int(segment));
	else if (type == TYPE_UINT)
		return print_uint(segment);
	else if (type == TYPE_HEX_LOWER)
		return (print_hex(segment));
	else if (type == TYPE_HEX_UPPER)
		return print_large_hex(segment);
	return (0);
}

int	output(t_list *segment_list)
{
	int			total;
	t_list		*node;
	t_segment	*segment;

	total = 0;
	node = segment_list;
	while (node != NULL)
	{
		segment = node->content;
		total += print_segment_content(segment);
		node = node->next;
	}
	return (total);
}

