/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:11:39 by mkorucu           #+#    #+#             */
/*   Updated: 2022/09/29 15:02:53 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_location(t_chr *chr)
{
	int	x;
	int	y;

	y = -1;
	while (chr->map[++y])
	{
		x = -1;
		while (chr->map[y][++x])
		{
			if (chr->map[y][x] == 'P')
			{
				chr->px = x;
				chr->py = y;
			}
		}
	}
	chr->collumn = x;
	chr->row = y;
}

void	ft_path_validator(t_chr *chr, int x, int y)
{
	char	*point;

	point = &chr->copy_map[y][x];
	if (*point == 'E')
		chr->valid_map = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			chr->c_count2--;
		*point = '.';
		if (chr->copy_map[y][x + 1] != '1' && chr->copy_map[y][x + 1] != '.')
			ft_path_validator(chr, x + 1, y);
		if (chr->copy_map[y][x - 1] != '1' && chr->copy_map[y][x - 1] != '.')
			ft_path_validator(chr, x - 1, y);
		if (chr->copy_map[y + 1][x] != '1' && chr->copy_map[y + 1][x] != '.')
			ft_path_validator(chr, x, y + 1);
		if (chr->copy_map[y - 1][x] != '1' && chr->copy_map[y - 1][x] != '.')
			ft_path_validator(chr, x, y - 1);
	}
}

void	ft_border_check(t_chr *chr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (chr->map[0][j] == '1' && chr->map[0][j + 1] == '1')
		j++;
	while (i < chr->row && chr->map[i][0] == '1' && \
	chr->map[i][j] == '1' && (ft_strlen(chr->map[i]) - 1) == j)
		i++;
	while (chr->map[i - 1][j] == '1' && j >= 0)
		j--;
	if (j != -1 || i != chr->row)
		ft_error("invalid border setup!", chr);
}

void	ft_char_check(char *str, t_chr *chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E')
			chr->e_count++;
		else if (str[i] == 'P')
			chr->p_count++;
		else if (str[i] == 'C')
			chr->c_count++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
			ft_error("missing character", chr);
		i++;
	}
	if (chr->e_count != 1 || chr->p_count != 1 || chr->c_count < 1)
		ft_error("wrong number of exit/player/collectable count!", chr);
	chr->c_count2 = chr->c_count;
}

void	ft_check_map(char *address, t_chr *chr)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(address, O_RDONLY);
	if (fd < 0)
		ft_error("error while opening map!", chr);
	tmp = get_next_line(fd);
	str = ft_strdup("");
	while (tmp)
	{
		str = ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	chr->map = ft_split(str, '\n');
	chr->copy_map = ft_split(str, '\n');
	ft_player_location(chr);
	ft_char_check(str, chr);
	ft_path_validator(chr, chr->px, chr->py);
	if (chr->c_count2 != 0 || chr->valid_map == 0)
		ft_error("invalid path setup!", chr);
	free(str);
	close(fd);
}
