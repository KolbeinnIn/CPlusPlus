#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Afangi {
private:
	class AfangiNode {
	public:
		Afangi *undanfari;
		AfangiNode *naesti;
		AfangiNode(Afangi *undanfari) : undanfari(undanfari), naesti(nullptr) {}
	};
	int numer;
	string nafn;
	AfangiNode *undanfarar; // virkar eins og head
public:
	Afangi() : numer(0), nafn(""), undanfarar(nullptr) { }
	Afangi(int numer, string nafn) : numer(numer), nafn(nafn), undanfarar(nullptr) { }

	void baetaVidUndanfara(Afangi *undanfari) {
		AfangiNode *nyrUndanfari = new AfangiNode(undanfari);
		//undanfarar = head
		if (undanfarar == NULL) { //ég kíki hvort listinn sé tómur
			undanfarar = nyrUndanfari;
		}
		else {
			AfangiNode *bid = new AfangiNode(undanfari);
			bid = undanfarar;
			while (bid->naesti != NULL) { //while lykkja sem finnur seinasta stakið í listanum
				bid = bid->naesti;
			}
			bid->naesti = nyrUndanfari;
		}
	}

	void prentaAfanga() {
		cout << "Numer: " << this->numer << " Nafn: " << this->nafn << endl;
		AfangiNode *undanfarinn = undanfarar;
		while (undanfarinn) {
			cout << "Undanfari: " << undanfarinn->undanfari->nafn << endl;
			undanfarinn = undanfarinn->naesti;
		}
	}
};

int main() {
	Afangi *forr1 = new Afangi(11, "Forritun IA");
	Afangi *forr2 = new Afangi(12, "Forritun II");
	Afangi *gagn1 = new Afangi(21, "Gagnasafnsfr. I");

	gagn1->baetaVidUndanfara(forr1);
	gagn1->prentaAfanga();
	cout << endl;

	Afangi *forr3 = new Afangi(13, "Forritun III");
	forr3->baetaVidUndanfara(forr1);
	forr3->baetaVidUndanfara(forr2);
	forr3->baetaVidUndanfara(gagn1);
	forr3->prentaAfanga();

	/*
	Ætti að skrifa út:

	Numer: 21 Nafn: Gagnasafnsfr. I
	Undanfari: Forritun IA

	Numer: 13 Nafn: Forritun III
	Undanfari: Forritun IA
	Undanfari: Forritun II
	Undanfari: Gagnasafnsfr. I
	*/

	return 0;
}