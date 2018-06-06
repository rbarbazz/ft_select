/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:18:40 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/10 18:17:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_putchar_tty(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

void			exec_term_command(const char *code)
{
	tputs(tgoto(tgetstr((char*)code, NULL), 0, 1), 1, ft_putchar_tty);
}

void			exec_term_command_p(const char *code, int p1, int p2)
{
	tputs(tgoto(tgetstr((char*)code, NULL), p1, p2), 1, ft_putchar_tty);
}
