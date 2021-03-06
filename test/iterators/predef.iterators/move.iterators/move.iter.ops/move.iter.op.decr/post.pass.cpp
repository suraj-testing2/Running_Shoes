//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <iterator>

// move_iterator

// move_iterator operator--(int);

#include <iterator>
#include <cassert>

#include "../../../../iterators.h"

template <class It>
void
test(It i, It x)
{
    std::move_iterator<It> r(i);
    std::move_iterator<It> rr = r--;
    assert(r.base() == x);
    assert(rr.base() == i);
}

int main()
{
    char s[] = "123";
    test(bidirectional_iterator<char*>(s+1), bidirectional_iterator<char*>(s));
    test(random_access_iterator<char*>(s+1), random_access_iterator<char*>(s));
    test(s+1, s);
}
