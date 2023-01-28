/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:15:58 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/28 16:57:52 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size;
	char			*p;
	unsigned int	n1;
	unsigned int	n2;

	if (!s1 || !s2)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	size = n1 + n2;
	p = (char *)malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, n1);
	ft_memcpy(p + n1, s2, n2);
	p[size] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*first_occurence;

	i = 0;
	first_occurence = NULL;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			first_occurence = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (first_occurence);
}

