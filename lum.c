/*
** lum.c for  in /home/perra_t/rendu/MUL_2014_rtv1
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Fri Mar 13 11:27:52 2015 tiphaine perra
** Last update Sun Mar 15 18:17:08 2015 tiphaine perra
*/

#include <math.h>
#include "rtv1.h"

void		ope_lum(t_obj *ob, t_eye *eye)
{
  eye->xlum = 750;
  eye->ylum = - 300;
  eye->zlum = 600;
  eye->interx = eye->xe + ob->d * eye->vx;
  eye->intery = eye->ye + ob->d * eye->vy;
  eye->interz = eye->ze + ob->d * eye->vz;
  eye->vxlum = - (eye->interx - eye->xlum);
  eye->vylum = - (eye->intery - eye->ylum);
  eye->vzlum = - (eye->interz - eye->zlum);
  eye->x2 = eye->interx + ob->d * eye->vxlum;
  eye->y2 = eye->intery + ob->d * eye->vylum;
  eye->z2 = eye->interz + ob->d * eye->vzlum;
  vect_nor(eye, ob);
}

int		cast(int r, int g, int b)
{
  if (r > 255)
    r = 255;
  else if (r < 0)
    r = 0;
  if (g > 255)
    g = 255;
  else if (g < 0)
    g = 0;
  if (b > 255)
    b = 255;
  else if (b < 0)
    b = 0;
  return (b * pow(256, 2) + g * 256 + r);
}

void		vect_nor(t_eye *eye, t_obj *ob)
{
  double	norm_l;
  double	norm_n;
  double	scal;
  double	cosi;

  norm_l = sqrt(pow(eye->vxlum, 2) + pow(eye->vylum, 2) + pow(eye->vzlum, 2));
  norm_n = sqrt(pow(eye->interx, 2) + pow(eye->intery, 2)
		+ pow(eye->interz, 2));
  scal = eye->vxlum * eye->interx + eye->vylum * eye->intery
    + eye->vzlum * eye->interz;
  cosi = scal / (norm_l * norm_n);
  if (cosi <= 0)
    {
      eye->color = 0x000000;
      return;
    }
  eye->color = cast(cosi * (eye->color & 0xFF),
		    cosi * ((eye->color >> 8) & 0xFF),
		    cosi * ((eye->color >> 16) & 0xFF));
}
