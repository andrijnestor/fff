/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:33:41 by anestor           #+#    #+#             */
/*   Updated: 2018/01/14 20:38:41 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_fdf *fdf)
{
	int		i;
	int		y;
	int		z;
	int		y1;
	int		z1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		y = PY(i) - WIN_H / 2;
		z = PZ(i);
		y1 = y;
		z1 = z;
		y = y1 * cos(RAD(fdf->x_angle)) + z1 * sin(RAD(fdf->x_angle));
		z = -y1 * sin(RAD(fdf->x_angle)) + z1 * cos(RAD(fdf->x_angle));
		PY(i) = y + WIN_H / 2;
		PZ(i) = z;
		i++;
	}
}

void	rotate_y(t_fdf *fdf)
{
	int		i;
	int		x;
	int		z;
	int		x1;
	int		z1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		x = PX(i) - WIN_W / 2;
		z = PZ(i);
		x1 = x;
		z1 = z;
		x = x1 * cos(RAD(fdf->y_angle)) + z1 * sin(RAD(fdf->y_angle));
		z = -x1 * sin(RAD(fdf->y_angle)) + z1 * cos(RAD(fdf->y_angle));
		PX(i) = x + WIN_W / 2;
		PZ(i) = z;
		i++;
	}
}

void	rotate_z(t_fdf *fdf)
{
	int		i;
	int		x;
	int		y;
	int		x1;
	int		y1;

	i = 0;
	while (i != fdf->grid_p_h * fdf->grid_p_w)
	{
		x = PX(i) - WIN_W / 2;
		y = PY(i) - WIN_H / 2;
		x1 = x;
		y1 = y;
		x = x1 * cos(RAD(fdf->z_angle)) - y1 * sin(RAD(fdf->z_angle));
		y = x1 * sin(RAD(fdf->z_angle)) + y1 * cos(RAD(fdf->z_angle));
		PX(i) = x + WIN_W / 2;
		PY(i) = y + WIN_H / 2;
		i++;
	}
}