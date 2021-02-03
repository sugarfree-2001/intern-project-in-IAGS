#include<iostream>
#include"Pizza.h"
#include"PizzaStore.h"
 
int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* ChicagoStore = new ChicagoPizzaStore();
	Pizza* pizza = nyStore->orderPizza(cheese);//ordered for A
	std::cout << "completed " << std:: endl;
	std::cout << "ordered for A " << pizza->getName() << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	pizza = ChicagoStore->orderPizza(cheese);//ordered for B
	std::cout << "completed " << std::endl;
	std::cout << "ordered for B " << pizza->getName() << std::endl;
}
