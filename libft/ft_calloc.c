/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:00 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 13:09:02 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t			count;
// 	unsigned char	*copy;

// 	copy = s;
// 	count = 0;
// 	while (count < n)
// 	{
// 		copy[count] = c;
// 		count++;
// 	}
// 	return (s);
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	(ft_memset(s, '\0', n));
// }
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*copy;

	if(nmemb * size > 0 && (nmemb * size /size != nmemb)) 
		return (NULL);
	copy = (void *)malloc(nmemb * size);
	if (!copy)
		return (NULL);
	ft_bzero(copy, nmemb * size);
	return (copy);
}
//NOTE
// To handle overflow and when is 0 should return a freeable pointer
// int main()
// {
// 	char *temp = ft_calloc(2,1);
// 	int check;
// 	check = 1;
// 	for(int i = 0; i < 2; i++)
// 	{
// 		check = (int)temp[i];
// 	}
// }
