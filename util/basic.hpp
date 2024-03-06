/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-02 13:39:09
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 17:06:37
 * @FilePath: /leetcode/util/basic.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <ranges>
#include <string>
#include <type_traits>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
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
        out << "  " << innerVec << std::endl;
    out << "]";
    return out;
}