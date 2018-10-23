#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
Fallið tekur inn tvo strengi, s1 og s2.
Fallið skilar til baka streng sem er samsettur úr fyrri helming s1 og fyrri helming s2.
Samsetningunni skal hagað þannig að sá strengur sem er fyrr í stafrófinu
verður aftari strengurinn.
Sjá dæmi um virkni í main fallinu.
*/
string endurRada(string s1, string s2) {
	string pre = s1.substr(0, s1.length() / 2);
	string post = s2.substr(0, s2.length() / 2);
	if (pre < post){
		return (post + pre);
	}
	else if (pre > post){
		return (pre + post);
	}
	else{
		return (pre + post);
	}
}

int main() {
	string str = endurRada("abcdef", "tuvxyz");
	cout << str << endl;  // tuvabc

	str = endurRada("tuvxyz", "abcdef");
	cout << str << endl; // tuvabc

	str = endurRada("abcXdef", "abcXdef");
	cout << str << endl; // abcabc

	str = endurRada("textinn", "tskoli");
	cout << str << endl; // tsktex

	str = endurRada("mjog langur texti", "annar langur texti");
	cout << str << endl; // mjog lanannar lan

	return 0;
}
