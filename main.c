/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:10 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/28 15:47:28 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#include<fcntl.h>
#include "get_next_line.c"

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
		if (str != NULL)
			write(1,str,ft_strlen(str));
		else
			printf("\n%s\n", str);
		free(str);
		/* code */
	}
	return(0);
}
