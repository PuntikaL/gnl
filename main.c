/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:10 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/27 15:37:13 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#include<fcntl.h>
#include "get_next_line.c"

int main()
{
		int fd;

		fd = open("test", O_RDONLY);
		get_next_line(fd);
		
		return(0);
}