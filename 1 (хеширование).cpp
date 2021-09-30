#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <cmath>
#include <sstream>


class HashTable {
private:

	std::vector<std::pair<std::string, std::string>> table;

public:


	HashTable(const size_t size) :
		table(getBiggetsClosestPrimeNumber_(size))
	{
	}


	size_t getHash(const std::string& key) const
	{
		size_t hash = 0;
		size_t index = 1;
		for (const auto& symbol : key)
		{
			hash += int(symbol) * (index * index);
			index++;
		}

		return hash % table.size();
	}



	bool isPrimeNumber_(const size_t number)
	{
		if (number > 1)
		{
			size_t sqrt_number = sqrt(number) + 1;
			for (size_t i = 2; i < sqrt_number; i++) {
				if (number % i == 0) {
					return false;
				}
			}
			return true;
		}
		else return false;
	}

	size_t getBiggetsClosestPrimeNumber_(size_t number)
	{
		while (!isPrimeNumber_(number))
		{
			number++;
		}
		return number;
	}

	void add(std::pair<std::string, std::string> pair)
	{
		int index;
		int i = 0;
		static int k = 2;
		do
		{
			index = getHash(pair.first) + i * k % table.size();
			i++;
			std::cout << index << std::endl;
		} while (!table[index].first.empty());

		table[index] = pair;
	}

	void print()
	{
		int index = 0;
		for (auto& pair : table)
		{
			if (!pair.first.empty())
			{
				std::cout << pair.first << " " << pair.second << " " << index << std::endl;
			}
			index++;
		}
	}

};

			
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);




	HashTable HT(10);
	HT.add({ "09.03.04", "JOPA" });
	HT.add({ "09.03.04", "JOPA" });
	HT.print();
	
	return 0;
}
