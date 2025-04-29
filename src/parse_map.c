/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/29 18:58:28 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

/*
	Reglas para que el mapa sea valido:
	-Todas las lineas deben tener la misma longitud.
	Muros(1){
		-Primera linea y ultima linea solo pueden haber 1
		-2 y 3 linea primer y ultimo caracter deben ser 1
	}
	-El mapa al menos debe tener una salida (E), un coleccionable (C)
	y una posicion inicial (P). Espacios vacios representados con 0.
*/

static int	map_height(const char *filename)
{
	char	*line;
	int		height;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	count_len(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[++i])
	{
		if (len != ft_strlen(game->map[i]))
			return (1);
	}
	game->line_len = len;
	return (0);
}

static int	map_elements(t_game *game, int line, int i)
{
	while (game->map[line++])
	{
		i = 0;
		if (line == game->height || line == 0)
		{
			while (game->map[line][i++])
				if (game->map[line][i] != '1')
					return (1);
		}
		else
		{
			if (game->map[line][0] != '1' || game->map[line][game->line_len
				- 1] != '1')
				return (1);
			while (game->map[line][i++])
			{
				if (game->map[line][i] == 'E')
					game->exits++;
				else if (game->map[line][i] == 'C')
					game->collectables++;
				else if (game->map[line][i] == '0')
					game->spaces++;
				else
					return (1);
			}
		}
	}
	return (0);
}

int	check_map(t_game *game)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	if (!count_len(game))
		return (1);
	else if (!map_elements(game, line, i))
		return (1);
	return (0);
}

int	copy_map(t_game *game, char *line, int fd)
{
	char	*trimmed;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)))
	{
		trimmed = ft_strtrim(line, "\n");
		if (!trimmed)
		{
			free(line);
			return (1);
		}
		game->map[i++] = trimmed;
		free(line);
		game->height++;
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
		perror("Error: height of map is not valid\n");
		close(fd);
		return (1);
	}
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
	{
		perror("Error: error in map malloc\n");
		close(fd);
		return (1);
	}
	
	return (copy_map(game, line, fd));
}
