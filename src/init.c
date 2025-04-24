/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:40 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/24 18:58:47 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

int init (void)
{

    void *mlx_ptr;
    void *mlx_window;
    mlx_ptr = mlx_init();

    if (!mlx_ptr)
        return (1);

    mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Window 1");

    if (!mlx_window)
    {
        mlx_destroy_display(mlx_ptr);
        free(mlx_ptr);
        return (1);
    }
    mlx_loop(mlx_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
    return (0);
}