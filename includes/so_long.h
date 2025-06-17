/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:14:29 by isrguerr          #+#    #+#             */
/*   Updated: 2025/06/18 00:04:40 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 1000
#define HEIGHT 800

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game
{
	int spaces;
	int player;
	int collectables;
	int walls;
	int exits;
	int height;
	int line_len;
	int valid_exit;
	int valid_collectable;
	char **map;
} t_game;

int read_map(const char *filename, t_game *game);
int check_map(const char *filename, t_game *game);
int free_game(t_game *game);

#endif