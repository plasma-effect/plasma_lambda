//Copyright plasma-effect 2015.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<p_lambda/utility.hpp>

namespace plasma
{
	namespace lambda
	{
		template<class Cond>struct if_base_t;
		template<class Cond, class True>struct if_true_t;
		template<class Cond, class True, class False>struct if_t;

		template<class Cond>struct if_base_t
		{
			Cond cond_;
			template<class True>PLASMA_LAMBDA_CONFIG_CONSTEXPR if_true_t<Cond, True> operator[](True&& true_)
			{
				return if_true_t<Cond, True>(
					std::forward<Cond>(cond_),
					std::forward<True>(true_));
			}
			PLASMA_LAMBDA_CONFIG_CONSTEXPR if_base_t(Cond&& cond)
				:cond_(std::forward<Cond>(cond)){}

		};

		template<class Cond, class True>struct if_true_t
		{
			Cond cond_;
			True true_;
			template<class False>PLASMA_LAMBDA_CONFIG_CONSTEXPR if_t<Cond, True, False> operator[](False&& false_)
			{
				return if_t<Cond, True, False>(
					std::forward<Cond>(cond_),
					std::forward<True>(true_),
					std::forward<False>(false_));
			}
			PLASMA_LAMBDA_CONFIG_CONSTEXPR if_true_t(Cond&& c, True&& t)
				:cond_(std::forward<Cond>(c)), true_(std::forward<True>(true_)){}
		};

		template<class Cond, class True, class False>struct if_t
		{
			Cond cond_;
			True true_;
			False false_;
			template<class... Ts>PLASMA_LAMBDA_CONFIG_CONSTEXPR auto operator()(Ts&&... args)
				->decltype(true_(std::forward<Ts>(args)...))
			{
				return (cond_(args...)) ?
					true_(std::forward<Ts>(args)...) :
					false_(std::forward<Ts>(args)...);
			}

			PLASMA_LAMBDA_CONFIG_CONSTEXPR if_t(Cond&& c, True&& t, False&& f)
				:cond_(std::forward<Cond>(c)),
				true_(std::forward<True>(t))
				,false_(std::forward<False>(f)){}
		};

		template<class Cond>PLASMA_LAMBDA_CONFIG_CONSTEXPR if_base_t<Cond> if_(Cond&& cond)
		{
			return if_base_t<Cond>(std::forward<Cond>(cond));
		}
	}
}