/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmagrevesse <emmagrevesse@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:39:59 by emmagrevess       #+#    #+#             */
/*   Updated: 2023/02/06 13:17:25 by emmagrevess      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nb(char const *s, char c)
{
	int	i;
	int	check;
	int	count;

	i = 0;
	check = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			count ++;
		}
		else if (s[i] == c && check == 1)
			check = 0;
		i++;
	}
	return (count);
}

char	*ft_puttab(int start, int end, char const *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(*res) * (end - start + 2));
	if (!res)
		return (0);
	if (s[end + 1] == '\0' && s[end] != c)
		end = end + 1;
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_free_return(char **tab, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
		free(tab[index++]);
	free(tab);
}

void	ft_malloc(char const *s, char c, char **tab, int j)
{
	int	start;
	int	check;
	int	i;

	i = -1;
	check = 0;
	start = 0;
	while (s[++i])
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			start = i;
			if (!s[i + 1])
				i--;
		}
		else if ((s[i] == c || !s[i + 1]) && check == 1)
		{
			check = 0;
			tab[j] = ft_puttab(start, i, s, c);
			if (!tab[j++])
				return (ft_free_return(tab, j - 1));
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_nb(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_malloc(s, c, tab, j);
	tab[ft_nb(s, c)] = NULL;
	return (tab);
}
