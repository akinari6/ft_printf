/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:02:00 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/02 15:00:19 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_list *segment_list;

    va_start(ap, format);
    segment_list = parse(format, ap);
    output(segment_list);
    va_end(ap);
}

int main()
{
    ft_printf("abcd%c123%sABC%p+++%d@@@%%", 'F', "|||||", "address", 42);
}
