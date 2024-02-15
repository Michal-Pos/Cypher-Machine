# Task Description
Write a C program that encrypts and decrypts text using the method described below. The text to be encrypted is assumed as follows. The text consists of the following characters, divided into 3 groups:
1. Latin uppercase letters: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.
2. Punctuation marks: '.,?' (period, comma, question mark), space, and newline character '\n'.
3. All other characters (they are ignored).

The cipher requires entering a key k, which is a natural number smaller than the number of letters in group (1). Encryption involves replacing each character from group 1 with the character occurring k places further in the alphabetical order, with the condition that if we go beyond the alphabet range, we start over, i.e., after 'Z' we go to 'ABC...'. Additionally, we reverse the order of letters in each word. 
We assume that words are groups of letters (1), separated by characters from group (2). We do not change characters from group (2) in any way; we copy them into the encoded text. The remaining characters (group 3) are ignored. Regardless of whether they are in the middle of a word or between words, we treat them as if they were not there at all, and in particular, they do not affect the division of the text into words or are included in the encrypted content.
The text to be encrypted is read from a file, and the encrypted text is saved to another file. The same applies to the decryption procedure.
The program should allow input from the keyboard for:
- the name of the input file,
- the name of the output file,
- the operation to be performed (encrypting or decrypting the file),
- the key k.
Assume that the names of input and output files do not contain whitespace characters (spaces, tabs, end-of-line characters, etc.), i.e., they are compatible with the %s format of the scanf function. Furthermore, they are not longer than 300 characters. We also assume that words in the text to be encrypted/decrypted consist of no more than 30 letters.
The program can only use the following libraries: math.h, stdio.h, stdlib.h, string.h (in the case of C++: cmath, cstdlib, cstring, fstream, iostream).
