/*
 * traits.h
 *
 *  Created on: 4 дек. 2015 г.
 *      Author: stas
 */

#ifndef YS_TRAITS_H
#define YS_TRAITS_H

#include <type_traits>

namespace ys {

template<typename T>
struct const_ref {
	using type = typename std::add_lvalue_reference<
					const typename std::remove_reference<
						typename std::remove_const<T>::type>::type>::type;
};

template<typename T>
using const_ref_t = typename const_ref<T>::type;

template<typename T1, typename ... T2>
constexpr bool any_of(T1 val, T1 arg, T2 ... args) {
	return val == arg || (sizeof...(args) == 0 ? true : any_of(val, args...));
}

template<typename T1, typename ... T2>
constexpr bool none_of(T1 val, T1 arg, T2 ... args) {
	return val != arg && (sizeof...(args) == 0 ? true : any_of(val, args...));
}

}

#endif /* YS_TRAITS_H */
