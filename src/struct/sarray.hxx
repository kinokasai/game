#pragma once
#include "logger.hh"
#include "macro.hh"
#include "sarray.hh"

template <class T>
sarray<T>::sarray(std::string name)
    : name_(name)
{}

template <class T>
std::vector<T> sarray<T>::filter_vec(std::function<bool(T&)> fn)
{
    std::vector<T> vec;
    for (auto& i : *this)
    {
        T& elt = i.second;
        if (fn(elt))
            vec.push_back(elt);
    }
    return vec;
}

template <class T>
int sarray<T>::insert(int id, T elt)
{
    this->insert(std::make_pair(id, elt));
    return 0;
}

template <class T>
int sarray<T>::insert(std::pair<int, T> value)
{
    //LOGI(name_, value.first);
    boost::container::flat_map<int, T>::insert(value);
    return 0;
}
