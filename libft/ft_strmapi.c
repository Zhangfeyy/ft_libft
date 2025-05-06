/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:31:08 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/28 16:31:10 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*ns;

	ns = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	n = 0;
	while (s[n])
	{
		ns[n] = f(n, s[n]);
		n++;
	}
	if (n == 0)
		ns[n] = f(n, s[n]);
	else
		ns[n] = '\0';
	return (ns);
}
