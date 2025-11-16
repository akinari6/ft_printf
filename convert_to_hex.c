/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinari <akinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:16 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/16 23:37:17 by akinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_buffer_size_p(void *ptr)
{
	int			buffer_size;
	unsigned long long	ll;

	buffer_size = 1;
	ll = (long long)ptr;
	while (ll > 0)
	{
		buffer_size += 1;
		ll /= 16;
	}
	return (buffer_size);
}

static int	calc_buffer_size_i(unsigned long long number)
{
	int			buffer_size;
	unsigned long long	ll;

	buffer_size = 1;
	ll = number;
	while (ll > 0)
	{
		buffer_size += 1;
		ll /= 16;
	}
	return (buffer_size);
}

char	*pointer_to_hex(void *ptr)
{
	const char	hex_base[] = "0123456789abcdef";
	unsigned long long	ll;
	int			buffer_size;
	char		*hex;

	if (ptr == NULL)
	{
		hex = ft_strdup("0");
		return (hex);
	}
	buffer_size = calc_buffer_size_p(ptr);
	hex = malloc(buffer_size);
	hex[--buffer_size] = '\0';
	ll = (long long)ptr;
	while (ll > 0)
	{
		hex[--buffer_size] = hex_base[ll % 16];
		ll /= 16;
	}
	return (hex);
}

char	*decimal_to_hex(unsigned long long number)
{
	const char	hex_base[] = "0123456789abcdef";
	int			buffer_size;
	char		*hex;

	if (number == 0)
	{
		hex = ft_strdup("0");
		return (hex);
	}
	buffer_size = calc_buffer_size_i(number);
	hex = malloc(buffer_size);
	hex[--buffer_size] = '\0';
	while (number > 0)
	{
		hex[--buffer_size] = hex_base[number % 16];
		number /= 16;
	}
	return (hex);
}

char	*decimal_to_large_hex(unsigned long long number)
{
	const char	hex_base[] = "0123456789ABCDEF";
	int			buffer_size;
	char		*hex;

	if (number == 0)
	{
		hex = ft_strdup("0");
		return (hex);
	}
	buffer_size = calc_buffer_size_i(number);
	hex = malloc(buffer_size);
	hex[--buffer_size] = '\0';
	while (number > 0)
	{
		hex[--buffer_size] = hex_base[number % 16];
		number /= 16;
	}
	return (hex);
}

// #include <stdio.h>
// int main()
// {
//     char *hex = pointer_to_hex("abc");
//     printf("%s\n", hex);
// }