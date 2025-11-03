/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:23:21 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 13:08:06 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_character(t_segment *segment, bool is_bonus)
{
    char *s;
    int length;

    if (!is_bonus)
        return write_and_count_char(segment->value.c);
    s = format_character(segment);
    if (s == NULL)
        return 0;
    length = write_and_count_str(s);
    free(s);
    return length;
}
