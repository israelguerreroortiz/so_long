/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:19:27 by iisraa11          #+#    #+#             */
/*   Updated: 2025/06/18 11:20:04 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int flood_fill(char **map, int x, int y, int height, int width)
{
    static int valid_exit = 0;
    static int valid_collectionable = 0;

    if (x < 0 || y < 0 || x >= height || y >= width)
        return (0);
    if (map[x][y] == '1' || map[x][y] == 'V')
        return (0);
    if (map[x][y] == 'E')
        valid_exit++;
    if (map[x][y] == 'C')
        valid_collectionable++;
    if (valid_exit == 1 && valid_collectionable == 1)
        return (1);
    map[x][y] = 'V';
    if (flood_fill(map, x + 1, y, height, width))
        return (1);
    if (flood_fill(map, x - 1, y, height, width))
        return (1);
    if (flood_fill(map, x, y + 1, height, width))
        return (1);
    if (flood_fill(map, x, y - 1, height, width))
        return (1);
    return (0);
}

int valid_map(t_game *game)
{
    char **map_copy;
    int found;

    map_copy = allocate_and_copy_map(game);
    if (map_copy == NULL)
    {
        perror("Error: Memory allocation failed for map copy\n");
        return (free_game(game));
    }

    found = find_player_and_flood_fill(map_copy, game);
    if (found == 0)
    {
        perror("Error: Map is not valid\n");
        return (free_game(game));
    }
    return (0);
}

// Helper function to allocate and copy the map
char **allocate_and_copy_map(t_game *game)
{
    char **map_copy;
    int i;

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

int find_player_and_flood_fill(char **map_copy, t_game *game)
{
    int i;
    int j;
    int found;

    found = 0;
    i = 0;
    while (i < game->height && !found)
    {
        j = 0;
        while (j < game->line_len && !found)
        {
            found = flood_fill(map_copy, i, j, game->height, game->line_len);
            j++;
        }
        i++;
    }
    free_2d_array(map_copy);
    return (found);
}
