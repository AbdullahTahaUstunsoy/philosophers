#include "philo.h"

int	start_simulation(t_table *table)
{
	table->simulation_start_time = current_time();
	if(!init_threads(table))
		return (0);
	if(!die_check(table))
		return (0);
	return (1);
}
static int check_philo_death(t_table *table, int *i)
{
	long long now;
	long long last_eat;
	int inx = *i;
	now = current_time();

	pthread_mutex_lock(&table->philo[inx].philo_eating_mutex);
	last_eat = table->philo[inx].last_eat_time;
	pthread_mutex_unlock(&table->philo[inx].philo_eating_mutex);

	if (now - last_eat > table->time_to_die)
	{
		pthread_mutex_lock(&table->die_check_mutex);
		if(table->die_check_flag == 0)
		{
			table->die_check_flag = 1;
			print_message2(table,
				time_difference(table->simulation_start_time, now),
				table->philo[inx].id, "is died");

		}
		pthread_mutex_unlock(&table->die_check_mutex);
		return (1);
	}
	return (0);
}
static void	check_meal_count(t_table *table, int i, int *are_all_philo_full)
{	
	pthread_mutex_lock(&table->philo[i].philo_eating_mutex);
	if (*are_all_philo_full && 
		table->philo[i].meal_count < table->number_of_times_each_philosopher_must_eat)
		*are_all_philo_full = 0;
	pthread_mutex_unlock(&table->philo[i].philo_eating_mutex);
}
static int	is_6th_argument_exist(t_table *table)
{
	if (table->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	return (1);
}
int	die_check(t_table *table)
{
	int i;
	int are_all_philo_full;

	while (1)
	{
		i = -1;
		are_all_philo_full = is_6th_argument_exist(table);
		pthread_mutex_lock(&table->die_check_mutex);
		if (table->die_check_flag)
		{
			pthread_mutex_unlock(&table->die_check_mutex);
			return (0);
		}
		pthread_mutex_unlock(&table->die_check_mutex);
		while (++i < table->number_of_philosophers)
		{
			if (check_philo_death(table,&i))
				return (0);
			check_meal_count(table,i,&are_all_philo_full);
		}
		if (are_philos_full(table,&are_all_philo_full))
			return (0);
		usleep(100);
	}
	return (1);
}