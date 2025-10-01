/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:14:29 by isrguerr          #+#    #+#             */
/*   Updated: 2025/10/01 17:03:06 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_game
{
	int		exit_active;
	int		steps;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collect;
	void	*mlx;
	void	*win;
	int		spaces;
	int		player;
	int		collect;
	int		walls;
	int		exits;
	int		height;
	int		width;
	int		valid_exit;
	int		valid_collect;
	char	**map;
	int		player_x;
	int		player_y;
}			t_game;

int			read_map(const char *filename, t_game *game);
int			check_map(const char *filename, t_game *game);
void		free_2d_array(char **array);
int			valid_map(t_game *game);
char		**allocate_and_copy_map(t_game *game);
int			find_player_and_flood_fill(char **map_copy, t_game *game);
int			map_elements(t_game *game, int line);
int			check_items(t_game *game);
int			add_items(t_game *game, int line, int i);
int			check_width(t_game *game);
int			map_height(const char *filename);
int			flood_fill(char **map, int x, int y, t_game *game);
int			init(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			close_window(t_game *game);
void		render_tiles(t_game *game);
int			key_hook(int keycode, t_game *game);
void		free_all(t_game *game);

#endif