#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

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
		void printStatus() {
			int perc = (double)reserved / capacity * 100;
			cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (perc) << "\%) seats reserved." << endl;
		}

		bool reserveSeats(int number_ob_seats) {
			if (reserved + number_ob_seats > round(capacity * 1.05))
				cout << "Cannot perform this operation" << endl;
			else reserved += number_ob_seats;
			return 0;
		}
		bool cancelReservations(int number_ob_seats){
			if (number_ob_seats < 0)
				cout << "Cannot perform this operation" << endl;
			else reserved -= number_ob_seats;
			return 0;
		}
};




int main() {
	int reserved = 0, capacity = 0, max = 0;
	
	cout << "Provide flight capacity: ";
	cin >> capacity;
	max = round(capacity * 1.05);
	while (reserved > max || reserved == 0){
		cout << "Provide number of reserved seats: ";
		cin >> reserved;
	}
	if (reserved < 0)
		reserved = 0;	
	FlightBooking booking = FlightBooking(1, capacity, reserved);
	string command;
	int /*id,*/ n;
	while (command != "quit") {
		booking.printStatus();
		cout << "What would you like to do?: ";
		getline(cin, command);

		stringstream ss;
		ss << command;
		ss >> command /*>> id*/ >> n;

		if (command == "add")
			booking.reserveSeats(n);
		if (command == "cancel")
			booking.cancelReservations(n);
	}
	
	booking.printStatus();
	return 0;
}