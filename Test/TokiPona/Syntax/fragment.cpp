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
    constexpr Fragment f(&akesi);

    static_assert( f.isLeaf() == true ,"not constexpr");
    static_assert( f.hasLhs() == false ,"not constexpr");
    static_assert( f.hasConjunctive() == false ,"not constexpr");
    static_assert( f.hasRhs() == false ,"not constexpr");
    static_assert( f.isValid() == true ,"not constexpr");
    static_assert( f.getLeaf() == akesi ,"not constexpr");
}

TEST(Fragment, ConstexprConstructInternal){
    using namespace lang::dictionary;
    static constexpr Fragment akesi_f(&akesi);
    static constexpr Fragment awen_f(&awen);

    constexpr Fragment akesi_awen_f(&akesi_f, &awen_f);

    static_assert( akesi_awen_f.isLeaf() == false ,"not constexpr");
    static_assert( akesi_awen_f.hasLhs() == true ,"not constexpr");
    static_assert( akesi_awen_f.hasConjunctive() == false ,"not constexpr");
    static_assert( akesi_awen_f.hasRhs() == true ,"not constexpr");
    static_assert( akesi_awen_f.isValid() == true ,"not constexpr");
    static_assert( akesi_awen_f.getLhs().getLeaf() == akesi ,"not constexpr");
    static_assert( akesi_awen_f.getRhs().getLeaf() == awen ,"not constexpr");
}

TEST(Fragment, ConstexprConstructInternalWithConj){
    using namespace lang::dictionary;
    static constexpr Fragment akesi_f(&akesi);
    static constexpr Fragment awen_f(&awen);

    constexpr Fragment akesi_li_awen_f(&akesi_f, li, &awen_f);

    static_assert( akesi_li_awen_f.isLeaf() == false ,"not constexpr");
    static_assert( akesi_li_awen_f.hasLhs() == true ,"not constexpr");
    static_assert( akesi_li_awen_f.hasConjunctive() == true ,"not constexpr");
    static_assert( akesi_li_awen_f.hasRhs() == true ,"not constexpr");
    static_assert( akesi_li_awen_f.isValid() == true ,"not constexpr");
    static_assert( akesi_li_awen_f.getLhs().getLeaf() == akesi ,"not constexpr");
    static_assert( akesi_li_awen_f.getRhs().getLeaf() == awen ,"not constexpr");
    static_assert( akesi_li_awen_f.getConjunctive() == li ,"not constexpr");
}

TEST(Fragment, ConstexprPlusNimiNimi){
    using namespace lang::dictionary;
    static constexpr Fragment akesi_f(&akesi);
    static constexpr Fragment awen_f(&awen);

    static constexpr Fragment akesi_awen_f = akesi_f + &awen_f;

    //static_assert( akesi_awen_f.isLeaf() == false ,"not constexpr");
    //static_assert( akesi_awen_f.hasLhs() == true ,"not constexpr");
    //static_assert( akesi_awen_f.hasConjunctive() == false ,"not constexpr");
    //static_assert( akesi_awen_f.hasRhs() == true ,"not constexpr");
    //static_assert( akesi_awen_f.isValid() == true ,"not constexpr");
    //static_assert( akesi_awen_f.getLhs().getLeaf() == akesi ,"not constexpr");
    //static_assert( akesi_awen_f.getRhs().getLeaf() == awen ,"not constexpr");
}
