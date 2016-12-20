# cs368_p5

Description
Wrote a program that searches for occurrences of given word within a given file.

The findWord program
The findWord program does the following:

Read in a word and the name of a file from the command line. A word is any sequence of non-whitespace characters.
If the file does not exist or cannot be opened, an error message should be given and the program should stop.
Otherwise the program should seach the file, line by line, for occurrences of the given word. An occurrence is any time the exact 
sequence of characters in the word appears. For example, there is one occurence of "the" in "therefore" and no occurrences of "the" in 
"with everyone". Capitalization also matters, i.e., "the" does not occur in "The quick brown fox".
For each line in which the given word occurs, the program prints out the entire line preceded by the line number 
After processing the entire file, the program should report the total number of occurrences of the given word within the file.
