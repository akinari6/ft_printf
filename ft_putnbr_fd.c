/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aktsuji <aktsuji@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:44:10 by aktsuji           #+#    #+#             */
/*   Updated: 2025/10/30 21:41:14 by aktsuji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BUF_SIZE 20

void	ft_putnbr_fd(int n, int fd)
{
	char		buffer[BUF_SIZE];
	int			i;
	long long	nl;

	nl = n;
	if (nl == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	i = BUF_SIZE;
	while (nl > 0)
	{
		buffer[--i] = '0' + (nl % 10);
		nl /= 10;
	}
	write(fd, buffer + i, BUF_SIZE - i);
}
