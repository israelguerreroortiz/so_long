/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:11:54 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/05 22:40:33 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)(big));
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j]) && (big[i + j] != '\0') && (i
				+ j < len))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
