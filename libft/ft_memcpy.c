/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:42:19 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 10:42:21 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*copy_dest;
	size_t				count;
	const unsigned char	*copy_src;

	copy_dest = dest;
	copy_src = src;
	count = 0;
	while (count < n)
	{
		copy_dest[count] = copy_src[count];
		count++;
	}
	return (dest);
}
