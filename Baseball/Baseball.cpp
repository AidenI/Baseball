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

const int MAX_SIZE = 9;
const int CARD_SIZE = 3;

void introMSG();
string inputNum();
bool strCompare(string userInput, string comNum);
int calcBallScore(string userInput, string comNum, int i);
bool resultOut(int sCount, int bCount);
void compare(string userInput, string comNum);
score_value calcCount(int i, int j, score_value foo);
score_value calcCompare(string userInput, string comNum, int i, int j, score_value foo);

class Computer
{
public:
	string GetNum() { return m_strComNum; }	

	void SetRandNum() {
		int card[MAX_SIZE];
		stringstream ss;
		srand((unsigned)time(NULL));
			
		shuffleCard(card);
		for (int i = 0; i < CARD_SIZE; i++)	{
			ss << card[i];
		}
		m_strComNum = ss.str();
	}

	int shuffleCard(int* card)
	{
		for (int i = 1; i < 10; i++)
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
//
//bool strCompare(string userInput, string comNum) {
//	int sCount = 0;
//	int bCount = 0;
//	bool bFlag = false;
//
//	for(int i = 0; i < 3; i++) {		
//		if(userInput.at(i) == comNum.at(i))
//		{
//			sCount++;		
//			bCount += calcBallScore(userInput, comNum, i);	
//		}
//		else
//			bCount += calcBallScore(userInput, comNum, i);	
//	}
//	bFlag = resultOut(sCount, bCount);
//
//	return bFlag;
//}
//
//int calcBallScore(string userInput, string comNum, int i) {
//	int ballScore = 0;
//	if(i > 3)
//		return ballScore;
//	for(int j = 0; j < 3; j++) {
//			if(userInput.at(i) == comNum.at(j))
//				ballScore++;
//		}
//	return ballScore;
//}
//
//bool resultOut(int sCount, int bCount) {
//	bool bFlag = false;
//	cout << sCount << " 스트라이크 " << bCount << " 볼입니다." << endl;
//	if(sCount == 3 && bCount == 0)
//		bFlag = true;
//
//	return bFlag;
//}

void compare(string userInput, string comNum) // 732, 771
{
	score_value value = {0, };
	int i = 0;
	int j = 0;
	for(i = 0; i < MAX_SIZE; i++)
	{
		for(j = 0; j < MAX_SIZE; j++)
		{
			value = calcCompare(userInput, comNum, i, j, value);
		}
	}
	cout << value.sCount << " 스트라이크 " << value.bCount << " 볼입니다." << endl;
}


score_value calcCount(int i, int j, score_value foo)
{	
	if(i == j)
		foo.sCount++;
	else
		foo.bCount++;

	return foo;
}

score_value calcCompare(string userInput, string comNum, int i, int j, score_value foo)
{
	if(userInput[i] == comNum[j])
	{
		foo = calcCount(i, j, foo);
	}	

	return foo;
}