/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:07:59 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/17 21:22:32 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_ptr(void *ptr)
{
	size_t	count;

	count = 0;
	if (!ptr)
		count += ft_print_str("(nil)");
	else
	{
		count += ft_print_str("0x");
		count += ft_print_hex((unsigned long)ptr, 0);
	}
	return (count);
}
