/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:50:23 by estrong           #+#    #+#             */
/*   Updated: 2022/06/04 14:32:08 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;

	if (ac != 1)
	{
		ft_putstr_fd("Myshell $ ", 1);
		ft_putstr_fd("no such file or directory", 1);
	}
	envp_to_lst(envp);
	while (1)
	{
		str = readline(SHCL"Myshell $ ");
		if (!str)
			return (0);
		else
			add_history(str);	// ???
		
	}
}