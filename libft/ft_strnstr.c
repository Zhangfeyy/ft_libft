/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:08:30 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 13:08:31 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	inner_count;
	size_t	outer_count;

	if (!*little)
		return ((char *)big);
	outer_count = 0;
	while (big[outer_count] && outer_count < len)
	{
		if (big[outer_count] == little[0])
		{
			inner_count = 0;
			while (little[inner_count] == big[outer_count + inner_count]
				&& (outer_count + inner_count < len) && little[inner_count])
				inner_count++;
			if (!little[inner_count])
				return ((char *)&big[outer_count]);
		}
		outer_count++;
	}
	return (NULL);
}
