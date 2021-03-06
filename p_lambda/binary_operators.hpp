//Copyright plasma-effect 2015.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<p_lambda/utility.hpp>

namespace plasma
{
	namespace lambda
	{
#		define PLASMA_LAMBDA_BINARY_OPERATORS(op,name)\
		template<class Lhs,class Rhs>struct name\
		{\
			Lhs lhs_;\
			Rhs rhs_;\
			PLASMA_LAMBDA_CONFIG_CONSTEXPR name(Lhs const& lhs,Rhs const& rhs)\
				:lhs_(lhs),rhs_(rhs){}\
			template<class... Ts>PLASMA_LAMBDA_CONFIG_CONSTEXPR auto operator()(Ts const&... args)\
				->decltype(lhs_(args...) op rhs_(args...))\
			{\
				return lhs_(args...) op rhs_(args...);\
			}\
		};\
		template<class Lhs,class Rhs>PLASMA_LAMBDA_CONFIG_CONSTEXPR name <Lhs,Rhs> operator op (Lhs const& lhs,Rhs const& rhs)\
		{\
			return name <Lhs, Rhs>{lhs,rhs};\
		}

		PLASMA_LAMBDA_BINARY_OPERATORS(+, binary_operator_plus_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(-, binary_operator_minus_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(*, binary_operator_mul_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(/ , binary_operator_div_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(%, binary_operator_mod_t);

		PLASMA_LAMBDA_BINARY_OPERATORS(<< , binary_operator_left_shift_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(>> , binary_operator_right_shift_t);

		PLASMA_LAMBDA_BINARY_OPERATORS(== , binary_operator_equal_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(!= , binary_operator_not_equal_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(< , binary_operator_less_than_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(> , binary_operator_more_than_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(<= , binary_operator_less_equal_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(>= , binary_operator_more_equal_t);

		PLASMA_LAMBDA_BINARY_OPERATORS(| , binary_operator_bit_or_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(&, binary_operator_bit_and_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(|| , binary_operator_logic_or_t);
		PLASMA_LAMBDA_BINARY_OPERATORS(&&, binary_operator_logic_and_t);
	}
}