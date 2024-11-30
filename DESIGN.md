# Homework 5: Design Document
    * author: *Arjun Taneja*
    * date: November 16 2024

# Function 1: score guess

For this function, I will iterate through both guess and secret and check their corresponding characters. If the index and the character both matches in both the strings, I will store "g" in that index of the result. If the character matches but the index does not, I will store "y" in the same index of the result array as the index of that character in the guess string. If neither the character nor the index match, I will store "x" in the result array for that character's position. At the end, I will iterate through my result. If all of the entries in the result array are "g" then I will return true otherwise I will return false.

# Function 2: valid guess

For this function, I will iterate through the vocabulary array of strings and compare each word with guess using strcmp. If the guess string matches with any string in the vocabulary array, I will return true. If the guess string does not match even after going over the whole vocabulary array, I will return false. To do this fast, I will try to sort the vocabulary array and use binary search to get a time complexity of O(logn).

# Function 3: load vocabulary

For this function, I will open the file using fopen and use fgets to read each word and use strdup to copy each word into a dynamically allocated array. I will keep using realloc to resize the array as needed. For each word, I will increment the word count in *num_words. At the end, after reading all words, I will close the file with fclose and return the array of strings.

# Function 4: free vocabulary

For this function, I will use a loop to iterate through the vocabulary array and free each string using free(). After this, I will also free the array of pointers itself.
