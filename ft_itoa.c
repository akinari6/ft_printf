/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:08:53 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 23:27:19 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	calc_buffer_size(long long nl)
{
	size_t	buffer_size;

	buffer_size = 0;
	if (nl < 0)
	{
		buffer_size++;
		nl = -nl;
	}
	while (nl > 0)
	{
		buffer_size++;
		nl /= 10;
	}
	return (buffer_size + 1);
}

static char	*return_zero(void)
{
	char	*buffer;

	buffer = malloc(2);
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '0';
	buffer[1] = '\0';
	return (buffer);
}

char	*ft_itoa(long long n)
{
	long long	nl;
	size_t		buffer_size;
	char		*buffer;
	size_t		i;

	if (n == 0)
		return (return_zero());
	nl = n;
	buffer_size = calc_buffer_size(nl);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (NULL);
	if (nl < 0)
	{
		nl = -nl;
		buffer[0] = '-';
	}
	i = buffer_size;
	buffer[--i] = '\0';
	while (nl > 0)
	{
		buffer[--i] = '0' + (nl % 10);
		nl /= 10;
	}
	return (buffer);
}

char	*ft_uitoa(unsigned long long n)
{
	unsigned long long	nl;
	size_t		buffer_size;
	char		*buffer;
	size_t		i;

	if (n == 0)
		return (return_zero());
	nl = n;
	buffer_size = calc_buffer_size(nl);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (NULL);
	if (nl < 0)
	{
		nl = -nl;
		buffer[0] = '-';
	}
	i = buffer_size;
	buffer[--i] = '\0';
	while (nl > 0)
	{
		buffer[--i] = '0' + (nl % 10);
		nl /= 10;
	}
	return (buffer);
}

