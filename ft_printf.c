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
#include <stdarg.h>
#include <stdlib.h>

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
		temp = (char *)ft_calloc(2);
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
	temp = (char *)ft_calloc(3);
	if(!temp)
		return (NULL);
	temp[0] = '%';
	temp[1] = *string;
	return (temp);
}

char *ft_character(va_list args)
{
	char *temp;

	temp = (char *)ft_calloc(2);
	temp[0] = va_arg(args, char);
	return (temp);
}

char *ft_string(va_list args)
{
	char *temp;
	temp = va_arg(args, char *);//will the value change with the args?
	return (temp);
}

char *ft_void(va_list args)
{
	char *temp;
	//type conversion
}

//16:00

char *ft_decimal(va_list args)
{
	char *temp;
	

}

char *ft_unsigned(va_list args)
{
	char *temp;
	//type conversion
}

//17:00

char *ft_hexl(va_list args)
{
	char *temp;
	//type conversion
}

char *ft_hexu(va_list args)
{
	char *temp;
	//type conversion
}