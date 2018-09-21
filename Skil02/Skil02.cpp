// Subnet Calculator, by rocco castoro

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <math.h>
using namespace std;


int main() {
	int ipTala[4];
	int ipHeiltolur[4];
	int netBitar = 0;
	int skipting = 0;
	//int subnet[4];
	cout << "Sladu inn upphafsnet: ";
	for (int i = 0; i < 4; i++){
		cin >> ipTala[i];
	}
	cout << endl << "Fjoldi netbita i upphafsneti: ";
	cin >> netBitar;
	cout << endl << "Fjoldi neta sem a ad skipta upphafsnetinu i: ";
	cin >> skipting;


	for (int i = 0; i < 4; i++){
		cout << ipTala[i];
		if (i < 3){
			cout << ".";
		}
	}
	cout << endl;
	ipHeiltolur[0] = ipTala[0] << 24;
	ipHeiltolur[1] = ipTala[1] << 16;
	ipHeiltolur[2] = ipTala[2] << 8;
	ipHeiltolur[3] = ipTala[3];
	unsigned int asd = ipTala[0] << 24 | ipTala[1] << 16 | ipTala[2] << 8 | ipTala[3]; //ATH UNSIGNED	
	cout << asd;
	/*
	for (int i = 0; i < 32; i++){
		if (i % 8 == 0 && i != 0){
			cout << ".";
		}
		if (i < netBitar){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	*/
	cout << endl;
}