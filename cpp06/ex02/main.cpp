#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	int rand = std::rand() % 3;
	switch (rand)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			std::cerr << "Something wrong with the random generator" << std::endl;
			return 0;
	}
}

void identity(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A is the identified type" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B is the identified type" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C is the identified type" << std::endl;
		return ;
	}
}

void identity(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": A Failed" << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": B Failed" << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": C Failed" << std::endl;
	}
}

int	main(void)
{
	std::srand(std::time(0));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "====== " << i + 1 << " Try  ======" << std::endl;
		Base	*base = generate();

		if (!base)
			return (1);
		identity(base);
		identity(*base);
		delete base;
		std::cout << std::endl;
	}
}
