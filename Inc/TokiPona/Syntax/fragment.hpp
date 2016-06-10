#pragma once

#include <memory>
#include <string>

#include <TokiPona/Lang/nimi.hpp>
#include <TokiPona/Lang/dictionary.hpp>

namespace tokipona {
namespace syntax {

template<   typename LHS = lang::Nimi&,
	    typename RHS = lang::Nimi&>
class Fragment{
private:
    const LHS lhs;
    const lang::Nimi* conjunctive;
    const RHS rhs;

public:
    constexpr Fragment():
	lhs(),
	conjunctive(nullptr),
	rhs(){}

    constexpr Fragment(	const LHS lhs_,
			const RHS rhs_):
	lhs(lhs_),
	conjunctive(nullptr),
	rhs(rhs_){}

    constexpr Fragment(	const LHS lhs_,
			const lang::Nimi& conj_,
			const RHS rhs_):
	lhs(lhs_),
	conjunctive(&conj_),
	rhs(rhs_){}

    constexpr const LHS& getLhs() const {return lhs;}
    constexpr const lang::Nimi* getConj() const {return conjunctive;}
    constexpr const RHS& getRhs() const {return rhs;}

    constexpr bool operator==(const Fragment& rhs_frag) const {
	return	(lhs == rhs_frag.lhs) && 
		(conjunctive == rhs_frag.conjunctive) &&
		(rhs == rhs_frag.rhs);
    }

    template<typename LI_RHS>
	constexpr const Fragment<Fragment<LHS, RHS>, LI_RHS>
	li(LI_RHS rhs_) const {
	    return Fragment<Fragment<LHS, RHS>, LI_RHS>(
		    *this, rhs_);
	}
};

constexpr Fragment<const lang::Nimi&, const lang::Nimi&>
	operator+(const lang::Nimi& lhs, const lang::Nimi& rhs){
    return Fragment<const lang::Nimi&, const lang::Nimi&>(lhs, rhs);
}

template<   typename RL = void,
	    typename RR = void>
constexpr Fragment<const lang::Nimi&, Fragment<RL,RR>>
	operator+(const lang::Nimi& lhs, const Fragment<RL,RR>& rhs){

    return Fragment<const lang::Nimi&, Fragment<RL,RR>>(lhs, rhs);
}

template<   typename LL = void,
	    typename LR = void>
constexpr Fragment<Fragment<LL,LR>, const lang::Nimi&>
	operator+(const Fragment<LL,LR>& lhs, const lang::Nimi& rhs){

    return Fragment<Fragment<LL,LR>, const lang::Nimi&>(lhs, rhs);
}

template<   typename LL = void,
	    typename LR = void,
	    typename RL = void,
	    typename RR = void>
constexpr Fragment<Fragment<LL,LR>, Fragment<RL,RR>>
	operator+(const Fragment<LL,LR>& lhs, const Fragment<RL,RR>& rhs){

    return Fragment<Fragment<LL,LR>, Fragment<RL,RR>>(lhs, rhs);
}

constexpr Fragment<const lang::Nimi&, const lang::Nimi&>
	li(const lang::Nimi& lhs, const lang::Nimi& rhs){

    return Fragment<	const lang::Nimi&,
			const lang::Nimi&>(lhs, lang::dictionary::li_c, rhs);
}

} //syntax
} //tokipona
