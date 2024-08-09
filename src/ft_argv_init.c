/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:28:24 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 16:26:27 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(char **parms)
{
	int	i;

	i = 0;
	while (parms[i])
		free(parms[i++]);
	free(parms);
}

int	ft_check_all_are_nums(char **parms)
{
	int	i;
	int	j;

	i = 0;
	while (parms[i])
	{
		j = 0;
		while (parms[i][j])
		{
			if (!ft_isdigit(parms[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char *argv[])
{
	char	**parms;

	if (argc == 2)
		parms = ft_split(argv[1], ' ');
	else
		parms = argv;
	if (ft_check_all_are_nums(parms) == -1)
	{
		ft_print_error("In parameters detected something more than digits!");
		if (argc == 2)
			ft_free(parms);
		return (-1);
	}
	if (argc == 2)
		ft_free(parms);
	return (1);
}
