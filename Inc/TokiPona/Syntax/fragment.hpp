#pragma once

#include <memory>

#include <TokiPona/Lang/nimi.hpp>

namespace tokipona {
namespace syntax {

class Fragment;

typedef struct FragmentContent{
    bool isLeaf;
    union payload {
	lang::Nimi leaf;
	struct children {
	    std::unique_ptr<Fragment> lhs;
	    std::unique_ptr<Fragment> rhs;
	};
    };
} FragmentContent;

class Fragment{
private:
    FragmentContent content;

public:
    Fragment(const lang::Nimi& nimi_);
    Fragment(const Fragment& lhs_, const Fragment& rhs_);
};

} //syntax
} //tokipona
