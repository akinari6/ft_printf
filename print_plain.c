/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:31:17 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/03 11:33:09 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_text(char *str)
{
    return write_and_count_str(str);
}

int print_percent()
{
    return write_and_count_char('%');
}
