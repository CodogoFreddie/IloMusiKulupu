#pragma once

#include <string>

namespace tokipona {
namespace lang {

typedef enum NimiType{
    NOUN,
    VERB,
    ADJECTIVE,
    CONJUNCTIVE,
} NimiType;

class Nimi{
public:
    const NimiType type;
    const char* string;
    Nimi(const NimiType type_, const char* string_);
};

} //lang
} //tokipona
