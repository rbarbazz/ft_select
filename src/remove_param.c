/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:19:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/03 18:57:50 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	remove_anywhereelse(t_param *tmp)
{
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	ft_strdel(&tmp->name);
	ft_memdel((void**)&tmp);
}

static void	remove_last(t_param *tmp)
{
	tmp->prev->next = NULL;
	ft_strdel(&tmp->name);
	ft_memdel((void**)&tmp);
}

static void	remove_first(t_param *tmp)
{
	g_data->head = tmp->next;
	g_data->head->prev = NULL;
	ft_strdel(&tmp->name);
	ft_memdel((void**)&tmp);
}

static void	get_new_datas(void)
{
	g_data->size_lst--;
	new_size_max();
	param_by_line();
	get_coordinates();
}

int			remove_param(long buffer)
{
	t_param	*tmp;
	int		i;

	tmp = g_data->head;
	i = 0;
	if (buffer == 127 || buffer == 2117294875)
	{
		while (tmp && i++ < g_data->curr_param)
			tmp = tmp->next;
		if (!tmp->prev && !tmp->next)
		{
			free_exit();
			exit(0);
		}
		else if (!tmp->prev)
			remove_first(tmp);
		else if (!tmp->next)
			remove_last(tmp);
		else
			remove_anywhereelse(tmp);
		get_new_datas();
	}
	else
		return (1);
	return (0);
}
