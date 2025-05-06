/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:36:51 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/05 21:36:52 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list args;
	va_start(args, string);
	char temp;

	while(*string)
	{
		temp = check(*string, args);
		write(1, &temp, 1);
		string++;
	}
	va_end(args);
}

// check the derected specifer, and keep the other ones
static char	*check(char *string, va_list args)
{
	char *temp;
	if(*string == '%')
	{
		string++;
		if(*string)
			return (specify(string, args));
	}
	else if(*string)
	{
		temp = (char *)ft_calloc(2, 1);
		if(!temp)
			return(NULL);
		temp[0] = *string;
		return (temp);
	}
	return ('\0');
}

static char	*specify(char *string, va_list args)
{
	char *temp;

	if(*string == 'c')
		return (ft_character(args));
	if(*string == 's')
		return (ft_string(args));
	if(*string == 'p')
		return (ft_void(args));
	if(*string == 'd' || *string =='i')
		return (ft_decimal(args));
	if(*string == 'u')
		return (ft_unsigned(args));
	if(*string == 'x')
		return (ft_hexl(args));
	if(*string == 'X')
		return (ft_hexu(args));
	temp = (char *)ft_calloc(3, 1);
	if(!temp)
		return (NULL);
	temp[0] = '%';
	temp[1] = *string;
	return (temp);
}
