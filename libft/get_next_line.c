/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:28:55 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/25 12:18:11 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:28:55 by isrguerr          #+#    #+#             */
/*   Updated: 2025/04/23 17:11:43 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

#define BUFFER_SIZE 42

static char	*get_remainder(char *remainder, char *buffer)
{
	char	*temp;

	if (!remainder)
	{
		remainder = ft_strdup("");
		if (!remainder)
			return (NULL);
	}
	temp = remainder;
	remainder = ft_strjoin(remainder, buffer);
	free(temp);
	if (!remainder)
		return (NULL);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder || !*remainder)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, remainder, i + 1);
	return (line);
}

static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	if (remainder[i] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(remainder + i);
	free(remainder);
	return (new_remainder);
}

static int	read_and_update_remainder(int fd, char **remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*remainder = get_remainder(*remainder, buffer);
		if (!*remainder)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(*remainder, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_and_update_remainder(fd, &remainder);
	if (bytes_read == -1 || (bytes_read == 0 && (!remainder || !*remainder)))
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
