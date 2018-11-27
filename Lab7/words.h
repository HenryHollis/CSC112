/**
 * These are my function declarations.
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.1, 2018
 */

#ifndef WORDS_H
#define WORDS_H

#include <iostream>


#define MAX_STRING_SIZE 20
using namespace std;

//=== data type to store a word and its count ==================
struct wordFreq{
char word[MAX_STRING_SIZE];  // the word
int count;              	 // the word frequency

wordFreq(){word[0] = '\0'; count = 0;}  // constructor for the WordFreq type , just a good idea ...

};
bool inCorrectNumArgs(int argc);
bool inFilesFailed(char fileName[]);
bool outFileFailed(char outPut[]);
void ReadWords(char fileName[], wordFreq *& list, int &num);
void removeStopWords(char stopText[], wordFreq*& list, int &num);
void outPutResults(wordFreq* list, char arg1[], char arg2[], char arg3[], int num);
void addWordToList(char str[], wordFreq*& list, int& num);
int search(char str[], wordFreq list[], int num);
void insertionSorter(wordFreq list[], int num);
ostream& operator<<(ostream & out, const wordFreq& list);
bool operator==(const wordFreq& lhs, const wordFreq& rhs);
bool operator>(const wordFreq& lhs, const wordFreq& rhs);


#endif