/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/23 18:45:41 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

int main (int argc, char **argv)
{
    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        ft_printf("%s", "Only valid arguments are ./so_long and .ber");
        return (-1);
    }
    
    return (0);
}
