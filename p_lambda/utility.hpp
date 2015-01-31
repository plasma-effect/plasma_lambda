//Copyright plasma-effect 2014.
//Distributed under the Boost Software License, Version 1.0.
//(See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if defined(_MSC_FULL_VER)
#	if _MSC_FULL_VER < 185000000
#	define PLASMA_LAMBDA_CONFIG_VS2013
#	elif _MSC_FULL_VER <= 190022310
#	define PLASMA_LAMBDA_CONFIG_VS2015_PRE
#	else
#	define PLASMA_LAMBDA_CONFIG_VS2015
#	endif
#else
#define PLASMA_LAMBDA_CONFIG_OTHER_COMPILER
#endif

#ifdef PLASMA_LAMBDA_CONFIG_VS2013
#define PLASMA_LAMBDA_CONFIG_CONSTEXPR
#define PLASMA_LAMBDA_CONFIG_CONST const
#define PLASMA_LAMBDA_CONFIG_NOEXCEPT throw()
#endif
#ifdef PLASMA_LAMBDA_CONFIG_VS2015_PRE
#define PLASMA_LAMBDA_CONFIG_CONSTEXPR
#define PLASMA_LAMBDA_CONFIG_CONST const
#define PLASMA_LAMBDA_CONFIG_NOEXCEPT noexcept
#endif
#ifdef PLASMA_LAMBDA_CONFIG_VS2015
#define PLASMA_LAMBDA_CONFIG_CONSTEXPR constexpr
#define PLASMA_LAMBDA_CONFIG_CONST constexpr
#define PLASMA_LAMBDA_CONFIG_NOEXCEPT noexcept
#endif
#ifdef PLASMA_LAMBDA_CONFIG_OTHER_COMPILER
#define PLASMA_LAMBDA_CONFIG_CONSTEXPR constexpr
#define PLASMA_LAMBDA_CONFIG_CONST constexpr
#define PLASMA_LAMBDA_CONFIG_NOEXCEPT noexcept
#endif


#include<type_traits>

namespace plasma
{
	namespace lambda
	{
		//-- index type --
		typedef unsigned int index_t;

		//-- for index_tuple idiom --
		template<index_t... Is>struct index_tuple
		{
			typedef index_tuple<Is...> type;
		};
		namespace detail
		{
			template<class, bool>struct index_count_next;
			template<index_t... Is>struct index_count_next<index_tuple<Is...>, false>
			{
				static PLASMA_LAMBDA_CONFIG_CONST index_t index = sizeof...(Is);
				typedef index_tuple<Is..., (Is + index)...> type;
			};
			template<index_t... Is>struct index_count_next<index_tuple<Is...>, true>
			{
				static PLASMA_LAMBDA_CONFIG_CONST index_t index = sizeof...(Is);
				typedef index_tuple<Is..., (Is + index)..., 2 * index> type;
			};
			template<index_t I>struct index_count :index_count_next<typename index_count<I / 2>::type, I % 2>{};
			template<>struct index_count<0>
			{
				typedef index_tuple<> type;
			};
		}
		//-- make index_tuple<0,...,I-1>(typedef index_tuple<0,...,I-1> type) --
		template<index_t I>using index_count = detail::index_count<I>;

		//-- using index_count_t = typename index_count<I>::type --
		template<index_t I>using index_count_t = typename index_count<I>::type;

		//-- for class_tuple idiom (what is class_tuple idiom) --
		template<class... Ts>struct class_tuple
		{
			typedef class_tuple<Ts...> type;
		};

		namespace detail//class_tuple_size
		{
			template<class>struct class_tuple_size_i
			{
				static PLASMA_LAMBDA_CONFIG_CONST index_t value = 0;
			};
			template<class... Ts>struct class_tuple_size_i < class_tuple<Ts...> >
			{
				static PLASMA_LAMBDA_CONFIG_CONST index_t value = sizeof...(Ts);
			};
		}
		//-- get class_tuple size --
		template<class ClassTuple>using class_tuple_size = detail::class_tuple_size_i<ClassTuple>;

		namespace detail
		{
			namespace class_tuple_first
			{
				template<class ClassTuple>struct move_top_i;
				template<class First,class... Arg,class... Ret>struct move_top_i<
					class_tuple<class_tuple<First, Arg...>, class_tuple<Ret...>>>:
					class_tuple<class_tuple<Arg...>, class_tuple< Ret..., First>>{};
				template<class ClassTuple>struct move_top :move_top_i<typename ClassTuple::type>{};

				template<class ClassTuple, index_t I>struct move_top_n :move_top_n<move_top_n<ClassTuple, I / 2>, (I / 2) + (I % 2)>{};
				template<class ClassTuple>struct move_top_n<ClassTuple, 1> :move_top<ClassTuple >{};
				template<class ClassTuple>struct move_top_n<ClassTuple, 0> :ClassTuple{};

				template<class ClassTuple>struct get_return;
				template<class T0, class T1>struct get_return<class_tuple<T0, T1>> :T1{};
			}
		}
		template<class ClassTuple,index_t I>using class_tuple_first =
			detail::class_tuple_first::get_return<typename detail::class_tuple_first::move_top_n<class_tuple<ClassTuple, class_tuple<>>, I>::type>;

		//-- using class_tuple_first_t = typename class_tuple_first<ClassTuple, I>::type --
		template<class ClassTuple, index_t I>using class_tuple_first_t = typename class_tuple_first<ClassTuple, I>::type;
	}
}