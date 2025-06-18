/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:40 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/18 19:44:32 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	init_textures(t_game *game)
{
	int w, h;
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &w,
			&h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
			&w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w,
			&h);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectable)
		return (1);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	render_map(t_game *game)
{
	char	tile;

	int x, y;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			if (tile == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectable, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	if (init_textures(game) != 0)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (free_game(game));
	}
	render_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	free(game->mlx);
	return (0);
}
