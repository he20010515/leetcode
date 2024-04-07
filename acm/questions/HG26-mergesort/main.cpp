/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2024-04-04 11:10:21
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-04-04 11:25:19
 * @FilePath: /leetcode/acm/questions/HG26-mergesort/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <vector>

void _my_merge(std::vector<int> &vec, std::vector<int> &buffer, size_t begin, size_t end)
{
    if (end == begin)
        return;
    auto mid = (begin + end) / 2;
    _my_merge(vec, buffer, begin, mid);
    _my_merge(vec, buffer, mid + 1, end);
    std::merge(buffer.begin() + begin, buffer.begin() + mid, buffer.begin() + mid + 1, buffer.begin() + end + 1, buffer.begin() + begin);
}
template <typename T>
void mergeSort(std::vector<int> &vec)
{
    auto buffer = std::vector<int>(vec.size());
    _my_merge(vec, buffer, 0, vec.size() - 1);
}

int main(int argc, char *argv[])
{

    std::vector<int> testinput = {7, 8, 9, 4, 5, 6, 1, 2, 3};
    mergeSort<int>(testinput);
}