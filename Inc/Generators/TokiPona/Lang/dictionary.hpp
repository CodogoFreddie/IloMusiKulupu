#pragma once

#include <array>
#include <vector>

#include <Generators/TokiPona/Lang/word.hpp>

namespace generators {
namespace tokipona {
namespace lang {

class Dictionary{
public:

    static const std::vector<Word> adjectives;
    static const std::vector<Word> nouns;
    static const std::vector<Word> particles;
    static const std::vector<Word> verbs;

    Dictionary();
};

} //lang
} //tokipona
} //generators
