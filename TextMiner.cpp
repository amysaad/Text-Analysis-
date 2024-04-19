//
// Created by Mark LeBlanc on 10/17/21.
//
#include <iostream>
#include <fstream>
#include <sstream>

#include <assert.h>


#include "TextMiner.h"



TextMiner::TextMiner(string newFilename) {
    filename      = newFilename;
    filenameKnown = true;
    fileIsLoaded  = false;

    longestWord         = "";
    allText             = "";
    numberOfLines       = 0;
    numberOfPalindromes = 0;
    numberOfWords       = 0;

}


// ------- OBJECT's can do: ACTIONS/BEHAVIORS ----------------------------
// -----------------------------------------------------------------------------------------
long TextMiner::readFileIntoOneString() {
    // SUMMARY: open and read lines from a file of text; save in one big string, allText
    // PRE: filenameKnown is true (we know the filename to open)
    // POST: private member allText stores the entire file as one string,
    //       private member numberOfLines set to number of successfully read input lines,
    //       private member fileIsLoaded set to true on success, false otherwise,
    //       and RETURNS the number of lines in the original file
    assert(filenameKnown == true);

    numberOfLines = 0;

    ifstream FIN;
    FIN.open( filename.c_str() );

    if ( FIN.is_open() ) {
        string theText;
        string line;

        getline(FIN, line);
        theText = line;
        while (FIN) // while we are NOT at the End Of the File (EOF)
        {

            if (numberOfLines == 0)
                theText = line;
            else {
                //cout << line << endl;
                theText = theText + DELIMITER + line;
            }
            numberOfLines++;

            // get the next line, if any more
            getline(FIN, line);
        }
        FIN.close();

        // save the entire text into the object
        allText = theText;
    }
    else {
        cout << "File" << filename << " did NOT open." << endl;
        fileIsLoaded = false;
    }

    if (numberOfLines > 0)
        fileIsLoaded = true;

    return numberOfLines;
} // end method: TextMiner::readFileIntoOneString()


void TextMiner::splitTextIntoWords() {
    // PRE: fileIsLoaded is true (we have read the file lines into one string already)
    // POST: private member array allWords[] holds each individual word
    assert(fileIsLoaded == true);

    string nextWord;

    long i=0;

    istringstream wordsAsStream(allText);
    while (getline(wordsAsStream, nextWord, DELIMITER)) {
        //cout << nextWord << endl;
        // trap empty length "words"
        if (nextWord.length() != 0) {
            allWords[i] = nextWord;
            i++;
        }
    } // while more words to split up
    numberOfWords = i;

}

string TextMiner::findLongestWord() {

    // PRE: fileIsLoaded is true, assigned the longest word at index 0.
    // POST: Will return the longest word found in the text.

    assert(fileIsLoaded == true);

    longestWord = allWords[0];

    for(short i = 1; i < numberOfWords; i++){
        if(allWords[i].length() > longestWord.length()) {
            longestWord = allWords[i];
        }
    }
    return longestWord;
}

bool TextMiner::isPalindrome(std::string aWord) const {

    // PRE: fileIsLoaded is true
    // POST: Checks if the word is a palindrome and will return a bool of True (YES) or False (NO).

    assert(fileIsLoaded == true);

    short l = aWord.length();

    for (short i = 0; i < aWord.length()/2; i++)
        if (aWord[i] != aWord[l - i-1])
            return false;
    return true;
}

long TextMiner::findNumberOfPalindromes() {

    // PRE: fileIsLoaded is true, variable count initiated at 0.
    // POST: It uses the isPalindrome() method to confirm if it is a Palindrome then will count the number of Palindromes and will return the number of Palindromes.

    assert(fileIsLoaded == true);

    long c = 0;

    for(short i = 0; i < numberOfWords; i++){
        if(isPalindrome(allWords[i])){
            c++;
            numberOfPalindromes = c;
        }
    }
    return numberOfPalindromes;
}

short TextMiner::findNumberOfCapitalLetters(){

    // PRE: fileIsLoaded is true, variable upper initiated at 0.
    // POST: The Loop will go through the array and use the isupper() function to check the entire text and count the
    // number of capital letters and store it into the variable initiated before the loop; upper and returns the number
    // of capital letters.

    assert(fileIsLoaded == true);

    short upper = 0;

    for (short i = 0; i < allText.length(); i++) {
        if (isupper(allText[i]))
            upper++;
        numberOfCaps = upper;
    }
    return numberOfCaps;
}

void TextMiner::removePunctuation() {

    // PRE: fileIsLoaded is true
    // POST: The Loop checks the text for any punctuation using the ispunct() function; no return (void function).


    assert(fileIsLoaded == true);

    for(short i = 0; i < allText.size(); i++){
        if(ispunct(allText[i])){
            allText.erase(i--, 1);
        }
    }
}

void TextMiner::keepHyphen(){

    assert(fileIsLoaded == true);

    for(short i = 0; i < numberOfWords; i++)

        string a = allWords[i];

}

void TextMiner::printStats() const {
    if (fileIsLoaded) {
        cout << endl;
        cout << "---- File STATS -----------------------------------------------" << endl;
        cout << "Filename:              " << filename << endl;
        cout << "Number of lines:       " << numberOfLines << endl;
        cout << "Number of words:       " << numberOfWords << endl;
        cout << "Longest word:          " << longestWord << " (" << longestWord.length() << " letters)" << endl;
        cout << "Number of palindromes: " << numberOfPalindromes << endl;
        cout << "Number of capital letters: " << numberOfCaps << endl;
        cout << "---------------------------------------------------------------" << endl;
    } else {
        cout << "No Stats yet; file: " << filename << " has not been loaded. (call readFileIntoOneString() )." << endl;
    }

} // end printStats()

// ------- GETTERS ----------------------------
string TextMiner::getFilename() const {
    return filename;
}
string TextMiner::getAllText() const {
    return allText;
}
long TextMiner::getNumberOfLines() const {
    return numberOfLines;
}
long TextMiner::getNumberOfWords() const {
    return numberOfWords;
}
string TextMiner::getLongestWord() const {
    return longestWord;
}
long TextMiner::getNumberOfPalindromes() const {
    return numberOfPalindromes;
}

