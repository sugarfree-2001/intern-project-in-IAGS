#include <iostream>
using namespace std;

class AirConditioner
{
public :

     virtual void work()
     {
		 cout <<  "This is an airconditioner"  <<  endl;
	 }

};

//Concrete Component
class GREE :public AirConditioner //GREE airconditioner, made in China, famous for wallet-friendly price
{
public :
	void work()
	{
		cout << "GREE airconditioner working for you" << endl;
	}
};

//Decorator
class Decorator: public AirConditioner
{
protected:
	AirConditioner *airconditioner;

public:
	void decorator(AirConditioner *_airconditioner)
	{
		this->airconditioner = _airconditioner;
	}
	void work()
	{
		airconditioner->work();
	}
};


//DecoratorA: work in turbo mode
class TurboWork :public  Decorator
{

public:
	void work()
	{
		cout << "torbo mode already" <<endl;
		airconditioner->work();

	}
};


//DecoratorB: work silently
class SilentWork :public Decorator
{

public:
	void work()
	{
		cout << "mute already" <<endl;
		airconditioner->work();
	}
};

int main()
{
	AirConditioner *pairconditioner = new GREE();
	Decorator *pDecorator = new Decorator();
	pDecorator->decorator(pairconditioner);
	TurboWork *pTurbo = new TurboWork();
	pTurbo->decorator(pDecorator);
   	SilentWork *pTurboSlient = new SilentWork();
	pTurboSlient->decorator(pTurbo);
	pTurboSlient->work();

	return 0;
}
