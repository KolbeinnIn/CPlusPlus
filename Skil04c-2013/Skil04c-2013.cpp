//Kolbeinn Ingólfsson skil04b-c
#include "stdafx.h"
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
		cout << endl << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (round(perc)) << "%) seats reserved.";
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


class FlightList {
private:
	FlightBooking *listi;
	int next;
	int staerd;
	int teljari = 0;

public:
	FlightList() {
		this->staerd = 2;
		listi = new FlightBooking[staerd];
		next = 0;
	}
	void setja(FlightBooking stak) {
		if (next <= staerd - 1)
			listi[next++] = stak;
		else {
			FlightBooking *temp = new FlightBooking[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[next++] = stak;
		}
	}
	void create(int b, int nn) {

		bool frue = true;
		int q = teljari;
		for (int i = 0; i < next + 2; i++) {
			int bid = listi[i].returnId();

			for (int j = 0; j < next + 2; j++){
				if (bid == b && b != 0) {//notar tímabundna id-ið og athugar hvort það hefur verið notað áður og break ef svo er.
					frue = false;
					break;
				}
			}
			if (listi[i].returnId() == 0 && frue != false) { //ef for lykkjan sem notar j breakaði þá gerist ekkert með q.
				q = i;
			}
		}
		if (frue == false) { //error skilaboð
			cout << "Annad flug er med thetta ID, reyndu aftur." << endl;
		}
		else{//ef for lykkjan sem notar j breakaði EKKI þá varð q = i og nýtt flug verður til.
			if (nn == 0)
				cout << "Vinsamlegast sladu inn capacity, reyndu aftur." << endl;
			else {
				setja(FlightBooking(b, nn, 0));
				teljari += 1;
			}
		}

	}
	int id(int b) { //function sem tekur inn id, athugar hvort það sé til nú þegar í listanum og returnar því sama id ef það er til
		for (int i = 0; i < next; i++)
		{
			if (listi[i].returnId() == b) {
				return b;
			}
		}
	}
	int id_s(int b){//þetta function er alveg eins og "id" hér fyrir ofan nema þetta returnar staðsetningu á því staki ef það fann id en ekki id sjálft (þess vegna _s fyrir stadsetning).
		for (int i = 0; i < next; i++)
		{
			if (listi[i].returnId() == b) {
				return i;
			}
		}
	}

	void syna() {
		for (int i = 0; i < next; i++)
		if (listi[i].returnId() != 0)
			listi[i].printStatus();
	}
	void add(int b, int reserved) {
		listi[b].reserveSeats(reserved);
	}
	void cancel(int b, int reserved) {
		listi[b].cancelReservations(reserved);
	}
	void del(int b) {
		listi[b] = FlightBooking(0, 0, 0);
	}
	~FlightList() {
		delete[]listi;
	}
};




int main() {
	//FlightBooking booking[10]; //býr til listann 
	FlightList booking = FlightList();
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
		if (command == "create")
			booking.create(id, n);
		if (booking.id(id) == id) {

			stadur = booking.id_s(id);
			if (command == "add") {
				booking.add(stadur, n);
			}
			else if (command == "cancel")
				booking.cancel(stadur, n);

			else if (command == "delete") {
				booking.del(stadur);
				teljari += 1;
			}
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}


		booking.syna();
		n = 0;
	}
	return 0;
}