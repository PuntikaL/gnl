/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:10 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/28 21:37:32 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#include<fcntl.h>
#include "get_next_line.c"
#include <stdio.h>

# define RED "\033[1;36m"
# define RESET "\033[0m"

int main()
{
	char *str;
	int fd;
	int i =1;

	fd = open("test", O_RDONLY);
	while (i != 0 || str != NULL)
	{
		i=0;
		str = get_next_line(fd);
		if (str != NULL){
			printf(RED"------------Return--------------\n"RESET);		
			write(1,str,ft_strlen(str));
			//printf("------------Return--------------\n\n");		
		}
		else
			printf("\n>>%s\n", str);
		free(str);
		/* code */
	}
	return(0);
}