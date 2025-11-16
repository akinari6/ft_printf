/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:23:21 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 22:17:11 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(t_segment *segment)
{
	if (segment->value.s == NULL)
		return (write_and_count_str("(null)"));
	return (write_and_count_str(segment->value.s));
}

int	print_pointer(t_segment *segment)
{
	char	*s;
	int		length;

	s = pointer_to_hex(segment->value.ptr);
	if (s == NULL)
		return 0;
	length = write_and_count_str("0x");
	length += write_and_count_str(s);
	free(s);
	return (length);
}

int	print_int(t_segment *segment)
{
	char	*s;
	int		length;


	s = ft_itoa(segment->value.i);
	if (s == NULL)
		return 0;
	length = write_and_count_str(s);
	free(s);
	return (length);
}

int	print_hex(t_segment *segment)
{
	char *s;
	int length;

	s = decimal_to_hex(segment->value.i);
	length = write_and_count_str(s);
	free(s);
	return (length);
}
