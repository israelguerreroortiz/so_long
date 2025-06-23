/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:03:05 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/23 18:03:34 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

static int	check_walls(char *line_map)
{
	int	i;

	i = 0;
	while (line_map[i])
	{
		if (line_map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_inner_line(t_game *game, int line)
{
	int	i;

	if (game->map[line][0] != '1' || game->map[line][game->width - 1] != '1')
		return (1);
	i = 1;
	while (i < game->width - 1)
	{
		if (add_items(game, line, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	map_elements(t_game *game, int line, int i)
{
	while (game->map[line])
	{
		i = 0;
		if (line == 0 || line == game->height - 1)
		{
			if (check_walls(game->map[line]) == 1)
				return (1);
		}
		else
		{
			if (check_inner_line(game, line) == 1)
				return (1);
		}
		line++;
	}
	return (check_items(game));
}
