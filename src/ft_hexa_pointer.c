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
#include "../include/ft_printf.h"

static char select_base(unsigned int num, int mark)
{
	if(num > 9 && mark == 1)
		return('a' + (num - 10));
	else if(num > 9 && mark == 2)
		return('A' + (num - 10));
	return('0' + num);
}

static void	convert_base(unsigned int receiver, char *temp, unsigned int *i, int mark)
{
	if(receiver/16 == 0)
	{
		temp[*i] = select_base(receiver % 16, mark);
		(*i)++;
	}
	else
	{
		convert_base(receiver / 16, temp, i, mark);
		temp[*i] = select_base(receiver % 16, mark);
		(*i)++;
	}
}
static uintptr_t len_hex(unsigned int receiver)
{
	uintptr_t size;
	unsigned int temp;

	temp = receiver;
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
	unsigned int receiver;
	unsigned int il;

	receiver = va_arg(args, unsigned int);
	temp = (char *)ft_calloc(len_hex(receiver) + 1, 1);
	if(!temp)
		return (NULL);
	il = 0;
	convert_base(receiver, temp, &il, 1);
	return (temp);
}

//only digital parts
char *ft_hexu(va_list args)
{
	char *temp;
	unsigned int receiver;
	unsigned int iu;

	receiver = va_arg(args,unsigned int);
	temp = (char *)ft_calloc(len_hex(receiver) + 1, 1);
	if(!temp)
		return (NULL);
	iu = 0;
	convert_base(receiver, temp, &iu, 2);
	return (temp);
}

char *ft_void(va_list args)
{
	uintptr_t add;
	char *temp;
	unsigned int i;

	add = (uintptr_t)va_arg(args, void *);
	temp = (char *)ft_calloc(len_hex(add) + 3, 1);
	if(!temp)
		return (NULL);
	temp[0] = '0';
	temp[1] = 'x';
	i = 2;
	convert_base(add, temp, &i, 1);
	return (temp);
	
}
//NOTE
//All the pointers need memory allocations
//for counters constant variables are enough, also save one step for freeing at the end pf the function