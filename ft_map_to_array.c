/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:47:25 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/06 15:11:15 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_size(int arg)
{
	int fd;
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
	}
	return (i);
}

int		**map_to_array(int arg)
{
	int **array;
	int i;
	int j;
	
	int fd;
	char *line;
	i = 0;
	fd = open(arg, O_RDONLY);
	array = (int **)malloc(sizeof(int *) * ft_size(arg));
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		j = strlen(line) - 1;
		array[i] = (int *)malloc(sizeof(int) * j);
		while (j >= 0)
		{
			array[i][j] = ft_atoi(ft_strsplit(line)[j]);
			j--;
		}
		free(line);
		i++;
	}
	close(fd);
	return (array);
}

int		main(int ac, char **av)
{
	int **array;

	array = map_to_array(av[i]);
	return (0);
}
