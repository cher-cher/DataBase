// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CDataBase.h"

using namespace std;

void PrintResult(vector<std::string> const & result)
{
	if (result.empty())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Result id: ";
		for (auto const & it : result)
		{
			cout << it << " ";
		}
		cout << endl;
	}
}

int main()
{
	string username;
	CDatabase db("db.csv");
	while (!cin.eof() && !cin.fail())
	{
		cout << "Enter username: ";
		getline(cin, username);
		PrintResult(db.FindAuthor(username));
	}
    return 0;
}

