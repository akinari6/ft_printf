/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:44:24 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 19:45:59 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_hex_prefix(t_options opts, bool is_large)
{
	if (!opts.flag_hash)
		return (ft_strdup(""));
	if (is_large)
		return (ft_strdup("0X"));
	return (ft_strdup("0x"));
}

static char	*create_padded_string(char *s, int pad_size, char pad_char,
		bool left)
{
	char	*pad;
	char	*result;

	pad = malloc(pad_size + 1);
	if (pad == NULL)
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

static char	*apply_prefix_and_width(char *s, char *prefix, t_options opts)
{
	char	*applied;
	char	*tmp;
	int		pad_size;

	pad_size = opts.width - ft_strlen(s) - ft_strlen(prefix);
	if (pad_size <= 0)
	{
		applied = ft_strjoin(prefix, s);
		free(prefix);
		free(s);
		return (applied);
	}
	if (opts.flag_zero && !opts.flag_minus)
	{
		tmp = create_padded_string(s, pad_size, '0', true);
		applied = ft_strjoin(prefix, tmp);
	}
	else
	{
		tmp = ft_strjoin(prefix, s);
		applied = create_padded_string(tmp, pad_size, ' ', !opts.flag_minus);
	}
	free(s);
	free(tmp);
	free(prefix);
	return (applied);
}

char	*format_hex(t_segment *segment, bool is_large)
{
	char	*s;
	char	*prefix;

	s = decimal_to_hex(segment->value.i);
	if (s == NULL)
		return (NULL);
	prefix = create_hex_prefix(segment->opts, is_large);
	if (prefix == NULL)
	{
		free(s);
		return (NULL);
	}
	s = apply_num_precision(s, segment->opts);
	if (s == NULL)
		return (NULL);
	s = apply_prefix_and_width(s, prefix, segment->opts);
	return (s);
}
