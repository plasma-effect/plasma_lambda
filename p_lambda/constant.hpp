//Copyright plasma-effect 2015.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<p_lambda/utility.hpp>

namespace plasma
{
	namespace lambda
	{
		template<class T>struct constant_t
		{
			T value_;
			PLASMA_LAMBDA_CONFIG_CONSTEXPR T operator()(...)
			{
				return value_;
			}
		};

		template<class T>PLASMA_LAMBDA_CONFIG_CONSTEXPR constant_t<T>constant(T v)
		{
			return constant_t<T>{v};
		}

	}
}