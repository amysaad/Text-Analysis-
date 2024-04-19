//
// Created by Amy Saad
//

#ifndef SOLUTION_TEXTMINER_H
#define SOLUTION_TEXTMINER_H

using namespace std;

#include <string>

const long MAX_WORDS = 10000; // ten thousand
const char DELIMITER = ' ';   // words separated by a space ' '

class TextMiner {
public:
    TextMiner(string newFilename);

    long   readFileIntoOneString();
    void   splitTextIntoWords();
    string findLongestWord();
    long   findNumberOfPalindromes();
    bool   isPalindrome(string aWord) const;

    short findNumberOfCapitalLetters();
    void removePunctuation();
    void keepHyphen();


    // getters
    string getFilename() const;
    string getAllText() const;
    long   getNumberOfLines() const;
    long   getNumberOfWords() const;
    string getLongestWord() const;
    long   getNumberOfPalindromes() const;
    short   numberOfCaps;

    void   printStats() const;


  private:
    bool   filenameKnown;       // true if we know the name of the filename
    bool   fileIsLoaded;        // true if we've read the lines in the file

    string filename;            // actual text filename opened, e.g., "mobyDick.txt"

    string allText;             // the entire text file stored as one string
    long   numberOfLines;       // number of lines in the original file

    string allWords[MAX_WORDS]; // allText (the entire file) stored as an array of words
    long   numberOfWords;       // 0 <= total number of words in the file <= MAX_WORDS

    long   numberOfPalindromes; // number of palindromes found in the file
    string longestWord;         // the word with the most letters in the entire text

}; // end class TextMiner


#endif //SOLUTION_TEXTMINER_H
