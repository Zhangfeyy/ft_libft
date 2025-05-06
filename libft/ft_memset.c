/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:15:58 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 10:16:06 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*copy;

	copy = s;
	count = 0;
	while (count < n)
	{
		copy[count] = c;
		count++;
	}
	return (s);
}
// int main()
// {
// 	char temp[10];
// 	int check;
// 	int count;
// 	ft_memset(temp, 1, 10);
// 	check = 0;
// 	count = 0;
// 	while(*temp)
// 	{
// 		check = (int)(*temp);
// 		count++;
// 	}
// }
