/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:49:53 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/05 21:49:59 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char *ft_character(va_list args)
{
	char *temp;

	temp = (char *)ft_calloc(2);
	if(!temp)
		return (NULL);
	temp[0] = va_arg(args, char);
	return (temp);
}

char *ft_string(va_list args)
{
	char *temp;
	temp = va_arg(args, char *);//will the value change with the args?
	return (temp);
}
