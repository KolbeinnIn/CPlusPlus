#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

int main(void){
	int tala, val;  //tala og val
	int lykkja = 0; //lykkja hefst
	do {
		//H�r prentast �t allur listinn til a� s�na valm�guleika
		cout << "\nTalnakerfisbreytir" << endl;
		cout << "1 - Breyta i tviundakerfid \n2 - Breyta i attundakerfid \n3 - Breyta i sextandakerfid \n0 - Haetta \n-----------------\nVeldu lid: ";
		cin >> val;
		//if cin.fail() er til a� koma � veg fyrir villu (endalaust loop) �egar er slegi� inn eitthva� anna� en integer.
		if (cin.fail()){
			cout << endl << "Villa, reyndu aftur." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //�etta er �a� sem l�tur villu me�h�ndlunina virka (fann �etta � netinu)
			cout << "1 - Breyta i tviundakerfid \n2 - Breyta i attundakerfid \n3 - Breyta i sextandakerfid \n0 - Haetta \n-----------------\nVeldu lid: ";
			cin >> val;
		}
		cout << endl;
		//switch statement 
		switch (val){
			case 1: //notandinn sl� inn 1 og f�r breytingu � binary
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
			case 2:  //notandinn sl� inn 2 og f�r breytingu � octal
				cout << "Veldu tolu til ad breyta i octal: ";
				cin >> tala;
				cout << "Talan " << dec << tala << " i octal er: " << oct << tala;
				cout << endl;
				break;

			case 3:  //notandinn sl� inn 3 og f�r breytingu � hexadecimal
				cout << "Veldu tolu til ad breyta i hex: ";
				cin >> tala;
				cout << "Talan " << dec << tala << " i hexadeciaml er: " << hex << tala;
				cout << endl;
				break;

			case 0:  //bara svo �a� koma ekki villubo�in �r default h�r a� ne�an.
				break;
			
			default:
				cout << "Rong tala, reyndu aftur." << endl;
		}
	} while (val != 0); //lykkja keyrir � me�an val er ekki 0
}