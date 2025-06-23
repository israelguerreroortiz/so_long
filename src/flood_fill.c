/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:19:27 by iisraa11          #+#    #+#             */
/*   Updated: 2025/06/23 18:35:47 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	check_position(char **map_copy, int y, int x, t_game *game)
{
	int	found;

	found = flood_fill(map_copy, y, x, game);
	if (found)
	{
		game->map[y][x] = '0';
		game->player_x = x;
		game->player_y = y;
	}
	return (found);
}

int	flood_fill(char **map, int y, int x, t_game *game)
{
	if (x < 0 || y < 0 || y >= game->height || x >= game->width)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
		game->valid_exit++;
	if (map[y][x] == 'C')
		game->valid_collectable++;
	if (game->valid_exit == 1 && game->valid_collectable == game->collectables)
		return (1);
	map[y][x] = 'V';
	if (flood_fill(map, y + 1, x, game))
		return (1);
	if (flood_fill(map, y - 1, x, game))
		return (1);
	if (flood_fill(map, y, x + 1, game))
		return (1);
	if (flood_fill(map, y, x - 1, game))
		return (1);
	return (0);
}

int	valid_map(t_game *game)
{
	char	**map_copy;
	int		found;

	map_copy = allocate_and_copy_map(game);
	found = find_player_and_flood_fill(map_copy, game);
	free_2d_array(map_copy);
	if (found == 0)
	{
		ft_printf("Error: Map is not valid\n");
		return (1);
	}
	return (0);
}

char	**allocate_and_copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_2d_array(map_copy);
			free_all(game);
			ft_printf("Error: Memory allocation failed for map copy\n");
			exit(1);
		}
		i++;
	}
	map_copy[game->height] = NULL;
	return (map_copy);
}

int	find_player_and_flood_fill(char **map_copy, t_game *game)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = 0;
	while (y < game->height && !found)
	{
		x = 0;
		while (x < game->width && !found)
		{
			if (map_copy[y][x] == 'P')
				found = check_position(map_copy, y, x, game);
			x++;
		}
		y++;
	}
	return (found);
}
