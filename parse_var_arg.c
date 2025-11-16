/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 20:34:51 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 17:59:55 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// todo
// 1. init options
// 2. classify fmt_typ
// 3. extract_value_from_va_list

t_options	get_initial_options(void)
{
	t_options	opts;

	opts.width = -1;
	opts.precision = -1;
	opts.flag_minus = false;
	opts.flag_zero = false;
	opts.flag_plus = false;
	opts.flag_space = false;
	opts.flag_hash = false;
	return (opts);
}

t_format_type	classify_fmt_type(char *content)
{
	int	content_length;

	content_length = ft_strlen(content);
	return (content[content_length - 1]);
}

void	extract_from_va_list(t_segment *segment, va_list ap)
{
	t_format_type	type;

	type = segment->fmt_type;
	if (type == TYPE_CHAR)
		segment->value.c = va_arg(ap, int);
	else if (type == TYPE_STRING)
		segment->value.s = va_arg(ap, char *);
	else if (type == TYPE_POINTER)
		segment->value.ptr = va_arg(ap, void *);
	else if (type == TYPE_INT || type == TYPE_UINT || type == TYPE_IINT)
		segment->value.i = va_arg(ap, long long);
	else if (type == TYPE_HEX_LOWER || type == TYPE_HEX_UPPER)
		segment->value.i = va_arg(ap, long long);
	else if (type == TYPE_PERCENT)
		segment->value.c = '%';
}

t_list	*parse_var_args(t_list *segment_list, va_list ap)
{
	t_list		*node;
	t_segment	*segment;

	node = segment_list;
	while (node != NULL)
	{
		segment = node->content;
		segment->opts = get_initial_options();
		if (segment->seg_type == SEG_FORMAT)
		{
			segment->fmt_type = classify_fmt_type(segment->content);
			extract_from_va_list(segment, ap);
		}
		node = node->next;
	}
	return (segment_list);
}

// #include <stdio.h>

// void	test_create_list(char **segments)
// {
// 	t_list		*lst;
// 	t_segment	*segment;

// 	lst = create_list(segments);
// 	while (lst != NULL)
// 	{
// 		segment = lst->content;
// 		printf("type: ");
// 		if (segment->seg_type == SEG_TEXT)
// 			printf("TEXT, ");
// 		else
// 			printf("FORMAT, ");
// 		printf("%s\n", segment->content);
// 		lst = lst->next;
// 	}
// }

// void	print_segment(t_segment *segment)
// {
// 	t_format_type	type;

// 	// segment type
// 	if (segment->seg_type == SEG_TEXT)
// 		printf("segment type:\ttext\n");
// 	else
// 		printf("segment type:\tformat\n");
// 	// content
// 	printf("content:\t%s\n", segment->content);
// 	if (segment->seg_type == SEG_TEXT)
// 	{
// 		printf("--------------------\n");
// 		return ;
// 	}
// 	// fmt_type
// 	printf("format type:\t%c\n", segment->fmt_type);
// 	// value
// 	type = segment->fmt_type;
// 	printf("value:\t\t");
// 	if (type == TYPE_CHAR || type == TYPE_PERCENT)
// 		printf("%c\n", segment->value.c);
// 	else if (type == TYPE_STRING)
// 		printf("%s\n", segment->value.s);
// 	else if (type == TYPE_POINTER)
// 		printf("%p\n", segment->value.ptr);
// 	else if (type == TYPE_INT || type == TYPE_UINT)
// 		printf("%lld\n", segment->value.i);
// 	else if (type == TYPE_HEX_LOWER || type == TYPE_HEX_UPPER)
// 		printf("%lld\n", segment->value.i);
// 	printf("--------------------\n");
// }

// void	test_parse_var_args(char *fmt, ...)
// {
// 	va_list	ap;
// 	t_list	*segment_list;
// 	t_list	*node;

// 	// char **segments = split_format_to_segments(fmt);
// 	// t_list *segment_list = create_list(segments);
// 	// t_list *node = segment_list;
// 	va_start(ap, fmt);
// 	segment_list = parse(fmt, ap);
// 	node = segment_list;
// 	// parse_var_args(segment_list, ap);
// 	while (node != NULL)
// 	{
// 		print_segment(node->content);
// 		node = node->next;
// 	}
// }

// int	main(void)
// {
// 	test_parse_var_args("abcd%c123%sABC%p+++%d@@@%%", 'F', "|||||", "address",
// 42);
// }
