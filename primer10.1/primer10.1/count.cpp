#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

const int KeyInt = 5;// 给定的int数值
const string KeyStr = "fuck";
typedef vector<int>::iterator intItr;//int 迭代器
typedef list<string>::iterator strItr;//int 迭代器

short count(intItr begin, intItr end, int givenInt){// 函数用来计算vector中givenInt参数的个数
	short countInt = 0;
	for (intItr i = begin; i != end; ++i){
		if (*i == givenInt)
			countInt++;
		else
			continue;
	}
	return countInt;
}

// 重载count 实现在list<string>中的应用
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

// 打印函数，用于格式化打印语句，打印string
void print(const string givenWord, short count){
	cout << "The count(s) of the given " << "string" << " \"" << givenWord << "\" " << "is(are):" << endl;
	cout << count << endl;
}
// 重载打印函数，打印int
void print(const int givenWord, short count){
	cout << "The count(s) of the given " << "int" << " \"" << givenWord << "\" " << "is(are):" << endl;
	cout << count << endl;
}

int main(int argc, char *argv[]){
	short countNmb;// 保存count函数的结果
	string tString;// 保存文件中的单独一行

	/*
	测试count函数在vector<int>中的结果
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
	测试count函数在list<string>中的结果
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