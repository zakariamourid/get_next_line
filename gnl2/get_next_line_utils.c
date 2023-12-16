/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <zmourid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:04:32 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/16 18:09:12 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*new;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (free(s1), (NULL));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (free(s1), (NULL));
	str[len] = 0;
	while (*s1)
		str[i++] = *s1++;
	free(s1 - i);
	while (*s2)
		str[i++] = *s2++;
	return (str);
}
