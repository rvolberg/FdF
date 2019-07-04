/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 09:16:48 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:05:21 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui colorise selon taille
*/

unsigned int		ft_color(float z, t_map *stc)
{
	unsigned int	color;

	color = 0xFFFFFF;
	if (z < 0)
		color = ft_clr_neg(z, stc, color);
	if (z >= 0)
		color = ft_clr_pos(z, stc, color);
	return (color);
}

/*
** ft couleur valeur negative
*/

unsigned int		ft_clr_neg(float z, t_map *stc, unsigned int clr)
{
	if (z >= -2 && z < 0)
		clr = 0xC6ECFF;
	else if (z >= -4 && z < -2)
		clr = 0xACDBFB;
	else if (z >= -6 && z < -4)
		clr = 0x96C9F0;
	else if (z >= -8 && z < -6)
		clr = 0x84B9E3;
	else if (z >= -10 & z < -8)
		clr = 0x79B2DE;
	else if (z < -10)
		clr = 0x71ABD8;
	return (clr);
}

/*
** ft couleur valeur positive
*/

unsigned int		ft_clr_pos(float z, t_map *stc, unsigned int clr)
{
	if (z >= 12)
		clr = 0XF5F4F2;
	else if (z >= 10 && z < 12)
		clr = 0XCAC3B8;
	else if (z >= 8 && z < 10)
		clr = 0XAC9A7C;
	else if (z >= 6 && z < 8)
		clr = 0XB9985A;
	else if (z >= 4 && z < 6)
		clr = 0xCAB982;
	else if (z >= 2 && z < 4)
		clr = 0xDED6A3;
	else if (z > 0 && z < 2)
		clr = 0xBDCC96;
	else if (z == 0)
		clr = 0XA7DFD2;
	return (clr);
}
