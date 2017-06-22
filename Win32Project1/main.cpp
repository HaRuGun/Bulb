#include <iostream>

void SomeFunction(int* aPtr, int value);

int main(void)
{
	int someValue = 0;

	if (someValue < 10)
	{
		if (someValue < 5)
		{
			std::cout << "dsadas" << std::endl;
		}
	}

	//////////////////////////////////////

	if (someValue >= 10)
	{
		return 0;
	}
	if (someValue >= 5)
	{
		return 0;
	}

	std::cout << "dsadas" << std::endl;


	return 0;
}

void SomeFunction( int* aPtr, int value )
{
	if (aPtr == nullptr)
	{
		// 에러 로그
		return;
	}
	if (value == 0)
	{
		return;
	}
}