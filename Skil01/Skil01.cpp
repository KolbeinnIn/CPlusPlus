#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main(void){
	int tala, val;  //tala og val
	int lykkja = 0; //lykkja hefst
	do {
		//Hér prentast út allur listinn til að sýna valmöguleika
		cout << "\nTalnakerfisbreytir" << endl;
		cout << "1 - Breyta i tviundakerfid \n2 - Breyta i attundakerfid \n3 - Breyta i sextandakerfid \n0 - Haetta \n-----------------\nVeldu lid: ";
		cin >> val;
		//if cin.fail() er til að koma í veg fyrir villu (endalaust loop) þegar er slegið inn eitthvað annað en integer.
		if (cin.fail()){
			cout << endl << "Villa, reyndu aftur." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //þetta er það sem lætur villu meðhöndlunina virka (fann þetta á netinu)
			cout << "1 - Breyta i tviundakerfid \n2 - Breyta i attundakerfid \n3 - Breyta i sextandakerfid \n0 - Haetta \n-----------------\nVeldu lid: ";
			cin >> val;
		}
		cout << endl;
		//switch statement 
		switch (val){
			case 1: //notandinn sló inn 1 og fær breytingu í binary
				cout << "Veldu tolu til ad breyta i binary: ";
				cin >> tala;
				if (tala < 256){
					cout <<"Talan " << dec << tala << " i binary er: "<< bitset<8>(tala) << endl;
					break;
				}
				else{
					cout << endl << "Sladu inn tolu minni en 256" << endl;
					break;
				}
			case 2:  //notandinn sló inn 2 og fær breytingu í octal
				cout << "Veldu tolu til ad breyta i octal: ";
				cin >> tala;
				cout << "Talan " << dec << tala << " i octal er: " << oct << tala;
				cout << endl;
				break;

			case 3:  //notandinn sló inn 3 og fær breytingu í hexadecimal
				cout << "Veldu tolu til ad breyta i hex: ";
				cin >> tala;
				cout << "Talan " << dec << tala << " i hexadeciaml er: " << hex << tala;
				cout << endl;
				break;

			case 0:  //bara svo það koma ekki villuboðin úr default hér að neðan.
				break;
			
			default:
				cout << "Rong tala, reyndu aftur." << endl;
		}
	} while (val != 0); //lykkja keyrir á meðan val er ekki 0
}