/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:04:48 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/17 16:28:43 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex(unsigned long int n, int type)
{
	size_t	count;
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, type);
	{
		if (type == 1)
			count += ft_print_char(upper[n % 16]);
		else
			count += ft_print_char(lower[n % 16]);
	}
	return (count);
}
