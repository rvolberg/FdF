/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:23:03 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 13:02:04 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

/*
** ft qui recup le fichier en parametre
*/

static int		ft_open(char **argv)
{
	int			fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("open() failed", 2);
	return (fd);
}

/*
** fonction principale
** recup fichier, verifie fichier et gere message d'erreur
*/

int				main(int argc, char **argv)
{
	int			fd;
	t_map		*stc;

	stc = NULL;
	if (argc == 2)
	{
		if (((fd = ft_open(argv)) == -1) ||
			((stc = ft_get_map(fd)) == NULL))
			return (0);
		if ((ft_print_map(stc)) == -1)
		{
			free_int_tab(stc->tab, stc->m_len, stc->m_hei);
			ft_strdel(&stc->map);
			free(stc);
			return (0);
		}
		if (close(fd) == -1)
		{
			ft_putendl_fd("close () failed", 2);
			return (0);
		}
	}
	else
		ft_putendl_fd("usage:\t ./fdf source_file target_file", 2);
	return (0);
}
