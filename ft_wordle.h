/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:54:48 by upolat            #+#    #+#             */
/*   Updated: 2024/04/05 14:58:59 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WORDLE_H
# define FT_WORDLE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <string.h>

# define MAX_WORD_LENGTH 6

char	*get_random_word(const char *filename);
int		check_word_in_file(const char *word);
int		ft_strcmp(const char *str1, char *str2);
void	ft_lowercase(char *str);
int		ft_strlen(char *str);
void	print_alphabet(int *arr);

#endif
