// Task 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class GameObj {
protected:
	string name;
	string lore;
	int x, y;
public:
	GameObj() :name(""), lore("Неизвестный объект"), x(0), y(0) {}
	GameObj(const GameObj& obj) : name(obj.name), lore(obj.lore), x(obj.x), y(obj.y) {}
	GameObj(const string& _name, const string& _lore, int _x, int _y) : name(_name), lore(_lore), x(_x), y(_y) {}
	~GameObj() {}
	virtual void show() = 0;
	void addLore(string newlore) {
		lore += newlore;
	}
	string getName() {
		return name;
	}
	string getLore() {
		return lore;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
};
class Entity : public GameObj {
protected:
	int power;
public:
	Entity() : GameObj(), power(0) {}
	Entity(const Entity& obj) : GameObj(obj), power(obj.power) {}
	Entity(string _name, string _lore, int _x, int _y, int _power) : GameObj(_name, _lore, _x, _y), power(_power) {}
	~Entity() {}
	virtual void move(int,int) = 0;
	void show() {
		cout << this->name << " сейчас находится на координатах (" << this->x << "; " << this->y << ")\n";
	}
};
class MythAnimal : public Entity {
public:
	MythAnimal() : Entity() {}
	MythAnimal(const MythAnimal& obj) : Entity(obj) {}
	MythAnimal(string _name, string _lore, int _x, int _y, int _power) : Entity(_name, _lore, _x, _y, _power) {}
	~MythAnimal() {}
	void move(int new_x, int new_y) override{
		cout << this->name << " мистически перемещается с (" << this->x << "; " << this->y << ") на (" << new_x << "; " << new_y << ").\n";
		x = new_x;
		y = new_y;
	}
	void attack(Entity& obj) {
		move(obj.getx(), obj.gety());
		cout << this->name << " напал на " << obj.getName() << "!\nЗаписи обновлены.\n";
		obj.addLore("\n-Был жестоко атакован ужасным мистическим чудищем, известным как " + name);
		lore = "\n-Напал на жалкого " + obj.getName();
	}
};
class Human : public Entity {
public:
	Human() : Entity() {}
	Human(const Human& obj) : Entity(obj) {}
	Human(string _name, string _lore, int _x, int _y, int _power) : Entity(_name, _lore, _x, _y, _power) {}
	~Human() {}
	void move(int new_x, int new_y) override {
		cout << this->name << " по-человечески перемещается с (" << this->x << "; " << this->y << ") на (" << new_x << "; " << new_y << ").\n";
		x = new_x;
		y = new_y;
	}
};
class Firebender : public Human{
public:
	Firebender() : Human() {}
	Firebender(const Firebender& obj) : Human(obj) {}
	Firebender(string _name, string _lore, int _x, int _y, int _power) : Human(_name, _lore, _x, _y, _power) {}
	~Firebender() {}
	void useMagic() {
		cout << this->name << " создаёт огонь в руках. *звуки огня*";
	}
	void useMagic(Entity& obj) {
		cout << this->name << " атакует огнём в сторону "<<obj.getName()<<". *звуки огня*" << "!\nЗаписи обновлены.\n";
		obj.addLore("\n-Был поджарен магом огня по имени " + name);
		lore = "\n-Поджарил " + obj.getName();
	}
};
class Airbender : public Human {
public:
	Airbender() : Human() {}
	Airbender(const Airbender& obj) : Human(obj) {}
	Airbender(string _name, string _lore, int _x, int _y, int _power) : Human(_name, _lore, _x, _y, _power) {}
	~Airbender() {}
	void useMagic() {
		cout << this->name << " покоряетет воздух. *звуки ветра*";
	}
	void useMagic(Entity& obj) {
		cout << this->name << " атакует воздушным потоком в сторону " << obj.getName() << ". *звуки ветра*" << "!\nЗаписи обновлены.\n";
		obj.addLore("\n-Был атакован магом воздуха по имени " + name);
		lore = "\n-Атаковал " + obj.getName();
	}
};
class Waterbender : public Human {
public:
	Waterbender() : Human() {}
	Waterbender(const Waterbender& obj) : Human(obj) {}
	Waterbender(string _name, string _lore, int _x, int _y, int _power) : Human(_name, _lore, _x, _y, _power) {}
	~Waterbender() {}
	void useMagic() {
		cout << this->name << " управляет водой. *звуки воды*";
	}
	void useMagic(Entity& obj) {
		cout << this->name << " обливает водой " << obj.getName() << ". *звуки воды*" << "!\nЗаписи обновлены.\n";
		obj.addLore("\n-Промок с головы до ног из-за мага воды по имени " + name);
		lore = "\n-Облил водой " + obj.getName();
	}
};
class Earthbender : public Human {
public:
	Earthbender() : Human() {}
	Earthbender(const Earthbender& obj) : Human(obj) {}
	Earthbender(string _name, string _lore, int _x, int _y, int _power) : Human(_name, _lore, _x, _y, _power) {}
	~Earthbender() {}
	void useMagic() {
		cout << this->name << " управляет землёй. *звуки земли*";
	}
	void useMagic(Entity& obj) {
		cout << this->name << " магией кидает камень в сторону " << obj.getName() << ". *звук летящего камня*" << "!\nЗаписи обновлены.\n";
		obj.addLore("\n-Был атакован магом земли по имени " + name);
		lore = "\n-Атаковал " + obj.getName();
	}
};
class MagicItem :public GameObj {
protected:
	string buffs;
public:
	MagicItem() : GameObj(), buffs("") {}
	MagicItem(const MagicItem& obj) : GameObj(obj), buffs(obj.buffs) {}
	MagicItem(string _name, string _lore, int _x, int _y, string _buffs) : GameObj(_name,_lore,_x,_y), buffs(_buffs) {}
	~MagicItem() {}
	void show() {
		cout << "Предмет "<< this->name << " расположен на координатах (" << this->x << "; " << this->y << ")\n";
	}
};


int main()
{
	setlocale(0, "ru");
	Human CabbageMan("Продавец капусты","Житель царства земли, просто продающий капусту.",0,0,10);
	MagicItem CabbageCart("Повозка с капустой", "Повозка, в которой очень много вкусной капусты на продажу.", 0,0, "Отличная капуста, восстанавливает силы.");
	CabbageCart.show();
	CabbageMan.show();
	Airbender Aang("Аанг", "Аватар, чьё предназначение спасти мир.", 0, -10, 200);
	Waterbender Katara("Катара", "Волшебница воды из Южного племени Воды. Путешествует вместе с Аангом, Соккой, Тоф и Момо",0,-11,150);
	Earthbender Toph("Тоф", "Величайшая волшебница земли. Слепа с детства, но это лишь сделало её сильнее. Путешествует вместе с Аангом, Соккой, Катарой и Момо", 0, -11, 300);
	Human Sokka("Сокка", "Сильнейший воин из Южного племени Воды(Потому что больше воинов там не осталось). Путешествует вместе с Аангом, Катарой, Тоф и Момо", 0, -11, 80);
	MythAnimal Momo("Момо", "Летающий лемур, питомец Аанга", 0, -8, 5);
	Firebender Azula("Азула", "Принцесса из Страны Огня, прибывшая в Царство Земли, чтобы поймать Аватара.", 0, -20, 500);
	cout << CabbageMan.getName()<<": "<< CabbageMan.getLore()<<endl;
	cout << CabbageCart.getName() << ": " << CabbageCart.getLore() << endl;
	cout << Aang.getName() << ": " << Aang.getLore() << endl;
	cout << Katara.getName() << ": " << Katara.getLore() << endl;
	cout << Sokka.getName() << ": " << Sokka.getLore() << endl;
	cout << Toph.getName() << ": " << Toph.getLore() << endl;
	cout << Momo.getName() << ": " << Momo.getLore() << endl;
	cout << Azula.getName() << ": " << Azula.getLore() << endl;
	Aang.show();
	Katara.show();
	Toph.show();
	Sokka.show();
	Momo.show();
	Azula.show();
	Aang.move(0, 10);
	Katara.move(0, 9);
	Toph.move(0, 8);
	Sokka.move(0, 7);
	Momo.move(0, 11);
	Aang.useMagic(CabbageMan);
	CabbageMan.addLore("\n-кричит: \"Моя капуста!\"");
	Azula.move(0, -1);
	Azula.useMagic(CabbageMan);
	CabbageMan.addLore("\n*присаживается в сторонке и плачет.*\n-бормочет:\"Моя капуста... бедная капуста...\"");
	cout<<CabbageMan.getLore();
	Aang.useMagic(Azula);
	Katara.useMagic(Azula);
	Toph.useMagic(Azula);
}
