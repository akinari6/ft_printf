/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:02:00 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 23:38:36 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	print_bool(bool flag)
{
	if (flag)
		printf("ENABLED\n");
	else
		printf("DISABLED\n");
}

void	print_full_segment(void *seg_ptr)
{
	t_segment		*segment;
	t_format_type	type;

	segment = seg_ptr;
	// segment type
	if (segment->seg_type == SEG_TEXT)
		printf("segment type:\ttext\n");
	else if (segment->seg_type == SEG_FORMAT)
		printf("segment type:\tformat\n");
	// content
	printf("content:\t[%s]\n", segment->content);
	if (segment->seg_type == SEG_TEXT)
	{
		printf("--------------------\n");
		return ;
	}
	// fmt_type
	printf("format type:\t%c\n", segment->fmt_type);
	// value
	type = segment->fmt_type;
	printf("value:\t\t");
	if (type == TYPE_CHAR || type == TYPE_PERCENT)
		printf("%c\n", segment->value.c);
	else if (type == TYPE_STRING)
		printf("%s\n", segment->value.s);
	else if (type == TYPE_POINTER)
		printf("%p\n", segment->value.ptr);
	else if (type == TYPE_INT || type == TYPE_IINT)
		printf("%lld\n", segment->value.i);
	else if (type == TYPE_UINT)
		printf("%lld\n", segment->value.ui);
	else if (type == TYPE_HEX_LOWER || type == TYPE_HEX_UPPER)
		printf("%lld\n", segment->value.i);
	printf("--------------------\n");
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*segment_list;
	int		total_length;

	va_start(ap, format);
	segment_list = parse(format, &ap);
	// ft_lstiter(segment_list, print_full_segment);
	total_length = output(segment_list);
	ft_lstclear(&segment_list, free_segment);
	va_end(ap);
	return (total_length);
}

// #include <limits.h>

// int main()
// {
// 	int a = printf(" %X ", -1);
// 	fflush(stdout);
// 	ft_printf(" %X ", -1);
// }