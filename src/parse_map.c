/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/24 20:25:45 by isrguerr         ###   ########.fr       */
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
static int	map_heigth(int fd)
{
	char	*line;
	int		height;

	height = 0;
	while ((line = get_next_line(fd)))
	{
		height++;
		free(line);
	}
	return (height);
}

static int	count_len(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = map[i];
	while (map[++i])
	{
		if (len != map[i])
			return (1);
	}
	return (0);
}

int	check_map(char **map, int fd)
{
	t_map	map;
	int		line;
	int		i;

	if (!count_len(map))
		return (1);
	line = 0;
	i = 0;
	while (map[line][i])
	{
		
	}
}

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	height = map_heigth(fd);
	map = NULL;
	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	while ((line = get_next_line(fd)))
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
