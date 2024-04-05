A simple wordle game that you can play in terminal.

How to start:
1. Clone the repository with ```git clone https://github.com/uygarpolat/ft_wordle.git ft_wordle```
2. Go to game directory with ```cd ft_wordle```
3. Compile it with ```make```
4. Run the game with ```./wordle.out```

How to play:
1. Standard Wordle rules apply.
2. Matches in correct locations are indicated by green.
3. Matches in incorrect locations are indicated by red.
4. Guessed letters disappear from the alphabet, unless they are a match, in which case they are colored according to the most recent guess.
5. If you enter a guess that has more than 5 characters, the first 5 characters are accepted.
