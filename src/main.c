/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/08 20:07:34 by iisraa11         ###   ########.fr       */
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
    ft_printf("%s", "El mapa es válido");
    return (0);
}
