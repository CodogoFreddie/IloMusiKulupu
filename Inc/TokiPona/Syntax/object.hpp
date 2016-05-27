#pragma once

#include <TokiPona/Syntax/scentence.hpp>
#include <TokiPona/Lang/word.hpp>

namespace tokipona {
namespace syntax {

class Object{
    int prefixObject;
    lang::Word* word;
    int suffixObject;

    Object():
	prefixObject(-1),
	word(nullptr),
	suffixObject(-1)
    {}

    Object(const lang::Word& word_):
	prefixObject(-1),
	word(*word_),
	suffixObject(-1)
    {}

    Object(const ID prefixObject_, const lang::Word& word_):
	prefixObject(prefixObject_),
	word(nullptr),
	suffixObject(-1)
    {}

    Object(const lang::Word& word_, const ID suffixObject_):
	prefixObject(-1),
	word(nullptr),
	suffixObject(suffixObject_)
    {}

    Object(const ID prefixObject_, const ID suffixObject_):
	prefixObject(prefixObject_),
	word(nullptr),
	suffixObject(suffixObject_)
    {}
};

} //syntax
} //tokipona
