/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/18 00:17:51 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int free_game(t_game *game)
{
    int i;

    if (!game || !game->map)
        return (1);
    i = 0;
    while (game->map[i] != NULL)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL;
    game->spaces = 0;
    game->collectables = 0;
    game->walls = 0;
    game->exits = 0;
    game->height = 0;
    game->line_len = 0;
    ft_printf("%s", "Mapa no válido");
    exit(1);
}

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
    int i;
    int j;
    char **map_copy;
    int found;

    found = 0;
    map_copy = malloc(sizeof(char *) * (game->height + 1));
    if (!map_copy)
        return (1);
    i = 0;

    while (i < game->height)
    {
        map_copy[i] = ft_strdup(game->map[i]);
        if (!map_copy[i])
        {
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (free_game(game));
        }
        i++;
    }
    map_copy[game->height] = NULL;
    i = 0;
    while (i < game->height && !found)
    {
        j = 0;
        while (j < game->line_len && !found)
        {
            if (map_copy[i][j] == 'P')
            {
                found = flood_fill(map_copy, i, j, game->height, game->line_len);
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < game->height)
        free(map_copy[i++]);
    free(map_copy);
    return (found);
}

int main(int argc, char **argv)
{
    t_game *game;

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (1);
    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        perror("Error: Only valid arguments are ./so_long and a .ber file\n");
        return (1);
    }
    if (check_map(argv[1], game) != 0)
        return (free_game(game));

    ft_printf("%s", "El mapa es válido");
    return (0);
}
