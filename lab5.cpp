/**
* This program takes in a text file and counts the word frequency of said file.
* It then outputs the frquencey into another file. The user can then use 3rd party software to generate
* a wordcloud from this frequency file.
* 
* 
* 
* @author Henry Hollis { @literal < hollhc17@wfu.edu >}
* @version 0.1 , Oct.18, 2018

 */


#include <iostream>
#include <string.h>
#include <fstream>

#define MAX_STRING_SIZE 20    //maximum string size

#define MAX_LIST_SIZE 5000    // maximum word list size

using namespace std;

//=== data type to store a word and its count ==================
struct wordFreq{

wordFreq (){word[0] = '\0'; count = 0;}  // constructor for the WordFreq type , just a good idea ...


char word[MAX_STRING_SIZE];  // the word
int count = 0 ;              // the word frequency
};

void process(char fileName[], wordFreq list[], int& num);
bool isWord(char str[]);
void readFileName(char fileName[]);
void addWordToList(char str[], wordFreq list[], int& num);
int search(char str[], wordFreq list[], int num);
void insertionSorter(wordFreq list[], int num);
void fileWriter(wordFreq list[],int num);
ostream& operator<<(ostream & out, const wordFreq& list);


/**
 * @brief      Main Function, a great place to start
 *
 * @return     error code 0 if everything works
 */
int main(){
wordFreq list[MAX_LIST_SIZE];    // list of unique words
int num = 0;           			 //number of unique words

char fileName[MAX_STRING_SIZE];  //store input file name

process(fileName, list, num);    //send the file to be processed

insertionSorter(list, num);      //I sort the frequency of words so that the frq file is nice and orderly

fileWriter(list, num);           //Write to file

return 0;
}


/**
 * @brief      Reads in the file name from user input.
 *
 * @param      fileName  The file name
 */
void readFileName(char fileName[]){
int i = 0; 								// local counter
char ch; 								// a character from the keyboard
cout << "Enter the name of the file -> ";

										// read in characters until a space , newline , or out of room...
ch = cin.get();
	while( ch != '\n' && ch != ' ' && i < (MAX_STRING_SIZE - 1)){
		fileName[i] = ch;
		ch = cin.get();
		i++;
	}
 										// add null terminator to the end to make it an official C - string
fileName[i] = '\0';

}


/**
 * @brief      processes the file (sends words to other helper functions)
 *
 * @param      fileName  The file name
 * @param      list      The list of my wordFreq structs
 * @param      num       The logical size of list
 */
void process(char fileName[], wordFreq list[], int& num){
cout<<"Read text file"<<endl;

readFileName(fileName);					
fstream inFile(fileName, ios :: in); 	//fstream for file
if(inFile.fail()) 						//If I can't open the file, recall the method
	readFileName(fileName);

char str[MAX_STRING_SIZE]; // current string
int n; 					   // length of string
char ch ; 				   // current character

						   
str[0] = '\0';			   // adding the null term to make a propper c-string
						   
ch = inFile.get();		   // get a character from the file...

/* This "bigWordTrigger" was implemented because a word that was over 19 characters would be 
 * truncated and simply stored up to 19 characters. To combat this, when such a "big word" is encountered,
 * this bigWordTrigger is set to true. Note the "or" condition in the if statement @ line 124. The block runs
 * if it encounters a delineator or if the bigWordTrigger is true. In effect, this means I process the 
 * part of the big word that would have been simply truncated. Let me know if you can think of a more
 * clever way to solve the problem :P 
*/
bool bigWordTrigger = false;               // initally, trigger is not activated

while (!inFile.eof()){			           // loop through until the end of file
						        
	if (!isalpha(ch) || bigWordTrigger){   // if ch is word delineator, or the rest of a big word, we can classify the string
						        
		bigWordTrigger = false;            // reset my trigger switch
		if(isWord(str))			           // if string is a word, add to list
			addWordToList(str, list, num);

	    str[0] = '\0';			// reset the string
	}
	else{
								
		n = strlen(str);
		if(n < MAX_STRING_SIZE - 1){  // add new character to end of the string , if there is space
			str[n] = tolower(ch);
			str[n+1] = '\0';
		}
		else
			bigWordTrigger = true;    // if there's not space set this big word trigger
	}

ch = inFile.get();     //get the next character
}

inFile.close();
cout<<fileName<<" has "<<num<< " total unique words."<<endl;
cout<<"-----------------------------------------------"<<endl;
}


/**
 * @brief      Determines if the C-string is a word (a word being composed of only letters).
 *
 * @param      str   The C-String in question
 *
 * @return     True if word, False otherwise.
 */
bool isWord(char str[]){

	bool word = true;   						 //assume word is true...

	for(int i =0; i<(signed)strlen(str); i++){   //loop through every letter in C-string
		if(!isalpha(str[i])){					 //if the current character is not a letter...
			return false;						 //return that its not a word
		}
		
	}
	return word;								 //If every charcater is a letter, its a word
}


/**
 * @brief      Adds a word(C-string) to the list of structs.
 *
 * @param      str   The C-string
 * @param      list  The list of of structs
 * @param      num   The logical size of list
 */
void addWordToList(char str[], wordFreq list[], int& num){
		int loc = search(str, list, num);          //first search the list for the character
		if(loc != -1)                              //if it was found...
			list[loc].count++;                     // ch was already in list, update the count
		else if(num < MAX_LIST_SIZE ){             //if it wasn't found and I still have room in list...
			strcpy(list[num].word , str);		   //copy the string to the end of my list of structs
			
			list[num].count++;                     //update the count
			num++;                                 //increase the logical size of list
			}
		else{
 		cout << "list out of space"<<endl;
 		
 		}
 

}


/**
 * @brief      linear searching algorithm
 *
 * @param[in]  ch    { a character being searched for }
 * @param      list  The list being searched
 * @param[in]  num   the logical size of list
 *
 * @return     { -1 if not found, or index of result if one was found}
 */
int search(char str[], wordFreq list[], int num){

	bool match = false;                          //assume no match..
	for (int i = 0; i <= num; i++) {             //loop through list of structs
		if (strlen(str) == strlen(list[i].word)) //if the string is not the same length as element, automatically skip it
			if (strcmp(str, list[i].word)==0)    
				match = true;					 //match found
						
		if (match)
			return i;							 //return index of match
	}
	return -1;
}


/**
 * @brief      { Basic insertion sorting alg }
 *
 * @param      list  The list of structs
 * @param[in]  num   The logical size of list
 */
void insertionSorter(wordFreq list[], int num){
	
		wordFreq temp ; 				// current value to sort
		int j ; 						// local counter
										// for each item in the list...
		for(int i = 1; i < num; i++){
		temp = list[i];
		// find correct location for temp
			for(j = i ; j > 0 && temp.count > list[j-1].count; j--)
				list[j] = list[j-1];
			list[j] = temp;
		}
	
}


/**
 * @brief      Writes the frequency data to a file
 *
 * @param      list  The list of structs
 * @param[in]  num   The logical size of the list
 */
void fileWriter(wordFreq list[],int num){

char fileName[MAX_STRING_SIZE]; 		//To store the name of the output file
cout<<"Create frequency file"<<endl;

fstream outFile;

do{
	readFileName(fileName);				//call method to produce a fileName of the user's choice
	outFile.open(fileName, ios::out);	//open the file for writing

	cout<<"Creating "<<fileName<<"... ";
}
while (outFile.fail());
	for(int i = 0; i < num ; i ++)		//loop through list and print frequency data in file
		outFile << list[i] << endl;
outFile.close();
cout<<"done!"<<endl;
}


/**
 * @brief      overloading the output opperator to easily print my structs
 *
 * @param      out   The output stream 
 * @param[in]  list  The list of structs
 *
 * @return     { description_of_the_return_value }
 */
ostream& operator<<(ostream & out, const wordFreq& list){
	out<<list.word<<' '<<list.count;
	return out;
}