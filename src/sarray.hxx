#pragma once
#include <boost/container/flat_map.hpp>

/* This is a Sparse Array implementation */

template <class T>
using sarray = boost::container::flat_map<int, T>;
