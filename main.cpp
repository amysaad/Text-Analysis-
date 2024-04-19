#include <iostream>
#include <string>

using namespace std;

#include "TextMiner.h"


int main() {

    string fileToTry = "text1.txt";

   TextMiner T(fileToTry);

    long numLinesRead;

   numLinesRead = T.readFileIntoOneString();

   if (numLinesRead > 0) {
       // LOAD FILE
       cout << ".... LOADING " << T.getFilename() << " .............." << endl;
       cout << "   " << T.getFilename() << " READ with " << numLinesRead << " lines read." << endl;

       // TOKENIZE
       T.splitTextIntoWords();

       cout << "   " << T.getFilename() << " TOKENIZED and has " << T.getNumberOfWords() << " words." << endl;

       cout << "   " << T.getFilename() << " Number of Capital Letters is: " << T.findNumberOfCapitalLetters() << endl;

       T.removePunctuation();

       // LONGEST WORD
       string longestWord;
       longestWord = T.findLongestWord();
       cout << "   " << T.getFilename() << " longest word: " << longestWord << " (length = " << longestWord.length() << ")." << endl;

       // LOOKING FOR PALINDROMES
       string testWord = "racecar";
       if (T.isPalindrome(testWord))
           cout << "   "  << "YES " << testWord << " is a PALindrome." << endl;
       else
           cout << "   "  << "NO " << testWord << " is NOT a PALindrome." << endl;

       long  nPals;
       nPals = T.findNumberOfPalindromes( );
       cout << "   "  << T.getFilename() << " has " << nPals << " palindromes." << endl;


       // PRINT THE FILE STATS
       T.printStats();

   } // end file opened OK

   else {
        cout << T.getFilename() << ": NO LINES from the file were READ (??)." << endl;
   }


    cout << endl << endl << "Done." << endl;
    return 0;
} // end main()
