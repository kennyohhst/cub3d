/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: code <code@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/02 14:14:43 by kkalika       #+#    #+#                 */
/*   Updated: 2024/02/16 12:09:59 by julius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	newline_break(char *str, size_t i, size_t len)
{
	while (i < len)
	{
		if (str[i] == '\n')
			if (str[i + 1] == '\n')
				exit(write(2, "error new_line_break\n", 22));
		i++;
	}
}

bool	the_one(char *str, size_t len)
{
	size_t	i;

	i = 1;
	while (i < len)
	{
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (str[i] != '1' && str[i] != '\t' && str[i] != ' ' && str[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

void	new_line_err_check(char *str, size_t i, size_t x)
{
	if (!str)
	{
		write(2, "empty file\n", 12);
		exit(1);
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (the_one(str + x, i))
				break ;
			x = i;
		}
		i++;
	}
	while (str[i] == '\n')
		i++;
	x = ft_strlen(str);
	while (str[--x] == '\n')
		;
	newline_break(str, i, x);
}


/**
 * @todo get_next_line kan NULL returnen bij MALLOC_ERROR dus je moet het beveiligen... strljoin ook ..  ft_split kan ook 0 return .... 
*/
char	**parse(char *map_input, t_god *data)
{
	int		fd;
	char	*temp_str;
	char	*str;
	char	**no_spaces_file;

	ft_bzero((void *)data, sizeof(t_god));
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
	new_line_err_check(str, 0, 0);
	no_spaces_file = ft_split(str, '\n');
	free(str);
	close(fd);
	if (dp_strlen(no_spaces_file) > 6)
		data->full_map = &no_spaces_file[6];
	return (no_spaces_file);
}
