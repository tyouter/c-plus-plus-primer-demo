#include<stdio.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

/*
*	 ��д�������Զ�ģʽ��һ���ļ����������ݶ��뵽һ��string �� vector �У���ÿһ����Ϊһ��������Ԫ�ش��� vector�С�
*/
typedef vector<string> file;
// ���ļ�����

file readfile(const string &s){
	file saveAsLine;
	ifstream input(s);
	string sTemp;

	if (input){
		while (getline(input, sTemp)){
				
				// ��Ϊ�ַ�����ȡ
				string word;
				istringstream record(sTemp);
				while (record >> word){
					saveAsLine.push_back(word);
				}
				
				// ��Ϊһ�ж�ȡ
				//saveAsLine.push_back(sTemp);
		}

	}
	else
		cerr << "open file faild!";
	return saveAsLine;

}

int main(){

	string filename = "D:\\Documents\\GitHub\\C++ primer\\httpd.txt";
	file savefile = readfile(filename);

	cout << "the file is:" << endl;
	for (auto i = savefile.begin(); i != savefile.end(); ++i){
		cout << *i << endl;
	}

	system("pause");
	return 0;
}