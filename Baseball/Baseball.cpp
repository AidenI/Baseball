#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <sstream>

using namespace std;

void introMSG();
string inputNum();

class Computer
{
public:
	string GetNum() { return m_strComNum; }	

	void SetRandNum()
	{
		int arr[3];
		stringstream ss;
		srand((unsigned)time(NULL));

		for (int i = 0; i < 3; i++)
		{	
			arr[i] = rand() % 10;
		}	
		for (int i = 0; i < 3; i++)
		{
			ss << arr[i];
		}
		m_strComNum = ss.str();
	}
private:
	string m_strComNum;
};

int main()
{
	string arrUser;
	
	int i = 0;
	
	introMSG();
	arrUser = inputNum();	

	Computer com;
	com.SetRandNum();
	string a = com.GetNum();

	return 0;
}

void introMSG()
{
	string strHead = "Play BaseBall Game!";

	cout << setw(strHead.size()+3) << setfill('*') << " " << endl;
	cout << '*' << strHead << '*' << endl;
	cout << setw(strHead.size()+3) << setfill('*') << " " << endl;
}

string inputNum()
{
	string str;
	bool bInputFlag = false;

	while (bInputFlag == false)
	{
		cout << "3자리 수를 입력하세요 : ";
		cin >> str;
		if(str.size() == 3)
			bInputFlag = true;
	}

	return str;
}

void strCompare(string userInput, string comNum)
{
	int sCount = 0;
	int bCount = 0;
	
	sCount = calCount(userInput, comNum);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j <3; j++)
		{
			if(userInput.at(i) == comNum.at(i))
				sCount++;
		}
	}
}

int calCount(string userInput, string comNum)
{
	int count = 0;
	for(int i = 0; i < 3; i++)
		{
			if(userInput.at(i) == comNum.at(i))
				count++;
		}
	return count;
}