/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:53:41 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/05 22:41:27 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dst == NULL)
		return (srclen);
	if (dstlen >= size)
		return (size + srclen);
	else
	{
		size = size - dstlen;
		ft_strlcpy(dst + dstlen, src, size);
	}
	return (dstlen + srclen);
}
