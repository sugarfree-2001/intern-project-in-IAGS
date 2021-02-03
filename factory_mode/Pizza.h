#ifndef PIZZA_H_
#define PIZZA_H_
#include<iostream>
#include<string>
#include<vector>
 
enum PizzaType{ cheese = 0, pepperoni, clam, veggie };
 
class Pizza{
public:
	Pizza(){
	}
	virtual ~Pizza(){
	}
	void prepare(){
		std::cout << "preparing " << name << std::endl;
		std::cout << "making dough... " << std::endl;
		std::cout << "adding sauce... " << std::endl;
		std::cout << "adding dosing: " <<std::endl;
		for (unsigned int i = 0; i < toppings.size(); ++i)
		{
			std::cout <<toppings[i];
		}
		std::cout << std::endl;
	}
	void bake(){
		std::cout << "baked in 350 degrees for 25 minutes" << std::endl;
	}
	void cut(){
		std::cout << "slicing the pizza" << std:: endl;
	}
	void box(){
		std::cout << "settling the pizza into packing box" << std::endl;
	}
	std::string getName(){
		return name;
	}
	void setName(std::string temp_name){
		name = temp_name;
	}
	void setdough(std::string temp_dough){
		dough = temp_dough;
	}
	void setSauce(std::string temp_sauce){
		sauce = temp_sauce;
	}
	void setToppings(std::vector<std::string> temp_topp){
		toppings.assign( temp_topp.begin(),temp_topp.end());
	}
private:
	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;
};
 
class NYStyleCheesePizza :public Pizza{
public:
	NYStyleCheesePizza(){
		setName("NewYork Style Cheese Pizza");
		setdough("thin, hard dough");
		setSauce("ketchup");
		std::vector<std::string > temp_topp;
		temp_topp.push_back("mashed");
		temp_topp.push_back("Reddiano");
		temp_topp.push_back("cream");
		setToppings(temp_topp);
	}
};
 
class ChicagoStyleCheesePizza :public Pizza{
public:
	ChicagoStyleCheesePizza(){
		setName("Chicago Style Cheese Pizza");
		setdough("very thin, hard dough");
		setSauce("plum ketchup");
		std::vector<std::string > temp_topp;
		temp_topp.push_back("chopped");
		temp_topp.push_back("Mozzarella");
		temp_topp.push_back("cream");
		setToppings(temp_topp);
	}
	void cut(){
		std::cout << "cutting the pizza into squares" << std::endl;
	}
};
 
#endif
