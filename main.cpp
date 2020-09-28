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

private:
	string name;
	string surname;
	string main_number; //999 000 00 00 
	string home_number;
	string work_number;
};

class Base
{	
public:
	void AddContact(const int& id, const Profile& profile)
	{
		data[id].insert(profile);
	}

	void List() const
	{
		for (const auto& item : data)
		{
			cout << "Id " << item.first << ": " << "\n"
			<< "Name: " << item.second.name << "\n"
			<< "Surname: " << item.second.surname << "\n"
			<< "Main number: " << item.second.main_number << "\n"
			<< "Home number: " << item.second.home_number << "\n"
			<< "Work number: " << item.second.work_number << "\n";
		}
	}

	bool DeleteContact(const int& id)
	{
		if (data.count(id) > 0)
		{
			data.erase(id);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool EditContact(const int& id, const Profile& profile)
	{
		if (data.count(id) > 0)
		{
			data.erase(id);
			AddContact(id, profile);
			return true;
		}
		else
		{
			return false;
		}

	}
private:
	unsorted_map<int, Profile> data;
};


int main()
{
	Base base;
	string line;
	int id = 0;

	while (getline(cin, line))
	{
		string command;
		istringstream cin_;
		cin_.str(line);

		cin_ >> command;

		if (command == "add")
		{
			++id;
			Profile profile;

			cout << "Contact's name . . . " << endl;
			cin_ >> profile.name;
			cout << "Contact's surname . . . " << endl;
			cin_ >> profile.surname;
			cout << "Contact's mobile number . . . " << endl;
			cin_ >> profile.main_number;
			cout << "Contact's home number . . . " << endl;
			cin_ >> profile.home_number;
			cout << "Contact's work_number . . . " << endl;
			cin_ >> profile.work_number;

			base.AddEvent(id, profile);
		}
		else if (command == "delete")
		{
			int id;

			cin_ >> id;

			if (base.DeleteEvent(id))
				cout << "Deleted successfully" << endl;
			else
				cout << "Event not found" << endl;
		}
		else if (command == "list")
		{
			base.List();
		}
		else if (command == "edit")
		{
			int id;

			cout << "Enter id . . ." << endl;

			cin_ >> id;

			if (base.DeleteEvent(id))
				cout << "Deleted successfully" << endl;
			else
				cout << "Event not found" << endl
		}
		else if (!command.empty())
		{
			cout << "Unknown command: " << command << endl;
		}
	}
	return 0;
}