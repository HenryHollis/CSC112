/**
* This program prompts the user for a file, if the file exists,
* then the program counts the occurances of letters, digits and other characters in the file.
* With insertion sorting, the results of the top 5 most used characters of each type
* are displayed to the user.
*
* @author  Henry Hollis {@literal  <hollhc17@wfu.edu>}
* @version  0.1,  Oct. 3, 2018
*/
#include <iostream>
#include <fstream> //lib for file manipulation
#include <ctype.h> //lib for isdigit method

// maximum string size, defined at compile time
#define MAX_STRING_SIZE 20
// maximum character list size, defined at compile time
#define MAX_LIST_SIZE 50

using namespace std;

// === data type to store a character and its count ================
struct charFreq{
char ch ; // the character
int count = 0; // the number of times the character occurred
};


//========= Function Declarations ===============

ostream& operator<<(ostream & out , const charFreq& list); 
void readFileName(char fileName[]);
void process(char fileName[], int alphaNum, int digNum, int otherNum, charFreq alphaList[], charFreq digList[], charFreq otherList[]);
void addToList(char ch, charFreq list[], int& num);
int search(char ch, charFreq list[], int num);
void printStats(charFreq alphaList[], charFreq digList[], charFreq otherList[], int alphaNum, int digNum, int otherNum);
void insertionSorter(charFreq list[], int num);
int sorter(char ch);

/**
 * @brief      main method
 *
 * @return     { 0 if no error }
 */
int main(){

charFreq alphaList[MAX_LIST_SIZE];  //list of unique letters
charFreq digList[MAX_LIST_SIZE];	//unique numbers
charFreq otherList[MAX_LIST_SIZE];	//unique other characters
int otherNum = 0; //number of unique other characters
int alphaNum = 0; // number of unique letters
int digNum = 0;	  //number of unique digits

char fileName[MAX_STRING_SIZE]; 

readFileName(fileName); //retrieve filename
process(fileName, alphaNum, otherNum, digNum, alphaList, digList, otherList); //process file

return 0;
}


/**
 * @brief      Reads a file name.
 *
 * @param      fileName:  an array which I'll save the filename chars in
 */
void readFileName(char fileName[]){
int i = 0; // local counter
char ch; // a character from the keyboard
cout << "Enter the name of the text file -> ";

// read in characters until a space , newline , or out of room
ch = cin.get();
	while( ch != '\n' && ch != ' ' && i < (MAX_STRING_SIZE - 1)){
		fileName[i] = ch;
		ch = cin.get();
		i++;
	}
 // add null terminator to the end to make it an official C - string
fileName[i] = '\0';
fstream inFile(fileName, ios::in); //declare filestream object
if(inFile.fail()) //If I can't open the file, recall the method
	readFileName(fileName);

inFile.close(); //close my file

}

/**
 * @brief      opens the file, extracts data and processes it
 *
 * @param      fileName   The file name
 * @param[in]  alphaNum   The logical size of alpha list
 * @param[in]  digNum     The logical size of digit list
 * @param[in]  otherNum   The logical size of other list
 * @param      alphaList  The alpha list
 * @param      digList    The digit list
 * @param      otherList  The other list
 */
void process(char fileName[], int alphaNum, int digNum, int otherNum, charFreq alphaList[], charFreq digList[], charFreq otherList[]){
fstream inFile(fileName, ios::in); //declare filestream object

char ch; // / < character from the file

ch = inFile.get(); //store character as ch
	while (!inFile.eof()){ //while not at the end of file...

		int id = sorter(ch); //sort the incoming character as a num, digit, or other

		if(id ==0 && alphaNum<MAX_LIST_SIZE) 			//if the char is a letter...
			addToList(tolower(ch), alphaList, alphaNum);
		
		else if (id == 1 && digNum <MAX_LIST_SIZE)	    //if the char is a number...
			addToList(ch, digList, digNum);
			
		
		else if (id == 2 && otherNum<MAX_LIST_SIZE)    //if the char is other...
			addToList(ch, otherList, otherNum);
			
		ch = inFile.get(); //get the next character
	}
inFile.close(); //close my file

printStats(alphaList, digList, otherList, alphaNum, digNum, otherNum); //print out the results
}


/**
 * @brief      adds the chracacter to a struct in the proper list
 *
 * @param[in]  ch    the character
 * @param      list  The list of structs
 * @param      num   The logical size of the list 
 */
void addToList(char ch, charFreq list[], int& num){
		int loc = search(ch, list, num); //first search the list for the character
		if(loc != -1) //if it was found...
			list[loc].count++; // ch was already in list, update the count
		else if(num < MAX_LIST_SIZE ){ //if it wasn't found and I still have room in list...
			list[num].ch = ch;//catalog the new character
			list[num].count++;//update the count
			num++; //increase the logical size of list
			}
		else{
 		cout << "list out of space \n ";
 		
 		}
 

}


/**
 * @brief      linear sorting algorithm
 *
 * @param[in]  ch    { a character being searched for }
 * @param      list  The list being searched
 * @param[in]  num   the logical size of list
 *
 * @return     { -1 if not found, or index of result if one was found}
 */
int search(char ch, charFreq list[], int num){
	for(int i = 0; i<=num; i++)
		if (ch == list[i].ch)
			return i;	
	return -1;
}


/**
 * @brief      prints out the results from the program
 *
 * @param      alphaList  The list of numbers and count
 * @param      digList    The list of digits and count
 * @param      otherList  The list of other chars and the count
 * @param[in]  alphaNum   The logical size of number list
 * @param[in]  digNum     The logical size of digit list
 * @param[in]  otherNum   The logical size of other list
 */
void printStats(charFreq alphaList[], charFreq digList[], charFreq otherList[], int alphaNum, int digNum, int otherNum){
	int low; //my local var

	cout<<endl<< "alpha top 5 out of "<< alphaNum<<endl;
	cout<<"---------------------"<<endl;

	insertionSorter(alphaList, alphaNum); //sort the list

	low=(5<alphaNum?5:alphaNum); // select the smallest between 5 and logical size
	for(int i =0; i<low; i++)
		cout<<alphaList[i]<<endl;
	cout<<endl;
	
	cout<< "digit top 5 out of "<< digNum<<endl;
	cout<<"---------------------"<<endl;

	insertionSorter(digList, digNum); //sort list

	low=(5<digNum?5:digNum);  // select the smallest between 5 and logical size

	for(int i =0; i<low; i++)
		cout<<digList[i]<<endl;
	cout<<endl;

	cout<< "other top 5 out of "<< otherNum<<endl;
	cout<<"---------------------"<<endl;

	insertionSorter(otherList, otherNum); //sort list

	low=(5<otherNum?5:otherNum); // select the smallest between 5 and logical size
	for(int i =0; i<low; i++)
		cout<<otherList[i]<<endl;
	cout<<endl;
}


/**
 * @brief      insertion sorting
 *
 * @param      list  The list of structs
 * @param[in]  num   The number logical size of the list
 */
void insertionSorter(charFreq list[], int num){
	
		charFreq temp ; // current value to sort
		int j ; // local counter

		// for each item in the list
		for(int i = 1; i < num; i++){
		temp = list[i];
		// find correct location for temp
			for(j = i ; j > 0 && temp.count > list[j-1].count; j--)
				list[j] = list[j-1];
			list[j] = temp;
		}
	
}


/**
 * @brief      determines whether the character is a number, digit, or other
 *
 * @param[in]  ch    a charcter in question
 *
 * @return     an integter, 0 for num, 1 for digit, and 2 for other
 */
int sorter(char ch){
	if (isalpha(ch))
		return 0; 
	else if(isdigit(ch))
		return 1;
	else
		return 2;
}


/**
 * @brief      Overloads the << operator to print my structs easier
 *
 * @param      out:   The outout stream
 * @param[in]  list:  a list of structs
 *
 * @return     the output stream
 */
ostream& operator<<(ostream & out, const charFreq& list){
	cout<<'['<<list.ch<<']'<<' '<<list.count;
	return out;
}

