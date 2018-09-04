/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:43:08 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/04 15:47:04 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	count_selected(void)
{
	t_param	*tmp;
	int		count;

	tmp = g_data->head;
	count = 0;
	while (tmp)
	{
		if (tmp->select)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void		print_selection(void)
{
	t_param	*tmp;
	int		count;
	int		i;

	tmp = g_data->head;
	count = count_selected();
	i = 0;
	exec_term_command("te");
	while (tmp)
	{
		if (tmp->select)
		{
			ft_printf("%s", tmp->name);
			i++;
			if (i < count)
				ft_printf(" ");
		}
		tmp = tmp->next;
	}
}

int			select_param(long buffer)
{
	t_param	*tmp;
	int		i;

	tmp = g_data->head;
	i = 0;
	if (buffer == 32)
	{
		while (tmp && i++ < g_data->curr_param)
			tmp = tmp->next;
		if (tmp->select)
			tmp->select = 0;
		else
			tmp->select = 1;
		move_right();
	}
	else
		return (1);
	return (0);
}
