/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzheng <rzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:46:14 by rzheng            #+#    #+#             */
/*   Updated: 2024/12/02 18:27:21 by rzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_word(const char *str, size_t start, size_t end);
static void	ft_free(char **strs, int count);
static void	process_split(char const *s, char c, char **res);
static int	ft_word_count(const char *str, char c);

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	process_split(s, c, res);
	return (res);
}

static void	process_split(char const *s, char c, char **res)
{
	size_t	i;
	size_t	start;
	size_t	len;
	int		j;

	i = 0;
	start = (size_t)-1;
	len = ft_strlen(s);
	j = 0;
	while (i <= len)
	{
		if (s[i] != c && start == (size_t) - 1)
			start = i;
		else if ((s[i] == c || i == len) && start != (size_t) - 1)
		{
			res[j++] = fill_word(s, start, i);
			if (!res[j - 1])
				return (ft_free(res, j - 1), (void)0);
			start = (size_t) - 1;
		}
		i++;
	}
}

static char	*fill_word(const char *str, size_t start, size_t end)
{
	char	*word;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, &str[start], end - start);
	word[end - start] = '\0';
	return (word);
}

static void	ft_free(char **strs, int count)
{
	while (count >= 0)
		free(strs[count--]);
	free(strs);
}

int	ft_word_count(const char *str, char c)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}
