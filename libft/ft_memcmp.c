/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:08:11 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 13:08:13 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			count;

	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (copy1[count] != copy2[count])
			return (copy1[count] - copy2[count]);
		count++;
	}
	return (0);
}
// int main()
// {
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	/* 1 */ int check1 = !ft_memcmp(s, sCpy, 4);
// 	/* 5 */ int check2 = ft_memcmp(s2, s3, 4);
// }
