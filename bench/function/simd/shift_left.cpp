// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

#include <simd_bench.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

template < int N >
struct shlN
{
  template<class T> T operator()(const T & a) const
  {
    return bs::shift_left(a, bd::as_integer_t<T>(N));
  }
};

DEFINE_SIMD_BENCH(simd_shift_left1, shlN<1>());
DEFINE_SIMD_BENCH(simd_shift_left2, shlN<2>());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_shift_left1, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<simd_shift_left2, NS_BENCH_IEEE_TYPES>(-10, 10);
}
