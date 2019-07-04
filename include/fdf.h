/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:01:31 by rvolberg          #+#    #+#             */
/*   Updated: 2018/04/11 13:38:01 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# define U_INT unsigned int

typedef struct			s_map
{
	void				*mlx;
	void				*win;
	void				*img;
	unsigned int		*data;
	char				*map;
	int					**tab;
	float				m_len;
	float				m_hei;
	float				d_len;
	float				d_hei;
	float				w_len;
	float				w_hei;
	float				t_len;
	float				t_hei;
	unsigned int		color;
	double				xm;
	double				ym;
	struct s_map		*next;
}						t_map;
t_map					*ft_struct_map();
t_map					*ft_get_map(int fd);
char					*ft_back_n(char *map);
int						ft_parsing_by_line(char *line, t_map *stc);
int						ft_parsing_by_map(t_map *stc);
int						ft_check_map(char *map);
int						ft_check_char_map(char *map);
int						ft_first_line_count(char *map);
int						ft_check_len_map(char *map);
int						ft_check_empty(char *map);
void					free_map_tab(char **tab);
void					free_int_tab(int **tab, int len, int hei);
t_map					*ft_map_size(t_map *stc);
int						ft_print_map(t_map *data);
unsigned int			*ft_data_filler(t_map *stc);
void					ft_print_pixel(float i, float j, t_map *stc, U_INT clr);
void					ft_segment(float *x, float *y, t_map *stc);
void					ft_seg_c(float *d, float *inc, float *crd, t_map *stc);
void					ft_seg_b(float *d, float *inc, float *crd, t_map *stc);
char					**ft_str_adaptor(t_map *stc);
int						**ft_map_to_tab(t_map *stc);
void					ft_axe_x(t_map *stc);
void					ft_axe_y(t_map *stc);
void					ft_crd_x_zero(float *x, float *y, int *crd, t_map *stc);
void					ft_crd_x_nz(float *x, float *y, int *crd, t_map *stc);
void					ft_crd_y_zero(float *x, float *y, int *crd, t_map *stc);
void					ft_crd_y_nz(float *x, float *y, int *crd, t_map *stc);

float					ft_coord_x(float x, float y, t_map *stc);
float					ft_coord_y(float x, float y, t_map *stc);
float					ft_coord_z(float x, float y, float z, t_map *stc);
void					ft_data_maker(t_map *stc);
void					ft_clear_image(t_map *stc);
int						ft_key(int key, t_map *param);
void					ft_zoom(int key, t_map *stc);
void					ft_move(int key, t_map *stc);
unsigned int			ft_color(float z, t_map *stc);
void					ft_reset_map(t_map *stc);
unsigned int			ft_clr_neg(float z, t_map *stc, unsigned int clr);
unsigned int			ft_clr_pos(float z, t_map *stc, unsigned int clr);
#endif
