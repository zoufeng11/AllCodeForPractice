#pragma once
#include<string>
#include<iostream>
#include<list>

using namespace std;
class Packing
{
public:
	virtual string pack() = 0;
};

class Item
{
public:
	virtual string name() = 0;

	virtual Packing* packing() = 0;

	virtual float price() = 0;

};



class Wrapper : public Packing
{
public:
	virtual string pack()
	{
		return "Wrapper";
	}
};

class Bottle : public Packing
{
public:
	virtual string pack()
	{
		return "Bottle";
	}
};

class Burger :public Item
{
public:
	virtual Packing* packing()
	{
		return (new Wrapper());
	}
};

class Drink : public Item
{
public:
	virtual Packing* packing()
	{
		return (new Bottle());
	}

};

class VegBurger : public Burger
{
public:
	virtual float price()
	{
		return 25.0f;
	}
	virtual string name()
	{
		return "Veg Burger";
	}
};

class MeatBurger : public Burger
{
public:
	virtual float price()
	{
		return 50.0f;
	}
	virtual string name()
	{
		return "MeatBurger";
	}
};

class Coke :public Drink
{

public:
	virtual float price()
	{
		return 15.0f;
	}
	virtual string name()
	{
		return "Coke";
	}
};

class Pepsi :public Drink
{

public:
	virtual float price()
	{
		return 17.0f;
	}
	virtual string name()
	{
		return "Pepsi";
	}
};

class Meal
{
private:
	list<Item*> *items = new list<Item*>();
public:
	void addItem(Item *item)
	{
		items->push_back(item);
	}
	float getCost()
	{
		float cost = 0.0f;
		list<Item*>::iterator it = items->begin();
		while (it != items->end())
		{
			cost += (*it)->price();
			it++;
		}
		return cost;
	}
	void showItems()
	{
		list<Item*>::iterator it = items->begin();
		while (it != items->end())
		{
			cout << "Item :" + (*it)->name() << endl;
			cout << "Packing :" + (*it)->packing()->pack() << endl;
			cout << "Price  :  ";
			cout << (*it)->price() << endl;
			it++;
		}
	}

};

class MealBuilder
{
public:
	Meal *prepareVegMeal()
	{
		Meal* meal = new Meal();
		meal->addItem(new VegBurger);
		meal->addItem(new Coke);
		return meal;
	}

	Meal* prepareMeatMeal()
	{
		Meal* meal = new Meal();
		meal->addItem(new MeatBurger);
		meal->addItem(new Pepsi());
		return meal;
	}

};

