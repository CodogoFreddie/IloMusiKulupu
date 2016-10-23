#pragma once

#include <string>

#include <Core/hashedString.hpp>

namespace tokipona {

namespace syntax {
	template <typename LHS, typename RHS> class Fragment;
}

namespace lang {

typedef enum NimiType {
	NOUN,
	VERB,
	ADJECTIVE,
	PREPOSITION,
	CONJUNCTIVE,
} NimiType;

class Nimi {
	public:
		const NimiType type;
		const core::HashedString string;
		constexpr Nimi(const NimiType type_, const char *string_)
			: type(type_), string(string_) {}

		Nimi(Nimi &n) = delete;
		Nimi(Nimi &&n) = delete;
		Nimi operator=(Nimi &n) = delete;
		Nimi operator=(Nimi &&n) = delete;

		constexpr bool operator==(const Nimi &rhs) const {
			return string == rhs.string;
		}
};

} // lang
} // tokipona
