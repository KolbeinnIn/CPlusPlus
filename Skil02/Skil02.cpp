//Kolbeinn Ingólfsson
//25.09.2018
//Skilaverkefni 2 - subnetting C++

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

void ip2fylki(int *ipTolur, int ipTala) {
	ipTolur[0] = (ipTala >> 24) & 0xff;
	ipTolur[1] = (ipTala >> 16) & 0xff;
	ipTolur[2] = (ipTala >> 8) & 0xff;
	ipTolur[3] = ipTala & 0xff;
}

void synaIpTolu(const char*texti, int *ipTolur) {

	for (int i = 0; i < 4; i++) {
		if (i != 3) {
			cout << ipTolur[i] << ".";
		}
		else {
			if (ipTolur[i] < 9){
				cout << ipTolur[i] << "       ";
			}
			else if (ipTolur[i] < 100){
				cout << ipTolur[i] << "      ";
			}
			else if (ipTolur[i] > 100){
				cout << ipTolur[i] << "     ";
			}
		}
	}
}

void synaIpTolu(const char*texti, int ipTala) {
	int ip[4];
	ip2fylki(ip, ipTala);
	synaIpTolu(texti, ip);
}



int ip2int(int *ipTolur) {
	return ipTolur[0] << 24 | ipTolur[1] << 16 | ipTolur[2] << 8 | ipTolur[3];
}

void subnetting(int ipNet, int netBitar, int bitaFjoldi) {
	cout << "IP net      Fyrsta nothaefa     Sidasta nothaefa       Broadcast      Maski" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	int magic = pow(2, (32 - (netBitar + bitaFjoldi))); //magic number er fyrsti biti sem er 1 talinn fra haegri.
	for (int i = 0; i < pow(2, bitaFjoldi); i++) {
		int tempnet = ipNet + (magic*i);
		synaIpTolu("", tempnet); //network
		synaIpTolu("\t", tempnet + 1); //fyrsta nothaefa
		synaIpTolu("\t", tempnet + magic - 2); //seinasta nothaefa
		synaIpTolu("\t", tempnet + magic - 1); //broadcast
		tempnet = 0xffffffff << (32 - (netBitar + bitaFjoldi)); //subnet maskinn vol.1
		synaIpTolu("\t", tempnet); //subnet maskinn vol.2
		cout << endl;
	}

}

int main() {
	int *ipTolur = new int[4];

	int prefix, subnet, subnetBitar; //subnet er hversu morg net a ad skipta i.

	cout << "Sladu inn upphafsnet: ";
	for (int i = 0; i < 4; i++) {
		cin >> ipTolur[i];
	}

	cout << endl << "Fjoldi netbita i upphafsneti: ";
	cin >> prefix;
	cout << endl << "Fjoldi neta sem a ad skipta upphafsnetinu i: ";
	cin >> subnet;


	cout << endl;

	int ip2Dec = ip2int(ipTolur);
	subnetBitar = ceil(log2(subnet));
	subnetting(ip2Dec, prefix, subnetBitar);

	/* skemmtileg leid til ad breyta prefix-inu í subnet maska i binary.

	for (int i = 0; i < 32; i++){
	if (i % 8 == 0 && i != 0){
	cout << ".";
	}
	if (i < prefix){
	cout << "1";
	}
	else{
	cout << "0";
	}
	}*/
	cout << endl;
}