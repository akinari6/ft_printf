/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:35:44 by aktsuji           #+#    #+#             */
/*   Updated: 2025/10/26 18:45:00 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*allocate_and_apply(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*node;
	void	*new_content;

	new_content = f(lst->content);
	node = ft_lstnew(new_content);
	if (node == NULL)
	{
		del(new_content);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*now;
	t_list	*previous;

	if (lst == NULL)
		return (NULL);
	head = allocate_and_apply(lst, f, del);
	if (head == NULL)
		return (NULL);
	previous = head;
	lst = lst->next;
	while (lst != NULL)
	{
		now = allocate_and_apply(lst, f, del);
		if (now == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		previous->next = now;
		previous = now;
		lst = lst->next;
	}
	return (head);
}
