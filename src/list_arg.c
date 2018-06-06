/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:23:55 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/29 17:49:35 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_param	*mk_head(char *name)
{
	t_param	*new;

	if (!(new = (t_param*)ft_memalloc(sizeof(t_param))))
		return (NULL);
	new->name = ft_strdup(name);
	new->size = ft_strlen(name);
	g_data->size_max = new->size;
	new->select = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static t_param	*add_elem(t_param *param, char *name)
{
	t_param	*new;
	t_param	*tmp;

	tmp = param;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_param*)ft_memalloc(sizeof(t_param))))
		return (NULL);
	new->name = ft_strdup(name);
	new->size = ft_strlen(name);
	if (new->size > g_data->size_max)
		g_data->size_max = new->size;
	new->select = 0;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	return (param);
}

t_param			*get_tail(t_param *head)
{
	t_param *tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_param			*mk_list(char **argv)
{
	t_param	*param;
	int		i;

	i = 0;
	param = mk_head(argv[++i]);
	i++;
	while (argv[i])
		param = add_elem(param, argv[i++]);
	return (param);
}
