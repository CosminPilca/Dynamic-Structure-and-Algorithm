#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d), current(0)
{
	//TODO - Implementation
}
///Complexitati:
/// Theta(1)

void MapIterator::first() {
	//TODO - Implementation
    current = 0;
}

///Complexitati:
/// Theta(1)

void MapIterator::next() {
	//TODO - Implementation
    if (!valid()){
        //throw runtime_error("");
        throw exception();
    }

        current++;
}
///Complexitati:
/// Theta(1)


TElem MapIterator::getCurrent(){
	//TODO - Implementation
    if(valid()) {
        return map.data[current];
    } else {
        //throw ("Iteratorul nu e valid");
        throw exception();
    }
	return NULL_TELEM;
}
///Complexitati:
/// Theta(1)


bool MapIterator::valid() const {
	//TODO - Implementation
	return current >= 0  && current < map.length && map.length > 0;
}

///Complexitati:
/// Theta(1)



void MapIterator::modifyCurrent(TElem e) {
    if (valid()) {
        map.data[current] = e;
    }else {
        throw exception();
    }
}


