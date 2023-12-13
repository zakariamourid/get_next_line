/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:30:19 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/12 17:06:17 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strdup(const char *s1)
{
        size_t  s_len;
        char    *data;
        int i;

        i = 0;
        s_len = ft_strlen(s1);
        data = malloc(s_len + 1);
        if (!data)
                return (NULL);
        while(s1[i])
        {
                data[i] = s1[i];
                i++;
        }

        return (data);
}

char    *ft_strchr(const char *s, int c)
{
        size_t  i;

        i = 0;
        if ((char)c == '\0')
                return ((char *)s + ft_strlen(s));
        while (s[i])
        {
                if (s[i] == (char)c)
                        return ((char *)s + i);
                i++;
        }
        return (NULL);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  s_len;
        size_t  i;

        i = 0;
        s_len = ft_strlen(src);
        if (!dstsize)
                return (s_len);
        while (src[i] && i < dstsize - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = 0;
        return (s_len);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *str;

        if (!s)
                return (NULL);
        if (!*s || !len)
                return (ft_strdup(""));
        if (start >= ft_strlen(s))
        {
                str = (char *)malloc(1 * sizeof(char));
                if (!str)
                        return (NULL);
                *str = '\0';
                return (str);
        }
        if (len + start > ft_strlen(s))
                len = ft_strlen(s) - start;
        if (!str)
                return (NULL);
        ft_strlcpy(str, s + start, len + 1);
        return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, size + 1);
	return (str);
}
//int main()
//{
//	char str[] = "hello world";
//	printf("sub = %s \n ",ft_substr(str,0,str + 5 - str));
//}
