#pragma once

#include <type_traits>

template <class S, class C, typename = void>
struct is_streamable : ::std::false_type
{};

template <class S, class C>
struct is_streamable<S, C,
    decltype(void(std::declval<S&>() <<std::declval<C const&>() ))
        > : ::std::true_type
{};
