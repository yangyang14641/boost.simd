//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/pack.hpp>
#include <simd_bench.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_raw_trunc, bs::raw_(bs::trunc));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_raw_trunc, NS_BENCH_NUMERIC_TYPES>(-10, 10);
}
