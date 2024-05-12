/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:12:03 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/10 16:06:44 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	int		size;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	while (!ft_strchr(str, '\n') && size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[size] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*buf;
	size_t	index;

	if (!str[0])
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index])
		index++;
	if (str[index] == '\n')
		index++;
	buf = (char *)malloc(sizeof(char) * (index + 1));
	if (!buf)
		return (NULL);
	ft_strlcpy(buf, str, index + 1);
	return (buf);
}

char	*ft_next_str(char *str)
{
	char	*buf;
	size_t	index;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(buf, &str[index], ft_strlen(str) - index + 1);
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_next_str(str);
	return (line);
}
