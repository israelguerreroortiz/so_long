/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:36:18 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/24 17:17:38 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (c == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (c == 'i' || c == 'd')
		count += ft_print_nbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_print_unsig(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), 1);
	else if (c == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(c);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += check_format(ap, format[i]);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
