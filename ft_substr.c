/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:29:10 by lpassera          #+#    #+#             */
/*   Updated: 2020/08/07 15:29:12 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sublen;
	size_t	slen;
	char	*str;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		sublen = 0;
	else if (ft_strlen(&s[start]) > len)
		sublen = len;
	else
		sublen = ft_strlen(&s[start]);
	if ((str = malloc((sublen + 1) * sizeof(char))))
	{
		ft_memcpy(str, &s[start], sublen);
		str[sublen] = '\0';
	}
	return (str);
}
