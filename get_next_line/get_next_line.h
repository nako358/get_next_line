/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:12:21 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/09 22:07:59 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1024
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *str, int c);
char	*ft_strlcpy(char *src, const char *str, size_t len);
size_t	ft_strlen(char *s);
char	*ft_read(int fd, char *buf);
char	*ft_get_line(char *str);
char	*ft_next_str(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif
