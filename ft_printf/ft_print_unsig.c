/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:28:01 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/17 16:20:10 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_unsig(unsigned int n)
{
	char	c;
	size_t	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_print_unsig(n / 10);
	}
	c = n % 10 + '0';
	count += ft_print_char(c);
	return (count);
}
