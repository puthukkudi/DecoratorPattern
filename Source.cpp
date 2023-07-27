
using namespace std;
#include <iostream>

class  Component
{
public:
	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
public :
	ConcreteComponent()
	{
		cout << "ConcreteComponent ctor \n";
	}

	void Operation() override
	{
		cout << "ConcreteComponent::Operation() \n";
	}
};	

class Decorator: public Component
{
private : 
	Component* comp;
public : 
	Decorator(Component* obj)
	{
		cout << "Decorator ctor \n";
		comp = obj;
	}

	void Operation() override
	{
		cout << "Decorator::Operation() \n";
		comp->Operation();
	}

	virtual ~Decorator() {}
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component* obj) : Decorator(obj)
	{
		cout << "ConcreteDecoratorA ctor \n";
		addedState = 0;
	}

	void Operation() override
	{
		Decorator::Operation();
		addedState = 1;
		cout << "ConcreteDecoratorA::Operation() \n";
		cout << "ConcreteDecoratorA::addedState : " << addedState << endl;

	}
private:
	int addedState = 0;
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component* obj) : Decorator(obj)
	{
		cout << "ConcreteDecoratorB ctor \n";
	}

	void Operation() override
	{
		Decorator::Operation();
		cout << "ConcreteDecoratorB::Operation() \n";
		AddedBehaviour();

	}

	void AddedBehaviour()
	{
		cout << "ConcreteDecoratorB::AddedBehaviour \n";
	}
};


int main()
{
	Component* decoratorComponentA = new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent));
	decoratorComponentA->Operation();
	return 0;
}