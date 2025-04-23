/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:37 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/23 18:45:46 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	i = 0;
	map = malloc(sizeof(char *) * (/*MAX_MAP_HEIGHT*/ 10 + 1));
	while ((line = get_next_line(fd)))
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
