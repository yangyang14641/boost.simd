//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#define BOOST_SIMD_ENABLE_DIAG
#include <boost/simd/pack.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T>;
  using pi_t = bs::pack<iT, N>;


  T a1[N], b[N], c[N];
  iT a2[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = ((i%2) ? T(i*2) : T(-2*i))/T(3);
    a2[i] = i+1;
    b[i] = bs::round(a1[i]) ;
    c[i] = bs::round(a1[i], a2[i]);
  }
  p_t aa1(&a1[0], &a1[N]);
  pi_t aa2(&a2[0], &a2[N]);
  p_t bb (&b[0], &b[N]);
  p_t cc (&c[0], &c[N]);
  STF_IEEE_EQUAL(bs::round(aa1), bb);
  STF_IEEE_EQUAL(bs::round(aa1, aa2), cc);
}

STF_CASE_TPL("Check round on pack" , STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}
