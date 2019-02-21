#include <iostream>
#include <time.h>

using namespace std;

class User
{
public:	
	User(){}
	User(const unsigned int _arrNum[]) : arrNum(_arrNum){}
	int GetNum() { return *arrNum; }	

private:	
	const unsigned int* arrNum;
	unsigned int askNum[3];
};

class Computer : public User
{
public:
	Computer(const unsigned int _arrNum[]) : arrComNum(_arrNum){}

	const int* GetRandNum()
	{
		int num[3] = {0, };
		srand((unsigned)time(NULL));

		for (int i = 0; i < 3; i++)
		{	
			num[i] = rand() % 10;
		}

		return num;
	}

private:
	const unsigned int* arrComNum;
};

int main()
{
	unsigned int arr[3];	
	for(int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		/*
		if(arr[i] > 9)
		{
			cout << "1~10숫자 입력" << endl;
			return 1;
		}*/
	}
	Computer c(arr);
	const int* b = new int[3];
	b =	c.GetRandNum();

	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;
	return 0;
}