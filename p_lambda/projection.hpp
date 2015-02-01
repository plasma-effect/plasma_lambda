//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include<p_lambda/utility.hpp>

#include<utility>

namespace plasma
{
	namespace lambda
	{
		namespace detail
		{
			namespace projection_t
			{
				template<class ClassTuple>struct project_i;
				template<class... Ts>struct project_i < class_tuple<Ts...> >
				{
					template<class T>static PLASMA_LAMBDA_CONFIG_CONSTEXPR auto run(Ts&&..., T&& arg, ...)->decltype(std::forward<T>(arg))
					{
						return std::forward<T>(arg);
					}
				};
			}
		}
		template<index_t I>struct projection_t
		{
			template<class... Ts>PLASMA_LAMBDA_CONFIG_CONSTEXPR auto operator()(Ts&&... args)->
				decltype(detail::projection_t::project_i<class_tuple_first_t<class_tuple<Ts...>,I>>::run(std::forward<Ts>(args)...))
			{
				return detail::projection_t::project_i<class_tuple_first_t<class_tuple<Ts...>, I>>::run(std::forward<Ts>(args)...);
			}
		};

		//-- projection I arg --
		template<index_t I>PLASMA_LAMBDA_CONFIG_CONSTEXPR projection_t<I> _()
		{
			return projection_t<I>();
		}
	}
}