#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Dyr {
protected:
	string nafn;
public:
	Dyr(string nafn1 = ""){
		this->nafn = nafn1;
	}
	void virtual segir(){
		cout << nafn << endl;
	}
};

class Hundur : public Dyr {
public:
	Hundur() : Dyr() {}
	Hundur(string nafn) : Dyr(nafn) {}
	void segir() {
		cout << "Voff" << endl;
	}
};

class Kottur : public Dyr {
public:
	Kottur() : Dyr() {}
	Kottur(string nafn) : Dyr(nafn) {}
	void segir() {
		cout << "Mjá" << endl;
	}
};

int main() {
	Dyr **dyragardur = new Dyr*[2];

	dyragardur[0] = new Hundur("Snati");
	dyragardur[1] = new Kottur("Snotra");

	dyragardur[0]->segir();
	dyragardur[1]->segir();

	/*
	Ætti að skrifa út:

	Voff
	Mjá

	*/

	return 0;
}
