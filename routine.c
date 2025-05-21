#include "philo.h"


static void	eating(t_table *table, int philo_id)
{
	if (philo_id % 2 == 0)
	{
		pthread_mutex_lock(&(table->forks[table->philo[philo_id].right_hand_id]));
		print_message(table, time_difference(table->simulation_start_time,
				current_time()), philo_id, "has taken a fork");
		pthread_mutex_lock(&(table->forks[table->philo[philo_id].left_hand_id]));
		print_message(table, time_difference(table->simulation_start_time,
				current_time()), philo_id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(table->forks[table->philo[philo_id].left_hand_id]));
		print_message(table, time_difference(table->simulation_start_time,
				current_time()), philo_id, "has taken a fork");
		pthread_mutex_lock(&(table->forks[table->philo[philo_id].right_hand_id]));
		print_message(table, time_difference(table->simulation_start_time,
				current_time()), philo_id, "has taken a fork");
	}
	print_message(table, time_difference(table->simulation_start_time,
		current_time()), philo_id, "is eating");
		eating2(table,philo_id);
		wait(table, table->time_to_eat);
	pthread_mutex_unlock(&(table->forks[table->philo[philo_id].left_hand_id]));
	pthread_mutex_unlock(&(table->forks[table->philo[philo_id].right_hand_id]));
}

static void	sleeping(t_table *table, int philo_id)
{
	wait(table, table->time_to_sleep);
	print_message(table, time_difference(table->simulation_start_time,
		current_time()), philo_id, "is sleeping");
}

static void	thinking(t_table *table, int philo_id)
{
	print_message(table, time_difference(table->simulation_start_time,
			current_time()), philo_id, "is thinking");
}
void	*philosophers_routine(void *philo)
{
	t_philo	*philosopher;
	int should_continue;
		
	philosopher = (t_philo *)philo;
	should_continue = 1;
	while (should_continue)
	{
		pthread_mutex_lock(&philosopher->table->die_check_mutex);
		should_continue = !philosopher->table->die_check_flag;
		pthread_mutex_unlock(&philosopher->table->die_check_mutex);
		if (!should_continue)
			break;
		eating(philosopher->table, philosopher->id);
		sleeping(philosopher->table, philosopher->id);
		thinking(philosopher->table, philosopher->id);
	}
	return (void*)(0);
}