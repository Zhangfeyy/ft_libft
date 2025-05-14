/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:49:53 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/13 21:28:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

char *ft_character(va_list args)
{
	char *temp;

	temp = (char *)ft_calloc(2, 1);
	if(!temp)
		return (NULL);
	temp[0] = (char)va_arg(args, unsigned int);//Use int due to default argument promotion
	return (temp);
}

char *ft_string(va_list args)
{
	char *temp;
	
	temp = va_arg(args, char *);//will the value change with the args?
	return (temp);
}
