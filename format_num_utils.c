/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_num_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:25:49 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 17:47:07 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*create_sign(bool is_minus, t_options opts)
{
	if (is_minus)
		return (ft_strdup("-"));
	if (opts.flag_plus)
		return (ft_strdup("+"));
	if (opts.flag_space)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

char	*apply_num_precision(char *s, t_options opts)
{
	char	*applied;
	char	*zero_pad;
	int		zero_pad_size;

	zero_pad_size = opts.precision - ft_strlen(s);
	if (opts.precision <= 0 || zero_pad_size <= 0)
		return (s);
	zero_pad = malloc(zero_pad_size + 1);
	ft_memset(zero_pad, '0', zero_pad_size);
	zero_pad[zero_pad_size] = '\0';
	applied = ft_strjoin(zero_pad, s);
	free(s);
	free(zero_pad);
	return (applied);
}