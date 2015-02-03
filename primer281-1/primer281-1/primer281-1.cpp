// primer281-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <sstream>
std::istream &StreamState(std::istream &str){
	std::string s;
	while (str >> s){
		std::istringstream temps(s);
		std::string output;
		while (temps >> output){
			std::cout << output << std::endl;
		}
		//std::cout << s << std::endl;

	}
			//std::cout << s << std::endl;
	str.clear();
	return str;
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::istream &str = StreamState(std::cin);
	std::istream::iostate str_state = str.rdstate();
	std::cout << std::endl;
	std::cerr << "str state is:" << (str_state == 0 ? "good" : "fault");
	system("pause");
	return 0;
}

