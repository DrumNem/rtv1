/*
** lum.c for  in /home/perra_t/rendu/MUL_2014_rtv1
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Fri Mar 13 11:27:52 2015 tiphaine perra
** Last update Sat Mar 14 17:36:14 2015 tiphaine perra
*/

#include "rtv1.h"
#include "my.h"

void	ope_lum(t_obj *ob, t_eye *eye)
{
  eye->xlum = 30;
  eye->ylum = 30;
  eye->zlum = 30;
  eye->interx = eye->xe + ob->d * eye->vx;
  eye->intery = eye->ye + ob->d * eye->vy;
  eye->interz = eye->ze + ob->d * eye->vz;
  eye->vxlum = eye->interx - eye->xlum;
  eye->vylum = eye->intery - eye->ylum;
  eye->vzlum = eye->interz - eye->zlum;
  eye->x2 = eye->interx + ob->d * eye->vxlum;
  eye->y2 = eye->intery + ob->d * eye->vylum;
  eye->z2 = eye->interz + ob->d * eye->vzlum;
  //appel je sais pas quoi
}

void	vect_nor()
{

}
