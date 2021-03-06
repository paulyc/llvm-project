//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T>
//   valarray<T>
//   abs(const valarray<T>& x);

#include <valarray>
#include <cassert>
#include <cstddef>

int main(int, char**)
{
    {
        typedef double T;
        T a1[] = {1.5,  -2.5,  3.4,  -4.5,  -5.0};
        T a3[] = {1.5,   2.5,  3.4,   4.5,   5.0};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<T> v3 = abs(v1);
        assert(v3.size() == v1.size());
        for (std::size_t i = 0; i < v3.size(); ++i)
            assert(v3[i] == a3[i]);
    }

  return 0;
}
