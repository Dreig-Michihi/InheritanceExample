#pragma once
#include <string>
#include <iostream>
using namespace std;
class creature
{
private:
	string title;
	double mass;//kg
protected:
	creature(): mass(0.0) {}
	creature(const creature& obj): title(obj.title), mass(obj.mass) {}//конструктор копирования
	creature(const string&_title, double _mass): title(_title), mass(_mass) {}
	//деструктор объявлен как виртуальный
	virtual ~creature() {
		cout << "creature deleted" << endl << endl;
	}
	//виртуальная функция для вывода информации об объекте
	virtual void _print() const{
		cout << "title: " << title << ", mass: " << mass;
	}
public:
	//открытая функция для вывода информации об объекте
	void print() const {
		cout << typeid(*this).name() << ": (";
		//вызов виртуальной функции
		//т.к. функция _print() виртуальная, она вызываться не будет
		//не только из текущего класса, но и из производных,
		//в зависимости от того, для какого объекта осуществляется вызов
		_print();
		cout << ")" << endl;
	}
	double get_mass() const {
		return mass;
	}
};
//класс animal наследуется от класса creature
class animal : public creature {
private:
	double speed;//m/s
public:
	animal(): creature() {}
	animal(const animal& obj): creature(obj), speed(obj.speed) {}//конструктор копирования
	animal(const string&_title, double _mass, double _speed): creature(_title,_mass), speed(_speed) {}
	~animal() {
		cout << "animal deleted" << endl;
	}
	double get_speed() const {
		return speed;
	}
protected:
	//вирутальная функция print переопределяется в производном классе
	void _print() const {
		creature::_print();
		cout << ", speed: " << speed;
	}
};
//класс bird наследуется от класса animal
class bird : public virtual animal {
private:
	double topfly;//km
public:
	bird() :animal() {}
	bird(const bird& obj) :animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly) : animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() {
		cout << "bird deleted" << endl;
	}
protected:
	void _print() const {
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};
//класс fish наследуется от класса animal
class fish : public virtual animal {
private:
	double maxdeep;//km
public:
	fish():animal(){}
	fish(const fish& obj) :animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep) : animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish() {
		cout << "fish deleted" << endl;
	}
protected:
	void _print() const {
		animal::_print();
		cout << ", maxdeep: " << maxdeep;
	}
};
//класс predator наследуется от класса animal
class predator : public virtual animal {
protected:
	predator() {}
public:
	~predator() {}
	//чисто виртуальная функция hunt будет определять 
	//посредством производных классов
	//удастся ли хищнику поохотиться на жертву (obj)
	virtual bool hunt(const animal& obj) = 0;
	//т.к. фунция hunt	чисто виртуальная, класс predator является абстрактным
};
//далее используется множественное наследование, т.к. орёл - и птица и хищник.
class eagle : public bird, public predator {
public:
	eagle() : bird() {}
	//из-за виртуального наследования, для передачи параметров в контсруктор класса animal, его необходимо вызвать явно
	eagle(const eagle& obj) :bird(obj), animal(obj) {}
	eagle(double _mass, double _speed, double _topfly) : bird("Орёл", _mass, _speed, _topfly), animal("Орёл", _mass, _speed) {}
	//определение тела функции hunt
	//т.к. функция hunt определена, класс eagle - НЕ абстрактный
	bool hunt(const animal& obj) {
		//функция get_mass может наследоваться классом eagle из класса animal
		//и через класс bird, и через класс predator
		//нужно указать, что она наследуется через bird
		return obj.get_mass() < bird::get_mass() && obj.get_speed()<bird::get_speed();
	}
};

