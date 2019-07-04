/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:41 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:01:26 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui reset la map a l affichage initial
*/

void				ft_reset_map(t_map *stc)
{
	mlx_destroy_image(stc->mlx, stc->img);
	stc->xm = 0;
	stc->ym = 0;
	stc->t_hei = 10;
	stc->t_len = 10;
	stc->tab = ft_map_to_tab(stc);
	ft_data_maker(stc);
}

/*
** ft qui zoom
*/

void				ft_zoom(int key, t_map *stc)
{
	if (key == 24)
	{
		mlx_destroy_image(stc->mlx, stc->img);
		stc->t_len = stc->t_len + 2;
		stc->t_hei = stc->t_hei + 2;
		ft_data_maker(stc);
	}
	if ((key == 27) && (stc->t_len > 2 && stc->t_hei > 2))
	{
		mlx_destroy_image(stc->mlx, stc->img);
		stc->t_len = stc->t_len - 2;
		stc->t_hei = stc->t_hei - 2;
		ft_data_maker(stc);
	}
}

/*
** ft pour deplacer map
** PROB AVEC DEPLACEMENT IMAGE => FIXER ? A VERIFIER.
*/

void				ft_move(int key, t_map *stc)
{
	mlx_destroy_image(stc->mlx, stc->img);
	if (key == 123)
		stc->xm = stc->xm - 5;
	else if (key == 126)
		stc->ym = stc->ym - 5;
	else if (key == 124)
		stc->xm = stc->xm + 5;
	else if (key == 125)
		stc->ym = stc->ym + 5;
	ft_data_maker(stc);
}
