/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/23 18:25:47 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

int	check_errors(t_game *game)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	if (check_width(game) != 0)
		return (1);
	else if (map_elements(game, line, i) != 0)
		return (1);
	if (game->exits < 1 || game->collectables < 1 || game->player < 1)
		return (1);
	return (0);
}

int	copy_map(t_game *game, char *line, int fd)
{
	char	*trimmed;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		if (!trimmed)
		{
			free(line);
			return (1);
		}
		game->map[i++] = trimmed;
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	return (0);
}

int	read_map(const char *filename, t_game *game)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	game->height = map_height(filename);
	if (game->height <= 0)
	{
		ft_printf("Error: height of map is not valid\n");
		close(fd);
		return (1);
	}
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
	{
		ft_printf("Error: error in map malloc\n");
		close(fd);
		return (1);
	}
	return (copy_map(game, line, fd));
}

int	check_map(const char *filename, t_game *game)
{
	if (read_map(filename, game) != 0)
	{
		ft_printf("Error: error reading map\n");
		free_all(game);
		exit(1);
	}
	if (check_errors(game) != 0)
	{
		ft_printf("Error: map is not valid\n");
		free_all(game);
		exit(1);
	}
	if (valid_map(game) != 0)
	{
		ft_printf("Error: map is not valid\n");
		free_all(game);
		exit(1);
	}
	return (0);
}
