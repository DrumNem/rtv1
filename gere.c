/*
** gere.c for  in /home/perra_t/rendu/MUL_2014_rtv1
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Thu Mar 12 17:42:44 2015 tiphaine perra
** Last update Sat Mar 14 18:55:22 2015 tiphaine perra
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"

int             gere_key(int keycode, t_wi *wi)
{
  if (keycode == 65307)
    exit(1);
  return (0);
}

int             gere_expose(t_wi *wi)
{
  mlx_put_image_to_window(wi->mlx_ptr, wi->win_ptr, wi->img_ptr, 0, 0);
  return (1);
}

void		transla(t_eye *eye, double x, double y, double z)
{
  eye->cpx = eye->xe + x;
  eye->cpy = eye->ye + y;
  eye->cpz = eye->ze + z;
}
