/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:02:59 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 15:10:58 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*joined_str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_str = malloc(size);
	if (joined_str == NULL)
		return (NULL);
	ft_strlcpy(joined_str, s1, size);
	ft_strlcat(joined_str, s2, size);
	return (joined_str);
}
