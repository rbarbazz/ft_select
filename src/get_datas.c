/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:19:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/12 11:49:16 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		get_curr_param(void)
{
	g_data->curr_param = g_data->param_line * -g_data->y + g_data->x;
}

void		param_by_line(void)
{
	g_data->param_line = g_data->sz.ws_col / (g_data->size_max + 1);
	if (g_data->param_line > g_data->size_lst)
		g_data->param_line = g_data->size_lst;
	if (g_data->param_line)
	{
		if (!g_data->size_lst % g_data->param_line)
			g_data->line_count = g_data->size_lst / g_data->param_line;
		else
			g_data->line_count = (g_data->size_lst / g_data->param_line) + 1;
	}
}

void		new_size_max(void)
{
	t_param	*tmp;

	tmp = g_data->head;
	g_data->size_max = 0;
	while (tmp && tmp->next)
	{
		if (tmp->size > g_data->size_max)
			g_data->size_max = tmp->size;
		tmp = tmp->next;
	}
}

void		get_coordinates(void)
{
	g_data->x = 0;
	g_data->x_max = g_data->param_line - 1;
	g_data->y = 0;
	g_data->y_max = -(g_data->size_lst / g_data->param_line) + 1;
	if ((g_data->size_lst % g_data->param_line) != 0)
		g_data->y_max--;
}
