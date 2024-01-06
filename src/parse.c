/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalika <kkalika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:14:43 by kkalika           #+#    #+#             */
/*   Updated: 2024/01/05 19:35:50 by kkalika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

size_t	void_lines(char *str)
{
	size_t	i;
	size_t	oops;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	oops = i;
	while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] != '\n'))
	{
		if (str[i] == '1' || str[i] == '0')
		{
			i = oops - 1;
			break ;
		}
		i++;
	}
	return (i);
}

int	raw_map_new_line_err(char *str, size_t len)
{
	size_t	i;

	i = void_lines(str);
	while (str[i++] && i < len)
	{
		if (str[i] == '\n' && i < len)
		{
			if (str[i + 1] == ' ' || str[i + 1] == '	')
			{
				if (!check_line(str + i + 1))
					return (0);
			}
			else if (str[i + 1] == '\n')
				return (0);
		}
	}
	return (1);
}

void	new_line_err_check(char *str)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(str);
	while (str[i] && str[i--] != '1' && str[i] != '0')
		;
	len = i;
	while (str[i] && str[i] != 'F' && str[i] != 'C' 
		&& str[i] != 'O' && str[i] != 'E' && str[i--] != 'A')
		;
	while (str[i] && str[i++] != '\n')
		;
	if (!raw_map_new_line_err(str + i, len))
		exit(write(2, "error lines\n", 13));
}

char	**parse(char *map_input, t_god *data, char ***temp)
{
	int		fd;
	char	*temp_str;
	char	*str;
	char	**no_spaces_file;
	(void)  temp;

	ft_bzero((void *) data, sizeof(t_god));
	str = NULL;
	fd = open(map_input, O_RDONLY);
	if (fd < 0)
		exit(write(2, "Error\nfd\n", 9));
	temp_str = get_next_line(fd);
	while (temp_str)
	{
		str = strljoin(str, temp_str, ft_strlen(temp_str), 0);
		free(temp_str);
		temp_str = get_next_line(fd);
	}
	new_line_err_check(str);
	no_spaces_file = ft_split(str, '\n');
	// (*temp) = ft_split(str, '\n');
	free(str);
	close(fd);
	if (dp_strlen(no_spaces_file) > 6)
		data->full_map = &no_spaces_file[6];
	return (no_spaces_file);
}
