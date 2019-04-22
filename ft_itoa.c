/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:06:27 by daharwoo          #+#    #+#             */
/*   Updated: 2018/11/25 16:58:40 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_intleng(long int n)
{
	int			i;
	long int	count;

	i = 1;
	count = 10;
	n = n < 0 ? -n : n;
	while (count < n)
	{
		count = count * 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int			i;
	int			leng;
	char		*str;
	long int	b;

	b = n;
	i = 0;
	leng = ft_intleng(b);
	if ((b < 0) && (str = ft_memalloc(leng + 2)))
	{
		str[i] = '-';
		i++;
	}
	else if ((str = ft_memalloc(leng + 1)))
		;
	else
		return (NULL);
	leng = b < 0 ? leng + 1 : leng;
	b = b < 0 ? -b : b;
	while (leng-- && str[leng] != '-')
	{
		str[leng] = '0' + (b % 10);
		b /= 10;
	}
	return (str);
}
