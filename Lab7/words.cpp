/**
 * These are my function definitions.
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.1, 2018
 */
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <string.h>

#include "words.h"
#include "stemming.h"
using namespace std;

/**
 * @brief      checks if user has entered the right number of args
 *
 * @param[in]  argc  The argument count
 *
 * @return     { true if incorrect number of args, false otherwise }
 */
bool inCorrectNumArgs(int argc){
	if(argc<4){
		cout<<"\nUsage: executable textFile stopFile frequencyFile\n"<<endl;
		return true;
	}
	return false;
}

/**
 * @brief      { Checks if the input files exist/can be opened }
 *
 * @param      fileName  The file name
 *
 * @return     { true if failed, false if they are openable}
 */
bool inFilesFailed(char fileName[]){
bool failed = false;
fstream inFile(fileName, ios :: in); 	//fstream for file
	if(inFile.fail()){
		failed =  true;
		cout<<fileName<<" failed to open"<<endl;
	}
inFile.close();
return failed;
	
}


/**
 * @brief      { Checks if the user can create a file for output data }
 *
 * @param      outPut  The output file name
 *
 * @return     { true if a file can't be opened, false otherwise }
 */
bool outFileFailed(char outPut[]){
bool failed = false;
fstream OutFile(outPut, ios :: out); 	//fstream for file
	if(OutFile.fail()){
		failed =  true;
		cout<<outPut<<" failed to open"<<endl;
	}
OutFile.close();
return failed;
}



/**
 * @brief      {Parses the words from the input text file. Stores the unique words in list of structs} 
 * 
 *
 * @param      fileName  The file name
 * @param      list      The list of structs
 * @param      num       The number of structs in list
 */
void ReadWords(char fileName[], wordFreq *& list, int &num){
		
fstream inFile(fileName, ios :: in); 	//fstream for file

char str[MAX_STRING_SIZE]; // current string
int n; 					   // length of string
char ch ; 				   // current character
str[0] = '\0';			   // adding the null term to make a propper c-string
						   
ch = inFile.get();		   // get a character from the file...


while (!inFile.eof()){			        // loop through until the end of file
						        
	if (!isalpha(ch)){   				// if ch is word delineator, or the rest of a big word, we can classify the string
		            
		if(strlen(str)>0){			           // if string is a word, add to list
			stemmer(str);
			if(strlen(str)>0)
				addWordToList(str, list, num);
		}

	    str[0] = '\0';					// reset the string
	}
	else{
								
		n = strlen(str);
		if(n < MAX_STRING_SIZE - 1){  	// add new character to end of the string , if there is space
			str[n] = tolower(ch);
			str[n+1] = '\0';
		}
		
	}

ch = inFile.get();     				 	 //get the next character
}

	if(strlen(str)>0){					 //if the buffer is not empty...
		stemmer(str);
		if(strlen(str)>0)
			addWordToList(str, list, num);	 //then add the leftover chars as a word
	}
inFile.close();

cout<<fileName<<" has "<<num<< " unique words"<<endl;
cout<<"-----------------------------------------------"<<endl;

}

void addWordToList(char str[], wordFreq*& list, int& num){
		int loc = search(str, list, num);          //first search the list for the character
		
		if(loc != -1){                            //if it was found...
			list[loc].count++;                     // ch was already in list, update the count
		}
		else{
			wordFreq* temp = new (nothrow) wordFreq[num+1];		//temp array, 1 bigger than list.
			assert(temp!=NULL);									//covering my ass.
			for(int i =0; i<num; i++){							
				temp[i] = list[i];								//populate temp with list members.
			}
			strcpy(temp[num].word, str);						//add word to end of temp array.
			temp[num].count = 1;
			if(list != NULL) delete[] list;						//delete old list to avoid leakage.
			list =temp;											//set list as temp array.
			num++;												//now increase list of members by one.
		}
 

}


/**
 * @brief      Searches for the list of structs for the first matching c-string.
 *
 * @param      target  The target c-string
 * @param      list    The list of structs
 * @param[in]  num     The number of structs in list
 *
 * @return     { location of match or -1 for no match}
 */
int search(char target[], wordFreq list[], int num){

	int i =0;                         
	int loc = -1;								//assume no match...
	while(i<num&&loc==-1){						//loop through elements while I dont have match...
		if(strcmp(list[i].word, target)==0){	
			loc = i;							//if I find match update loc.
		}
		i++;
	}
	return loc;
}

/**
 * @brief      Sorts the list of structs in decreasing order of their counts
 *
 * @param      list  The list of structs
 * @param[in]  num   The number of structs in list
 */
void insertionSorter(wordFreq list[], int num){
		wordFreq temp; 					// current value to sort
		int j;	 						// local counter
										// for each item in the list...
		for(int i = 1; i < num; i++){
		temp = list[i];
										// find correct location for temp
			for(j = i ; j > 0 && list[j-1] > temp; j--)
				list[j] = list[j-1];	//swap
			list[j] = temp;
		}
		
	
}


/**
 * @brief      { parses stoptext file, checks list of structs for matches with stop words.
 * 			   Deletes the word if it matches a stop word.}
 * 
 *
 * @param      stopText  The stop text file name
 * @param      list      The list of structs
 * @param      num       The number of structs in list
 */
void removeStopWords(char stopText[], wordFreq*& list, int &num){
	
	fstream inFile(stopText, ios::in);	
	char line[MAX_STRING_SIZE];			//declare a c-string to read stop word chars into
 	
 		while (inFile >> line){			//loop while there's still input
 			
 		
 			int loc = search(line, list, num);	//search my list of structs for stopword
 			

    		if(loc!=-1){						//if I find it...
					
    			wordFreq* temp = new (nothrow) wordFreq[num-1];		//temporary dynamic list declaration
    			assert(temp!=NULL);									//make sure I have enough heap

    			for(int i = loc; i<num; i++){					
    				list[i] = list[i+1];							//delete matching word in structs list
    				
    				}
    				
    			num--;												//now there is one less struct in list
    			

    			for(int j = 0; j <num; j++)
    				temp[j] = list[j];								//copy list to temp list, which is one unit smaller

    			if(list != NULL) delete[] list;			//delete the old list...
				list=temp;								//and set it to temp list.

    		}
    		
    		
    	}

    inFile.close();

}


/**
 * @brief      { writes data to a file }
 *
 * @param      list  The list of structs
 * @param      arg1  The argument 1 from cmd line
 * @param      arg2  The argument 2 from cmd line
 * @param      arg3  The argument 3 from cmd line
 * @param[in]  num   The number of structs in list
 */
void outPutResults(wordFreq* list, char arg1[], char arg2[], char arg3[], int num){
	cout<<"without stop words (read from "<<arg2<<")"<<endl;
	cout<<arg1<<" has "<< num<<" unique words"<<endl;
	cout<<"-----------------------------------------------"<<endl;		//user info. printed out
	cout<<"Creating "<<arg3<<" ... ";

	fstream outFile(arg3, ios:: out);	

	for(int i = 0; i<num;i++)
    	outFile<<list[i]<<endl;							//write the list of structs to a file
    outFile.close();
    cout<<"done!"<<endl;

}

/**
 * @brief      overloading the output operator to print my structs easily
 *
 * @param      out   The output stream
 * @param[in]  list  The list of structs
 *
 * @return     {the output stream adress }
 */
ostream& operator<<(ostream & out, const wordFreq& list){  
	out<<list.word<<' '<<list.count;
	return out;
}


/**
 * @brief      overloading the > operator to compare the alphabetic order of 
 * 			   the words in my wordStructs
 *
 * @param[in]  lhs   The left hand struct
 * @param[in]  rhs   The right hand struct
 *
 * @return     {true if lhs is bigger, false if not}
 */
bool operator>(const wordFreq& lhs, const wordFreq& rhs){  
	for(int i = 0; i <(signed)strlen(lhs.word); i++){
		if(lhs.word[i]<rhs.word[i])
			return false;
		if(lhs.word[i]>rhs.word[i])
			return true;
	}
	if(strlen(lhs.word)>strlen(rhs.word))
		return true;
	return false;
}

/**
 * @brief      overloading the equality operator for my wordFreq struct
 *
 * @param[in]  lhs   The left hand struct
 * @param[in]  rhs   The right hand struct
 *
 * @return     {true if equal, false if not}
 */
bool operator==(const wordFreq& lhs, const wordFreq& rhs){  
	if(strcmp(lhs.word, rhs.word)==0)
		return true;
	return false;
}