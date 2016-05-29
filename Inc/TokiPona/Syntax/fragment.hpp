#pragma once

#include <memory>
#include <string>

#include <TokiPona/Lang/nimi.hpp>

namespace tokipona {
namespace syntax {

class Fragment{
private:
    const lang::Nimi* leaf;

    const Fragment* lhs;
    const lang::Nimi* conjunctive;
    const Fragment* rhs;

public:
    constexpr Fragment():
	leaf(nullptr),
	lhs(nullptr),
	conjunctive(nullptr),
	rhs(nullptr){}

    constexpr Fragment(const lang::Nimi* nimi_):
	leaf(nimi_),
	lhs(nullptr),
	conjunctive(nullptr),
	rhs(nullptr){}

    constexpr Fragment(const Fragment* lhs_, const Fragment* rhs_):
	leaf(nullptr),
	lhs(lhs_),
	conjunctive(nullptr),
	rhs(rhs_){}

    constexpr Fragment(	const Fragment* lhs_,
			const lang::Nimi& conj_,
			const Fragment* rhs_):
	leaf(nullptr),
	lhs(lhs_),
	conjunctive(&conj_),
	rhs(rhs_){}

    constexpr Fragment operator+(const Fragment* rhs_) const {
	return Fragment(this, rhs_);
    }

    void setLeaf(const lang::Nimi&& conj_);
    void setLHS(const lang::Nimi&& conj_);
    void setConjunctive(const lang::Nimi&& conj_);
    void setRHS(const lang::Nimi&& conj_);

    constexpr bool isLeaf() const{return (leaf!=nullptr);}
    constexpr bool hasLhs() const{return (lhs!=nullptr);}
    constexpr bool hasConjunctive() const{return (conjunctive!=nullptr);}
    constexpr bool hasRhs() const{return (rhs!=nullptr);}
    constexpr bool isValid() const{return (isLeaf() || (hasLhs() && hasRhs()));}

    constexpr const lang::Nimi& getLeaf() const {return *leaf;}
    constexpr const Fragment& getLhs() const {return *lhs;}
    constexpr const lang::Nimi& getConjunctive() const {return *conjunctive;}
    constexpr const Fragment& getRhs() const {return *rhs;}

    const std::string toString() const;
};


} //syntax
} //tokipona
