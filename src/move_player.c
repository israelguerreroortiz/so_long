/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:03:11 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/19 19:18:12 by isrguerr         ###   ########.fr       */
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
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;
	char	tile = game->map[new_y][new_x];

	if (tile == '1') // pared
		return;

	// recoge objeto
	if (tile == 'C')
	{
		game->collectables--;
		game->map[new_y][new_x] = '0'; // elimina el colectable del mapa
		if (game->collectables == 0)
			game->exit_active = 1; // activa la salida
	}

	// intento salir
	if (tile == 'E')
	{
		if (game->exit_active)
			close_window(game); // salgo si la salida está activa
		else
			return; // salida aún desactivada
	}

	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	render_map(game);
}

