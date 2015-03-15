/*
** rotate.c for  in /home/perra_t/TP/TP_Raytracer
** 
** Made by tiphaine perra
** Login   <perra_t@epitech.net>
** 
** Started on  Mon Mar  2 16:20:22 2015 tiphaine perra
** Last update Sun Mar 15 20:36:53 2015 tiphaine perra
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "rtv1.h"

void	rotate_z(t_eye *eye, double ang)
{
  float	mat[3][3];
  float	tmpx;
  float	tmpy;
  float	tmpz;

  mat[0][0] = cos(PI * ang / 180);
  mat[1][0] = sin(PI * ang / 180);
  mat[2][0] = 0;
  mat[0][1] = -sin(PI * ang / 180);
  mat[1][1] = cos(PI * ang / 180);
  mat[2][1] = 0;
  mat[0][2] = 0;
  mat[1][2] = 0;
  mat[2][2] = 1;
  tmpx = eye->vx * mat[0][0] + eye->vy * mat[1][0]
    + eye->vz * mat[2][0];
  tmpy = eye->vx * mat[0][1] + eye->vy * mat[1][1]
    + eye->vz * mat[2][1];
  tmpz = eye->vx * mat[0][2] + eye->vy * mat[1][2]
    + eye->vz * mat[2][2];
  eye->vx = tmpx;
  eye->vy = tmpy;
  eye->vz = tmpz;
}

void	rotate_y(t_eye *eye, double ang)
{
  float	mat[3][3];
  float	tmpx;
  float	tmpy;
  float	tmpz;

  mat[0][0] = cos(PI * ang / 180);
  mat[1][0] = 0;
  mat[2][0] = -sin(PI * ang / 180);
  mat[0][1] = 0;
  mat[1][1] = 1;
  mat[2][1] = 0;
  mat[0][2] = sin(PI * ang / 180);
  mat[1][2] = 0;
  mat[2][2] = cos(PI * ang / 180);
  tmpx = eye->vx * mat[0][0] + eye->vy * mat[1][0]
    + eye->vz * mat[2][0];
  tmpy = eye->vx * mat[0][1] + eye->vy * mat[1][1]
    + eye->vz * mat[2][1];
  tmpz = eye->vx * mat[0][2] + eye->vy * mat[1][2]
    + eye->vz * mat[2][2];
  eye->vx = tmpx;
  eye->vy = tmpy;
  eye->vz = tmpz;
}

void	rotate_x(t_eye *eye, double ang)
{
  float	mat[3][3];
  float	tmpx;
  float	tmpy;
  float	tmpz;

  mat[0][0] = 1;
  mat[1][0] = 0;
  mat[2][0] = 0;
  mat[0][1] = 0;
  mat[1][1] = cos(PI * ang / 180);
  mat[2][1] = sin(PI * ang / 180);
  mat[0][2] = 0;
  mat[1][2] = -sin(PI * ang / 180);
  mat[2][2] = cos(PI * ang / 180);
  tmpx = eye->vx * mat[0][0] + eye->vy * mat[1][0]
    + eye->vz * mat[2][0];
  tmpy = eye->vx * mat[0][1] + eye->vy * mat[1][1]
    + eye->vz * mat[2][1];
  tmpz = eye->vx * mat[0][2] + eye->vy * mat[1][2]
    + eye->vz * mat[2][2];
  eye->vx = tmpx;
  eye->vy = tmpy;
  eye->vz = tmpz;
}

void	rotate(t_obj *ob, t_eye *eye)
{
  ob->rx = 40;
  ob->ry = 0;
  ob->rz = 0;
  eye->tmp_x = eye->vx;
  eye->tmp_y = eye->vy;
  eye->tmp_z = eye->vz;
  rotate_x(eye, ob->rx);
  rotate_y(eye, ob->ry);
  rotate_z(eye, ob->rz);
}

void	unrotate(t_eye *eye)
{
  eye->vx = eye->tmp_x;
  eye->vy = eye->tmp_y;
  eye->vz = eye->tmp_z;
}
