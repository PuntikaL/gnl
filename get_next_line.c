/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:08 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/28 17:31:36 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_out(char *start, char *ret)
{
	char	*tmp;
	
	if(start == NULL || ret == NULL)
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
	 	if (ptr++ !=  NULL)
	 	{
	 		str = malloc(1);
			tmp = str;
	 		str = ft_strjoin(ptr, "");
			free(tmp);
	 	}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	int	read_status;
	char	*buff;
	static char	*str;
	char	*ptr;
	char	*res;
	char	*tmp;
	
	res = NULL;
	read_status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1));
	buff[BUFFER_SIZE] = '\0';
	while((read_status) > 0)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		buff[read_status]='\0';
		if(str == NULL)
		{
			str = malloc(1);
			tmp = str;
			str = ft_strjoin("", buff);
			free(tmp);
		}
		else
		{
			tmp = str;
			str = ft_strjoin(str, buff);
			if (tmp)
				free(tmp);
		}
		ptr = (ft_strchr(str, '\n'));
		if (ptr != NULL)
		{
			res =  get_out(str,ptr);
			tmp = str;
			str = check_new_line(str);
			free(tmp);
			break;
		}
		if (read_status < BUFFER_SIZE)
		{
			ptr = ft_strchr(str, '\0');
			res =  get_out(str,ptr);
			if (*res == '\0')
			{
				free(str);
				str = NULL;
				free(res);
				free(buff);
				return (NULL);
			}
			free(str);
			str = NULL;
			break;
		}
	}
	free(buff);
	return (res);
}

// # include <fcntl.h>
// # include <stdio.h>

// int	main(void)
// {
// 	int fd;
	
// 	fd = open("gnlTester/files/empty", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }