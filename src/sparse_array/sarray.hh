#pragma once
#include <boost/container/flat_map.hpp>
#include <functional>
#include <vector>

template <class T>
class sarray : public boost::container::flat_map<int, T>
{
    public:
        sarray(std::string name);
        sarray<T> filter(std::function<bool()> fn);
        std::vector<T> filter_vec(std::function<bool(T&)> fn);
        int insert(int id, T elt);
        int insert(std::pair<int, T> value);
    private:
        std::string name_;
};

#include "sarray.hxx"
