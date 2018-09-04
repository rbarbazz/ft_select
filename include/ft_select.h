/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:51:56 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/09/04 15:53:51 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct		s_param
{
	char			*name;
	int				size;
	int				select;
	struct s_param	*next;
	struct s_param	*prev;
}					t_param;

typedef struct		s_data
{
	int				size_max;
	int				size_lst;
	int				param_line;
	int				curr_param;
	int				x;
	int				x_max;
	int				y;
	int				y_max;
	struct winsize	sz;
	int				fd;
	t_param			*head;
	t_param			*tail;
}					t_data;

extern				t_data	*g_data;

void				sig_handler(int signo);
void				free_exit(void);

void				print_list(void);
void				print_selection(void);

/*
** move the cursor and select param
*/

int					select_param(long buffer);
int					move_cursor(long buffer);
void				move_right(void);
int					rm_param(long buffer);
void				get_curr_param(void);

/*
** get all required datas relative to the list and the terminal size
*/

void				param_by_line(void);
void				new_size_max(void);
void				get_coordinates(void);

/*
** termcaps functions
*/

int					apply_term_setting(int def);
struct termios		*get_term_setting(void);
void				exec_term_command(const char *code);
void				exec_term_command_p(const char *code, int p1, int p2);

/*
** list functions
*/

t_param				*mk_list(char **argv);
t_param				*get_tail(t_param *head);

#endif
