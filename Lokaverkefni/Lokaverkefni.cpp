//Kolbeinn Ingólfsson
//Lokaverkefni FORR3CG05DU


//Kolbeinn Ingólfsson
//Lokaverkefni FORR3CG05DU
#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

class Booking {
protected:
	int id;
	int capacity;
	int reserved;
	int gerd;

public:
	Booking(int i = 0, int cap = 0, int res = 0, int gerdin = 0) {
		id = i;
		capacity = cap;
		reserved = res;
		gerd = gerdin;
	}
	void virtual printStatus() {
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
	int FBS() {
		return gerd;
	}
};


class FlightBooking : public Booking{
public:
	FlightBooking(int id, int capacity, int reserved) {}
	void printStatus_F(){}

	class BusBooking : public Booking{
	public:
		BusBooking(int id, int capacity, int reserved) {}
		void printStatus_B(){
			double perc = (double)reserved / capacity * 100;
			cout << endl << "Bus " << id << " : " << reserved << "/" << capacity << " (" << (round(perc)) << "%) seats reserved.";
		}

		class SkipBooking : public Booking{
		public:
			SkipBooking(int id, int capacity, int reserved) {}
			void printStatus_S(){
				double perc = (double)reserved / capacity * 100;
				cout << endl << "Skip " << id << " : " << reserved << "/" << capacity << " (" << (round(perc)) << "%) seats reserved.";
			}


			class BookList {
			private:
				Booking **listi;
				int next;
				int staerd;
				int teljari = 0;
			public:
				BookList() {
					this->staerd = 2;
					listi = new Booking*[staerd];
					next = 0;
				}
				void createFlight(FlightBooking stak) {
					if (next <= staerd - 1)
						listi[next++] = new FlightBooking(stak);
					else {
						Booking **temp = new Booking*[staerd * 2];
						for (int i = 0; i < staerd; i++)
							temp[i] = listi[i];

						delete[]listi;
						listi = temp;
						staerd *= 2;
						listi[next++] = new FlightBooking(stak);
					}
				}
				void createBus(BusBooking stak) {
					if (next <= staerd - 1)
						listi[next++] = new BusBooking(stak);
					else {
						Booking **temp = new Booking*[staerd * 2];
						for (int i = 0; i < staerd; i++)
							temp[i] = listi[i];

						delete[]listi;
						listi = temp;
						staerd *= 2;
						listi[next++] = new BusBooking(stak);
					}
				}
				void createSkip(SkipBooking stak) {
					if (next <= staerd - 1)
						listi[next++] = new SkipBooking(stak);
					else {
						Booking **temp = new Booking*[staerd * 2];
						for (int i = 0; i < staerd; i++)
							temp[i] = listi[i];

						delete[]listi;
						listi = temp;
						staerd *= 2;
						listi[next++] = new SkipBooking(stak);
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
					else{//ef for lykkjan sem notar j breakaði EKKI þá varð q = i og nýtt flug/skip/bus verður til.
						if (nn == 0)
							cout << "Vinsamlegast sladu inn capacity, reyndu aftur." << endl;
						else {
							if (gerd == "flight")
								createFlight(Booking(b, nn, 0);
							else if (gerd == "skip")
								createskip(Booking(b, nn, 0);
							else if (gred == "bus")
								createBus(Booking(b, nn, 0);
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
					listi[b] = Booking(0, 0, 0);
				}
				~BookList() {
					delete[]listi;
				}
			};




			int main() {
				//FlightBooking booking[10]; //býr til listann 
				BookList booking = BookList();
				string command = "";
				string gerd = "";
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
					cout << endl << "Dæmi: create/add/cancel/delete flight/skip/bus ID N" << endl;
					ss >> command >> id >> gerd >> n;
					if (n >= 0){
						if (command == "create"){
							if (gerd == "flight")
								booking.create(id, n, 1);
							else if (gerd == "skip")
								booking.create(id, n, 2);
							else if (gred == "bus")
								booking.create(id, n, 3);
							else
								cout << endl << "Vinsamlegast reyndu aftur" << endl;
						}
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
					}
					else
						cout << endl << "Reyndu aftur." << endl;



					booking.syna();
					n = 0;
				}
				return 0;
			}
		}