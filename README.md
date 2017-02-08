# Regex

To Compile:
gcc -std=c99 -o grep grep.c io.c regex.c -D_GNU_SOURCE

Usage:
echo [text] | ./grep [regex_expression]

Notes:

We have implemented the regex special characters
. - Matches any character
* - Matches multiple of previous symbol (optional)
+ - Matches multiple of previous symbol (requires once)
[abc] - Matches any characters within brackets

We have also implemented escaping of special characters.


