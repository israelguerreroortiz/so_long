/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/22 18:20:28 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx/mlx.h"

#define WIDTH 1000
#define HEIGHT 800

int main (void)
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
}
