#pragma once

#include <memory>
#include <string>

#include <TokiPona/Lang/nimi.hpp>

namespace tokipona {
namespace syntax {

class Fragment{
private:
    bool isLeaf;
    const lang::Nimi* leaf;

    bool isInternal;
    std::unique_ptr<Fragment> lhs;
    bool hasConjunctive;
    lang::Nimi* conjunctive;
    std::unique_ptr<Fragment> rhs;

public:
    Fragment():
	isLeaf(false),
	isInternal(false),
	hasConjunctive(false){} //invalid state => not initalised

    Fragment(const lang::Nimi& nimi_); //leaf or conjunctive
    Fragment(Fragment& lhs_, Fragment& rhs_); //internal
    Fragment(	Fragment& lhs_,
		const lang::Nimi& conj_,
		Fragment& rhs_); //internal with conj

    ~Fragment();

    void setLeaf(const lang::Nimi&& conj_);
    void setLHS(const lang::Nimi&& conj_);
    void setConjunctive(const lang::Nimi&& conj_);
    void setRHS(const lang::Nimi&& conj_);

    const std::string toString() const;
};

Fragment operator+(lang::Nimi& lhs_, lang::Nimi& rhs_);
Fragment operator+(Fragment& lhs_, lang::Nimi& rhs_);
Fragment operator+(lang::Nimi& lhs_, Fragment& rhs_);
Fragment operator+(Fragment& lhs_, Fragment& rhs_);

} //syntax
} //tokipona
