/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:45:29 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 12:00:39 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	if (c == '\f')
		return (true);
	if (c == '\n')
		return (true);
	if (c == '\r')
		return (true);
	if (c == '\t')
		return (true);
	if (c == '\v')
		return (true);
	return (false);
}

int	ft_atoi(const char *nptr)
{
	long long	number;
	bool		is_minus;
	int			i;

	number = 0;
	i = 0;
	is_minus = 0;
	while (nptr[i] != '\0' && is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_minus = 1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		number *= 10;
		number += (nptr[i] - '0');
		i++;
	}
	if (is_minus)
		number = -number;
	return (number);
}
