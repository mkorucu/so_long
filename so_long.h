/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          ::      ::    ::   */
/*                                                    : :         :     */
/*   By: mkorucu <mkorucu@student.42istanbul.com.t  #  :       #        */
/*                                                #####   #           */
/*   Created: 2022/09/29 17:22:09 by mkorucu           ##    ##             */
/*   Updated: 2022/09/29 17:22:11 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "sources/libft/libft.h"
# include "sources/get_next_line/get_next_line.h"
# include "sources/ft_printf/ft_printf.h"

# define DOWN "./textures/down.xpm"
# define LEFT "./textures/left.xpm"
# define RIGHT "./textures/right.xpm"
# define UP "./textures/up.xpm"
# define GND "./textures/ground.xpm"
# define CLT "./textures/collect.xpm"
# define EXIT "./textures/door.xpm"
# define WALLS "./textures/walls.xpm"

typedef struct s_chr
{
	void	*mlx;
	void	*mlx_window;
	void	*up;
	void	*down;
	void	*right;
	void	*left;
	void	*wall;
	void	*clt;
	void	*exit;
	void	*ground;
	char	**map;
	char	**copy_map;
	int		imgx;
	int		imgy;
	int		px;
	int		py;
	int		c_count;
	int		c_count2;
	int		p_count;
	int		e_count;
	int		row;
	int		collumn;
	int		move;
	int		valid_map;
	int		pos;
	char	input;
}			t_chr;

void	ft_player_location(t_chr *chr);
void	ft_path_validator(t_chr *chr, int x, int y);
void	ft_char_check(char *map, t_chr *chr);
void	ft_check_map(char *address, t_chr *chr);
void	ft_border_check(t_chr *chr);
void	ft_image_import(t_chr *chr);
void	ft_put_image(t_chr *chr, int i, int j, int c);
void	ft_add_image(void *image, t_chr *chr, int pos, int pos2);
void	ft_put_map(t_chr *chr);
void	ft_put_move(t_chr *chr);
int		ft_free_chr(t_chr *chr);
void	ft_error(char *s, t_chr *chr);
void	ft_move(t_chr *chr, int x, int y, char keyboard_input);
int		ft_key_input(int key, t_chr *chr);

#endif
