/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:45:28 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/28 15:45:31 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	output(int n, int fd)
{
	char	c;

	c = '0' + n;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / 10 == 0)
		output(n % 10, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		output(n % 10, fd);
	}
}
// int main ()
// {
// 	int fd = open("test", O_RDWR | O_CREAT);
// 	ft_putnbr_fd(-345678, fd);
// }
