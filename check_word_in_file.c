/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word_in_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:09:34 by upolat            #+#    #+#             */
/*   Updated: 2024/04/05 15:15:00 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wordle.h"

int	ft_strcmp(const char *str1, char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (1);
		if (*str2 > *str1)
			return (-1);
		str1++;
		str2++;
	}
	return (0);
}

int	check_word_in_file(const char *word)
{
	int		fd;
	char	buffer[MAX_WORD_LENGTH];
	ssize_t	bytes_read;
	ssize_t	i;
	int		offset;

	offset = 0;
	i = 0;
	fd = open("wordlist_guesses.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	// Read words from file and compare with the input word
	while ((bytes_read = read(fd, buffer, MAX_WORD_LENGTH)) > 0)
	{
		// Find the newline character and remove it if present
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				break ;
			}
			i++;
		}
		// Compare the input word with the word from file
		if (ft_strcmp(word, buffer) == 0)
		{
			close(fd);
			return (1);
		}
		// Move to the next word in the file
		offset += bytes_read;
		if (lseek(fd, offset, SEEK_SET) == -1)
		{
			perror("Error seeking file");
			close(fd);
			return (0);
		}
	}
	if (bytes_read == -1)
		perror("Error reading file");
	if (close(fd) == -1)
		perror("Error closing file");
	return (0); // Return 0 if word is not found in file
}
