/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/17 20:12:27 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

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
    exit (1);
}

int flood_fill(char **map, int x, int y, int height, int width)
{
    if (x < 0 || y < 0 || x >= height || y >= width)
        return (0);
    if (map[x][y] == '1' || map[x][y] == 'V')
        return (0);
    if (map[x][y] == 'E')
        return (1);
    map[x][y] = 'V'; // Mark as visited
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

int valid_map(t_game **game)
{
    int i, j;
    char **map_copy;
    int found = 0;

    // Allocate and copy the map
    printf("Hola");
    printf("%d", (*game)->height);
    map_copy = malloc(sizeof(char *) * ((*game)->height + 1));
    if (!map_copy)
        return (1);
    for (i = 0; i < (*game)->height; i++)
    {
        map_copy[i] = ft_strdup((*game)->map[i]);
        if (!map_copy[i])
        {
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (1);
        }
    }
    map_copy[(*game)->height] = NULL;

    // Find player position and start flood fill
    for (i = 0; i < (*game)->height && !found; i++)
    {
        for (j = 0; j < (*game)->line_len && !found; j++)
        {
            if (map_copy[i][j] == 'P')
            {
                found = flood_fill(map_copy, i, j, (*game)->height, (*game)->line_len);
            }
        }
    }

    // Free map copy
    for (i = 0; i < (*game)->height; i++)
        free(map_copy[i]);
    free(map_copy);

    return (found ? 0 : 1);
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        perror("Error: Only valid arguments are ./so_long and a .ber file\n");
        return (1);
    }

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        perror("Error: Memory allocation failed\n");
        return (1);
    }

    if (read_map(argv[1], game) != 0)
    {
        free_game(game);
        ft_printf("%s", "El mapa no es válido");
        return (1);   
    }
    else if (check_map(game) != 0)
    {
        free_game(game);
        ft_printf("%s", "El mapa no es válido");
        return (1);   
    }
    else if(valid_map(&game) != 0)
    {
        free_game(game);
        ft_printf("%s", "El mapa no es válido");
        return (1);   
    }
    ft_printf("%s", "El mapa es válido");
    return (0);
}
