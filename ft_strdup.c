/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmourid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:29:59 by zmourid           #+#    #+#             */
/*   Updated: 2023/12/12 12:20:06 by zmourid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*data;
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
