/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:35:31 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 12:17:01 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*free_segment_strs(char **segment_strs)
{
	int	i;

	i = 0;
	while (segment_strs[i] != NULL)
	{
		free(segment_strs[i]);
		i++;
	}
	free(segment_strs);
	return (NULL);
}

t_list	*parse(char const *format, va_list ap)
{
	char	**segment_strs;
	t_list	*segment_list;

	segment_strs = split_format_to_segments(format);
	if (segment_strs == NULL)
		return (NULL);
	segment_list = create_list(segment_strs);
	if (segment_list == NULL)
		return (free_segment_strs(segment_strs));
	parse_var_args(segment_list, ap);
	ft_lstiter(segment_list, parse_options);
	free(segment_strs);
	return (segment_list);
}

