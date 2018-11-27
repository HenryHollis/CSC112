/**
 * This is my stemming function definition
 * 
 * @author Henry Hollis { @literal < hollhc17@wfu.edu >}
 * @version 0.1, Nov.1, 2018
 */

#include <iostream>
#include "stemming.h"

using namespace std;


/**
 * @brief      Function to extract the stem of a c-string
 *
 * @param      str   The string
 */
void stemmer(char str[]){

 	int len = strlen(str);    //length of c-string


 	/*a series of filters that should extract the stem of the word*/

 	/*Plural Rules*/

 	if(len>=6 && str[len-1]=='s' && str[len-2]=='e' && str[len-3]=='i'){
 		str[len-3]='y';
 		str[len-2]='\0';
 		len = strlen(str); //update length
 	}
 	else if(len>=5 && str[len-1]=='s' && str[len-2]=='e' && str[len-3]=='v'){
 		str[len-1]='\0';
 		len = strlen(str); //update length
 	}
 	else if(str[len-1]=='s' && str[len-2]!='s' && str[len-2]!='u'){
 		str[len-1]='\0';
 		len = strlen(str); //update length
 	}

 	/*Past Tense Rules*/

 	if(len>=5 && str[len-1]=='d' && str[len-2]=='e' && str[len-3]=='v'){
 		str[len-1]='\0';
 		len = strlen(str); //update length
 	}
 	else if(len>=5 && str[len-1]=='d' && str[len-2]=='e'){
 		str[len-2]='\0';
 		len = strlen(str); //update length
 	}

 	/*Adverb Rule*/

 	if(len>=7 && str[len-1]=='y' && str[len-2]=='l'){
 		str[len-2]='\0';
 		len = strlen(str); //update length
 	}

 	/*Present Tense Rule*/
 	if(len>=5 && str[len-1]=='g' && str[len-2]=='n' && str[len-3]=='i'){
 		str[len-3]='\0';
 		len = strlen(str); //update length
 	}

 }