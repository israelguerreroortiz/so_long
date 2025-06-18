/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/18 11:24:15 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

/*
  Función que mapea los elementos de map.ber
*/
int map_elements(t_game *game, int line, int i)
{
	while (game->map[line])
	{
		i = 0;
		if (line == game->height - 1 || line == 0)
		{
			while (game->map[line][i])
			{
				if (game->map[line][i++] != '1')
					return (1);
			}
		}
		else
		{
			if (game->map[line][0] != '1' || game->map[line][game->line_len - 1] != '1')
				return (1);
			i++;
			while (i < game->line_len - 1)
			{
				if (add_items(game, line, i++) == 1)
					return (1);
			}
		}
		line++;
	}
	return (check_items(game));
}

/*
	Chequea que todas las líneas tengan la
	misma longitud y el mapa sea válido
*/
int check_errors(t_game *game)
{
	int line;
	int i;

	line = 0;
	i = 0;
	if (count_len(game) != 0)
		return (1);
	else if (map_elements(game, line, i) != 0)
		return (1);
	if (game->exits < 1 || game->collectables < 1 || game->player < 1)
		return (1);
	return (0);
}
/*
	Función que copia el mapa
*/
int copy_map(t_game *game, char *line, int fd)
{
	char *trimmed;
	int i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		if (!trimmed)
		{
			free(line);
			return (1);
		}
		game->map[i++] = trimmed;
		free(line);
	}
	game->map[i] = NULL;
	close(fd);
	return (0);
}
/*
	Función que reserva memoria para el mapa y posteriormente
	redirige a función para copiar el mapa
*/
int read_map(const char *filename, t_game *game)
{
	int fd;
	char *line;

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

int check_map(const char *filename, t_game *game)
{
	if (read_map(filename, game) != 0)
	{
		perror("Error: error reading map\n");
		return (free_game(game));
	}
	if (check_errors(game) != 0)
	{
		perror("Error: map is not valid\n");
		return (free_game(game));
	}
	if (valid_map(game) != 0)
	{
		perror("Error: map is not valid\n");
		return (free_game(game));
	}
	return (0);
}
