/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzhang <fzhang@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:43:06 by fzhang            #+#    #+#             */
/*   Updated: 2025/04/23 20:43:08 by fzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_item(char const *s, char c, size_t *i)
{
	char	*item;
	size_t	j;
	size_t	len;

	len = 0;
	j = *i;
	while (s[j] != c && (j < ft_strlen(s)))
	{
		len++;
		j++;
	}
	item = (char *)malloc((len + 1) * sizeof(char));
	if (!item)
		return (NULL);
	j = 0;
	while (j < len)
	{
		item[j] = s[*i + j];
		j++;
	}
	*i = *i + j;
	item[j] = '\0';
	return (item);
}

static void	remove_mem(char **split, size_t j)
{
	while (j > 0)
	{
		free(split[j]);
		j--;
	}
	free(split[0]);
	free(split);
}

static char	**fillin_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = get_item(s, c, &i);
			if (!split[j])
			{
				remove_mem(split, j);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc((get_len(s, c) + 1) * sizeof(char *));
	if (!split)
	{
		free(split);
		return (NULL);
	}
	if (!fillin_split(s, c, split))
		return (NULL);
	return (split);
}
//
// int main ()
// {
// 	char ** split = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	int check = ft_strncmp(split[1], "2a,",4);
// }
