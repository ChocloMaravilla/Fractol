/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:13:42 by rmedina-          #+#    #+#             */
/*   Updated: 2023/10/22 14:54:33 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word_start(char const *s, char c, int i)
{
	return (s[i] != c && (i == 0 || s[i - 1] == c));
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_word_start(s, c, i))
			count++;
		i++;
	}
	return (count);
}

static void	free_words(char **words, int words_i)
{
	int	i;

	i = 0;
	while (i < words_i)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	copy_words(char const *s, char c, char **words, int word_count)
{
	int	i;
	int	words_i;
	int	word_start;

	i = 0;
	words_i = 0;
	while (words_i < word_count)
	{
		while (s[i] == c)
			i++;
		word_start = i;
		while (s[i] && s[i] != c)
			i++;
		words[words_i] = ft_substr(s, word_start, i - word_start);
		if (!words[words_i])
		{
			free_words(words, words_i);
			return (0);
		}
		words_i++;
	}
	words[words_i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;

	word_count = count_words(s, c);
	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (0);
	if (!copy_words(s, c, words, word_count))
		return (0);
	return (words);
}
