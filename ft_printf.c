/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:02:00 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 22:16:24 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*segment_list;
	int		total_length;

	va_start(ap, format);
	segment_list = parse(format, ap);
	total_length = output(segment_list);
	ft_lstclear(&segment_list, free_segment);
	va_end(ap);
	return (total_length);
}
