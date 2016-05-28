#pragma once

#include <string>

namespace tokipona {

namespace syntax{
    class Fragment;
}

namespace lang {

typedef enum NimiType{
    NOUN,
    VERB,
    ADJECTIVE,
    PREPOSITION,
    CONJUNCTIVE,
} NimiType;

class Nimi{
public:
    const NimiType type;
    const char* string;
    Nimi(const NimiType type_, const char* string_):
	type(type_), string(string_){}

    Nimi(Nimi& n) = delete;
    Nimi(Nimi&& n) = delete;
    Nimi operator=(Nimi& n) = delete;
    Nimi operator=(Nimi&& n) = delete;

    syntax::Fragment operator+(const Nimi& rhs) const;
    syntax::Fragment operator+(syntax::Fragment& rhs) const;
};

} //lang
} //tokipona
