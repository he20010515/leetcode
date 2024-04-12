/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-02 13:39:09
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-04-09 01:36:01
 * @FilePath: /leetcode/util/basic.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>
#include <ranges>
#include <tuple>
#include <type_traits>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.size() == 0)
    {
        out << "[]";
        return out;
    }
    const auto flag = &(*(--vec.end()));
    out << "[";
    for (auto &&elem : vec)
    {
        if (&elem == flag)
            out << elem;
        else
            out << elem << ", ";
    }
    out << "]";
    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &vec)
{
    out << "[" << std::endl;
    for (const auto &innerVec : vec)
        out << "  " << innerVec << ',' << std::endl;
    out << "]";
    return out;
}

// support cout << tuple;
template <size_t Index = 0, typename... Args>
typename std::enable_if<Index == sizeof...(Args), void>::type
print_tuple(std::ostream &out, const std::tuple<Args...> &tuple)
{
    // do nothing;
}
template <size_t Index = 0, typename... Args>
typename std::enable_if<(Index < sizeof...(Args)), void>::type
print_tuple(std::ostream &out, const std::tuple<Args...> &tuple)
{
    if (Index != 0)
        out << ", ";
    out << std::get<Index>(tuple);
    print_tuple<Index + 1>(out, tuple); // 递归调用
}
template <typename... Args>
std::ostream &operator<<(std::ostream &out, const std::tuple<Args...> &tuple)
{
    out << "(";
    print_tuple(out, tuple);
    out << ")";
    return out;
}

template <size_t Index, typename... Args>
class MyTupleHash
{
public:
    size_t operator()(const std::tuple<Args...> &t) const
    {
        const size_t prime = 31;
        size_t seed = MyTupleHash<Index - 1, Args...>{}(t);
        seed ^= std::hash<typename std::tuple_element<Index, std::tuple<Args...>>::type>{}(std::get<Index>(t) + prime);
        return seed;
    }
};

template <typename... Args>
class MyTupleHash<0, Args...>
{
public:
    size_t operator()(const std::tuple<Args...> &t) const
    {
        return std::hash<typename std::tuple_element<0, std::tuple<Args...>>::type>{}(std::get<0>(t));
    }
};