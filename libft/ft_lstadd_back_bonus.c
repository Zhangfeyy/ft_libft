/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:39:48 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/30 20:39:50 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	while (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
// 
// int main()
// {
// 	t_list *temp;
// 	int a = 1;
// 	int b = 2;
// 	temp = ft_lstnew((void *)&a);
//	//make a pointer with the value 1(though may not be a valid addtress)
// 	ft_lstadd_back(&temp, ft_lstnew((void*)&b));
// 	temp = temp->next;
// 	int check = *((int *)(temp->content));
// 	check = -check;
// }
