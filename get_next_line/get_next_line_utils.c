/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:52:25 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/10 16:07:35 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strlcpy(char *src, const char *str, size_t len)
{
	char	*buf;

	buf = src;
	len--;
	while (*str && len--)
		*src++ = *str++;
	*src++ = '\0';
	return (buf);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buf;
	size_t	s1_len;
	size_t	s2_len;
	char	*ans;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buf)
		return (NULL);
	ans = buf;
	ft_strlcpy(buf, s1, s1_len + 1);
	ft_strlcpy(&buf[s1_len], s2, s2_len + 1);
	free(s1);
	return (ans);
}
