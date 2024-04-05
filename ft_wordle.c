/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:59:02 by upolat            #+#    #+#             */
/*   Updated: 2024/04/05 15:15:35 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wordle.h"

void	ft_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_alphabet(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 26)
	{
		printf("\033[1m");
		printf("\033[0m");
		if (arr[i] == 3)
			printf("\033[1;32m");
		if (arr[i] == 2)
			printf("\033[1;31m");
		if (arr[i] == 1)
		{
			printf(" ");
			i++;
			continue ;
		}
		c = i + 'a';
		printf("%c", c);
		i++;
	}
	printf("\033[1m");
	printf("\033[0m");
	printf("\n");
}

int	main(void)
{
	int		i;
	int		j;
	int		c;
	int		guess_counter;
	char	guess[6];
	int		alphabet[26];
	char	*word;
	char	temp[6] = {'B', 'B', 'B', 'B', 'B', '\0'};
	int		blocker[6] = {1, 1, 1, 1, 1, 1};

	word = get_random_word("wordlist_answers.txt");
	i = 0;
	while (i < 26)
	{
		alphabet[i] = 0;
		i++;
	}
	i = 0;
	guess_counter = 1;
	printf("\033[1m");
	printf("\033[0m");
	printf("\nWelcome to ");
	printf("\033[1;32m");
	printf("ft_wordle!\n\n");
	printf("\033[1m");
	printf("\033[0m");
	while (guess_counter <= 6)
	{
		while (1)
		{
			printf("Enter your guess #%d:\n", guess_counter);
			scanf("%5s", guess);
			while ((c = getchar()) != '\n' && c != EOF);
			if (ft_strlen(guess) == 5)
			{
				ft_lowercase(guess);
				if (check_word_in_file(guess))
					break ;
				else
					printf("%s is not a valid guess.\n", guess);
			}
			else
				printf("Please enter a 5-letter word.\n");
		}
		i = 0;
		while (guess[i] != '\0')
		{
			if (guess[i] == word[i])
			{
				temp[i] = 'G';
				blocker[i] = 0;
				alphabet[guess[i] - 'a'] = 3;
			}
			//printf("%d", blocker[i]);
			i++;
		}
		//printf("\n");
		i = 0;
		while (guess[i] != '\0')
		{
			j = 0;
			while (word[j] != '\0')
			{
				if (guess[i] == word[j] && blocker[j] != 0 && temp[i] != 'G')
				{
					temp[i] = 'Y';
					blocker[j] = 0;
					if (alphabet[guess[i] - 'a'] < 3)
						alphabet[guess[i] - 'a'] = 2;
					//printf("%d", blocker[j]);
					break ;
				}
				else
				{
					if (alphabet[guess[i] - 'a'] < 2)
						alphabet[guess[i] - 'a'] = 1;
				}
				//printf("%d", blocker[j]);
				j++;
			}
			//printf("\n");
			i++;
		}
		i = 0;
		j = 0;
		while (guess[i] != '\0')
		{
			if (temp[i] == 'G')
			{
				printf("\033[1;32m");
				j++;
			}
			else if (temp[i] == 'Y')
				printf("\033[1;31m");
			printf("%c", guess[i]);
			printf("\033[1m");
			printf("\033[0m");
			i++;
		}
		if (j == 5)
		{
			printf("\nCongrats, that's the word!\n");
			return (1);
		}
		i = 0;
		while (i < 5)
		{
			temp[i] = 'B';
			blocker[i] = 1;
			i++;
		}
		temp[i] = '\0';
		blocker[i] = 1;
		printf("\n");
		print_alphabet(alphabet);
		guess_counter++;
	}
	printf("\nThe word was: ");
	printf("\033[1;32m");
	printf("%s\n", word);
	return (1);
}
