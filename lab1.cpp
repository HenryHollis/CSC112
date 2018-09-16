/**
 * This program prompts the user for a lightbulb quantity then
 * tells the user the minimum number of containers required for
 * said order. It also prints an itemized receipt.
 * 
 * @author Henry Hollis {@literal <hollhc17@wfu.edu>}
 * @version 0.1, Sept. 11, 2018
 */
#include <iostream>
using namespace std;

//Function definitions
void inputOrder();
void calcOrder(int quant);
void outputOrder(int quant, int sml, int med, int lrg, int hge, double packagingCost, double lightCost, double tot);
void hugeCount(int order, int& numOfHuge, int& leftOvers);
void largeCount(int& leftOvers, int& numOfLarge);
void medCount(int& leftOvers, int& numOfMediums);
void smallCount(int& leftOvers, int& numOfSmalls);


/**
 * @brief      {This is my main function, the mighty fine place to start.}
 *
 * @return     0, or error code 0
 */
int main(){
	inputOrder();
	return 0;
}


/**
 * @brief      { Get the order information }
 * @return     void
 */
void inputOrder(){
	int order;
	cout << "Enter the number of light bulbs in the order -> " <<endl;
	cin >> order;
	calcOrder(order);
}


/**
 * @brief      Calculates the order shipping cost and schedule.
 *
 * @param[in]  quant  The quantity of light bulbs in the order
 * @return     void
 */
void calcOrder(int quant){
	int numOfHuge = 0; //Number of huge boxes needed
	int numOfMediums = 0; //Number of Medium boxes needed
	int numOfLarge = 0; //Number of Large boxes needed
	int numOfSmalls = 0; //number of Small boxes needed
	double lightBulbCost = quant * 1.55; //raw cost of the light bulbs
	
	int leftOvers = 0; //the number of light bulbs that won't fit in a box
	
	hugeCount(quant, numOfHuge, leftOvers);
	largeCount(leftOvers, numOfLarge);
	medCount(leftOvers, numOfMediums);
	smallCount(leftOvers, numOfSmalls);

	double packagingCost = (numOfHuge*5.0)
		+(numOfLarge*3.5)
		+(numOfMediums*2.0)
		+(numOfSmalls*0.75); // the raw shipping cost

	double total = (packagingCost + lightBulbCost); //the order total

	outputOrder(quant, numOfSmalls, numOfMediums, numOfLarge, numOfHuge, packagingCost, lightBulbCost, total);
	
}


/**
 * @brief      Determines the number of huge boxes, notice I pass by ref for both variables
 *
 * @param[in]  order      The quantity of light bulbs
 * @param      numOfHuge  The number of huge boxes soon to be set
 * @param      leftOvers  The number of leftover light bulbs soon to be set
 * @return     void
 */
void hugeCount(int order, int& numOfHuge, int& leftOvers){
	numOfHuge = (order/20);  //Here is where the # of huge boxes is set
	leftOvers = (order%20);  //Here is where the # of leftovers is set
}


/**
 * @brief      Determines the number of large boxes, notice I pass by ref for both variables
 *
 * @param      leftOvers   The number of leftover bulbs soon to be set
 * @param      numOfLarge  The number of large boxes soon to be set
 * @return     void
 */
void largeCount(int& leftOvers, int& numOfLarge){
	numOfLarge = (leftOvers/15);  //Here is where the # of large boxes is set
	leftOvers = (leftOvers%15);  //Here is where the # of leftovers is set
}


/**
 * @brief      Determines the number of medium boxes needed, notice I pass by ref for both variables
 *
 * @param      leftOvers     The number of leftover bulbs soon to be set
 * @param      numOfMediums  The of medium boxes soon to be set
 * @return     void
 */
void medCount(int& leftOvers, int& numOfMediums){
	numOfMediums = (leftOvers/7);  //Here is where the # of medium boxes is set
	leftOvers = (leftOvers%7);  //Here is where the # of leftovers is set
}


/**
 * @brief      Detremines the number of small boxes needes, notice I pass by ref for both variables
 *
 * @param      leftOvers    The number of leftover bulbs soon to be set
 * @param      numOfSmalls  The number of small boxes soon to be set
 * @return     void
 */
void smallCount(int& leftOvers, int& numOfSmalls){
	numOfSmalls = (leftOvers/1); //Here is where the # of small boxes is set
	leftOvers = (leftOvers%1);  //Here is where the # of leftovers is set
}


/**
 * @brief      Printing the shipment schedule and cost
 *
 * @param[in]  quant          The quantity of light bulbs
 * @param[in]  sml            the number of small boxes needed
 * @param[in]  med            the number of medium boxes needed
 * @param[in]  lrg            the number of large boxes needed
 * @param[in]  hge            the number of huge boxes needed
 * @param[in]  packagingCost  the cost of packaging
 * @param[in]  lightCost      the cost of the lightbulbs
 * @param[in]  tot            The total
 * @return     void
 */
void outputOrder(int quant, int sml, int med, int lrg, int hge, double packagingCost, double lightCost, double tot){
	cout<< " Shipment Schedule for "<<quant<< " Bulbs."<<endl;
	cout << "---------------------------------"<<endl;
	cout <<"Number of Containers Required"<<endl;
	cout<<" Huge   " << hge << endl;
	cout<<" Large  " << lrg << endl;
	cout<<" Medium " <<med << endl;
	cout<<" Small  " << sml << endl << endl;
	cout <<" Cost of the light bulbs: $ " << lightCost << endl;
	cout <<" Cost of the containers:  $ " << packagingCost << endl;
	cout <<" Total cost of order:     $ " << tot <<endl;
}