#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


int main() {
	ofstream myfileW;
	string listi [3];
	int x;
	int tala = 0;
	string strengur;
	/*myfileW.open("H:\\2018H\\CPlusPlus\\Skil08\\siccfile.txt");
	for (int i = 0; i < 10; i++)
		myfileW << "vo strengur\n";


	myfileW.close();
	*/

	ifstream myfileR;
	myfileR.open("H:\\2018H\\CPlusPlus\\Skil08\\siccfile.txt");
	if (!myfileR) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (getline(myfileR, strengur)){
		cout << strengur << endl;
	}
	myfileW.close();
	return 0;
}

