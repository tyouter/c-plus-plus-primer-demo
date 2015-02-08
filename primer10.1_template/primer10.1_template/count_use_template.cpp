#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

const int KeyInt = 5;// 给定的int数值
const string KeyStr = "fuck";

// 返回输入值函数，用以区别count函数中T1类型
template<typename T>
T self(T input){
	return input;
}

template<typename T1, typename T2>
short count(T1 begin, T1 end, T2 self(T2 given)){// 函数用来计算容器中given参数的个数
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
void print(T givenWord, short count){// 打印函数，用于格式化打印语句
	cout << "The count(s) of the given " << "string" << " \"" << givenWord << "\" " << "is(are):" << endl;
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