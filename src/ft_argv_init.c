/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/09/04 23:53:22 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//			Checking for duplicates in argv[]  or parms
static int	ft_check_for_duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

//			Checking if all of arguments are numbers
static int	ft_isnumerical(char *c)
{
	int	index;

	index = 0;
	if (c[0] == '-')
		index++;
	while (c[index])
	{
		if (!ft_isdigit(c[index]))
			return (0);
		index++;
	}
	return (1);
}

static int ft_checker(char **parms, int tmp, int i, int malloc)
{
	if (!ft_isnumerical(parms[i]))
		return (ft_print_error("Error\n", parms, malloc), 1);
	if (ft_check_for_duplicates(tmp, parms, i))
		return (ft_print_error("Error\n", parms, malloc), 1);
	if (tmp < -2147483648 || tmp > 2147483647)
		return (ft_print_error("Error\n", parms, malloc), 1);
	return (0);
}

/*
		Checking if provided parameters meet the requirements
		There are 2 ways parameters can be passed to program:
			- as an string
			- as a separate arguments
		If they are passed as separate arguments we avoid using malloc

		We are checking for:
			- if arguments is numerical
			- if there are duplicates
			- if number is contained within INT
*/
void	ft_parse_parameters(int argc, char **argv)
{
	int		i;
	int		malloc;
	long	tmp;
	char	**parms;

	i = 0;
	if (argc == 2)
		parms = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		parms = argv;
	}
	if (argc == 2)
		malloc = 1;
	else
		malloc = 0;
	while (parms[i])
	{
		tmp = ft_atoi(parms[i]);
		ft_checker(parms, tmp, i, malloc);
		i++;
	}
	if (argc == 2)
		ft_free(parms);
}
