#include<stdio.h>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

/*
*	 编写函数，以读模式打开一个文件，将其内容读入到一个string 的 vector 中，将每一行作为一个独立的元素存于 vector中。
*/
typedef vector<string> file;
// 读文件函数

file readfile(const string &s){
	file saveAsLine;
	ifstream input(s);
	string sTemp;

	if (input){
		while (getline(input, sTemp)){
				
				// 作为字符来读取
				string word;
				istringstream record(sTemp);
				while (record >> word){
					saveAsLine.push_back(word);
				}
				
				// 作为一行读取
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