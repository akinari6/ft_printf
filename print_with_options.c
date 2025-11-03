/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:23:21 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 16:02:54 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(t_segment *segment, bool is_bonus)
{
	char	*s;
	int		length;

	if (!is_bonus)
		return (write_and_count_char(segment->value.c));
	s = format_character(segment);
	if (s == NULL)
		return (0);
	length = write_and_count_str(s);
	free(s);
	return (length);
}

int	print_string(t_segment *segment, bool is_bonus)
{
	char	*s;
	int		length;

	if (segment->value.s == NULL)
		return (write_and_count_str("(null)"));
	if (!is_bonus)
		return (write_and_count_str(segment->value.s));
	s = format_string(segment);
	if (s == NULL)
		return (0);
	length = write_and_count_str(s);
	free(s);
	return (length);
}

int	print_pointer(t_segment *segment, bool is_bonus)
{
	char *s;
	int length;

	s = pointer_to_hex(segment->value.ptr);
	if (s != NULL && !is_bonus)
	{
        length = write_and_count_str("0x");
		length += write_and_count_str(s);
		free(s);
		return (length);
	}
	s = format_pointer(s, segment->opts);
	if (s == NULL)
		return (0);
	length = write_and_count_str(s);
	free(s);
	return (length);
}
