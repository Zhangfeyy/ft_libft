/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:19:12 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/06 17:19:14 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static char *convert_base(int receiver, char *temp, int *i)
{
	if(receiver/16 == 0)
	{
		temp[*i] = select_base(receiver % 16);
		*i++;
	}
	else
	{
		convert_base(receiver / 16, temp, i);
		temp[*i] = select_base(receiver % 16);
		*i++;
	}
}

static char select_base(int num)
{
	if(num > 9)
		return('a' + (num- 10));
	return('0' + num);
}

static int len_hex(int receiver)
{
	int size;
	int temp = receiver;
	size = 1;
	while(temp/16 != 0)
	{
		size++;
		temp = temp / 16;
	}
	return (size);
}

char *ft_hexl(va_list args)
{
	char *temp;
	int receiver;
	int *i;

	receiver = va_arg(args, int);
	temp = (char *)ft_calloc(len_hex(receiver) + 3, 1);
	if(!temp)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'x';
	*i = 2;
	convert_base(receiver, temp, i);
	return (temp);
}

//only digital parts
char *ft_hexu(va_list args)
{
	char *temp;
	int receiver;
	int *i;
	
	receiver = va_arg(args, int);
	temp = (char *)ft_calloc(len_hex(receiver) + 3, 1);
	if(!temp)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'X';
	*i = 2;
	convert_base(receiver, temp, i);
	return (temp);
}