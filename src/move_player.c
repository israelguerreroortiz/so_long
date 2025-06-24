/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:03:11 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/24 14:08:18 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

void	move_up(t_game *game)
{
	move_player(game, 0, -1);
}

void	move_down(t_game *game)
{
	move_player(game, 0, 1);
}

void	move_left(t_game *game)
{
	move_player(game, -1, 0);
}

void	move_right(t_game *game)
{
	move_player(game, 1, 0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		if (--game->collect == 0)
			game->exit_active = 1;
	}
	if (tile == 'E')
	{
		if (game->exit_active)
			close_window(game);
		else
			return ;
	}
	game->player_x = new_x;
	game->player_y = new_y;
	render_tiles(game);
}
