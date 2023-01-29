/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:08 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/29 10:11:02 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_out(char *start, char *ret)
{
	char	*tmp;

	if ((start == NULL || ret == NULL || start == ret) \
		&& (*start != '\n'))
		return (NULL);
	tmp = malloc(ret - start + 1);
	ft_memcpy(tmp, start, ret - start + 1);
	tmp[ret - start + 1] = '\0';
	return (tmp);
}

char	*check_new_line(char *str)
{
	char	*ptr;
	char	*tmp;

	ptr = (ft_strchr(str, '\n'));
	if (ptr != NULL)
	{
		if (ptr++ != NULL)
		{
			str = malloc(1);
			tmp = str;
			str = ft_strjoin(ptr, "");
			if (tmp)
				free(tmp);
		}
	}
	return (str);
}

int	found_nl(char **str, char **res)
{
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr(*str, '\n');
	if (ptr != NULL)
	{
		*res = get_out(*str, ptr);
		tmp = *str;
		*str = check_new_line(*str);
		if (tmp)
			free(tmp);
		return (1);
	}
	return (0);
}

void	check_first(char **str, char *buff)
{
	char	*tmp;

	if (*str == NULL)
	{
		*str = malloc(1);
		tmp = *str;
		*str = ft_strjoin("", buff);
		if (tmp)
			free(tmp);
	}
	else
	{
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		if (tmp)
			free(tmp);
	}
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			read_status;
	char		*res;
	char		*buff;
	char		*ptr;

	read_status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	while (read_status > 0)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		buff[read_status] = '\0';
		check_first(&str, buff);
		if (found_nl(&str, &res))
			break ;
		if (read_status < BUFFER_SIZE)
		{
			last_line (&ptr, &res, &str);
			break ;
		}
	}
	return (free(buff), res);
}
