/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:20:15 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/14 14:08:40 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		set_term_setting(struct termios *old, \
	struct termios *new)
{
	*new = *old;
	new->c_lflag &= (~(ICANON | ECHO) | ISIG);
	new->c_cc[VMIN] = 1;
	new->c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, new) < 0)
	{
		ft_memdel((void**)&old);
		exit(1);
	}
}

struct termios	**get_term_setting(void)
{
	static struct termios	*def_set = NULL;

	return (&def_set);
}

int				apply_term_setting(int def)
{
	struct termios	**def_set;
	struct termios	new_set;

	def_set = get_term_setting();
	if (*def_set && def)
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, *def_set))
			return (1);
		ft_memdel((void**)def_set);
	}
	else
	{
		*def_set = (struct termios*)ft_memalloc(sizeof(struct termios));
		if (tcgetattr(STDIN_FILENO, *def_set))
		{
			ft_memdel((void**)&def_set);
			return (1);
		}
		set_term_setting(*def_set, &new_set);
	}
	return (0);
}
