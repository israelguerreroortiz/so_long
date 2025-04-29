/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/29 18:51:49 by isrguerr         ###   ########.fr       */
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
    while (game->map[i])
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

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        ft_printf("Error: Only valid arguments are ./so_long and a .ber file\n");
        return (1);
    }

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        ft_printf("Error: Memory allocation failed\n");
        return (1);
    }

    if (read_map(argv[1], game) > 0 || !check_map(game))
        free_game(game);

    // init_game(); // Uncomment and implement this function if needed
    return (0);
}
