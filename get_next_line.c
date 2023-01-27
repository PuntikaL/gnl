/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:08 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/27 16:19:47 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void	get_out(char *start, char *ret)
{
	int i;
	
	for(i = 0; start[i] != *ret; i++)
	{
		printf("%c",start[i]);
		
	}
	printf("\n\n");
}

char	*check_new_line(char *buff, char *str)
{
	char	*ptr;

	str = ft_strjoin(str, buff);
	ptr = (ft_strchr(str, '\n'));
	if (ptr != NULL)
	{
		get_out(str,ptr);
		free(str);
	 	if (ptr++ !=  NULL)
	 	{
	 		str = malloc(1);
	 		str = ft_strjoin(ptr, "");
	 	}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	int	read_status;
	char	*buff;
	static char	*str;

	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = '\0';
	str = malloc(1);
	//read_status = read(fd, buff, buffsize);
	while((read_status = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if(str == NULL)
		{
			str = ft_strjoin("", buff);
		}
		str = check_new_line(buff, str);
		//str = ft_strjoin(str, buff);
	}
	//printf("%s\n", str);
	return(NULL);
}
