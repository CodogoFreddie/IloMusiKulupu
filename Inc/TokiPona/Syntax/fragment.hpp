#pragma once

#include <memory>
#include <string>

#include <TokiPona/Lang/nimi.hpp>

namespace tokipona {
namespace syntax {

class Fragment;

typedef struct FragmentContent{
    bool isLeaf;
    union payload {
	lang::Nimi* leaf;
	struct children {
	    std::unique_ptr<Fragment> lhs;
	    bool hasConnector;
	    lang::Nimi* conector;
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

    Fragment(Fragment&& f);

    ~Fragment();

    const std::string toString() const;
};

} //syntax
} //tokipona
