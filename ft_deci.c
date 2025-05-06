/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:51:32 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/05 21:51:34 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char *ft_decimal(va_list args)
{
	char *temp;

	temp = ft_itoa_int(va_arg(args, int));
	return (temp);
}

char *ft_unsigned(va_list args)
{
	char *temp;
	temp = ft_itoa_unsigned(va_arg(args, unsigned int));
	return (temp);
}
