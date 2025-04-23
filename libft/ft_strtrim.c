/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:26:29 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/07 12:30:09 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	sub_size;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	sub_size = j - i + 1;
	substr = malloc(sub_size);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s1 + i, sub_size);
	return (substr);
}
