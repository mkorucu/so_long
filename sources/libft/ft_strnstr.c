/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:08:00 by mkorucu           #+#    #+#             */
/*   Updated: 2022/09/22 16:08:02 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	hay;
	size_t	need;

	hay = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[hay] != 0 && hay < n)
	{
		need = 0;
		while (haystack[hay + need] == needle[need]
			&& needle[need] && need + hay < n)
			need++;
		if (need == ft_strlen(needle))
			return ((char *)&haystack[hay]);
		hay++;
	}
	return (NULL);
}
