#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
    length = 0 ;
    capacity = 2;
    data = new TElem[capacity];
 //  theta (1)
}

Map::~Map() {
	//TODO - Implementation
    delete[] data;
}
//Complexitate
//Best case : O(1)
//Worst case : O(n)



TValue Map::add(TKey c, TValue v) {
    bool isKeyFound = false;
    for (int i = 0; i < length; ++i) {
        if (data[i].first == c) {
            TValue oldValue = data[i].second;
            data[i].second = v;
            return oldValue;
        }
    }

    if (length == capacity -1) {
        capacity *= 2;
        TElem *newData = new TElem[capacity];
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }


    data[length] = std::make_pair(c, v);
    ++length;
    return NULL_TVALUE;
}



 /// Complexitate:
 /// Best case : O(1)
 /// Best case: O(n)




TValue Map::search(TKey c) const {
    //TODO - Implementation
    for (int i = 0; i < length; ++i) {
        if (data[i].first == c) {
            return data[i].second;
        }


    }
    return NULL_TVALUE;
}

/// Complexitate:
/// Best case : Theta(1)
/// Worst case: O(n)

TValue Map::remove(TKey c){
	//TODO - Implementation
    for (int i = 0; i < length; ++i){
        if (data[i].first == c) {
            TValue removedValue = data[i].second;
            for (int j = i; j< length - 1; ++j) {
                data[j] = data[j+1];

            }
            --length;
            return removedValue;
        }
    }
	return NULL_TVALUE;
}
/// Complexitati:
/// Best case: Theta (n)
/// Worst case: O(n)

int Map::size() const {
	//TODO - Implementation
	return length;
}
/// Complexitati:
/// Theta(1) //

bool Map::isEmpty() const {
	//TODO - Implementation
	return length == 0;
}

/// Complexitati:
/// Theta(1) //

MapIterator Map::iterator() const{
	return MapIterator(*this);
}

/// Complexitati:
/// Theta(1) //