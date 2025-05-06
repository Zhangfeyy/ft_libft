/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:08:44 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 13:08:46 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	put_int(const char *src, int i)
{
	return (src[i] - '0');
}

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r')
		return (1);
	if (c == '\t' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

static int	multi(const char *str, int i)
{
	if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	return (10 * multi(str, i + 1));
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr += multi(nptr, i) * put_int(nptr, i);
		i++;
	}
	return (nbr * sign);
}
// int main()
// {
// 	char escape[] = {9, 10, 11, 12, 13, 0, 48};
// 	int check1 = ft_atoi(escape);
// 	check1 = -check1;
// }
