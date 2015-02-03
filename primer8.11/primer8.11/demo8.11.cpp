#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;

struct PersonInfo{
	string name;
	vector<string> phone;
};
int main(){
	ifstream finput("D:\\Documents\\GitHub\\C++ primer\\c-plus-plus-primer-demo\\primer8.11\\phone.txt");
	string line, word;
	//string &reline = line;
	vector<PersonInfo> people;
	istringstream record;
	if (finput){
		while (getline(finput, line)){
			PersonInfo info;
			record.clear();
			record.str(line);
			record >> info.name;
			while (record >> word)
				info.phone.push_back(word);
			people.push_back(info);
		}	
	}
else
	cout << "no data ?!" << endl;

	system("pause");
	return 0;
}