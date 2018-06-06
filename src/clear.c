/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:40:47 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/10 18:31:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		free_data(void)
{
	t_param	*tmp;

	while (g_data->head)
	{
		tmp = g_data->head;
		g_data->head = g_data->head->next;
		ft_strdel(&tmp->name);
		ft_memdel((void**)&tmp);
	}
	g_data->head = NULL;
	ft_memdel((void**)&g_data);
}

int				free_exit(void)
{
	exec_term_command("ve");
	exec_term_command("te");
	signal(SIGWINCH, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	if (apply_term_setting(1))
		return (1);
	close(g_data->fd);
	free_data();
	return (0);
}
