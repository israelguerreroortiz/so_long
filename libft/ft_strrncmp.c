/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:09:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/23 18:34:17 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./libft.h"

int	ft_strrncmp(const char *s1, const char *s2, int n)
{
    int	i;
    int	j;
    int k;

    i = ft_strlen(s1) - 1;
    j = ft_strlen(s2) - 1;
    k = 0;
    while(k < n)
    {
        if (s1[i] != s2[j])
            return (1);
        k++;
        i--;
        j--;
    }
    return (0);
}
