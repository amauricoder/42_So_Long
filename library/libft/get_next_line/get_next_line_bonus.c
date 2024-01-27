/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:49:08 by aconceic          #+#    #+#             */
/*   Updated: 2023/11/21 09:06:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*extract_excedent(char *stash)
{
	int		i;
	char	*extract_line;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i ++;
	if (ft_strchr(stash, '\n'))
		i ++;
	extract_line = ft_calloc(sizeof(char), i + 1);
	if (!extract_line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		extract_line[i] = stash[i];
		i ++;
	}
	if (stash[i] == '\n')
		extract_line[i++] = '\n';
	extract_line[i] = '\0';
	return (extract_line);
}

char	*update_stash(char *old_stash)
{
	int		i;
	int		j;
	int		len;
	char	*stash_update;

	i = 0;
	while (old_stash[i] != '\0' && old_stash[i] != '\n')
		i++;
	if (!old_stash || !ft_strchr(old_stash, '\n'))
	{
		free(old_stash);
		return (NULL);
	}
	len = ft_strlen(&old_stash[i] + 1);
	stash_update = ft_calloc(sizeof(char), len + 1);
	if (!stash_update)
		return (NULL);
	j = 0;
	i++;
	while (old_stash[i] != '\0')
		stash_update[j++] = old_stash[i++];
	stash_update[j] = '\0';
	free(old_stash);
	return (stash_update);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_excedent(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		i;
	char	*variable;
	char	*variable2;
	char	*variable3;
	
	i = 0;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	
	//fd linha 1
	variable = get_next_line(fd);
	printf("%s\n", variable);
	free(variable);
	
	//fd2 linha 1
	variable2 = get_next_line(fd2);
	printf("%s\n", variable2);
	free(variable2);
	
	//fd3 linha 1
	variable3 = get_next_line(fd3);
	printf("%s\n", variable3);
	free(variable3);
	
	//fd linha 2
	variable = get_next_line(fd);
	printf("%s\n", variable);
	free(variable);

	//fd2 linha 2
	variable2 = get_next_line(fd2);
	printf("%s\n", variable2);
	free(variable2);
	
	//fd3 linha 2
	variable3 = get_next_line(fd3);
	printf("%s\n", variable3);
	free(variable3);
	//close open
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}*/
