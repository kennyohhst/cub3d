/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:59:46 by kkalika           #+#    #+#             */
/*   Updated: 2023/12/02 15:14:05 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    test_parse_data(t_god *data)
{
    t_god   *temp;
	int		i;

	i = 0;
    if (!data)
	{
		write(1, "Data is empty\n", 15);
        return ;
	}
    temp = data;
    while (temp->full_map[i])
    {
		printf("%s\n", temp->full_map[i++]);			
		// printf("%", );		
		// printf("%", );		
		// printf("%", );			
    }
	printf("%d\n", temp->line_number_texture_path);		
	printf("%d\n", temp->line_number_c_f);		
	printf("%d\n", temp->line_number_map);		

}