/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:04:46 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/07 14:07:25 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		s++;
		i++;
	}
}
