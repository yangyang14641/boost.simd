//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_INC_S_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_INC_S_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/if_plus.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( inc_
                          , (typename A0)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bd::generic_<bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const saturated_tag &,  A0 const& a0
                                    ) const BOOST_NOEXCEPT
    {
      return if_plus(is_not_equal(a0, Valmax<A0>()),
                    a0,
                    One<A0>());
    }
  };
  BOOST_DISPATCH_OVERLOAD ( inc_
                          , (typename A0)
                          , bd::cpu_
                          , bs::saturated_tag
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const saturated_tag &,  A0 const& a0
                                    ) const BOOST_NOEXCEPT
    {
      return a0+One<A0>();
    }
  };
} } }


#endif
