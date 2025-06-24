/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:21:48 by iisraa11          #+#    #+#             */
/*   Updated: 2025/06/24 14:07:21 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	map_height(const char *filename)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	check_width(t_game *game)
{
	int		i;
	size_t	width;

	i = 0;
	width = ft_strlen(game->map[i]);
	while (game->map[++i])
	{
		if (width != ft_strlen(game->map[i]))
			return (1);
	}
	game->width = width;
	return (0);
}

int	add_items(t_game *game, int line, int i)
{
	if (game->map[line][i] == 'E')
		game->exits++;
	else if (game->map[line][i] == 'C')
		game->collect++;
	else if (game->map[line][i] == 'P')
		game->player++;
	else if (game->map[line][i] == '1')
		game->walls++;
	else if (game->map[line][i] == '0')
		game->spaces++;
	else
		return (1);
	i++;
	return (0);
}

int	check_items(t_game *game)
{
	if (game->exits != 1)
		return (1);
	else if (game->player != 1)
		return (1);
	else if (game->collect < 1)
		return (1);
	else
		return (0);
}
