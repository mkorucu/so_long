/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:07:25 by mkorucu           #+#    #+#             */
/*   Updated: 2022/09/22 16:07:26 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buff)
{
	size_t	j;
	size_t	i;
	char	*collect;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	collect = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (collect == NULL)
		return (NULL);
	j = -1;
	i = 0;
	if (str)
		while (str[++j] != '\0')
			collect[j] = str[j];
	while (buff[i] != '\0')
		collect[j++] = buff[i++];
	collect[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free (str);
	return (collect);
}
