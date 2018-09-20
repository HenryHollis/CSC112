/**
 * This program simulates a drunken sailor stubling on a board.
 * The user supplies a board length, a number of steps and a number of trials
 * to run. A percentage of falls is then output to the screen.
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1 , Sept . 20 , 2018
 */
#include <iostream>
#include <cstdlib> //I need this for my random function
using namespace std;


//function declarations:
void readExperiementData(int & boardLength, int & steps, int & numTrials);
void drunkenWalk(int boardLength, int steps, int &sailorFalls);
void displayBoard(int position, int boardLength);
void outputExperimentalStats(int numTrials, int sailorFalls);
int randStep();


/**
 * @brief      Main function, from which I call my functions
 *
 * @return     int 0, (no errors)
 */
int main(){
	int boardLength = 0;
	int steps = 0;
	int numTrials = 0;
	int sailorFalls = 0;
	readExperiementData(boardLength, steps, numTrials);

	for(int i = 0; i < numTrials; i++){ //loop that repeats for as many trials as specified
	
	drunkenWalk(boardLength, steps, sailorFalls);

	}	
	outputExperimentalStats(numTrials, sailorFalls);
	return 0;
}


/**
 * @brief      This will prompt the user for a loardlength, steps and number of trials
 *
 * @param      boardLength  The board length
 * @param      steps        The steps
 * @param      numTrials    The number of trials
 */
void readExperiementData(int & boardLength, int & steps, int & numTrials){
	cout<<" Enter the board length, max number of steps and number of experiments -> ";
	cin >> boardLength >> steps >> numTrials;
	
}


/**
 * @brief      Prints the final statistics to the screen
 *
 * @param[in]  numTrials    The number trials
 * @param[in]  sailorFalls  The number of times the sailor fell
 */
void outputExperimentalStats(int numTrials, int sailorFalls){
	double fallPercentage = (double(sailorFalls)/numTrials)*100; //Here I call calculate and store the fall percentage
	cout << "After "<< numTrials<< " experiments, sailor fell "<<sailorFalls<< " time, ";
	cout<< "fall percentage was " << fallPercentage << "%" <<endl;
}


/**
 * @brief      A function that pseudoramdomly returns -1 or 1
 *
 * @return     returns a 1 or -1, which will be used for right or left step.
 */
int randStep(){
	return (rand()%2?-1:1);
}


/**
 * @brief      The function that actually simulates the drunken walk,
 *
 * @param[in]  boardLength  The board length
 * @param[in]  steps        The steps
 * @param[in]  numTrials    The number trials
 * @param      sailorFalls  The number of sailor falls, passed by ref b/c it modifies the variable in main
 */
void drunkenWalk(int boardLength, int steps, int &sailorFalls){
		int position = 0;

		cout << "========" << endl; //Output to match the example

		displayBoard(position, boardLength);//an initial display, with sailor in middle

		for(int j = 0; j < steps; j++){ //loop for each step the sailor takes
			
			 

			if (randStep() == 1){ //sailor moves right
				position++; //position increases
			}

			else{ //sailor moves left
				position--;//position decreases
			}

			if(position<-boardLength || position > boardLength){ //if the sailor falls...
				displayBoard(position, boardLength);
				cout<<"Sailor FELL :("<< endl;
				sailorFalls++;
				break; //exit the step loop
			}

			displayBoard(position, boardLength); // prints the step

			if (j == steps-1)
				cout<<"Sailor SAFE :)"<< endl; //prints safe at the end of every trial, if he doesn't fall.

		}

	}


/**
 * @brief      Prints the board and sailor graphically
 *
 * @param[in]  leadingBoard   The board length in front of sailor
 * @param[in]  trailingBoard  The board length behind sailor
 */
void displayBoard(int position, int boardLength){
	
		for(int i = -(boardLength); i < boardLength+1; i++){
			if(i==position){
				cout<<"*";
			}
			else{
				cout<<"_";
			}

		}
		cout<<endl;
		
}
