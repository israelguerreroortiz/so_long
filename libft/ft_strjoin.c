/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:08:41 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/05 21:47:12 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_size;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = malloc(str_size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	ft_strlcpy(str + i, s2, str_size);
	return (str);
}
