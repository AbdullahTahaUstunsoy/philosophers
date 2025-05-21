#include "philo.h"

static int	is_number(char *str)
{
	int	flag_for_minus;
	int	is_digit_flag;

	flag_for_minus = 0;
	is_digit_flag = 0;	
	while (*str)
	{
		if (*str == '+')
			str++;
		if (*str == '-' && flag_for_minus == 0)
		{
			str++;
			flag_for_minus = 1;
		}
		if ((*str < 48 || *str > 57) && is_digit_flag == 0)
		{
			is_digit_flag = 1;
		}
		str++;
	}
	if (is_digit_flag == 1 || flag_for_minus == 1)
		return (0);
	return (1);
}


static int	is_valid(int argc, char **argv)
{
	int	is_valid_flag;

	is_valid_flag = 1;
	if (argc == 5)
	{
		if (ft_atol(argv[1]) < 0 || ft_atol(argv[2]) < 0 || ft_atol(argv[3]) < 0 || ft_atol(argv[4]) < 0)
			is_valid_flag = 0;
	}
	if (argc == 6)
	{
		if (ft_atol(argv[5]) <= 0)
			is_valid_flag = 0;
	}
	return (is_valid_flag);
}

static int one_philo(t_table *table,char **argv)
{
	if (ft_atol(argv[1]) == 1)
	{
		long long start_time;
		long long time_diff;
		
		start_time = current_time();
		printf("%d %d %s\n",0, 1, "has taken a fork");
		wait2(ft_atol(argv[2]));
		time_diff = current_time() - start_time;
		printf("%lld %d %s\n",time_diff,1,"is died");
		free(table);
		return (0);
	}
	return (1);
}
int	check_arguments(t_table *table, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_number(argv[i]) == 0)
		{
			print_error1("Please enter valid arguments",table);
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (is_valid(argc, argv) == 0)
		{
			print_error1("Please enter valid arguments",table);
			return (0);
		}
		i++;
	}
	if (!one_philo(table,argv))
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long number;

	number = 0;
	while (!str && (*str == 32 || *str == 9))
		str++;
	if (*str == '-')
		str++;
	if (*str == '+')
		str++;
	while (*str)
	{
		number = ((number * 10) + (*str - '0'));
		str++;
	}
	return (number);
}
