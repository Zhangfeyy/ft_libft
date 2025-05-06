/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:38:22 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 10:38:24 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	(ft_memset(s, '\0', n));
}
// int main()
// {
// 	char temp[50];
// 	ft_bzero(temp, 50);
// 	int check;
// 	for(int count = 0; count < 50; count++)
// 	{
// 		check = (int)temp[count];
// 	}
// }
