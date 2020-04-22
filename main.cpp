#include <iostream>

#include <map>
#include <string>
#include <vector>

#include "HashTable.hpp"

using Table = std::vector<std::map<std::string, int>>;

int main()
{
	/**
	 * User table
	 */
	Table user = {
		{
			{"id", 1}
		},
		{
			{"id", 2}
		},
		{
			{"id", 3}
		}
	};

	/**
	 * Post table
	 */
	Table post = {
		{
			{"id_user", 1}
		},
		{
			{"id_user", 2}
		},
		{
			{"id_user", 3}
		},
		{
			{"id_user", 4}
		},
		{
			{"id_user", 4}
		}
	};

	/**
	 * Result table
	 */
	Table result = {};

	
	/**
	 * Hash table for the post table
	 */
	HashTable hashPostTable;


	/**
	 * Load to the hash post table
	 */
	for (auto& row : post)
	{
		hashPostTable.insert(row["id_user"], row["id_user"]);
	}

	/**
	 * Join
	 */
	int counter = 0;
	for (auto& row : user)
	{
		if (hashPostTable.get(row["id"]))
		{
			for (auto& pair : row)
			{
				result.push_back(post[counter]);
				result[counter].insert(pair);
			}
		}
		counter++;
	}

	/**
	 * Show row name
	 */
	std::string rowName;
	for (auto pair : result.front())
	{
		rowName = pair.first;
		std::cout << rowName << "\t";
	}

	std::cout << std::endl;
	
	/**
	 * Show fileds
	 */
	for (auto row : result)
	{
		for (auto pair : row)
		{
			std::cout << pair.second << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}