/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:40 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/19 19:51:17 by isrguerr         ###   ########.fr       */
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

int	key_hook(int keycode, t_game *game)
{
	printf("key: %d\n", keycode);
	printf("player: %d, %d\n", game->player_x, game->player_y); // posible crash aquí

	if (keycode == 65307) // ESC
		close_window(game);
	else if (keycode == 119) // W
		move_up(game);
	else if (keycode == 115) // S
		move_down(game);
	else if (keycode == 97) // A
		move_left(game);
	else if (keycode == 100) // D
		move_right(game);
	return (0);
}


void	render_map(t_game *game)
{
	char	tile;

	int x, y;
	y = 0;
	ft_printf("game width: %d, height: %d\n", game->width, game->height);
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
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, game->player_x * TILE_SIZE,
			game->player_y * TILE_SIZE);
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
	mlx_hook(game->win, 2, 1L<<0, key_hook, game);
	mlx_loop(game->mlx);
	free(game->mlx);
	return (0);
}
