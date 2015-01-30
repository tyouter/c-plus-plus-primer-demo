#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

// 书店类
class Sales_data{
	friend ostream &print(ostream &out, const Sales_data &itemdata);
	friend istream &read(istream &is, Sales_data &item);
private:
	string ISBN;
	unsigned salenum;
	double singlePrice;
	double gain;
	//double totalPrice() const;
public:
	Sales_data(){
		ISBN = "defaultbook";
		salenum = 0;
		singlePrice = 0.0;
		gain = 0.0;
	}
	string isbn() const{//加了const
		return ISBN;
	}

	Sales_data& combine(const Sales_data &sdata){// &的含义不是很清楚
		salenum += sdata.salenum;
		gain += sdata.gain;
		return *this;
	}	
};
//double Sales_data::totalPrice() const{
//	return singlePrice * salenum;
//}
istream &read(istream &is, Sales_data &item){
	//double singlePrice = 0;
	is >> item.ISBN >> item.salenum >> item.singlePrice;
	item.gain = item.singlePrice * item.salenum;
	return is;
}

ostream &print(ostream &os, const Sales_data &item){
	os << item.isbn() << "	" << item.salenum << "	"
	   << item.singlePrice << "	" << item.gain;
	return os;
}


/*
错误的代码
*/
//ostream  &print(ostream &out, const Sales_data &itemdata){// &的含义不是很清楚
//	out << itemdata.isbn() << "	" << itemdata.salenum << "	" << itemdata.singlePrice << "	" 
//		<< itemdata.totalPrice << endl;
//	return out;
//}
//
//void read(ifstream &file,  Sales_data &sdata){
//	string singleLine;
//	if (!file.eof()){
//		getline(file, singleLine);
//		stringstream lineToDevide(singleLine);
//		string singleWord;
//		lineToDevide >> sdata.ISBN;
//
//		lineToDevide >> singleWord;
//		sdata.salenum = stoi(singleWord);
//
//		lineToDevide >> singleWord;
//		sdata.singlePrice = stod(singleWord);
//
//		lineToDevide >> singleWord;
//		sdata.totalPrice = stod(singleWord);
//	}
//	else cerr << "end of file, no book to handle!" << endl;
//
//}
int main(int argc, char *argv[]){
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if (read(input, total)){
		Sales_data trans;
		while (read(input, trans)){
			if (total.isbn() == trans.isbn()){
				total.combine(trans);
			}
			else{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else{
		cerr << "No data?!" << endl;
	}
	/*
	错误代码
	*/
	/*ifstream bookFile(filename);
	Sales_data total;
	read(bookFile, total);
	Sales_data trans;
	while (read(bookFile, trans)){
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else{
		cerr << "No data?!" << endl;
	}
	return 0;*/
}