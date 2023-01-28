/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:08 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/28 15:55:21 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 17
#endif
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char	*get_out(char *start, char *ret)
{
	char	*tmp;
	
	if(start == NULL || ret == NULL)
		return (NULL);
	tmp = malloc(ret - start + 1);
	ft_memcpy(tmp, start, ret - start + 1);
	tmp[ret - start + 1] = '\0';
	//printf("%s", tmp);
	return (tmp);
}
/// @brief cut the left words and connect to static str
/// @param buff 
/// @param str 
/// @return 
char	*check_new_line(char *buff, char *str)
{
	char	*ptr;
	char	*tmp;

	//str = ft_strjoin(str, buff);
	ptr = (ft_strchr(str, '\n'));
	if (ptr != NULL)
	{
		//get_out(str,ptr);
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
	
	read_status = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
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
			free(tmp);
		}
	// printf("str 3 = %s\n",str);
		ptr = (ft_strchr(str, '\n'));
		if (ptr != NULL)
		{
			res =  get_out(str,ptr);
			tmp = str;
			str = check_new_line(buff, str);
			free(tmp);
			break;
		}
		// if (buff[BUFFER_SIZE - 1] == '\0' && !ft_strchr(str, '\n'))
		// 	return (get_out(str, str+BUFFER_SIZE - 1));
	//printf("str 4 = %s\n",str);
		if (read_status < BUFFER_SIZE)
		{
			ptr = ft_strchr(str, '\0');
			res =  get_out(str,ptr);
			if (*res == '\0')
			{
				free(str);
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