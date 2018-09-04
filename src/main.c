/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:08:21 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/04 15:54:20 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_data		*g_data;

static int	init_data(int argc, char **argv)
{
	g_data->size_lst = argc - 1;
	ioctl(g_data->fd, TIOCGWINSZ, &g_data->sz);
	if (!(g_data->head = mk_list(argv)))
		return (1);
	g_data->tail = get_tail(g_data->head);
	param_by_line();
	if (!g_data->param_line)
		ft_dprintf(g_data->fd, "T\no\no\n\nS\nm\na\nl\nl\n");
	else
		get_coordinates();
	g_data->curr_param = 0;
	return (0);
}

/*
** initiate termsettings, signals and tty
*/

static int	term_init(void)
{
	char	*term_type;

	if (!(term_type = getenv("TERM")) || (tgetent(NULL, term_type)) != 1 ||\
	apply_term_setting(0))
		return (1);
	if (!(g_data = (t_data*)ft_memalloc(sizeof(t_data))))
		return (1);
	if ((g_data->fd = open(ttyname(STDIN_FILENO), O_WRONLY)) < 0)
		return (1);
	exec_term_command("vi");
	exec_term_command("ti");
	signal(SIGWINCH, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGHUP, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGCONT, sig_handler);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	long	buffer;

	i = 1;
	if (argc < 2 || term_init() || init_data(argc, argv))
		return (1);
	while (1)
	{
		if (g_data->param_line > 0)
			print_list();
		buffer = 0;
		if (read(STDIN_FILENO, &buffer, sizeof(long)) < 0)
			free_exit();
		if (!move_cursor(buffer) || !select_param(buffer) || !rm_param(buffer))
			get_curr_param();
		else if (buffer == 27)
			break ;
		else if (buffer == 10)
		{
			print_selection();
			free_exit();
		}
	}
	exec_term_command("te");
	free_exit();
}
