/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:51:01 by fzhang            #+#    #+#             */
/*   Updated: 2025/05/05 12:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check(t_list *lst, t_list **temp_new,
	void *(*f)(void *), void (*del)(void *))
{
	void	*content;

	if (!lst)
		return (1);
	content = f(lst->content);
	*temp_new = ft_lstnew(content);
	if (!(*temp_new))
	{
		del(content);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_old;
	t_list	*temp_new;
	t_list	*new;
	void	*content;

	temp_new = NULL;
	if (check(lst, &temp_new, f, del))
		return (NULL);
	temp_old = lst;
	new = temp_new;
	while (temp_old->next)
	{
		temp_old = temp_old->next;
		content = f(temp_old->content);
		temp_new->next = ft_lstnew(content);
		if (!temp_new->next)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp_new = temp_new->next;
	}
	return (new);
}
// int main()
// {
// 	int total = 0;
// 	int tab[] = {0, 1, 2, 3};
// 	t_list * l =  ft_lstnew(tab);
// 	for (int i = 1; i < 4; ++i)
// 		ft_lstadd_back(&l, ft_lstnew(tab + i));
// 	t_list * m = ft_lstmap(l, addOne, free);
// 	total = 0;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		total += *(int *)l->content;
// 		l = (t_list *)l->next;
// 	}
// 	total = 0;
// 	while(m)
// 	{
// 		total += *(int *)m->content;
// 		m = (t_list *)m->next;
// 	}
// }
