/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:07:09 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 16:19:36 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_sign(char *s, t_options opts)
{
	char	*new;

	if (s != NULL && opts.flag_plus)
	{
		new = ft_strjoin("+", s);
		free(s);
		return (new);
	}
	else if (s != NULL && opts.flag_space)
	{
		new = ft_strjoin(" ", s);
		free(s);
		return (new);
	}
	return (s);
}

static char	*apply_prefix(char *s)
{
	char	*new;

	if (s == NULL)
		return (NULL);
	new = ft_strjoin("0x", s);
	free(s);
	return (new);
}

static char	*apply_width_opts(char *s, t_options opts)
{
	char	*new;
	int		s_len;
	int		length;

	s_len = ft_strlen(s);
	length = opts.width - (opts.flag_space || opts.flag_plus) - 2;
	if (s_len >= length || !(opts.flag_minus || opts.flag_zero))
		return (s);
	new = malloc(length + 1);
	if (new == NULL)
	{
		free(s);
		return (NULL);
	}
	if (opts.flag_minus)
	{
		ft_strlcpy(new, s, length + 1);
		ft_memset(new + ft_strlen(s), ' ', length);
		new[length] = '\0';
	}
	else if (opts.flag_zero)
	{
		ft_memset(new, '0', length);
		new[length - s_len] = '\0';
		ft_strlcat(new, s, length + 1);
	}
	free(s);
	return (new);
}

static char	*apply_width_normal(char *s, t_options opts)
{
	char	*new;
	int		s_len;
	int		length;

	s_len = ft_strlen(s);
	length = opts.width;
	if (s_len >= length || opts.flag_minus || opts.flag_zero)
		return (s);
	new = malloc(length + 1);
	if (new == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_memset(new, 0, length + 1);
	ft_memset(new, ' ', length - ft_strlen(s));
	ft_strlcat(new, s, length + 1);
	free(s);
	return (new);
}

char	*format_pointer(char *s, t_options opts)
{
	char	*new;

	new = NULL;
	if (opts.width > 0)
		new = apply_width_opts(s, opts);
	if (new == NULL)
		new = apply_prefix(s);
	else
		new = apply_prefix(new);
	if (opts.flag_plus || opts.flag_space)
		new = apply_sign(new, opts);
	new = apply_width_normal(new, opts);
	if (new != NULL && opts.width > 0)
		return (new);
}
