/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:52:31 by atoupart          #+#    #+#             */
/*   Updated: 2016/01/12 20:23:50 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_calcul_string(char **tab, char const *s, char c)
{
	int			i;
	int			k;
	size_t		size;

	i = 0;
	k = 0;
	size = 0;
	while (s[i])
	{
		while ((s[i] != c) && s[i])
		{
			size++;
			i++;
			if ((s[i] == c) || !s[i])
			{
				tab[k] = ft_strsub(s, (size_t)i - size, size);
				k++;
				size = 0;
			}
		}
		if (s[i])
			i++;
	}
	tab[k] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		col;

	i = 0;
	col = 0;
	if (!s)
		return (NULL);
	if (s[0] != c && s[0])
		col++;
	while (s[i])
	{
		if (s[i] == c)
		{
			if ((s[i + 1] != c) && s[i + 1])
				col++;
		}
		i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (col + 1))))
		return (NULL);
	return (ft_calcul_string(tab, s, c));
}
