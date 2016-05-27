#pragma once

#include <string>

namespace tokipona {
namespace lang {

typedef enum WordType{
    NOUN,
    VERB,
    ADJECTIVE,
} WordType;

class Word{
public:
    const WordType type;
    const char* nimi;
    const char* word;

    const char* getAsNoun(bool toki = false) const {
	return (nimi);
    }
    const char* getNounModConnector(bool toki = false) const {
	return "that";
    }
    const char* getAsVerb(bool toki = false) const {
	return nimi;
    }
    const char* getAsAdjective(bool toki = false) const {
	return nimi;
    }
};

} //lang
} //tokipona
