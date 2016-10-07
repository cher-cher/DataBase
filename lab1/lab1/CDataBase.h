#pragma once
#include "stdafx.h"

class CDatabase
{
public:
	CDatabase(std::string const & nameInputFile);
	std::vector<std::string> CDatabase::FindAuthor(std::string const & username);
private:
	bool CheckCorrectFile(std::string const & nameInputFile);
	void ProcessFile();
	void FillingDB(std::istream & fin);
private:
	std::ifstream m_fin;
	std::map<std::string, std::string> m_mapUsers;
};