#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int id;
	int right_hand_id;
	int left_hand_id;
	long long last_eat_time;
	int meal_count;
	int is_full_flag;
	pthread_t philosopher;
	pthread_mutex_t philo_eating_mutex;
	struct s_table *table;
}			t_philo;

typedef struct s_table
{
	int die_check_flag;
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	long long simulation_start_time;
	t_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t write_text;
	pthread_mutex_t die_check_mutex;

}			t_table;

void		print_error1(char *str, t_table *table);
void print_error2(char *str,t_table *table, int counter);
void		print_error3(char *str, t_table *table);
void		print_error4(char *str,t_table *table, int last_mutex, int flag);
void 		print_error5(char *str, t_table *table, int counter);
int		check_arguments(t_table *table, int argc, char **argv);
long	ft_atol(const char *str);
void 	init_philos2(t_table *table, int i);
int 	init_mutexes2(t_table *table);
int		init(t_table *table, int argc, char **argv);
int		init_threads(t_table *table);
void		*philosophers_routine(void *philo);
long long	current_time(void);
long long	time_difference(long long sim_start_time, long long current_time);
int		start_simulation(t_table *table);
void		print_message(t_table *table, long long time_difference,
				int philosopher_id, char *str);
void		eating2(t_table *table, int philo_id);
void		wait(t_table *table, int time_to_x);
int	die_check(t_table *table);
void		time_to_die_check(t_philo *philo, long last_eat_time,
				long long current_time, long long time_to_die);
void		clear(t_table *table);
void		print_message2(t_table *table, long long time_difference,
				int philosopher_id, char *str);
int are_philos_full (t_table *table, int *flag);
void 	wait2(long time);

#endif