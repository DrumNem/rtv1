/*
** rt1.c for  in /home/perra_t/TP/TP_Raytracer
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Mon Mar  2 15:05:46 2015 tiphaine perra
** Last update Sat Mar 14 18:46:37 2015 tiphaine perra
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"

double		compare(t_obj *ob)
{
  if (ob->k1 < 0 && ob->k2 > 0)
    return (ob->k2);
  else if (ob->k2 < 0 && ob->k1 > 0)
    return (ob->k1);
  else if (ob->k1 > 0 && ob->k2 > 0 && ob->k1 >= ob->k2)
    return (ob->k2);
  else if (ob->k1 > 0 && ob->k2 > 0 && ob->k2 >= ob->k1)
    return (ob->k1);
  else
    return (0);
}

int		calc(t_eye *eye, int x, int y, t_obj *ob)
{
  int		color;

  eye->vx = 1.5 * WINX;
  eye->vy = WINX / 2 - x;
  eye->vz = WINY / 2 - y;
  eye->xe = -350;
  eye->ye = 0;
  eye->ze = 170;
  inter_sphere(ob, eye);
  inter_plan(ob, eye);
  inter_cylindre(ob, eye);
  inter_cone(ob, eye);
  return (ob->color);
}

void            my_pixel_put_to_image(int x, int y, t_wi *wi, int color)
{
  int           bpp;
  int           size_line;
  int           endian;
  int           *data;
  int           i;

  data = (int *)mlx_get_data_addr(wi->img_ptr, &bpp, &size_line, &endian);
  if (x >= 0 && x < WINX && y >= 0 && y < WINY)
    {
      i = WINX * y + x;
      data[i] = color;
    }
}

int		remplis_image(t_wi *wi, t_eye *eye, t_obj *ob)
{
  int		x;
  int		y;

  x = 0;
  while (x <= WINX)
    {
      y = 0;
      while (y <= WINY)
	{
	  ob->d = 1000000000;
	  ob->color = 0x000000;
	  my_pixel_put_to_image(x, y, wi, calc(eye, x, y, ob));
	  y++;
	}
      if (x == 100)
	puts("Please wait : 25%");
      else if (x == 200)
	puts("Please wait : 50%");
      else if (x == 300)
	puts("Please wait : 75%");
      else if (x == 400)
	puts("Please wait : 100%");
      x++;
    }
  return (0);
}

int		main()
{
  t_wi		wi;
  t_eye		eye;
  t_obj		ob;
  int		bpp;
  int		size_line;
  int		endian;
  unsigned long color;
  int		x;

  x = 0;
  ob.d = 1000000000;
  ob.color = 0x000000;
  wi.mlx_ptr = mlx_init();
  wi.img_ptr = mlx_new_image(wi.mlx_ptr, WINX, WINY);
  wi.data = (int*)mlx_get_data_addr(wi.img_ptr, &bpp, &size_line, &endian);
  wi.win_ptr = mlx_new_window(wi.mlx_ptr, WINX, WINY, "rtv1");
  remplis_image(&wi, &eye, &ob);
  mlx_expose_hook(wi.win_ptr, gere_expose, &wi);
  mlx_key_hook(wi.win_ptr, gere_key, &wi);
  mlx_loop(wi.mlx_ptr);
  mlx_put_image_to_window(wi.mlx_ptr, wi.win_ptr, wi.img_ptr, 0, 0);
  return (0);
}
