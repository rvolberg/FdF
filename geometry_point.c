/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:17:55 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/07 13:31:08 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui cree les bonne coordonnee X
*/

float		ft_coord_x(float x, float y, t_map *stc)
{
	float	r;

	r = (x - y) * stc->t_len + (stc->d_len / 2) + stc->xm;
	return (r);
}

/*
** ft qui cree les bonne coordonne Y
*/

float		ft_coord_y(float x, float y, t_map *stc)
{
	float	r;

	r = (x + y) * stc->t_hei + (stc->d_hei / 2) + stc->ym;
	return (r);
}

/*
** ft qui cree les bonne coordonnee quand la valeur Z != 0
*/

float		ft_coord_z(float x, float y, float z, t_map *stc)
{
	float	r;

	r = (x + y - z) * stc->t_hei + (stc->d_hei / 2) + stc->ym;
	return (r);
}
