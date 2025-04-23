/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:36:11 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/05 22:42:35 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static char	*save_words(char const *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	str_size;
	char	*word;

	i = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	start = i;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (start == i)
		return (NULL);
	str_size = i - start + 1;
	word = malloc(str_size);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, str + start, str_size);
	return (word);
}

static char	**free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;
	char	**array;

	count = count_words(str, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		while (str[j] != '\0' && str[j] == c)
			j++;
		array[i] = save_words(str + j, c);
		if (array[i] == NULL)
			return (free_array(array));
		while (str[j] != '\0' && str[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
