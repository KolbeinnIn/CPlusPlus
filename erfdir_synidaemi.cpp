#include <iostream>

using namespace std;

class A {
private:
	int pri_a;
protected:
	int pro_a;
public:
	int pub_a;
	A() {
		pri_a = pro_a = pub_a = 0;
		cout << "A constructor" << endl;
	}
	A(int pri_a, int pro_a, int pub_a) {
		cout << "A hinn constructorinn\n";
		this->pri_a = pri_a;
		this->pro_a = pro_a;
		this->pub_a = pub_a;
	}
	virtual void synaNafn() {
		cout << "A" << endl;
	}
};

class B : private A {
private:
	int pri_b;
protected:
	int pro_b;
public:
	int pub_b;
	B() : A(1, 2, 3) {
		pri_b = pro_b = pub_b = 0;
		cout << "B constructor" << endl;
		//cout << "pri_a: " << pri_a << endl;
		cout << "pro_a: " << pro_a << endl;
		cout << "pub_a: " << pub_a << endl;

	}
	void synaNafn() {
		cout << "B" << endl;
	}
};

class C : protected A {
private:
	int pri_c;
protected:
	int pro_c;
public:
	int pub_c;
	C() {
		pri_c = pro_c = pub_c = 0;
		cout << "C constructor" << endl;
		//cout << "pri_a: " << pri_a << endl;
		cout << "pro_a: " << pro_a << endl;
		cout << "pub_a: " << pub_a << endl;
	}
	void synaNafn() {
		cout << "C" << endl;
	}
};

class D : public A {
private:
	int pri_d;
protected:
	int pro_d;
public:
	int pub_d;
	D() {
		pri_d = pro_d = pub_d = 0;
		cout << "D constructor" << endl;
		//cout << "pri_a: " << pri_a << endl;
		cout << "pro_a: " << pro_a << endl;
		cout << "pub_a: " << pub_a << endl;
	}
	void synaNafn() {
		cout << "D" << endl;
	}
};

int main() {
	A a;
	cout << "-----------------------\n";

	B b; // class B : private A
	// cout << "b.pri_a: " << b.pri_a << endl; 
	// cout << "b.pro_a: " << b.pro_a << endl; 
	// cout << "b.pub_a: " << b.pub_a << endl; 
	cout << "-----------------------\n";

	C c; // class C : protected A
	// cout << "c.pro_a: " << c.pro_a << endl; 
	// cout << "c.pri_a: " << c.pri_a << endl; 
	// cout << "c.pub_a: " << c.pub_a << endl; 
	cout << "-----------------------\n";

	D d; // class D : public A
	// cout << "d.pri_a: " << d.pri_a << endl; 
	// cout << "d.pro_a: " << d.pro_a << endl; 
	// cout << "d.pub_a: " << d.pub_a << endl; 
	cout << "-----------------------\n";

	A *ad = new D();

	cout << "-----------------------\n";
	ad->synaNafn();

	cout << "-----------------------\n";
	static_cast<D*>(ad)->synaNafn();
	// static_cast<C*>(ad)->synaNafn();

	return 0;
}