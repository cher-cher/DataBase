#include "stdafx.h"
#include "CDataBase.h"

using namespace std;

vector<size_t> PrefFunc(const string &findString)
{
	vector<size_t> pref(findString.length(), 0);
	size_t prefixLen = 0;
	for (size_t i = 1; i < findString.length(); ++i)
	{
		while ((prefixLen > 0) && (findString[i] != findString[prefixLen]))
		{
			prefixLen = pref[prefixLen - 1];
		}
		if (findString[prefixLen] == findString[i])
		{
			prefixLen++;
		}
		pref[i] = prefixLen;
	}
	return pref;
}

bool DoKMPSearch(const string &findString, const string &str)
{
	vector<size_t> prefix = PrefFunc(findString);
	size_t pos = 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		while (pos > 0 && (pos >= findString.length() || findString[pos] != str[i]))
		{
			pos = prefix[pos - 1];
		}
		if (str[i] == findString[pos])
		{
			pos++;
		}
		if (pos == findString.length())
		{
			return true;
		}
	}
	return false;
}

vector<string> CDatabase::FindAuthor(string const & username)
{
	vector<string> ids;
	string line;
	bool id;
	for (auto it = m_mapUsers.begin(); it != m_mapUsers.end(); it++)
	{
		if (DoKMPSearch(username, it->second))
		{
			ids.push_back(it->first);
		}
	}
	return ids;
}

void CDatabase::FillingDB(istream& fin)
{
	string line;
	string ids;
	getline(fin, line);
	while (getline(fin, line))
	{
		ids = line.substr(0, line.find_first_of(","));
		m_mapUsers.insert(pair<string, string>(ids, line));
	}
	/*for (auto it = m_mapUsers.begin(); it != m_mapUsers.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}*/
}

bool CDatabase::CheckCorrectFile(std::string const & nameInputFile)
{
	m_fin.open(nameInputFile);
	if (!m_fin)
	{
		cout << "Can't open " + nameInputFile << endl;
		return false;
	}
	return true;
}

void CDatabase::ProcessFile()
{
	string inputStr;
	vector<string> line;
	FillingDB(m_fin);
}

CDatabase::CDatabase(std::string const & nameInputFile)
{
	if (CheckCorrectFile(nameInputFile))
	{
		ProcessFile();
	}
}

