#pragma once

#include <TokiPona/Syntax/scentence.hpp>
#include <TokiPona/Lang/word.hpp>

namespace tokipona {
namespace syntax {

class Object{
public:
    const bool isComposite; 

    const lang::Word& word;

    const Object* lhs;
    const Object* rhs;

    const std::string getWord(bool toki = false) const {
	std::string intermediateString;
	if(isComposite){
	    intermediateString = lhs->getWord(toki);
	    intermediateString += std::string(" ");
	    intermediateString += rhs->getConnector(toki);
	    intermediateString += std::string(" ");
	    intermediateString += rhs->getWord(toki);
	}
	else{
	    intermediateString =  word.getAsNoun();
	}
	return intermediateString;
    }

    const char* getConnector(bool toki = false) const {
	if(toki){
	    return "";
	}
	else{
	    if(isComposite){
		return " of ";
	    }
	    else{
		return word.getNounModConnector(toki);
	    }
	}
    }

};

} //syntax
} //tokipona
