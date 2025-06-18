/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:19:27 by iisraa11          #+#    #+#             */
/*   Updated: 2025/06/18 20:23:46 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	flood_fill(char **map, int x, int y, t_game *game)
{
	static int	valid_exit = 0;
	static int	valid_collectionable = 0;

	if (x < 0 || y < 0 || x >= game->height || y >= game->width)
		return (0);
	printf("Checking position (%d, %d)\n", x, y);
	if (map[x][y] == '1' || map[x][y] == 'V')
		return (0);
	if (map[x][y] == 'E')
		valid_exit++;
	if (map[x][y] == 'C')
		valid_collectionable++;
	if (valid_exit == 1 && valid_collectionable == game->collectables)
		return (1);
	map[x][y] = 'V';
	if (flood_fill(map, x + 1, y, game))
		return (1);
	if (flood_fill(map, x - 1, y, game))
		return (1);
	if (flood_fill(map, x, y + 1, game))
		return (1);
	if (flood_fill(map, x, y - 1, game))
		return (1);
	return (0);
}

int	valid_map(t_game *game)
{
	char	**map_copy;
	int		found;
	
	map_copy = allocate_and_copy_map(game);
	if (map_copy == NULL)
	{
		perror("Error: Memory allocation failed for map copy\n");
		return (free_game(game));
	}
	found = find_player_and_flood_fill(map_copy, game);
	if (found == 0)
	{
		ft_printf("Error: Map is not valid\n");
		return (free_game(game));
	}
	return (0);
}

// Helper function to allocate and copy the map
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
			return (NULL);
		}
		i++;
	}
	map_copy[game->height] = NULL;
	return (map_copy);
}

int	find_player_and_flood_fill(char **map_copy, t_game *game)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (i < game->height && !found)
	{
		j = 0;
		while (j < game->width && !found)
		{
            if (map_copy[i][j] == 'P')
			    found = flood_fill(map_copy, i, j, game);
			j++;
		}
		i++;
	}
	free_2d_array(map_copy);
	return (found);
}
