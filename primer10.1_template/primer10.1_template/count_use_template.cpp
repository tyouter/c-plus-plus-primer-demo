#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

const int KeyInt = 5;// ������int��ֵ
const string KeyStr = "fuck";

// ��������ֵ��������������count������T1����
template<typename T>
T self(T input){
	return input;
}

template<typename T1, typename T2>
short count(T1 begin, T1 end, T2 self(T2 given)){// ������������������given�����ĸ���
	short countNmb = 0;
	for (T1 i = begin; i != end; ++i){
		if (*i == given)
			countNmb++;
		else
			continue;
	}
	return countNmb;
}


template<typename T>
void print(T givenWord, short count){// ��ӡ���������ڸ�ʽ����ӡ���
	cout << "The count(s) of the given " << "string" << " \"" << givenWord << "\" " << "is(are):" << endl;
	cout << count << endl;
}

int main(int argc, char *argv[]){
	short countNmb;// ����count�����Ľ��
	string tString;// �����ļ��еĵ���һ��

	/*
	����count������vector<int>�еĽ��
	*/
	ifstream input("int.txt");
	vector<int> iStore;
	int givenInt = KeyInt;
	int iTemp = 0;
	if (input){
		while (getline(input, tString)){
			iTemp = atoi(tString.c_str());
			iStore.push_back(iTemp);
		}

		countNmb = count(iStore.begin(), iStore.end(), givenInt);
		print(givenInt, countNmb);
	}
	else
		cerr << "No such file" << endl;

	/*
	����count������list<string>�еĽ��
	*/
	ifstream inputstr("string.txt");
	list<string> sList;
	string givenStr = KeyStr;
	string sTemp;
	if (inputstr){
		while (getline(inputstr, tString)){
			sTemp = tString;
			sList.push_back(sTemp);
		}
		countNmb = count(sList.begin(), sList.end(), givenStr);
		print(givenStr, countNmb);
	}
	else
		cerr << "No such file" << endl;


	system("pause");
	return 0;
}