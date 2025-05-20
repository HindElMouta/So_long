/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:28:53 by hinel-mo          #+#    #+#             */
/*   Updated: 2024/11/21 14:28:09 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_space(char **split, size_t j)
{
	while (j--)
	{
		if (split[j])
		{
			free(split[j]);
			split[j] = NULL;
		}
	}
	free(split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	**set_mem(char **split, char const *s, char c, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
			{
				free_space(split, j);
				return (NULL);
			}
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!set_mem(tab, s, c, 0))
		return (NULL);
	return (tab);
}
