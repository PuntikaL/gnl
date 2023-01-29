/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:52:11 by pleepago          #+#    #+#             */
/*   Updated: 2023/01/29 08:58:06 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 17
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_out(char *start, char *ret);
char	*check_new_line(char *str);
char	*get_next_line(int fd);
int	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int	clone(char *ptr, char *res, char *str, char *buff);
int	found_nl(char **str, char **res);
void	check_first(char **str, char *buff);
void	last_line(char **ptr, char **res, char **str);

# endif