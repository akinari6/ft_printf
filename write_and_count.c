/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_and_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:26:40 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 11:27:58 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_and_count_str(char* str)
{
    int length;

    length = ft_strlen(str);
    ft_putstr_fd(str, STDOUT_FILENO);
    return length;
}

int write_and_count_char(char c)
{
    ft_putchar_fd(c, STDOUT_FILENO);
    return 1;
}
