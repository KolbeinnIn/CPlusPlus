#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}

void FlightBooking::printStatus() {
	int perc = (double)reserved / capacity * 100;
	cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << (perc) << "\%) seats reserved." << endl;
}

bool FlightBooking::reserveSeats(int number_ob_seats) {
	// try to add reservations and return 'true' on success keep the limits in mind  
	return false;
}
bool FlightBooking::canceReservations(int number_ob_seats){

	// try to cancel reservations and return 'true' on success keep the  limits in mind  
	return false;
}

int main() {
	int reserved = 0, capacity = 0, max = 0;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	max = round(capacity * 1.05);
	while (reserved > max || reserved == 0){
		cout << "Provide number of reserved seats: ";
		cin >> reserved;
	}

	FlightBooking booking(1, capacity, reserved);
	booking.printStatus();
	return 0;
}