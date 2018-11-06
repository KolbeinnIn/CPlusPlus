//Kolbeinn Ingólfsson skil04b-c 
//ATH, það er vesen með parametra að actually save-ast, þannig þetta technically virkar ekki.
#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking {
private:
	int id;
	int capacity;
	int reserved;
	int max;

public:
	FlightBooking(int i, int cap, int res) {
		id = i;
		capacity = cap;
		reserved = res;
		double max = round(capacity * 1.05);
	}

	FlightBooking(){
		id = 0;
		capacity = 0;
		reserved = 0;
	}

	bool printStatus() {
		double perc = (double)reserved / capacity * 100;
		cout << endl << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (perc) << "%) seats reserved.";
		return 0;
	}

	bool reserveSeats(int number_ob_seats) {
		cout << "max: " << max << endl;
		cout << "cap: " << capacity << endl;
		cout << "res: " << reserved << endl;
		cout << "seats: " << number_ob_seats << endl;
		if (reserved + number_ob_seats > max || number_ob_seats < 0){
			cout << "Cannot perform this operation" << endl;
		}
		else reserved += number_ob_seats;
		return 0;
	}
	bool cancelReservations(int number_ob_seats) {
		if (number_ob_seats < 0 || reserved - number_ob_seats < 0)
			cout << "Cannot perform this operation" << endl;
		else reserved -= number_ob_seats;
		return 0;
	}
	int returnId() {
		return id;
	}
};




int main() {
	/*int reserved = 0, capacity = 0;

	cout << "Provide flight capacity: ";
	cin >> capacity;
	int max = round(capacity * 1.05);
	while (reserved > max || reserved == 0) {
		cout << "Provide number of reserved seats: ";
		cin >> reserved;
	}
	if (reserved < 0)
		reserved = 0;
	*/

	FlightBooking booking[10];
	string command = "";
	int n;
	int id;
	int teljari = 0;
	int s = 0;

	while (command != "quit") {		
		cout << endl << "What would you like to do?: ";
		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> id >> n;

		cout << endl << "n: " << n << endl;
		for (int i = 0; i < 10; i++)
		{
			if (booking[i].returnId() == id) {
				s = i;
				cout << "return id: " << booking[i].returnId() << " done." << endl;
			}
		}

		if (command == "add"){
			cout << "---------";
			booking[id].printStatus();
			booking[id].reserveSeats(n);
			cout << "---------";
		}
		else if (command == "cancel")
			booking[id].cancelReservations(n);
		else if (command == "create") {
			int q = teljari;
			for (int i = 0; i < 10; i++) {
				if (booking[i].returnId() == -1) {
					q = i;
				}
			}
			booking[q] = FlightBooking(id, n, 0);
			teljari += 1;
		}
		else if (command == "delete") {
			booking[s] = FlightBooking(-1, 0, 0);
			teljari += 1;
		}
		for (int i = 0; i < 10; i++)
		{
			if (booking[i].returnId() != 0)
				booking[i].printStatus();
		}
	}
	return 0;
}
