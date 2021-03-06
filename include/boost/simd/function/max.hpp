//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing max capabilities

    Computes the largest of its parameter.

    @par semantic:
    For any given value @c x and @c y of type @c T:

    @code
    T r = max(x, y);
    @endcode

    is similar to:

    @code
    T r =  (x > y) ? x : y;
    @endcode

    @par Note:

    With this definition max(x, @ref Nan) should return x...

    On some systems the intrinsic used returns Nan as soon x or y is a nan.
    So the real definition of our max function must add: but if y is Nan the result is system dependent.

    This can be corrected using the pedantic_ decorator that ensures the standard behaviour at a cost.

    @see maxnum, maxnummag,  maxmag

  **/
  Value max(Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/max.hpp>
#include <boost/simd/function/simd/max.hpp>

#endif
