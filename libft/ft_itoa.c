/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:40:17 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 21:40:20 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static char	*str_limit(void)
{
	char	*ns;
	char	*limit;
	int		n;

	limit = "-2147483648";
	ns = (char *)malloc(12);
	if (!ns)
		return (NULL);
	n = 0;
	while (limit[n])
	{
		ns[n] = limit[n];
		n++;
	}
	ns[n] = '\0';
	return (ns);
}

static int	get_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	convert(int n, char *str, int *i)
{
	if (n / 10 != 0)
	{
		convert(n / 10, str, i);
		str[*i] = n % 10 + '0';
		(*i)++;
	}
	else
	{
		str[*i] = n % 10 + '0';
		(*i)++;
	}
}

char	*ft_itoa_int(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
	{
		return (str_limit());
	}
	str = (char *)malloc((get_len(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	convert(n, str, &i);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	unsigned int		i;

	str = (char *)malloc((get_len(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	convert(n, str, &i);
	str[i] = '\0';
	return (str);
}