//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<p_lambda/utility.hpp>

namespace plasma
{
	namespace lambda
	{
#		define PLASMA_LAMBDA_MONADIC_OPERATORS(op,name)\
			template<class Type>struct name\
		{\
			Type func_;\
			PLASMA_LAMBDA_CONFIG_CONSTEXPR name(Type const& arg):func_(arg){}\
			template<class... Ts>PLASMA_LAMBDA_CONFIG_CONSTEXPR auto operator()(Ts const&... args)\
				->decltype(op func_(args...))\
			{\
				return op func_(args...);\
			}\
		};\
		template<class Type>PLASMA_LAMBDA_CONFIG_CONSTEXPR \
			name <Type> operator op (Type const& arg)\
		{\
			return name <Type>{arg};\
		}

		PLASMA_LAMBDA_MONADIC_OPERATORS(-, monadic_operator_minus_t);
		PLASMA_LAMBDA_MONADIC_OPERATORS(+, monadic_operator_plus_t);
		PLASMA_LAMBDA_MONADIC_OPERATORS(~, monadic_operator_tilda_t);
		PLASMA_LAMBDA_MONADIC_OPERATORS(!, monadic_operator_not_t);


	}
}