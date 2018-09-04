/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 19:22:02 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/04 14:14:37 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		move_left(void)
{
	if (!g_data->curr_param)
	{
		g_data->x = g_data->x_max;
		if (g_data->size_lst % g_data->param_line)
			g_data->x = (g_data->size_lst % g_data->param_line) - 1;
		g_data->y = g_data->y_max;
	}
	else if (g_data->x == 0)
	{
		g_data->y++;
		g_data->x = g_data->x_max;
	}
	else
		g_data->x--;
}

void			move_right(void)
{
	if (g_data->curr_param == g_data->size_lst - 1)
	{
		g_data->x = 0;
		g_data->y = 0;
	}
	else if (g_data->x == g_data->x_max)
	{
		g_data->y--;
		g_data->x = 0;
	}
	else
		g_data->x++;
}

static void		move_down(void)
{
	if (g_data->curr_param == g_data->size_lst - 1 && !(g_data->size_lst % \
		g_data->param_line))
	{
		g_data->x = 0;
		g_data->y = 0;
	}
	else if (g_data->y != g_data->y_max && !(g_data->size_lst % \
	g_data->param_line))
		g_data->y--;
	else if (g_data->y == g_data->y_max || (g_data->y == (g_data->y_max + 1) \
	&& (g_data->x > (g_data->size_lst % g_data->param_line) - 1)))
	{
		if (g_data->x + 1 <= g_data->x_max)
			g_data->x++;
		else
			g_data->x = 0;
		g_data->y = 0;
	}
	else
		g_data->y--;
}

static void		move_up(void)
{
	if (!g_data->curr_param)
	{
		g_data->x = g_data->x_max;
		g_data->y = g_data->y_max;
		if ((g_data->size_lst % g_data->param_line))
			g_data->y++;
	}
	else if (!g_data->y && !(g_data->size_lst % g_data->param_line))
	{
		g_data->x--;
		g_data->y = g_data->y_max;
	}
	else if (!g_data->y && (g_data->x > (g_data->size_lst % \
	g_data->param_line)))
	{
		g_data->x--;
		g_data->y = g_data->y_max + 1;
	}
	else if (!g_data->y)
	{
		g_data->x--;
		g_data->y = g_data->y_max;
	}
	else
		g_data->y++;
}

int				move_cursor(long buffer)
{
	if (g_data->size_lst == 1)
	{
		g_data->x = 0;
		g_data->x = 0;
		return (1);
	}
	else if (buffer == 4414235)
		move_right();
	else if (buffer == 4479771)
		move_left();
	else if (buffer == 4348699)
		move_down();
	else if (buffer == 4283163)
		move_up();
	else
		return (1);
	return (0);
}
