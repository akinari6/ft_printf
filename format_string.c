/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:21:26 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 14:04:15 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *apply_precision(char *s, int precision)
{
	int s_len;
	char *new;

	s_len = ft_strlen(s);
	if (precision >= s_len)
		return s;
	new = malloc(precision + 1);
	if (new == NULL)
		return NULL;
	ft_strlcpy(new, s, precision + 1);
	free(s);
	return new;
}

static char *apply_width(char *s, t_options opts)
{
    char *new;
    int s_len;
    int i;

    s_len = ft_strlen(s);
    if (s_len >= opts.width)
        return s;
    new = malloc(opts.width + 1);
    if (opts.flag_minus)
    {
        ft_strlcpy(new, s, opts.width + 1);
        ft_memset(new + s_len, ' ', opts.width - s_len);
    }
	else
	{
		ft_memset(new, ' ', opts.width - s_len);
        new[opts.width - s_len] = '\0';
        ft_strlcat(new, s, opts.width);
	}
    new[opts.width] = '\0';
    free(s);
    return new;
}

char	*format_string(t_segment *segment)
{
	char *s;

	segment->opts.flag_zero = false;
	s = ft_strdup(segment->value.s);
	if (s != NULL && segment->opts.precision > 0)
		s = apply_precision(s, segment->opts.precision);
	if (s != NULL && segment->opts.width > 0)
		s = apply_width(s, segment->opts);
	return (s);
}