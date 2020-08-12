/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:20:27 by lpassera          #+#    #+#             */
/*   Updated: 2020/08/07 12:20:28 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t index;

	dstlen = 0;
	srclen = 0;
	index = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstsize > 0)
	{
		while (index + dstlen < dstsize - 1 && src[index])
		{
			dst[dstlen + index] = src[index];
			index++;
		}
		dst[dstlen + index] = '\0';
	}
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (srclen + dstlen);
}
