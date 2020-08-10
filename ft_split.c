/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:18:55 by lpassera          #+#    #+#             */
/*   Updated: 2020/08/10 13:18:56 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char sep)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	if (!str || !sep)
		return (0);
	while (str[index])
	{
		while (str[index] == sep)
			index++;
		if (str[index] != sep && str[index])
			count++;
		while (str[index] != sep && str[index])
			index++;
	}
	return (count);
}

static size_t	ft_word_len(char const *str, char sep)
{
	size_t length;

	length = 0;
	while (str[length] != sep && str[length])
		length++;
	return (length);
}

static void		ft_free_matrix(char **matrix, size_t size)
{
	size_t index;

	index = 0;
	while (index < size)
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

char			**ft_split(char const *s, char c)
{
	size_t	wordcount;
	size_t	index;
	size_t	arr_i;
	char	**arr;

	wordcount = 0;
	index = 0;
	arr_i = -1;
	wordcount = ft_count_words(s, c);
	if (!s || !c || !(arr = malloc((wordcount + 1) * sizeof(char *))))
		return (NULL);
	while (++arr_i < wordcount)
	{
		while (s[index] == c)
			index++;
		if (!(arr[arr_i] = ft_substr(s, index, ft_word_len(&s[index], c))))
		{
			ft_free_matrix(arr, arr_i + 1);
			break ;
		}
		index += ft_word_len(&s[index], c);
	}
	arr[arr_i] = NULL;
	return (arr);
}
