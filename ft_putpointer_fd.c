/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:25:50 by aktsuji           #+#    #+#             */
/*   Updated: 2025/11/02 15:48:24 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define PTR_BUFFER_SIZE 64

void ft_putpointer_fd(void *ptr, int fd)
{
    const char hex_base[] = "0123456789abcdef";
    unsigned long long ptr_nbr; 
    char buffer[PTR_BUFFER_SIZE];
    int index;

    if (ptr == NULL)
    {
        
    }
    ptr_nbr = (unsigned long long)ptr;
    index = PTR_BUFFER_SIZE;
    while (ptr_nbr > )
}
