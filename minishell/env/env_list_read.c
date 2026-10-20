/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:17:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/05/15 19:27:09 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*env_get(char *name, t_data	*data)
{
	t_env	*i;

	if (name && data && *name != '\0')
	{
		i = data->env;
		while (i)
		{
			if (_str_n_equal(i->name, name, _strlen(name) + 1))
				return (i);
			i = i->next;
		}
	}
	return (NULL);
}
