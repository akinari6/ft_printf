/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:41:06 by aktsuji           #+#    #+#             */
/*   Updated: 2025/10/30 20:49:26 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	del_content(void *segment)
{
	free(segment);
}

static void	free_segment_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static t_segment	*create_node(char *segment_str)
{
	t_segment	*segment;

	segment = malloc(sizeof(t_segment));
	if (segment == NULL)
		return (NULL);
	if (segment_str[0] == PERCENT)
		segment->seg_type = SEG_FORMAT;
	else
		segment->seg_type = SEG_TEXT;
	segment->content = segment_str;
	return (segment);
}

t_list	*create_list(char **segments)
{
	int			i;
	t_list		*head;
	t_list		*node;
	t_segment	*content;

	i = 0;
	head = NULL;
	while (segments[i] != NULL)
	{
		content = create_node(segments[i]);
		if (content == NULL)
		{
			ft_lstclear(&head, del_content);
			free_segment_strs(segments);
			return (NULL);
		}
		node = ft_lstnew(content);
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

// #include <stdio.h>

// void	test_create_list(char **segments)
// {
// 	t_list		*lst;
// 	t_segment	*segment;

// 	lst = create_list(segments);
// 	while (lst != NULL)
// 	{
// 		segment = lst->content;
// 		printf("type: ");
// 		if (segment->seg_type == SEG_TEXT)
// 			printf("TEXT, ");
// 		else
// 			printf("FORMAT, ");
// 		printf("%s\n", segment->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	char	**segments;

// 	segments = split_format_to_segments("abcd%sabcd%2#.3s");
// 	test_create_list(segments);
// }
