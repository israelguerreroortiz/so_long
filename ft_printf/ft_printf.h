/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:18:05 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/17 16:29:13 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_print_char(char c);
size_t	ft_print_str(char *s);
size_t	ft_print_nbr(int n);
size_t	ft_print_hex(unsigned long int n, int type);
size_t	ft_print_unsig(unsigned int n);
size_t	ft_print_ptr(void *ptr);
int		ft_printf(char const *format, ...);

#endif