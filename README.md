# Cypher Machine
The goal is to design a program to cypher and decypher text containing characters from 3 groups:
1. Latin capital letters: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
2. Punctuation characters '.,?' and newline character '\n'
3. Other characters (they will be ignored)

Cypher reqires providing key *k*, which is a natural number smaller than number of characters in (1.).

## Cyphering
Cyphering changes all character from group (1) to a character that occures *k*-place further in group (1), assuming that 'A' comes after 'Z'.
We don't change characters from group (2) and we ommit characters from group (3).

## Assumptions
- names of input and output files are compatible with ```%s``` format. Additionaly, they are not longer than 300 characters 
- words in the text are not longer than 300 characters
