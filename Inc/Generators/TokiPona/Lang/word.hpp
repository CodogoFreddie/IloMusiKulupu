#pragma once

#include<string>

namespace generators {
namespace tokipona {
namespace lang {

enum TypeOfWord{
    NOUN,
    ADJ,
    VERB,
    PART
};

class Word{
private:

public:
    const TypeOfWord type;
    const std::string nimi;
    const std::string word;

    Word(const TypeOfWord type_, const char* nimi_, const char* word_):
	type(type_),
	nimi(nimi_),
	word(word_){}


};

} //lang
} //tokipona
} //generators
