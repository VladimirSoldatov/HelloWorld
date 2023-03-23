#include<iostream>
#include <map>
#include<algorithm>
#include <vector>
#include <set>
using namespace std;
int myFunc(int massive[], int size)
{
	int count;
	int flag = true;
	int number = 0;
	for (int i = 0;i<size; i++)
	{
		count = 0;
		for (int j = 0;j<size;j++)
		{
			if (i == j)
				continue;
			if (massive[i] == massive[j])
				count++;
		}
		if (count == 0)
		{
			number = massive[i];
			//flag = false;
			break;
		}
	}


	return number;
}


int myFunc1(int massive[],int size)
{
	int result = -1;
	map<int, int> dict;
	for (int i = 0; i < size; i++)
	{
		if (dict.find(massive[i]) == dict.end())
		{
			dict[massive[i]]= 1;
		}
		else
		{
			dict[massive[i]]++;
		}
		
	}
	for (map<int, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
	{
		if ((*iter).second == 1)
		{
			result = (*iter).first;
		}
	}
	return result;
}
int myFunc3(int massive[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result ^= massive[i];
	}
	return result;
}
int myFunc4(int massive[], int size) 
{
	int result = -1;
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back(massive[i]);
	}
	for (int item : vec)
	{
		if (count_if(vec.begin(), vec.end(), [item](int elem) {return elem == item; }) == 1)
			result = item;
	}
	return result;
}

int maxContinue(string phrase)
{
	int count = 0;
	int maxCount = 0;
	char tmp = '\0';
	for (char cel : phrase)
	{
		
	
		if (cel != tmp)
		{
			count++;
		}
		else
		{

			count = 0;
		}
		if (count > maxCount)
			maxCount = count;
		tmp = cel;

	}
	return maxCount;
}
bool anagramma(string text1, string text2 )
{
	sort(text1.begin(), text1.end());
	cout << text1 <<endl;
	sort(text2.begin(), text2.end());
	cout << text2<<endl;
	bool result = false;
	map<char, int> dict1;
	map<char, int> dict2;
	if (text1.size() != text2.size())
		return false;
	for (int i = 0; i < text1.size(); i++)
	{
		if (dict1.find(text1.at(i)) == dict1.end())
			dict1[text1.at(i)] = 1;
		else
			dict1[text1.at(i)]++;
		if (dict2.find(text2.at(i)) == dict2.end())
			dict2[text2.at(i)] = 1;
		else
			dict2[text2.at(i)]++;

	}
	if (dict1 == dict2)
		result = true;
	return result;
}
int main()
{
	int massive1[]{ 1,2,2,4,5,6,1,6,5 };//4
	int massive2[]{ 1,2,1 };//2
	int massive3[]{ 1,2,3,4,5,6,1,2,3,4,5 };//6
	int massive4[]{ 4,2,7,3,4,3,0,7,2 };
	int* massive5 = new int[3] {1, 2, 3};
	//cout << myFunc(massive1) << endl;
	//cout << myFunc(massive2) << endl;
	//cout << myFunc(massive3) << endl;
	//cout << myFunc(massive4) << endl;
	cout << myFunc4(massive1, sizeof(massive1)/sizeof(int)) << endl;
	cout << myFunc3(massive2, sizeof(massive2) / sizeof(int)) << endl;
	cout << myFunc3(massive3, sizeof(massive3) / sizeof(int)) << endl;
	cout << myFunc3(massive4, sizeof(massive4) / sizeof(int)) << endl;
	string str = "sssshghgg"; //4
	string str1 = "sssss";//1
	string str2 = "htdrfd";//6
	string str3 = "kkqosddfghd";//5 макимальное количество
	string str4 = "k";//1 макимальное количество
	cout << endl;
	cout << maxContinue(str) << endl;
	cout << maxContinue(str1) <<endl;
	cout << maxContinue(str2) << endl;
	cout << maxContinue(str3) << endl;
	cout << maxContinue(str4) << endl;
	///////////////////
	string str41 = "maska";
	string str5 = "skama";//Да
	string str6 = "skaama";//Анагарамма или нет
	string str7 = "skamm";//Анагарамма или нет
	cout << anagramma(str41, str6);



}
