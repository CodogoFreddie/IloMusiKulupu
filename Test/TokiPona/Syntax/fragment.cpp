#include<TokiPona/Syntax/fragment.hpp>

#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <TokiPona/Lang/dictionary.hpp>

using namespace tokipona;
using namespace syntax;

TEST(Fragment, ConstexprConstructInternal){
    using namespace lang::dictionary;

    constexpr auto akesi_awen = akesi + awen;

    //static_assert(akesi_awen.getLhs() == akesi, "not constexpr");
    static_assert(akesi_awen.getConj() == nullptr, "not constexpr");
    //static_assert(akesi_awen.getRhs() == awen, "not constexpr");
}

TEST(Fragment, ConstExprConstructDifferentTrees){
    using namespace lang::dictionary;

    constexpr auto nimi_nimi_plus_nimi = (akesi + awen) + ante;
    constexpr auto nimi_plus_nimi_nimi = akesi + (awen + ante);
    constexpr auto nimi_nimi_nimi = akesi + awen + ante;

    //static_assert( nimi_nimi_plus_nimi.getLhs().getLhs() == akesi, "not constexpr");
    //static_assert( nimi_nimi_plus_nimi.getLhs().getRhs() == awen, "not constexpr");
    //static_assert( nimi_nimi_plus_nimi.getRhs() == ante, "not constexpr");
    //static_assert( nimi_nimi_plus_nimi.getConj() == nullptr, "not constexpr");
    
    //static_assert( nimi_plus_nimi_nimi.getLhs() == akesi, "not constexpr");
    //static_assert( nimi_plus_nimi_nimi.getRhs().getLhs() == awen, "not constexpr");
    //static_assert( nimi_plus_nimi_nimi.getRhs().getRhs() == ante, "not constexpr");
    //static_assert( nimi_plus_nimi_nimi.getConj() == nullptr, "not constexpr");
    
    //static_assert( nimi_nimi_nimi.getLhs().getLhs() == akesi, "not constexpr");
    //static_assert( nimi_nimi_nimi.getLhs().getRhs() == awen, "not constexpr");
    //static_assert( nimi_nimi_nimi.getRhs() == ante, "not constexpr");
    //static_assert( nimi_nimi_nimi.getConj() == nullptr, "not constexpr");
}

TEST(Fragment, ConstExprConjunctive){
    using namespace lang::dictionary;

    constexpr auto akesi_li_awen = li(akesi, awen);

    //static_assert(akesi_li_awen.getLhs() == akesi, "not constexpr");
    //static_assert(akesi_li_awen.getConj() == &li_c, "not constexpr");
    //static_assert(akesi_li_awen.getRhs() == awen, "not constexpr");
}
