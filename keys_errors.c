/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:18:05 by mkorucu           #+#    #+#             */
/*   Updated: 2022/09/29 14:31:09 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_input(int key, t_chr *chr)
{
	if (key == 13 || key == 126)
		ft_move(chr, 0, -1, 'w');
	else if (key == 0 || key == 123)
		ft_move(chr, -1, 0, 'a');
	else if (key == 1 || key == 125)
		ft_move(chr, 0, 1, 's');
	else if (key == 2 || key == 124)
		ft_move(chr, 1, 0, 'd');
	else if (key == 53)
		ft_free_chr(chr);
	return (1);
}

void	ft_move(t_chr *chr, int x, int y, char keyboard_input)
{
	chr->input = keyboard_input;
	if (chr->map[chr->py + y][chr->px + x] != '1' \
	&& chr->map[chr->py + y][chr->px + x] != 'E')
	{
		if (chr->map[chr->py + y][chr->px + x] == 'C')
			ft_printf("c_count: %d\n", --chr->c_count);
		chr->map[chr->py + y][chr->px + x] = 'P';
		chr->map[chr->py][chr->px] = '0';
		chr->py += y;
		chr->px += x;
		mlx_clear_window(chr->mlx, chr->mlx_window);
		ft_put_map(chr);
		ft_printf("Move: %d\n", ++chr->move);
		ft_put_move(chr);
	}
	else if (chr->map[chr->py + y][chr->px + x] == 'E' && chr->c_count == 0)
		ft_free_chr(chr);
}

void	ft_error(char *msg, t_chr *chr)
{
	int	i;

	i = 0;
	ft_printf("%s\n", msg);
	while (chr->map && chr->map[i] && chr->copy_map[i])
	{
		free(chr->map[i]);
		free(chr->copy_map[i]);
		i++;
	}
	free(chr);
	exit(EXIT_FAILURE);
}

int	ft_free_chr(t_chr *chr)
{
	int	i;

	i = 0;
	while (chr->map && chr->map[i] && chr->copy_map[i])
	{
		free(chr->map[i]);
		free(chr->copy_map[i]);
		i++;
	}
	mlx_destroy_image(chr->mlx, chr->up);
	mlx_destroy_image(chr->mlx, chr->down);
	mlx_destroy_image(chr->mlx, chr->left);
	mlx_destroy_image(chr->mlx, chr->right);
	mlx_destroy_image(chr->mlx, chr->exit);
	mlx_destroy_image(chr->mlx, chr->wall);
	mlx_destroy_image(chr->mlx, chr->ground);
	mlx_destroy_window(chr->mlx, chr->mlx_window);
	free(chr);
	exit(EXIT_SUCCESS);
	return (1);
}

void	ft_put_move(t_chr *chr)
{
	char	*str;

	str = ft_itoa(chr->move);
	mlx_string_put(chr->mlx, chr->mlx_window, 5, 30, 0xFF0000, "Move: ");
	mlx_string_put(chr->mlx, chr->mlx_window, 50, 30, 0xFF0000, str);
	mlx_hook(chr->mlx_window, 2, 1L << 0, ft_key_input, chr);
	mlx_hook(chr->mlx_window, 17, 0, ft_free_chr, chr);
	free(str);
}
