/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:36:36 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/04 11:13:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pcurrent;

	pcurrent = lst;
	if (!pcurrent)
		return (pcurrent);
	while (pcurrent->next)
	{
		pcurrent = pcurrent->next;
	}
	return (pcurrent);
}
// int main()
// {
// 	t_list *temp = NULL;
// 	int check = (ft_lstlast(temp) == NULL);
// }
