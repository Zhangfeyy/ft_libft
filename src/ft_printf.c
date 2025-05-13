/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:36:51 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/13 21:25:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

static char	*specify(const char *string, va_list args)
{
	char *temp;

	if(*string == 'c')
		return (ft_character(args));
	else if(*string == 's')
		return (ft_string(args));
	else if(*string == 'p')
		return (ft_void(args));
	else if(*string == 'd' || *string =='i')
		return (ft_decimal(args));
	else if(*string == 'u')
		return (ft_unsigned(args));
	else if(*string == 'x')
		return (ft_hexl(args));
	else if(*string == 'X')
		return (ft_hexu(args));
	else if(*string == '\0')
		return (NULL);
	else
	{
		temp = (char *)ft_calloc(3, 1);
		// if(!temp)
		// 	return (NULL);
		temp[0] = '%';
		temp[1] = *string;
		return (temp);
	}
}

// check the derected specifer, and keep the other ones
static char	*check(const char **string, va_list args)
{
	char *temp;

	if(**string == '%')
	{
		(*string)++;
		temp = specify(*string, args);
	}
	//if is true, else if will still be checked
	else
	{
		temp = (char *)ft_calloc(2, 1);
		if(!temp)
			return(NULL);
		temp[0] = **string;
		return (temp);
	}
	return(temp);
}

int	ft_printf(const char *string, ...)
{
	va_list args;
	va_start(args, string);
	char *temp;
	int	count;

	count = 0;
	while(*string)
	{
		temp = check(&string, args);
		if(temp)
		{
			if(temp[0] == '\0')
			{
				write(1, "\0", 1);
                		count += 1;
			}
			else
			{
				write(1, temp, ft_strlen((const char *)temp));
				count += ft_strlen((const char *)temp);
			}
			free(temp);
		}
		string++;
	}
	va_end(args);
	return(count);
}
//Mistake Note
// I directly used string++ in check*(), however, i only passed the string by value, i cannot /
// change the value of the string itself. So i can only operate the subvalue of a variable/
// in functions.
// In C, ownership here means who can modify the value of the pointer 
// and how it is passed around. It does not refer to the "main function" 
// but rather to where the variable is declared and how it's passed between functions.
// So printf actually operates the string
