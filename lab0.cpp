/**
* This program prompts the user for a temperature and scale then
* prints the conversion in the opposite scale.
*
* @author Henry Hollis {@literal <hollhc17@wfu.edu>}
* @version 0.1, Sept. 6, 2018
*/

#include<iostream>
using namespace std;

/* function definitions */
double cToF(double temp);
double fToC(double temp);

int main(){
	

	cout << "Enter a temperature (value and scale): \n"; /* user is prompted */

	
	char unit; /* initialized for "f" or "c" */
	double temp;/* initialized for acutal number */
	cin >> temp >> unit;
	

	if (unit == 'f' || unit == 'F'){/* in the case where 'f' is found... */
		double res = fToC(temp); /* pass on the work to my method */
		cout << "Converted temperature is " << res << " C" << endl;
	}

	else if (unit == 'c' || unit == 'C'){ /* in the case 'c' was found... */
		double res = cToF(temp);/* pass on work to method */
		cout << "Converted temperature is " << res << " F" << endl;
	}
	else{
		cout << "Error: scale must be C or F" << endl;/* in the case no such unit is found, error displayed */
		}
	return 0; 

}

double cToF(double temp){
	double res = temp * (9.0/5.0) + 32.0; /* formula for converting celc to faren */
	return res;
}

double fToC(double temp){
	double res = (temp - 32.0)*(5.0/9.0); /* formula for converting faren to celc */
	return res;
}