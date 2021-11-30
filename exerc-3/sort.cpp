#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Item {
private:
	std::string data;
	int key;

public:
	Item(const char *data, int key) { this->data = data; this->key = key; }
	
	int getKey() { return key; }
	std::string getData() { return data; }
	
	void setKey(int key) { this->key = key; }
	void setData(const char *data) { this->data = data; }
};


bool compareItem(Item *i1, Item *i2) {
	return i1->getKey() < i2->getKey();
}


class Items {
private:
	std::vector<Item*> *items;

public:
	Items() { items = new std::vector<Item*>(); }
	void insertItem(int key, const char *data) { items->push_back(new Item(data, key)); }
	void sort() { std::sort(items->begin(), items->end(), compareItem); }
	
	void print() {
		for(int i = 0; i < items->size(); i++) {
			std::cout << "items[" << i << "]: {key: " << items->at(i)->getKey() << 
				", data: " << items->at(i)->getData() << "}" << std::endl;
		}
	}

	~Items() {
		while(!items->empty()) {
			items->pop_back();
		}
	}
};


int main() {
	Items *items = new Items();
	items->insertItem(2, "def");
	items->insertItem(1, "abc");
	items->print();
	
	items->sort();
	items->print();
	
	items->~Items();
	
	return 0;
}




