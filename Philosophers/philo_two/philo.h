/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/22 00:35:52 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include "./libft/libft.h"

# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

# define ONE_MILLISEC 	1000

typedef struct		s_state
{
	unsigned int	n_philo;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	unsigned int	n_must_eat;
	unsigned int	eat_count;
	uint64_t		t_start_usec;
	uint64_t		t_start_sec;
	bool			meals;
	bool			option;
	bool			philo_dead;
}					t_state;

typedef	struct		s_data
{
	struct s_state	*state;
	struct s_philo	*philo;
}					t_data;

/*
** Function for all Philo
*/
int					parsing_manager(t_state *state);
int					data_manager(int ac, char **av, t_state *state);
int					check_argument(int ac, char **av, int *prog_arg);
unsigned int		get_time(unsigned int start_usec, unsigned int start_sec);
int					error_status(char *message);
int64_t				ft_atoi64(const char *str);
uint64_t			ft_atou64(const char *str);

#endif
