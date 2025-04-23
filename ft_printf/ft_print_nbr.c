/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:16:21 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/17 16:19:55 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_nbr(int n)
{
	char	c;
	size_t	count;

	count = 0;
	if (n == INT_MIN)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_nbr(n / 10);
	c = n % 10 + '0';
	count += ft_print_char(c);
	return (count);
}
