/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:45:33 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/04 20:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		temp = (*lst)->next;
		(*lst)->next = temp->next;
		ft_lstdelone(temp, del);
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

// int main()
// {
// 	int *a = malloc(sizeof(int));
// 	*a = 2;
// 	t_list *new = ft_lstnew((void *)a);
// 	int check = *((int *)(new->content));
// 	ft_lstclear(&new, free);
// 	check = (new == NULL);
// }
