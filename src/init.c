/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:40 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/23 17:55:11 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	init_textures(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119)
		move_up(game);
	else if (keycode == 115)
		move_down(game);
	else if (keycode == 97)
		move_left(game);
	else if (keycode == 100)
		move_right(game);
	return (0);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectable, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_tiles(t_game *game)
{
	char	tile;
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	ft_printf("Steps: %d\n", game->steps);
	game->steps++;
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
		return (close_window(game));
	render_tiles(game);
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
	free(game->mlx);
	return (0);
}
