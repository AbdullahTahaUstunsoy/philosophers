#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (argc != 5 && argc != 6)
	{
		print_error1("Wrong amount of arguments!",table);
		return (1);
	}
	if (!(check_arguments(table,argc, argv)))
		return (1);
	if (!(init(table, argc, argv)))
		return (1);
	if(!start_simulation(table))
	{
		clear(table);
		return (1);
	}
	return 0;
}