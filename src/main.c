/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/25 12:23:44 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"



static void free_game(t_game *game)
{
    int i;

    if (!game || !game->map)
        return;
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
}

int main (int argc, char **argv)
{
    t_game  *game;
    
    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        ft_printf("%s", "Only valid arguments are ./so_long and .ber");
        return (1);
    }
    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (1);
    read_map(argv[1], game);
    return 0;
    if (!check_map(game))
    {   
        ft_printf("%s", "Mapa no válido");
        free_game(game);
        return(1);
    }
    ft_printf("%s", "Mapa válido");
    //init();
    return (0);
}
