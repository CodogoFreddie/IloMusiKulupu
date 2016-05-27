#pragma once

#include <assert.h>
#include <set>

#include <iostream>

namespace core {

typedef unsigned int ID;

class IDManager{
private:
    ID greatestID;
    std::set<ID> activeIDs;
    std::set<ID> retiredIDs;

public:
    IDManager():
	    greatestID(0)
    {}

    const ID yield(){
	ID newID;
	if(retiredIDs.empty()){
	    newID = greatestID++;
	    activeIDs.insert(activeIDs.end(), newID);
	}
	else{
	    newID = *(retiredIDs.begin());
	    retiredIDs.erase(newID);
	    activeIDs.insert(newID);
	}
	return newID;
    };

    void retire(const ID id){
	assert(activeIDs.count(id) == 1);
	assert(retiredIDs.count(id) == 0);

	activeIDs.erase(id);
	retiredIDs.insert(id);
    }

    bool idIsActive(const ID id){
	if(id >= greatestID) return false;
	if(activeIDs.size() < retiredIDs.size()){
	    return activeIDs.count(id);
	}
	else{
	    return !(retiredIDs.count(id));
	}
    }
};
} //core
