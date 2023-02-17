/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:24:14 by mkorucu           #+#    #+#             */
/*   Updated: 2022/09/29 14:21:08 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_map(t_chr *chr)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	ft_image_import(chr);
	while (++i < chr->row)
	{
		j = -1;
		while (++j <= chr->collumn)
		{
			if (j == chr->collumn)
			{
				c += 64;
				chr->pos = 0;
			}
			else
				ft_put_image(chr, i, j, c);
		}
	}
}

void	ft_add_image(void *image, t_chr *chr, int pos, int pos2)
{
	mlx_put_image_to_window(chr->mlx, chr->mlx_window, chr->ground, pos, pos2);
	mlx_put_image_to_window(chr->mlx, chr->mlx_window, image, pos, pos2);
	chr->pos += 64;
}

void	ft_put_image(t_chr *chr, int i, int j, int c)
{
	if (chr->map[i][j] == '1')
		ft_add_image(chr->wall, chr, chr->pos, c);
	else if (chr->map[i][j] == 'E')
		ft_add_image(chr->exit, chr, chr->pos, c);
	else if (chr->map[i][j] == 'P')
	{
		if (chr->input == 'w')
			ft_add_image(chr->up, chr, chr->pos, c);
		else if (chr->input == 's')
			ft_add_image(chr->down, chr, chr->pos, c);
		else if (chr->input == 'd')
			ft_add_image(chr->right, chr, chr->pos, c);
		else if (chr->input == 'a')
			ft_add_image(chr->left, chr, chr->pos, c);
	}
	else if (chr->map[i][j] == 'C')
		ft_add_image(chr->clt, chr, chr->pos, c);
	else if (chr->map[i][j] == '0')
		ft_add_image(chr->ground, chr, chr->pos, c);
	else
		ft_error("unsupportted char in map layout!", chr);
}

void	ft_image_import(t_chr *chr)
{
	chr->down = mlx_xpm_file_to_image(chr->mlx, DOWN, &chr->imgx, &chr->imgy);
	chr->left = mlx_xpm_file_to_image(chr->mlx, LEFT, &chr->imgx, &chr->imgy);
	chr->right = mlx_xpm_file_to_image(chr->mlx, RIGHT, &chr->imgx, &chr->imgy);
	chr->up = mlx_xpm_file_to_image(chr->mlx, UP, &chr->imgx, &chr->imgy);
	chr->wall = mlx_xpm_file_to_image(chr->mlx, WALLS, &chr->imgx, &chr->imgy);
	chr->clt = mlx_xpm_file_to_image(chr->mlx, CLT, &chr->imgx, &chr->imgy);
	chr->exit = mlx_xpm_file_to_image(chr->mlx, EXIT, &chr->imgx, &chr->imgy);
	chr->ground = mlx_xpm_file_to_image(chr->mlx, GND, &chr->imgx, &chr->imgy);
}

int	main(int ac, char **av)
{
	t_chr	*chr;

	chr = ft_calloc(sizeof(t_chr), 1);
	if (ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 5))
	{
		chr->input = 'd';
		ft_check_map(av[1], chr);
		chr->mlx = mlx_init();
		chr->mlx_window = mlx_new_window(chr->mlx, chr->collumn * 64, \
		chr->row * 64, "JoJo");
		ft_put_map(chr);
		ft_put_move(chr);
		mlx_loop(chr->mlx);
	}
	else if (ac != 2)
		ft_error("wrong number of argument!", chr);
	else if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 5))
		ft_error("wrong file type!", chr);
	return (0);
}
