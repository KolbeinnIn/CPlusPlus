//Kolbeinn Ingólfsson skil04b
#include "pch.h"
//ATH EMIL GAUTUR. þessi kóði var gerður í visual studio 2017 og include pch.h er notað í stað stdafx.h
//#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking {
private:
	int id;
	int capacity;
	int reserved;


public:
	FlightBooking(int i = 0, int cap = 0, int res = 0) {
		id = i;
		capacity = cap;
		reserved = res;
	}
	void printStatus() {
		double perc = (double)reserved / capacity * 100;
		cout << endl << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (perc) << "%) seats reserved.";
	}

	void reserveSeats(int number_ob_seats) {
		if (reserved + number_ob_seats > round(capacity * 1.05) || number_ob_seats < 0){
			cout << "Cannot perform this operation" << endl;
		}
		else reserved += number_ob_seats;
	}
	void cancelReservations(int number_ob_seats) {
		if (number_ob_seats < 0 || reserved - number_ob_seats < 0)
			cout << "Cannot perform this operation" << endl;
		else reserved -= number_ob_seats;
	}
	int returnId() {
		return id;
	}
};


int main() {
	FlightBooking booking[10]; //býr til listann 
	string command = "";
	int n = 0;
	int id;
	int teljari = 0;
	int stadur = 0; //stadur er tímabundið númer staðsetningarinnar á ákveðnu flugi í listanum
	int bid = 0; //sést í commenti neðar.
	bool frue = true; //sést í commenti neðar.

	while (command != "quit") {		
		cout << endl << "What would you like to do?: ";
		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> id >> n;
		for (int i = 0; i < 10; i++)
		{
			if (booking[i].returnId() == id) {
				stadur = i;
			}
		}

		if (command == "add"){
			booking[stadur].reserveSeats(n);
		}
		else if (command == "cancel")
			booking[stadur].cancelReservations(n);
		else if (command == "create") {
			if (n == 0)
				cout << "Vinsamlegast sladu inn capacity, reyndu aftur." << endl;
			else{
				int q = teljari;
				for (int i = 0; i < 10; i++) { // hér er for lykkja sem fer í gegnum listann
					bid = booking[i].returnId(); //býr til tímabundið id úr listanum
				
					for (int j = 0; j < 10; j++) {
						if (bid == id && bid != 0) { //notar tímabundna id-ið og athugar hvort það hefur verið notað áður og break ef svo er.
							frue = false;
							break;
						}
					}
					if (booking[i].returnId() == 0 && frue != false) { //ef for lykkjan sem notar j breakaði þá gerist ekkert með q.
						q = i;
					}
				}
				if (frue == true){ //ef for lykkjan sem notar j breakaði EKKI þá varð q = i og nýtt flug verður til.
					booking[q] = FlightBooking(id, n, 0);
					teljari += 1;
				}
				else //error skilaboð
					cout << "Annad flug er med thetta ID, reyndu aftur." << endl;
			}
		}

		else if (command == "delete") {
			booking[stadur] = FlightBooking(0, 0, 0);
			teljari += 1;
		}
		for (int i = 0; i < 10; i++) //for lykkja til að prenta út flugin
		{
			if (booking[i].returnId() != 0)
				booking[i].printStatus();
		}
		n = 0;

	}
	return 0;
}