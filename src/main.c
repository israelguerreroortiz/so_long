/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:46:36 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/18 20:27:30 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int free_game(t_game *game)
{
    int i;

    if (!game || !game->map)
        exit(1);
    i = 0;
    while (game->map[i] != NULL)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    exit(1);
}

void free_2d_array(char **array)
{
    int i;
    if (!array)
        return;
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int main(int argc, char **argv)
{
    t_game *game;

    game = ft_calloc(1, sizeof(t_game));
    if (!game)
        return (1);
    if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4))
    {
        ft_printf("Error: Only valid arguments are ./so_long and a .ber file\n");
        return (1);
    }
    if (check_map(argv[1], game) != 0)
        return (free_game(game));
    init(game);
    return (0);
}
