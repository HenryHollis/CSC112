/**
 *This program simulates a group of drunken sailors (the number of which
 *the user chooses), stumbling around a loop (the size of which is also chosen)
 *When every step on the loop has been or is currently occupied, the program 
 *terminates and outputs the number of steps taken. 
 *
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
6* @version 0.1 , Sept . 27 , 2018
 */
#include <iostream>
#include <cstdlib>
using namespace std;

//function declarations
void readExperimentData(int & ringLength, int & numSailors);
bool ringCovered( int ringLength, int a[]);
void displayRing(int ringLength,int numSailors, int a[], int b[]);
void outputExperimentStats(int iterations);
int randStep();
void drunkenWalk( int ringLength, int a[], int b[], int numSailors);


/**
 * @brief      My main function, where my arrays are declared and my methods are called
 *
 * @return     {0}
 */
int main(){
	int ringLength;
	int numSailors =0;
	int ring[50] = {0};
	int sailorPositions[20] = {0};
	readExperimentData(ringLength, numSailors);
	drunkenWalk(ringLength, ring, sailorPositions, numSailors);
	
	return 0;
}


/**
 * @brief      A function that simulates a step toward the right(1) or left(-1)
 *
 * @return     Either 1 or -1
 */
int randStep(){ 
	return ( rand ()%2? -1:1); 
}


/**
 * @brief      The user is able to enter input. I need to pass the params by reference
 * 			   because I want this method to change them in main.
 *
 * @param      ringLength  The ring length
 * @param      numSailors  The number sailors
 */
void readExperimentData(int & ringLength, int & numSailors){
	do{
	cout << "Enter the ring length and number of sailors -> ";
	cin>>ringLength;
	cin>>numSailors;
	}while(ringLength<1||ringLength>50||numSailors<1||numSailors>20);
}


/**
 * @brief      The function that simulates the druken sailors taking steps
 *
 * @param[in]  ringLength  The ring length
 * @param      a           an array representing ring length, 1 is stored if the block has been occupied
 * @param      b           an array of sailor positions, containing the sailor positions
 * @param[in]  numSailors  The number sailors
 */
void drunkenWalk( int ringLength, int a[], int b[], int numSailors){
	int iterations = 0;//initially, zero steps have been taken

	for(int j = 0; j<numSailors;j++){ //beforethey start stepping, I print out their positions
		cout<<"s"<<j<<":"<<b[j]<< " ";
		a[0] = 1; //the first step in ring will always have been occupied
	}

	cout<<endl;

	displayRing(ringLength, numSailors, a, b); //graphing the inital conditions

	do{
	cout<<"=========="<<endl;
	for(int i = 0; i <numSailors; i++){ //for every sailor that hte user specifies...

		int step = randStep(); //take a step, right or left
		if((b[i] + step) < 0){//if step puts sailor to the left of our graph..
			b[i] = ringLength -1; //put sailor on right end
			a[b[i]] = 1; //remember that his space was occupied
			cout<<"s"<<i<<":"<<b[i]<< " ";
		}
		else if(b[i] + step > (ringLength-1)){//if step puts sailor to the right of our graph...
			b[i] = 0;//put sailor back on left side
			a[b[i]] = 1;//remember that he occupied his old space
			cout<<"s"<<i<<":"<<b[i]<<" ";
		}
		else{ //when the step is in the middle of our graph
			b[i] += step; //add the step to his position
			a[b[i]] = 1; //remember that he occupied his old space
			cout<<"s"<<i<<":"<<b[i]<<" ";
		}
	}
	cout<<endl;
	
	displayRing(ringLength, numSailors, a, b); //after every sailor has stepped, graph it
	iterations++; //increase the iterations
	}while(!ringCovered(ringLength, a)); //do this procedure until the ring has been occupied
	outputExperimentStats(iterations); //output stats

}


/**
 * @brief      A function to determine if every space on ring has been occupied
 *
 * @param[in]  ringLength  The ring length
 * @param      a           a array containing the info about whether a space has been occupied
 *
 *
 * @return     true if every space has been occupied, false otherwise
 */
bool ringCovered( int ringLength, int a[]){
	int talley = 0;
	for(int i = 0; i < ringLength; i++) //search through array of ring occupancy
		if(a[i]==1)
			talley++; 
	if (talley == (ringLength)) //if every ring space has been occupied...
		return true;
	else	//if some spaces have never been occupied...
		return false;

}


/**
 * @brief      graphs the positions and history of sailors and ring
 *
 * @param[in]  ringLength  The ring length
 * @param[in]  numSailors  The number sailors
 * @param      a           the history of occupancy of every ring space
 * @param      b           the position of every sailor
 */
void displayRing(int ringLength, int numSailors, int a[], int b[]){
	
	for(int i =0; i<ringLength; i++){ //for every space on the ring...
		bool occupied= false;//assume that it is not currently occupied
		for(int j = 0; j<numSailors;j++) //look at every sailors position...
			if(b[j] == i) //and if it equals the ring space in question...
				occupied=true; //then the space is occupied
				
		if(occupied) 	//if the ring space is occupied
			cout<<"*";
		else if(a[i]==1) //if the ring space has ever been occupied
			cout<<"^"; 
		else			//if the ring space has never been occupied
			cout<<"_";

	}
	cout<<endl;

}


/**
 * @brief      prints the number of iterations it took to cover ring.
 *
 * @param[in]  iterations  The iterations
 */
void outputExperimentStats(int iterations){
	cout<<endl<<iterations<<" iterations required for coverage"<<endl;
}

