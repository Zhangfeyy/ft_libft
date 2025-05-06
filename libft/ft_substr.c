/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:20:43 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 19:20:46 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	check_len(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	count;

	length = len + 1;
	count = 0;
	if (start >= ft_strlen(s))
		length = 1;
	else
	{
		while (s[start + count])
			count++;
	}
	if (count < len)
		length = count + 1;
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	size_t			length;

	length = check_len(s, start, len);
	sub = (char *)malloc(length * sizeof(char));
	if (!sub)
		return (NULL);
	ft_bzero(sub, length);
	if (start > ft_strlen(s) || !s[start])
		return (sub);
	i = 0;
	while (i < length - 1)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
// int main()
// {
// 	char *test = ft_substr("hello", 4294967295, 0);
//	int check = (test == NULL);
// }
