/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:43:56 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 12:35:29 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_flag(char c)
{
	int			i;
	const char	flags[] = "-0# +";

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static int	set_flag(t_segment *segment, char *content, int i)
{
	while (content[i] != '\0' && is_flag(content[i]))
	{
		if (content[i] == '-')
			(*segment).opts.flag_minus = true;
		else if (content[i] == '0')
			(*segment).opts.flag_zero = true;
		else if (content[i] == '#')
			(*segment).opts.flag_hash = true;
		else if (content[i] == ' ')
			(*segment).opts.flag_space = true;
		else if (content[i] == '+')
			(*segment).opts.flag_plus = true;
		i++;
	}
	return (i);
}

void	parse_options(void *segment_ptr)
{
	int			i;
	t_segment	*segment;
	char		*content;

	i = 1;
	segment = segment_ptr;
	content = segment->content;
	while (content[i] != '\0')
	{
		i = set_flag(segment, content, i);
		printf("DRBUG: %d, %s\n", i, content + i);
		(*segment).opts.width = ft_atoi(content + i);
		while (content[i] != '\0' && ft_isdigit(content[i]))
			i++;
		i++;
		(*segment).opts.precision = ft_atoi(content + i);
		break ;
	}
}
