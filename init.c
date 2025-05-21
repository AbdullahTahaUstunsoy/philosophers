#include "philo.h"

int	init_threads(t_table *table)
{
	int	i;
	int counter;

	i = -1;
	counter = 0;
	while (++i < table->number_of_philosophers)
	{
		if (pthread_create(&table->philo[i].philosopher, NULL, philosophers_routine,
				(void *)&table->philo[i]))
			{
				print_error5("Philo creation error\n",table,counter);
				return (0);
			}
			usleep(50);
			counter++;
	}
	return (1);
}
	
static void	init_table(t_table *table, int argc, char **argv)
{
	table->die_check_flag = 0;
	table->number_of_philosophers = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		table->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
}
static int	init_philos(t_table *table)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	table->philo = (t_philo *)malloc(sizeof(t_philo)
			* (table->number_of_philosophers));
	if (table->philo == NULL)
	{
		print_error1("Can not be allocated for philos\n",table);
		return (0);
	}
	while (i < table->number_of_philosophers)
	{
		init_philos2(table,i);
		if (pthread_mutex_init(&table->philo[i].philo_eating_mutex,NULL))
		{
			print_error2("Mutex init error\n",table,counter);
			return (0);
		}
		counter++;
		i++;
	}
	return (1);
}

static int	init_mutexes1(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t)
	* table->number_of_philosophers);
	if (table->forks == NULL)
	{
		print_error3("Couldn't be allocated for forks\n",table);
		return (0);
	}
	if (!init_mutexes2(table))
		return (0);
	return (1);
}

int	init(t_table *table, int argc, char **argv)
{
	init_table(table, argc, argv);
	if (!init_philos(table))
		return (0);
	if(!init_mutexes1(table))
		return (0);
	return (1);
}