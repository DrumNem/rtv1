/*
** fct_int.c for  in /home/perra_t/TP/TP_Raytracer
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Mon Mar  2 15:49:21 2015 tiphaine perra
** Last update Sun Mar 15 19:32:10 2015 tiphaine perra
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"

int             inter_plan(t_obj *ob, t_eye *eye)
{
  ob->z = 0;
  ob->k = -(eye->ze / eye->vz);
  if (eye->vz ==0 && eye->ze == 0)
    eye->color = 0x0000FF;
  if (ob->k < 0.00001)
    return (1);
  else
    {
      if (ob->k > 0 && ob->k < ob->d)
        {
          ob->d = ob->k;
          eye->color = 0x0000FF;
        }
    }
  return (0);
}

void             inter_sphere(t_obj *ob, t_eye *eye)
{
  transla(eye, -500, 0, 0);
  ob->R = 200;
  ob->a = pow(eye->vx, 2) + pow(eye->vy, 2) + pow(eye->vz, 2);
  ob->b = 2 *
    ((eye->cpx * eye->vx) + (eye->cpy * eye->vy) + (eye->cpz * eye->vz));
  ob->c = pow(eye->cpx, 2) + pow(eye->cpy, 2)
    + pow(eye->cpz, 2) - pow(ob->R, 2);
  ob->del = pow(ob->b, 2) - (4 * (ob->a * ob->c));
  if (ob->del > 0)
    {
      ob->k1 = (-ob->b + sqrt(ob->del)) / (2 * ob->a);
      ob->k2 = (-ob->b - sqrt(ob->del)) / (2 * ob->a);
      if (compare(ob) != 0 && compare(ob) < ob->d)
        {
          ob->d = compare(ob);
          eye->color = 0xF9BFDF;
        }
      else
	return;
    }
}

void		inter_cylindre(t_obj *ob, t_eye *eye)
{
  transla(eye, -530, 0, 0);
  ob->R = 45;
  ob->a = pow(eye->vx, 2) + pow(eye->vy, 2);
  ob->b = (2 * (eye->cpx * eye->vx)) + (2 * (eye->cpy * eye->vy));
  ob->c = pow(eye->cpx, 2) + pow(eye->cpy, 2) - pow(ob->R, 2);
  ob->del = pow(ob->b, 2) - (4 * ob->a * ob->c);
  if (ob->del >= 0)
    {
      ob->k1 = (-ob->b + sqrt(ob->del)) / (2 * ob->a);
      ob->k2 = (-ob->b - sqrt(ob->del)) / (2 * ob->a);
      if (compare(ob) != 0 && compare(ob) < ob->d)
        {
          ob->d = compare(ob);
          eye->color = 0x935535;
        }
    }
}

void		inter_cone(t_obj *ob, t_eye *eye)
{

  transla(eye, -650, -200, -250);
  ob->ang = 80;
  ob->a = pow(eye->vx, 2) + pow(eye->vy, 2)
    - (pow(eye->vz, 2) / pow(tan(PI * ob->ang / 180), 2));
  ob->b = (2 * (eye->cpx * eye->vx)) + (2 * (eye->cpy * eye->vy))
    - (2 * eye->vz * eye->cpz / pow(tan(PI * ob->ang / 180), 2));
  ob->c = pow(eye->cpx, 2) + pow(eye->cpy, 2)
    - (pow(eye->cpz, 2) / pow(tan(PI * ob->ang / 180), 2));
  ob->del = pow(ob->b, 2) - (4 * ob->a * ob->c);
  if (ob->del > 0)
    {
      ob->k1 = (-ob->b + sqrt(ob->del)) / (2 * ob->a);
      ob->k2 = (-ob->b - sqrt(ob->del)) / (2 * ob->a);
      if (compare(ob) != 0 && compare(ob) < ob->d)
        {
          ob->d = compare(ob);
          eye->color = 0xB2F0E3;
        }
    }
}
