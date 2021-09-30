#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <cmath>
#include <sstream>

using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	vector<pair<int, string>> table[hashGroups];
public:

	int hashFunction(int key);
	void insertItem(int key, string value);
	void insertItems(string key, string value);
	void removeItem(string key);
	void printTable();
	void findItem();
	int StrtoInt(string key);
	int InttoStr(int key);
	void KeyValue();
	bool KeyExists(int key);
	int Rehash(int key, int path, string value);
};
int HashTable::hashFunction(int key) {
	int hash = 0;

	for (int i = 0; i < jopa; i++) {
		hash += key * (i + 1);
	}
	return hash % hashGroups;
}
bool HashTable::KeyExists(int key) {
	int kluch = 1;
	if (kluch == key) {
		cout << 't' << endl;
		return true;
	}
	else {
		cout << 'f' << endl;
		return false;
	}
}
int HashTable::Rehash(int key, int path, string value) {
	int hashValue = hashFunction(key, value);
	auto& cell = table[hashValue];
	cout << path << endl;
	for (auto bItr = begin(cell); bItr != end(cell); bItr++) {
		while (true) {
			if (!KeyExists(bItr->first)) {
				cell.emplace_back(key, value);
				return 0;
			}
		}
	}

}
void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key, value);
	auto& cell = table[hashValue];
	while (true) {
		if (KeyExists(hashValue)) {
			hashValue++;
			cout << hashValue << endl;
		}
		else {
			break;
		}
	}
	cell = table[hashValue];
	/*for (auto bItr = begin(cell); bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExist = true;
			while (true) {
				cell = table[hashValue + 10];
				if (bItr->first == key) 
				break;
				if (bItr->second != s) {
					while (true) {
						if (bItr->second == s)
							break;
						else
							bItr++;
					}
				}
				keyExist = true;
				bItr->second = value;
				break;
				
			}
			break;
		}
		*/
	
		/*if (!keyExist) {
			cell.emplace(bItr, pair<int, string>(key, value));
		}
		/*
	keyExist = KeyExists(bItr->first);
	cout << '1' << endl;
	if (keyExist == true) {
		while (true) {
			if (bItr == end(cell)) {
				bItr = begin(cell);
			}
				advance(bItr, 1);
			if (bItr->second == s) {
				cell.emplace(bItr, pair<int, string>(key, value));
				return;
			}
		}
	}
	else {
		cell.emplace(bItr, pair<int, string>(key, value));
		break;
	}
	*/
	cell.emplace_back(key, value);

}
void HashTable::removeItem(string kiy, string value) {
	int key = StrtoInt(kiy);
	int hashValue = hashFunction(key, value);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] key item removed" << endl;
			break;
		}
	}
		if (!keyExists) {
			cout << "Item not found" << endl;
		}
		return;
	
}
void HashTable::insertItems(string key, string znachenie) {
	int ptr = HashTable::StrtoInt(key);
	HashTable::insertItem(ptr, znachenie);
}
void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue; 

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			HashTable::InttoStr(bItr->first);
			cout << "Value: " << bItr->second << endl << endl;
		}

	}
	return;
}
void HashTable::findItem() {
	string kiy;
	cout << "Write key: " << endl;
	cin >> kiy;
	int key = HashTable::StrtoInt(kiy);
	int hashValue = hashFunction(key, );
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first = key) {
			keyExists = true;
			HashTable::InttoStr(key);
			cout << "Value: " << bItr->second << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "[INFO] Value do not exists" << endl;
	}
}
int HashTable:: StrtoInt(string key) {
		int j;
		key.erase(std::remove(key.begin(), key.end(), '.'), key.end());
		j = atoi(key.c_str());
		return (j);
}
int HashTable::InttoStr(int key) {
	stringstream ss;
	ss << key << endl;
	string NewString = ss.str();
	if (NewString.length() == 6) {
		NewString.insert(0, string("0"));
		NewString.insert(2, string("."));
		NewString.insert(5, string("."));
	    cout << "Key: " << NewString;
	}
	else {
		NewString.insert(2, string("."));
		NewString.insert(5, string("."));
		cout << "Key: " << NewString;
	}
	return -1;
}
/*void HashTable::KeyValue() {
	int key = 0;
	int *arr = new int[hashGroups];
	for (int i = 0; i < hashGroups; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		for (auto bItr = table[i].begin(); bItr != table[i].end(); bItr++) {
			size_t j = distance(table[i].begin(), bItr->first);
			key = hashFunction(bItr->first);
			int j = bItr->first;
			arr[j] = key;
			for (int i = 0; i < hashGroups; i++) {
				cout << arr[i] << " " << bItr->second << endl;
			}
		}

	}
	return;

}
*/
void HashTable::KeyValue() {
	int key = 0, k = 1;
	int n = 0;
	for (int i = 0; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;
		for (auto bItr = table[i].begin(); bItr != table[i].end(); bItr++) {
			cout << "Index: " << i << " Value: " << bItr->second << endl;
		}
	}
	
}	
			/*	cout << " #1 ";

			if (i == n) {
				cout << " #2 ";
				key = hashFunction(bItr->first);
				cout << key << " " << bItr->second << endl;
				break;
			}
			cout << " #3 ";
			key1 = hashFunction(bItr->first);
			if (key == key1) {
				cout << " #44444444444 ";
				key1 += 1;
				cout << key1 << " " << bItr->second << endl;
			}
				key = key1;
				n += 2;
			
			//cout << "key = " << key << " key1 = " << key1 << endl;
			

			*/
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HashTable HT;
	//-----------------------------------------------------
	string key = "01.03.03";
	string znachenie = "РТУ МИРЭА";
	HT.insertItems(key, znachenie);

	key = "09.03.09";
	znachenie = "РУДН";
	HT.insertItems(key, znachenie);
	key = "09.03.01";
	znachenie = "Левый вуз";
	HT.insertItems(key, znachenie);

	key = "44.04.07";
	znachenie = "РГГУ";
	HT.insertItems(key, znachenie);

	key = "05.03.06";
	znachenie = "МАИ";
	HT.insertItems(key, znachenie);

	key = "03.03.08";
	znachenie = "МЭИ";
	HT.insertItems(key, znachenie);

	key = "37.03.01";
	znachenie = "РАНХиГС";
	HT.insertItems(key, znachenie);

	key = "10.02.05";
	znachenie = "МГУ";
	HT.insertItems(key, znachenie);
	
	//-----------------------------------------------------
	HT.printTable();
	
	//HT.removeItem("37.03.01");
	//HT.removeItem("37.04.12");
	HT.KeyValue();
//	HT.findItem();
	
	return 0;
}



/*
int hashValue = hashFunction(key);
auto& cell = table[hashValue];
auto bItr = begin(cell);
string s = HashTable::InttoStr(key);;
//bool keyExists = false;
for (; bItr != end(cell); bItr++) {
	if (bItr->second == "-") {
		removeItem(key);
		cell.emplace_back(key, value);
		cout << "[INFO] Value gets it's place" << endl;
		break;
	} else if ((bItr->first == hashValue) && (bItr->second != "-")) {
		while (bItr->second != "") {
			bItr->first += 1;
		}
		cell.emplace_back(key, value);
		cout << "[INFO] Value gets it's place. Gets new key" << endl;
		break;
	}
}
return;



int hashValue = hashFunction(key); // 03.04.09 => 9
auto& cell = table[hashValue];
auto bItr = begin(cell);
bool keyExists = false;
cout << "1" << endl;
for (; bItr != end(cell); bItr++) {
	cout << "2" << endl;
	if (bItr->first == key) {
		cout << "3" << endl;
		keyExists = true;
		bItr->second = key;
	}
		cout << "[WARNING] key exists" << endl;
		for (auto bItr1 = begin(cell); bItr1 != end(cell); bItr1++) {
			if (bItr1->second.empty() == true) {
				bItr1->first = key;
				bItr1->second = value;
				break;
			}
		}

		if (!keyExists) {
			cell.emplace_back(key, value);
			cout << "[TRUE]" << endl;
		}
		}
		*/
		/*if (bItr->second != s) {
					while (T) {
						if (bItr->second == s)
							break;
						else
							bItr++;
					}
				}
				keyExist = true;
				bItr->second = value;
				break;
			}
		}
			if (!keyExist) {
				cell.emplace(bItr, pair<int, string>(key, value));
			}
		*/