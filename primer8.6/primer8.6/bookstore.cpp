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

int main(int argc, char *argv[]){
	ifstream input(argv[1]);
	ofstream output;
	output.open(argv[2], ofstream::app);
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

}