// InheritanceExample2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Ex2.h"
using namespace std;

int main()
{
	setlocale(0, "Rus");
	bird raven("Ворона", 0.3, 10, 0.1);
	fish hammerhead("Рыба - молот", 150, 5, 0.5);
	eagle eagle1(1, 100, 1);
	raven.print();
	hammerhead.print();
	//динамическое создание объекта класса eagle
	//объект запоминается как ссылка на объект класса predator,
	//подобное возможно, т.е. eagle является производным для predator.
	//predator& eagle1 = *new eagle(1, 100, 1);
	eagle1.print();
	cout << "Eagle vs raven: " << eagle1.hunt(raven) << endl;
	cout << "Eagle vs hammerhead: " << eagle1.hunt(hammerhead) << endl << endl;
	//очищение динамически выделенной памяти.
	//delete &eagle1;
	return 0;
}
