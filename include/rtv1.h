/*
** rtv1.h for  in /home/perra_t
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Thu Feb  5 14:39:07 2015 tiphaine perra
** Last update Sun Mar 15 21:22:26 2015 tiphaine perra
*/

#ifndef	RTV1_H
#define	RTV1_H

#define PI 3.141592653589793
#define WINX 920
#define WINY 800

typedef struct	s_window
{
  void          *mlx_ptr;
  void          *img_ptr;
  void          *win_ptr;
  int           *data;
}		t_wi;

typedef struct	s_eye
{
  int		color;
  double	vx;
  double	vy;
  double	vz;
  double	xe;
  double	ye;
  double	ze;
  double	xlum;
  double	ylum;
  double	zlum;
  double	interx;
  double	intery;
  double	interz;
  double	vxlum;
  double	vylum;
  double	vzlum;
  double	cpx;
  double	cpy;
  double	cpz;
  double	tmp_x;
  double	tmp_y;
  double	tmp_z;
}		t_eye;

typedef struct	s_obj
{
  char		*genre;
  double	x;
  double	y;
  double	z;
  double	a;
  double	b;
  double	c;
  double	R;
  double	del;
  double	k1;
  double	k2;
  double	k;
  double	d;
  double	rx;
  double	ry;
  double	rz;
  double	ang;
}		t_obj;

double		compare(t_obj *);
int             gere_key(int, t_wi *);
int             calc(t_eye *, int, int, t_obj *);
int             remplis_image(t_wi *, t_eye *, t_obj *);
int             gere_expose(t_wi *);
int             inter_plan(t_obj *, t_eye *);
void		inter_sphere(t_obj *, t_eye *);
void		inter_cone(t_obj *, t_eye *);
void		rotate_z(t_eye *, double);
void		rotate_y(t_eye *, double);
void		rotate_x(t_eye *, double);
void		rotate(t_obj *,t_eye *);
void		unrotate(t_eye *);
void		transla(t_eye *, double, double, double);
void		ope_lum(t_obj *, t_eye *);
int		cast(int, int, int);
void		vect_nor(t_eye *, t_obj *);

#endif
