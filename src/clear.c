/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:40:47 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/12 11:21:23 by rbarbazz         ###   ########.fr       */
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

void			free_exit(void)
{
	exec_term_command("ve");
	signal(SIGWINCH, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGHUP, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	if (apply_term_setting(1))
		exit(EXIT_FAILURE);
	close(g_data->fd);
	free_data();
	exit(EXIT_SUCCESS);
}
