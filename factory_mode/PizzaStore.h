#ifndef PIZZASTORE_H_
#define PIZZASTORE_H_
#include"pizza.h"
class PizzaStore{
public:
	Pizza* orderPizza(PizzaType type){
		Pizza* temp_pizza;
		temp_pizza = createPizza(type);
 
		temp_pizza->prepare();
		temp_pizza->bake();
		temp_pizza->cut();
		temp_pizza->box();
 
		return temp_pizza;
	}
	virtual Pizza* createPizza(PizzaType type) = 0;
};
 
class NYPizzaStore :public PizzaStore{
public:
	Pizza* createPizza(PizzaType type){
		Pizza *pizza = new Pizza;;
		switch (type)
		{
		case cheese:
			pizza = new NYStyleCheesePizza();
			break;
		/*case cheese:
			pizza = new NYStyleCheesePizza();
			break;
		case cheese:
			pizza = new NYStyleCheesePizza();
			break;*/
		default:
			std::cout << "There is not this type of pizze" << std::endl;
		}
		return pizza;
	}
};
 
class ChicagoPizzaStore :public PizzaStore{
public:
	Pizza* createPizza(PizzaType type){
		Pizza *pizza = new Pizza;
		switch (type)
		{
		case cheese:
			pizza = new ChicagoStyleCheesePizza();
			break;
			
		default:
			std::cout << "There is not this type of pizze" << std::endl;
		}
		return pizza;
	}
};
#endif
