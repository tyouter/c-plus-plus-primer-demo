#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

const int KeyInt = 5;// ������int��ֵ
const string KeyStr = "fuck";
typedef vector<int>::iterator intItr;//int ������
typedef list<string>::iterator strItr;//int ������

short count(intItr begin, intItr end, int givenInt){// ������������vector��givenInt�����ĸ���
	short countInt = 0;
	for (intItr i = begin; i != end; ++i){
		if (*i == givenInt)
			countInt++;
		else
			continue;
	}
	return countInt;
}

// ����count ʵ����list<string>�е�Ӧ��
short count(strItr begin, strItr end, string givenStr){
	short countInt = 0;
	for (strItr i = begin; i != end; ++i){
		if (*i == givenStr)
			countInt++;
		else
			continue;
	}
	return countInt;
}

// ��ӡ���������ڸ�ʽ����ӡ��䣬��ӡstring
void print(const string givenWord, short count){
	cout << "The count(s) of the given " << "string" << " \"" << givenWord << "\" " << "is(are):" << endl;
	cout << count << endl;
}
// ���ش�ӡ��������ӡint
void print(const int givenWord, short count){
	cout << "The count(s) of the given " << "int" << " \"" << givenWord << "\" " << "is(are):" << endl;
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