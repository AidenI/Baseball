#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <sstream>

using namespace std;

typedef struct
{
	int sCount;
	int bCount;
}score_value;

const int MAX_SIZE = 10;
const int CARD_SIZE = 3;

void introMSG();
string inputNum();
bool compare(string userInput, string comNum);
score_value calcCount(int i, int j, score_value* foo);
score_value calcCompare(string userInput, string comNum, int i, int j, score_value* foo);

class Computer
{
public:
	string GetNum() { return m_strComNum; }	

	void SetRandNum() {
		int card[MAX_SIZE] = {0,};
		stringstream ss;
		srand((unsigned)time(NULL));
			
		shuffleCard(card);
		for (int i = 0; i < CARD_SIZE; i++)	{
			ss << card[i+1];
		}
		m_strComNum = ss.str();
	}

	void shuffleCard(int* card)
	{
		for (int i = 1; i < MAX_SIZE; i++)
			card[i] = i;

		for (int i = 9; i > 1; --i)
		{
			int s = (rand() % i) + 1;
			int temp = card[s];
			card[s] = card[i];
			card[i] = temp;
		}
	}
private:
	string m_strComNum;
};

int main() {
	string arrUser;	
	bool bFlag = false;
	Computer com;
	com.SetRandNum();
	const string comNum = com.GetNum();

	while(bFlag == false) {
		introMSG();
		arrUser = inputNum();	
		compare(arrUser, comNum);
	}
	return 0;
}

void introMSG() {
	string strHead = "Play BaseBall Game!";

	cout << setw(strHead.size()+3) << setfill('*') << " " << endl;
	cout << '*' << strHead << '*' << endl;
	cout << setw(strHead.size()+3) << setfill('*') << " " << endl;
}

string inputNum() {
	string str;
	bool bInputFlag = false;

	while (bInputFlag == false)	{
		cout << "3자리 수를 입력하세요 : ";
		cin >> str;
		if(str.size() == CARD_SIZE)
			bInputFlag = true;
	}
	return str;
}

bool compare(string userInput, string comNum) 
{
	score_value value = {0, };
	int i = 0;
	int j = 0;
	bool bResultFlag = true;
	for(i = 0; i < CARD_SIZE; i++)
	{
		for(j = 0; j < CARD_SIZE; j++)
		{
			value = calcCompare(userInput, comNum, i, j, &value);
		}
	}
	cout << value.sCount << " 스트라이크 " << value.bCount << " 볼입니다." << endl;
	if(value.sCount == 3 && value.bCount == 0)
		return bResultFlag;
}


score_value calcCount(int i, int j, score_value* foo)
{	
	if(i == j)
		foo->sCount++;
	else
		foo->bCount++;

	return *foo;
}

score_value calcCompare(string userInput, string comNum, int i, int j, score_value* foo)
{
	if(userInput[i] == comNum[j])
	{
		*foo = calcCount(i, j, foo);
	}	

	return *foo;
}