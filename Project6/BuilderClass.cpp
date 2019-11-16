#include "BuilderClass.h"
#include <iostream>
using namespace std;

int Buildermain()
{
	MealBuilder* mealBuilder = new MealBuilder();
	Meal* vegMeal = mealBuilder->prepareVegMeal();
	cout << "Veg meal" << endl;
	vegMeal->showItems();
	cout << "Total cost : ";
	cout << vegMeal->getCost() << endl;
	return 0;
}