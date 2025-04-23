/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:13:32 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/10 13:25:36 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	buff_size;

	buff_size = (ft_strlen(s) + 1);
	new = malloc(buff_size);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, buff_size);
	return (new);
}
