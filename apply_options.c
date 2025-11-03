/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:23:57 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 13:23:50 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_width(char *s, t_options opts)
{
    char *new;
    int s_len;
    int i;

    s_len = ft_strlen(s);
    if (s_len >= opts.width)
        return s;
    new = malloc(opts.width + 1);
    if (opts.flag_minus)
    {
        ft_strlcpy(new, s, opts.width + 1);
        ft_memset(new + s_len, ' ', opts.width - s_len);
    }
    else if (opts.flag_zero)
    {
        ft_memset(new, '0', opts.width - s_len);
        new[opts.width - s_len] = '\0';
        ft_strlcat(new, s, opts.width);
    }
    new[opts.width] = '\0';
    free(s);
    return new;
}