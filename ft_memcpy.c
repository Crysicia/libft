/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:09:50 by lpassera          #+#    #+#             */
/*   Updated: 2020/08/04 17:09:51 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t index;

	index = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (index < n)
	{
		*(char *)(dst + index) = *(char *)(src + index);
		index++;
	}
	return (dst);
}
