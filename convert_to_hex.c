/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:48:16 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 16:01:45 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_buffer_size_p(void *ptr)
{
	int			buffer_size;
	long long	ll;

	buffer_size = 1;
	ll = (long long)ptr;
	while (ll > 0)
	{
		buffer_size += 1;
		ll /= 16;
	}
	return (buffer_size);
}

static int	calc_buffer_size_i(int number)
{
	int			buffer_size;
	long long	ll;

	buffer_size = 1;
	ll = number;
	while (ll > 0)
	{
		buffer_size += 1;
		ll /= 16;
	}
	return (buffer_size);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	length;

// 	length = 0;
// 	while (s[length] != '\0')
// 		length++;
// 	return (length);
// }


// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	if (size == 0)
// 		return (ft_strlen(src));
// 	i = 0;
// 	while (src[i] != '\0' && i < size - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (ft_strlen(src));
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*duplicated_str;
// 	size_t	duplicate_size;

// 	duplicate_size = ft_strlen(s) + 1;
// 	duplicated_str = (char *)malloc(duplicate_size);
// 	if (duplicated_str == NULL)
// 		return (NULL);
// 	ft_strlcpy(duplicated_str, s, duplicate_size);
// 	return (duplicated_str);
// }

char	*pointer_to_hex(void *ptr)
{
	const char	hex_base[] = "0123456789abcdef";
	long long	ll;
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

char	*decimal_to_hex(int number)
{
	const char	hex_base[] = "0123456789abcdef";
	long long	ll;
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