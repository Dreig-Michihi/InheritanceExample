#pragma once
#include <iostream>
using namespace std;
class B1
{
public:
	B1() {
		cout << "Object of " << typeid(*this).name() << " was created!\n";
	}
	~B1() {
		cout << "Object of " << typeid(*this).name() << " was destroyed!\n";
	}
};
class B2
{
public:
	B2() {
		cout << "Object of " << typeid(*this).name() << " was created!\n";
	}
	~B2() {
		cout << "Object of " << typeid(*this).name() << " was destroyed!\n";
	}
};
class D1: private virtual B1, public virtual B2
{
public:
	D1() {
		cout << "Object of " << typeid(*this).name() << " was created!\n";
	}
	~D1() {
		cout << "Object of " << typeid(*this).name() << " was destroyed!\n";
	}
};
class D2: public virtual B1, private virtual B2
{
public:
	D2() {
		cout << "Object of " << typeid(*this).name() << " was created!\n";
	}
	~D2() {
		cout << "Object of " << typeid(*this).name() << " was destroyed!\n";
	}
};
class D3: private D1, public D2
{
public:
	D3() {
		cout << "Object of " << typeid(*this).name() << " was created!\n";
	}
	~D3() {
		cout << "Object of " << typeid(*this).name() << " was destroyed!\n";
	}
};
