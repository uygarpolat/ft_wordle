/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:11:31 by upolat            #+#    #+#             */
/*   Updated: 2024/04/05 15:14:40 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wordle.h"

char	*get_random_word(const char *filename)
{
	int			fd;
	char		buffer[MAX_WORD_LENGTH];
	static char	word[MAX_WORD_LENGTH];
	int			word_count;
	int			random_word_index;
	int			i;

	i = 0;
	word_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while (read(fd, buffer, MAX_WORD_LENGTH) > 0)
		word_count++;
	srand(time(NULL));
	random_word_index = rand() % word_count;
	lseek(fd, 0, SEEK_SET); // Reset file pointer to the beginning of the file
	// Read words until you reach the selected word
	while (i < random_word_index)
	{
		read(fd, buffer, MAX_WORD_LENGTH);
		i++;
	}
	read(fd, buffer, MAX_WORD_LENGTH); // Read the word that is chosen by the random number generator
	close(fd);
	i = 0;
	while (i < MAX_WORD_LENGTH)
	{
		if (buffer[i] == '\n')
		{
			word[i] = '\0';
			break ;
		}
		word[i] = buffer[i];
		i++;
	}
	return (word);
}
