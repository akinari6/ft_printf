/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_segments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:00:45 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 16:27:51 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_conversion_specifier(char c)
{
	int			i;
	const char	*conversion_specifier = SPECS;

	i = 0;
	while (conversion_specifier[i] != '\0')
	{
		if (c == conversion_specifier[i])
			return (true);
		i++;
	}
	return (false);
}

static size_t	count_segments(const char *format)
{
	int		i;
	size_t	count;
	bool	in_format;

	i = 0;
	count = 0;
	in_format = false;
	while (format[i] != '\0')
	{
		if (format[i] == PERCENT)
		{
			i++;
			while (format[i] != '\0' && !is_conversion_specifier(format[i]))
				i++;
			count++;
			i++;
		}
		else
		{
			while (format[i] != '\0' && format[i] != PERCENT)
				i++;
			count++;
		}
	}
	return (count);
}

static char	*extract_segment(const char *format, int *idx)
{
	int		length;
	char	*segment;

	length = 0;
	if (format[*idx] == PERCENT)
	{
		length++;
		while (format[*idx + length] != '\0'
			&& !is_conversion_specifier(format[*idx + length]))
			length++;
		length++;
	}
	else
	{
		while (format[*idx + length] != '\0'
			&& format[*idx + length] != PERCENT)
			length++;
	}
	segment = malloc(length + 1);
	if (segment == NULL)
		return (NULL);
	ft_strlcpy(segment, format + *idx, length + 1);
	*idx = *idx + length;
	return (segment);
}

static void	*free_segments(char **segments, int segment_index)
{
	int	i;

	i = 0;
	while (i < segment_index)
	{
		free(segments[i]);
		i++;
	}
	free(segments);
	return (NULL);
}

char	**split_format_to_segments(const char *format)
{
	char	**segments;
	size_t	segment_count;
	int		format_index;
	int		segment_index;
	int		length;

	segment_count = count_segments(format);
	segments = malloc(sizeof(char *) * (segment_count + 1));
	format_index = 0;
	segment_index = 0;
	while (segment_index < segment_count)
	{
		segments[segment_index] = extract_segment(format, &format_index);
		if (segments[segment_index] == NULL)
			return (free_segments(segments, segment_index));
		segment_index++;
	}
	segments[segment_count] = NULL;
	return (segments);
}

// #include <stdio.h>

// void	print_count_segments(char *str)
// {
// 	int	actual;

// 	actual = count_segments(str);
// 	printf("%d\n", actual);
// }

// void test_split_format_to_segments(const char *str)
// {
// 	char **segments = split_format_to_segments(str);
// 	for (int i = 0; segments[i] != NULL; i++) {
// 		printf("%s, ", segments[i]);
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	// print_count_segments("abcde");
// 	// print_count_segments("abcd%sabcd%2.3s\n");
// 	// print_count_segments("abcd%sabcd%#2.3sc\n");
// 	test_split_format_to_segments("abcde");
// 	test_split_format_to_segments("abcd%sabcd%2#.3s");
// }
