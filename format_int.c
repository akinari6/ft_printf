/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:31:57 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 19:29:22 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_unsigned(long long l)
{
	long long	num;
	int			length;
	char		*str;

	length = 0;
	if (l == 0)
		return (ft_strdup("0"));
	if (l < 0)
		l = -l;
	num = l;
	while (num > 0)
	{
		length += 1;
		num /= 10;
	}
	str = malloc(length + 1);
	if (str == NULL)
		return (str);
	str[length] = '\0';
	while (l > 0)
	{
		str[--length] = '0' + l % 10;
		l /= 10;
	}
	return (str);
}

static char	get_pad_char(t_options opts)
{
	if (opts.flag_zero && opts.precision <= 0 && !opts.flag_minus)
		return ('0');
	return (' ');
}

static char	*create_padded_string(char *s, int pad_size, char pad_char,
		bool left)
{
	char	*pad;
	char	*result;

	pad = malloc(pad_size + 1);
	if (!pad)
		return (NULL);
	pad[pad_size] = '\0';
	ft_memset(pad, pad_char, pad_size);
	if (left)
		result = ft_strjoin(pad, s);
	else
		result = ft_strjoin(s, pad);
	free(pad);
	return (result);
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

static char	*apply_sign_and_width(char *s, bool is_minus, t_options opts)
{
	char	*sign;
	char	*tmp;
	char	*result;
	int		pad_size;

	sign = create_sign(is_minus, opts);
	pad_size = opts.width - ft_strlen(s) - ft_strlen(sign);
	if (pad_size <= 0)
		return (join_and_free(sign, s));
	if (opts.flag_zero && !opts.flag_minus)
    {
        tmp = create_padded_string(s, pad_size, '0', true);
        result = ft_strjoin(sign, tmp);
    }
    else
    {
        tmp = ft_strjoin(sign, s);
        result = create_padded_string(tmp, pad_size, ' ', !opts.flag_minus);
    }
    free(s);
    free(tmp);
    free(sign);
	return (result);
}

char	*format_int(t_segment *segment)
{
	char	*s;
	bool	is_minus;

	is_minus = segment->value.i < 0;
	s = itoa_unsigned(segment->value.i);
	if (s == NULL)
		return (NULL);
	s = apply_num_precision(s, segment->opts);
	if (s == NULL)
		return (NULL);
	s = apply_sign_and_width(s, is_minus, segment->opts);
	return (s);
}
