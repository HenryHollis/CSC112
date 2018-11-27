/**
 * This program takes in a text file, analyzes the frecuency of
 * each word, then removes all the stop words that the user designates in a 
 * stop word text file. A frequency of the remaining words is then output to another
 * text file.
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Oct.25, 2018
 */
#include <iostream>
#include "words.h"
using namespace std;

/**
 * @brief      Main function to delegate work
 *
 * @param[in]  argc  The number of args
 * @param      argv  The list of args
 *
 * @return     { 0 if okay, 1 if something bad happened }
 */
int main(int argc, char *argv[]){

	/*checking whether user input is suitable*/

	if(inCorrectNumArgs(argc))
		return 1;
	else if(inFilesFailed(argv[1]))
			return 1;
	else if(inFilesFailed(argv[2]))
		return 1;
	else if(outFileFailed(argv[3]))
		return 1;

	wordFreq *list = NULL; 					// dynamic list of unique words
    int num = 0; 							// number of unique words

    ReadWords(argv[1], list, num);  		//parse input file
    
    removeStopWords(argv[2], list, num);	//remove stop words
    
    insertionSorter(list, num);  			//sort the frequency of words so that the frq file is nice and orderly
    
    outPutResults(list, argv[1], argv[2], argv[3], num);	//save remaining words to file

}

