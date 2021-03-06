#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Afangi {
private:
	int numer;
	string nafn;
	Afangi *undanfarar;
	int fjoldiUndanfara;
public:
	Afangi() : numer(0), nafn(""), undanfarar(nullptr), fjoldiUndanfara(0) { }

	Afangi(int numer, string nafn) {
		this->numer = numer;
		this->nafn = nafn;
		this->undanfarar = nullptr;
		this->fjoldiUndanfara = 0;
	}

	void baetaVidUndanfara(Afangi undanfari) {
		// Ef enginn undanfari er skr��u � �fangann
		// � a� b�a til n�tt fylki me� pl�ssi fyrir
		// einn �fanga og setja undanfarann � �a�.
		// Annars � a� st�kka fylki� um eitt stak og
		// b�ta undanfaranum � �a�
		undanfarar = new Afangi[fjoldiUndanfara+2];

		if (fjoldiUndanfara <= sizeof(undanfarar)){
			undanfarar[fjoldiUndanfara++] = undanfari;
		}
		else {
			Afangi *temp = new Afangi[fjoldiUndanfara + 1];
			for (int i = 0; i < sizeof(undanfarar)+1; i++){;
				temp[i] = undanfarar[i];
			}
			delete[]undanfarar;
			undanfarar = temp;
			fjoldiUndanfara++;

			undanfarar[fjoldiUndanfara++] = undanfari;
		}
	}


	void prentaAfanga() {
		cout << "Numer: " << this->numer << " Nafn: " << this->nafn << endl;
		if (undanfarar) {
			cout << (this->fjoldiUndanfara == 1 ? "Undanfari: " : "Undanfarar: ") << endl;
			for (int i = 0; i < this->fjoldiUndanfara; i++) {
				this->undanfarar[i].prentaAfanga();
			}
		}
	}
};

int main() {
	Afangi forr1 = Afangi(11, "Forritun IA");
	Afangi forr2 = Afangi(12, "Forritun II");
	Afangi gagn1 = Afangi(21, "Gagnasafnsfr. I");
	gagn1.baetaVidUndanfara(forr1);
	gagn1.prentaAfanga();
	cout << endl;
	Afangi forr3 = Afangi(13, "Forritun III");
	forr3.baetaVidUndanfara(forr1);
	forr3.baetaVidUndanfara(forr2);
	forr3.baetaVidUndanfara(gagn1);
	forr3.prentaAfanga();

	/*
	�tti a� skrifa �t:

	Numer: 21 Nafn: Gagnasafnsfr. I
	Undanfari:
	Numer: 11 Nafn: Forritun IA

	Numer: 13 Nafn: Forritun III
	Undanfarar:
	Numer: 11 Nafn: Forritun IA
	Numer: 12 Nafn: Forritun II
	Numer: 21 Nafn: Gagnasafnsfr. I
	Undanfari:
	Numer: 11 Nafn: Forritun IA
	*/

	return 0;
}