/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 13:59:22
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 15:43:17
 * @FilePath: /leetcode/util/leetcode.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "solution.hpp"
#include "units.hpp"

template <typename... args, size_t... is>
auto __helper(Solution &s, tuple<args...> &t, index_sequence<is...>)
{
    return s.sol(get<is>(t)...);
}

template <typename... args>
auto call_sol(Solution &s, tuple<args...> &t)
{
    return __helper(s, t, index_sequence_for<args...>{});
}
template <typename... args>
auto call_sol(Solution *s, tuple<args...> &t)
{
    return __helper(*s, t, index_sequence_for<args...>{});
}

int main(int argc, char const *argv[])
{
    auto sol = new Solution;
    size_t total_test_num = TEST_UNIT_INPUT.size(), passed_test_num = 0;
    size_t index = 0;
    for (auto &&[in, out] : std::ranges::views::zip(TEST_UNIT_INPUT, TEST_UNIT_OUTPUT))
    {
        index++;
        auto res = call_sol(sol, in);
        auto is_right = compare(out, res);
        if (is_right)
        {
            cout << "[" << index << "/" << total_test_num
                 << "] 🎉  passed" << endl;
            passed_test_num++;
        }
        else
        {
            cout << "[" << index << "/" << total_test_num
                 << "] 💥  failed" << endl;
            cout << in << endl;
            cout << "gt:\t";
            cout << out << endl;
            OutputType ourout = std::make_tuple(res);
            cout << "pre:\t";
            cout << ourout << endl;
        }
    }
    float passed_percent = passed_test_num * 1.0f / total_test_num;
    cout << "--------" << endl;
    cout << "unit test finish,"
         << "total:" << total_test_num
         << " passed:" << passed_test_num
         << " percent:" << passed_percent * 100 << "%" << endl;

    if (passed_test_num == total_test_num)
    {
        cout << "🎉🎉🎉🎉🎉 all tests passed" << endl;
    }

    return 0;
}
