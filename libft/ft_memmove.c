/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:09:57 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 10:10:01 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*copy_dest;
	const unsigned char	*copy_src;
	size_t				count;

	copy_dest = (unsigned char *)dest;
	copy_src = (const unsigned char *)src;
	if (copy_dest > copy_src)
	{
		count = n;
		while (count > 0)
		{
			count--;
			copy_dest[count] = copy_src[count];
		}
	}
	else if (copy_dest <= copy_src)
	{
		count = 0;
		while (count < n)
		{
			copy_dest[count] = copy_src[count];
			count++;
		}
	}
	return (dest);
}
// int main ()
// {
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
// 	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
// 	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
// 	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
// 	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
// 	int check2 = ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7);
// 	check2++;
// }
