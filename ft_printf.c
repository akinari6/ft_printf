/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:02:00 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 16:17:41 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void print_bool(bool flag)
{
	if (flag)
		printf("ENABLED\n");
    else
	    printf("DISABLED\n");
}

void print_full_segment(void *seg_ptr)
{
    t_segment *segment = seg_ptr;
    // segment type
    if (segment->seg_type == SEG_TEXT)
        printf("segment type:\ttext\n");
    else if (segment->seg_type == SEG_FORMAT)
        printf("segment type:\tformat\n");

    // content
    printf("content:\t%s\n", segment->content);

    if (segment->seg_type == SEG_TEXT) 
    {
        printf("--------------------\n");
        return;
    }

    // fmt_type
    printf("format type:\t%c\n", segment->fmt_type);

    // value
    t_format_type type;

    type = segment->fmt_type;
    printf("value:\t\t");
    if (type == TYPE_CHAR || type == TYPE_PERCENT)
        printf("%c\n", segment->value.c);
    else if (type == TYPE_STRING)
        printf("%s\n", segment->value.s);
    else if (type == TYPE_POINTER)
        printf("%p\n", segment->value.ptr);
    else if (type == TYPE_INT || type == TYPE_UINT)
        printf("%lld\n", segment->value.i);
    else if (type == TYPE_HEX_LOWER || type == TYPE_HEX_UPPER)
        printf("%lld\n", segment->value.i);

	// options
	t_options opts = (*segment).opts;
	printf("options\n");
	printf("\twidth\t\t: %d\n", opts.width);
	printf("\tprecision\t: %d\n", opts.precision);
	printf("\tminus(-)\t: "); print_bool(opts.flag_minus);
	printf("\tzero(0)\t\t: "); print_bool(opts.flag_zero);
	printf("\tplus(+)\t\t: "); print_bool(opts.flag_plus);
	printf("\tspace( )\t: "); print_bool(opts.flag_space);
	printf("\thash(#)\t\t: "); print_bool(opts.flag_hash);
    printf("--------------------\n");
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_list *segment_list;
    int total_length;

    va_start(ap, format);
    segment_list = parse(format, ap);
    // ft_lstiter(segment_list, print_full_segment); // for debug
    total_length = output(segment_list, true);
    ft_lstclear(&segment_list, free_segment);
    va_end(ap);
    return total_length;
}



int main()
{
    int a = ft_printf("abcd|%-0+# 10.20c|123|%10.4s|ABC|%30p|+++|%d|@@@|%%|\n", 'F', "?????", "address", 42);
    printf("%d\n", a);
}
// abcd123ABC+++@@@
//F         
// abcdF         123ABC+++@@@
