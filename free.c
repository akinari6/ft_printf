/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:39:10 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 12:40:54 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void free_segment(void *segment_ptr)
{
    t_segment *segment;

    segment = segment_ptr;
    free(segment->content);
    free(segment);
}
