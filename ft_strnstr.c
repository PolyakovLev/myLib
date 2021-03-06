/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:08:07 by daharwoo          #+#    #+#             */
/*   Updated: 2018/11/25 16:26:33 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	int		lastresult;

	if (!*haystack)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	lastresult = 1;
	while (nlen <= len &&
			*haystack != '\0' &&
			(lastresult = ft_strncmp(haystack, needle, nlen)))
	{
		len--;
		haystack++;
	}
	if (lastresult != 0)
		return (NULL);
	return ((char *)haystack);
}
