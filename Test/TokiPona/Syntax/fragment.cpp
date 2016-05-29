#include<TokiPona/Syntax/fragment.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <TokiPona/Lang/dictionary.hpp>

using namespace tokipona;
using namespace syntax;

TEST(Fragment, ConstexprConstructEmpty){
    constexpr Fragment f;

    static_assert( f.isLeaf() == false ,"not constexpr");
    static_assert( f.hasLhs() == false ,"not constexpr");
    static_assert( f.hasConjunctive() == false ,"not constexpr");
    static_assert( f.hasRhs() == false ,"not constexpr");
    static_assert( f.isValid() == false ,"not constexpr");
}

TEST(Fragment, ConstexprConstructLeaf){
    using namespace lang::dictionary;
    constexpr Fragment f(akesi);

    static_assert( f.isLeaf() == true ,"not constexpr");
    static_assert( f.hasLhs() == false ,"not constexpr");
    static_assert( f.hasConjunctive() == false ,"not constexpr");
    static_assert( f.hasRhs() == false ,"not constexpr");
    static_assert( f.isValid() == true ,"not constexpr");
    static_assert( f.getLeaf() == akesi_n ,"not constexpr");
}

TEST(Fragment, ConstexprConstructInternal){
    using namespace lang::dictionary;

    constexpr Fragment akesi_awen(&akesi, &awen);

    static_assert( akesi_awen.isLeaf() == false ,"not constexpr");
    static_assert( akesi_awen.hasLhs() == true ,"not constexpr");
    static_assert( akesi_awen.hasConjunctive() == false ,"not constexpr");
    static_assert( akesi_awen.hasRhs() == true ,"not constexpr");
    static_assert( akesi_awen.isValid() == true ,"not constexpr");
    static_assert( akesi_awen.getLhs().getLeaf() == akesi_n ,"not constexpr");
    static_assert( akesi_awen.getRhs().getLeaf() == awen_n ,"not constexpr");
}

TEST(Fragment, ConstexprConstructInternalWithConj){
    using namespace lang::dictionary;
    constexpr Fragment akesi_li_awen(&akesi, li_n, &awen);

    static_assert( akesi_li_awen.isLeaf() == false ,"not constexpr");
    static_assert( akesi_li_awen.hasLhs() == true ,"not constexpr");
    static_assert( akesi_li_awen.hasConjunctive() == true ,"not constexpr");
    static_assert( akesi_li_awen.hasRhs() == true ,"not constexpr");
    static_assert( akesi_li_awen.isValid() == true ,"not constexpr");
    static_assert( akesi_li_awen.getLhs().getLeaf() == akesi_n ,"not constexpr");
    static_assert( akesi_li_awen.getRhs().getLeaf() == awen_n ,"not constexpr");
    static_assert( akesi_li_awen.getConjunctive() == li_n ,"not constexpr");
}

TEST(Fragment, ConstexprPlusNimiNimi){
    using namespace lang::dictionary;

    static constexpr Fragment akesi_awen = akesi + awen;

    static_assert( akesi_awen.isLeaf() == false ,"not constexpr");
    static_assert( akesi_awen.hasLhs() == true ,"not constexpr");
    static_assert( akesi_awen.hasConjunctive() == false ,"not constexpr");
    static_assert( akesi_awen.hasRhs() == true ,"not constexpr");
    static_assert( akesi_awen.isValid() == true ,"not constexpr");
    static_assert( akesi_awen.getLhs().getLeaf() == akesi_n ,"not constexpr");
    static_assert( akesi_awen.getRhs().getLeaf() == awen_n ,"not constexpr");
}

TEST(Fragment, ConstexprNimiPlusNimiNimi){
    using namespace lang::dictionary;
    
    static constexpr auto awen_ante = awen + ante;
    static constexpr Fragment akesi_awen_ante_1 = (akesi + awen ) + ante;
    static constexpr Fragment akesi_awen_ante_2 = akesi + (awen + ante);
    static constexpr Fragment akesi_awen_ante_3 = akesi + awen + ante;

    //static_assert( akesi_awen.isLeaf() == false ,"not constexpr");
    //static_assert( akesi_awen.hasLhs() == true ,"not constexpr");
    //static_assert( akesi_awen.hasConjunctive() == false ,"not constexpr");
    //static_assert( akesi_awen.hasRhs() == true ,"not constexpr");
    //static_assert( akesi_awen.isValid() == true ,"not constexpr");
    //static_assert( akesi_awen.getLhs().getLeaf() == akesi_n ,"not constexpr");
    //static_assert( akesi_awen.getRhs().getLeaf() == awen_n ,"not constexpr");
}
TEST(Fragment, ConstexprNimiNimiPlusNimi){
    using namespace lang::dictionary;

    //static constexpr Fragment akesi_awen = akesi + awen;

    //static_assert( akesi_awen.isLeaf() == false ,"not constexpr");
    //static_assert( akesi_awen.hasLhs() == true ,"not constexpr");
    //static_assert( akesi_awen.hasConjunctive() == false ,"not constexpr");
    //static_assert( akesi_awen.hasRhs() == true ,"not constexpr");
    //static_assert( akesi_awen.isValid() == true ,"not constexpr");
    //static_assert( akesi_awen.getLhs().getLeaf() == akesi_n ,"not constexpr");
    //static_assert( akesi_awen.getRhs().getLeaf() == awen_n ,"not constexpr");
}
