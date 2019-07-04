/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:05:24 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 12:47:36 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
**  ft qui recupere les evenements clavier vers les differents fonctions
*/

int				ft_key(int key, t_map *param)
{
	if (key == 53)
	{
		free_int_tab(param->tab, param->m_len, param->m_hei);
		ft_strdel(&param->map);
		free(param);
		ft_putendl("EXIT_SUCCESS");
		exit(0);
	}
	if (key == 15)
		ft_reset_map(param);
	if ((key == 24) || (key == 27))
		ft_zoom(key, param);
	if ((key >= 123) && (key <= 126))
		ft_move(key, param);
	return (0);
}

/*
** fonction qui change la couleur d'un pixel dans le tableau data
*/

void			ft_print_pixel(float i, float j, t_map *stc, U_INT clr)
{
	U_INT		x;
	U_INT		max_pixels;

	x = ((j * stc->d_len) + i);
	max_pixels = stc->d_hei * stc->d_len;
	if ((x < max_pixels) && (i < stc->d_len) && (i > 0) && (j < stc->d_hei))
		stc->data[x] = clr;
	else
		return ;
}

/*
** ft qui envoie data vers x et y pour tracer segment et perspective
*/

unsigned int	*ft_data_filler(t_map *stc)
{
	ft_axe_x(stc);
	ft_axe_y(stc);
	mlx_put_image_to_window(stc->mlx, stc->win, stc->img, 0, 0);
	return (stc->data);
}

/*
** ft qui initialise l'image data
*/

void			ft_data_maker(t_map *stc)
{
	int			bbp;
	int			sizeline;
	int			endian;
	U_INT		color;

	color = 0x72F1CA;
	stc->img = mlx_new_image(stc->mlx, stc->d_len, stc->d_hei);
	stc->data = (U_INT *)mlx_get_data_addr(stc->img, &bbp, &sizeline, &endian);
	stc->data = ft_data_filler(stc);
	mlx_string_put(stc->mlx, stc->win, 20, 20, color, "FDF - to leave : ESC");
	mlx_string_put(stc->mlx, stc->win, 20, 40, color, "move : arrows keys");
	mlx_string_put(stc->mlx, stc->win, 20, 60, color, "zoom : - / +");
	mlx_string_put(stc->mlx, stc->win, 20, 80, color, "RESET : R");
}

/*
** ft qui fait le lien graphique et initialise les differents pointeurs
*/

int				ft_print_map(t_map *stc)
{
	if ((stc->mlx = mlx_init()) == NULL)
	{
		ft_putendl_fd("Error : connection to graphical server failed", 2);
		return (-1);
	}
	stc->win = mlx_new_window(stc->mlx, stc->w_len, stc->w_hei, "output win");
	ft_data_maker(stc);
	mlx_key_hook(stc->win, ft_key, (void *)stc);
	mlx_loop(stc->mlx);
	return (0);
}
