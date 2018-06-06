/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:43:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/07 18:30:04 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** print current selected param in underline reverse-video mode
*/

static void	print_curr_selected(t_param *tmp)
{
	exec_term_command("mr");
	exec_term_command("us");
	ft_dprintf(g_data->fd, "%s", tmp->name);
	exec_term_command("me");
	exec_term_command("ue");
	if (g_data->size_max != tmp->size)
		ft_dprintf(g_data->fd, "%*c", (g_data->size_max - tmp->size), ' ');
}

/*
** print selected param in reverse-video mode
*/

static void	print_selected(t_param *tmp)
{
	exec_term_command("mr");
	ft_dprintf(g_data->fd, "%s", tmp->name);
	exec_term_command("me");
	if (g_data->size_max != tmp->size)
		ft_dprintf(g_data->fd, "%*c", (g_data->size_max - tmp->size), ' ');
}

/*
** print current selection in underlined mode
*/

static void	print_curr(t_param *tmp)
{
	exec_term_command("us");
	ft_dprintf(g_data->fd, "%s", tmp->name);
	exec_term_command("ue");
	if (g_data->size_max != tmp->size)
		ft_dprintf(g_data->fd, "%*c", (g_data->size_max - tmp->size), ' ');
}

/*
** print the list according to their attributes(selected, current, normal)
*/

void		print_list(void)
{
	t_param	*tmp;
	int		i;
	int		curr;

	tmp = g_data->head;
	i = 1;
	curr = 0;
	exec_term_command("cl");
	while (tmp)
	{
		if (curr == g_data->curr_param && tmp->select)
			print_curr_selected(tmp);
		else if (curr == g_data->curr_param)
			print_curr(tmp);
		else if (tmp->select)
			print_selected(tmp);
		else
			ft_dprintf(g_data->fd, "%-*s", g_data->size_max, tmp->name);
		ft_dprintf(g_data->fd, " ");
		if (i == g_data->param_line && !(i = 0))
			ft_dprintf(g_data->fd, "\n");
		tmp = tmp->next;
		curr++;
		i++;
	}
}
