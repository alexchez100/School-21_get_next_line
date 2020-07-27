/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:33:40 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/14 13:23:06 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *str, int ch)
{
	while (1)
	{
		if (*str == (char)ch)
			return (char*)str;
		if (!*str)
			return (0);
		str++;
	}
	return (0);
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = dest;
	sp = src;
	if ((dp != NULL) && (sp != NULL))
	{
		while (n--)
			*dp++ = *sp++;
	}
	return (dest);
}

char			*ft_strdup(const char *str)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (new)
		ft_memcpy(new, str, ft_strlen(str) + 1);
	return (new);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

size_t			ft_strlen(const char *s)
{
	size_t		lenght;

	lenght = 0;
	if (!s)
		return (0);
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}
