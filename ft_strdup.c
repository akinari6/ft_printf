/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:48:48 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 13:49:16 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_str;
	size_t	duplicate_size;

	duplicate_size = ft_strlen(s) + 1;
	duplicated_str = (char *)malloc(duplicate_size);
	if (duplicated_str == NULL)
		return (NULL);
	ft_strlcpy(duplicated_str, s, duplicate_size);
	return (duplicated_str);
}
