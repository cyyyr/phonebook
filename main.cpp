#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>


using namespace std;

/*class Data {
public:
	Data(string data) : data_(data) {
		cout << "Data constucted\n";
	}
	~Data() {
		cout << "Data destructed\n";
	}

	const string& Get() const {
		return data_;
	}
	string& Get() {
		return data_;
	}
private:
	string data_;
};*/

class Profile
{
public:
	Profile()
	{
		// profile = new Profile();
		name = "Name";
		surname = "Surname";
		main_number = "Empty";
		home_number = "Empty";
		work_number = "Empty";
		id = 0;
	}

	string Name() const
	{
		return name;
	}
	string Surname() const
	{
		return surname;
	}
	string Mobile() const
	{
		return main_number;
	}
	string Home() const
	{
		return home_number ;
	}
	string Woek() const
	{
		return work_number;
	}
	int Id() const
	{
		return id;
	}

private:
	string name;
	string surname;
	string main_number; //999 000 00 00 
	string home_number;
	string work_number;
	int id;
};

class Base
{

};


int main()
{
	Profile book;
	cout << book.Name() << endl;
	return 0;
}