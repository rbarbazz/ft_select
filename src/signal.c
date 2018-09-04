/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:58:01 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/04 11:13:22 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_winch(void)
{
	ioctl(g_data->fd, TIOCGWINSZ, &g_data->sz);
	param_by_line();
	if (!g_data->param_line)
	{
		exec_term_command("cl");
		ft_dprintf(g_data->fd, "T\no\no\n\nS\nm\na\nl\nl\n");
	}
	else
	{
		get_coordinates();
		get_curr_param();
		print_list();
	}
	signal(SIGWINCH, sig_handler);
}

static void	sig_cont(void)
{
	if (apply_term_setting(0))
		exit(1);
	exec_term_command("vi");
	exec_term_command("ti");
	g_data->fd = open(ttyname(STDIN_FILENO), O_WRONLY);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &g_data->sz);
	param_by_line();
	if (!g_data->param_line)
	{
		exec_term_command("cl");
		ft_dprintf(g_data->fd, "T\no\no\n\nS\nm\na\nl\nl\n");
	}
	else
	{
		get_coordinates();
		get_curr_param();
		print_list();
	}
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
}

void		sig_handler(int signo)
{
	char	vsusp[2];

	if (signo == SIGWINCH)
		sig_winch();
	else if (signo == SIGTSTP)
	{
		vsusp[0] = (*get_term_setting())->c_cc[VSUSP];
		vsusp[1] = 0;
		exec_term_command("ve");
		exec_term_command("te");
		signal(SIGTSTP, SIG_DFL);
		apply_term_setting(1);
		ioctl(STDOUT_FILENO, TIOCSTI, vsusp);
		close(g_data->fd);
	}
	else if (signo == SIGCONT)
		sig_cont();
	else
		free_exit();
}
