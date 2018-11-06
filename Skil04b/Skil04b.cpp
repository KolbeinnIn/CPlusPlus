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
		FlightBooking(int i, int cap, int res) {
			id = i;
			capacity = cap;
			reserved = res;
		}
		FlightBooking() {
			id = 0;
			capacity = 0;
			reserved = 0;
		}
		void printStatus() {
			int perc = (double)reserved / capacity * 100;
			cout << endl << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (perc) << "\%) seats reserved.";
		}

		void reserveSeats(int number_ob_seats) {
			if (reserved + number_ob_seats > round(capacity * 1.05) || number_ob_seats < 0)
				cout << "Cannot perform this operation" << endl;
			else reserved += number_ob_seats;
		}
		void cancelReservations(int number_ob_seats){
			if (number_ob_seats < 0 || reserved - number_ob_seats < 0)
				cout << "Cannot perform this operation" << endl;
			else reserved -= number_ob_seats;
		}
		int returnId(){
			return id;
		}
		

		
};




int main() {
	int reserved = 0, capacity = 0, max = 0;
	int teljari = 0;
	
	cout << "Provide flight capacity: ";
	cin >> capacity;
	max = round(capacity * 1.05);
	while (reserved > max || reserved == 0){
		cout << "Provide number of reserved seats: ";
		cin >> reserved;
	}
	if (reserved < 0)
		reserved = 0;

	FlightBooking booking[10];
	string command = "";
	int id, n;
	while (command != "quit") {
		booking[id].printStatus();
		cout << endl << "What would you like to do?: ";
		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> id >> n;

		if (command == "add")
			booking[id].reserveSeats(n);
		if (command == "cancel")
			booking[id].cancelReservations(n);
		if (command == "create"){
			int q = teljari;
			for (int i = 0; i < 10; i++){
				if (booking[i].returnId() == -1){
					q = i;
				}
				booking[q] = FlightBooking(id, n, 0);
				teljari += 1;
			}
		}
	}
	
	
	return 0;
}