/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 16:17:42
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <string>
#include <unordered_map>

using namespace std;
class Solution
{
private:
public:
    bool sol(string s)
    {
        enum CharType
        {
            Char_num,
            Char_point,
            Char_e,
            Char_sign,
            Char_unknown,
        };
        enum Status
        {
            ST_begin,
            ST_sign,
            ST_numbefore,
            ST_numpoint_withprefixnum,
            ST_numpoint_withoutprefixnum,
            ST_numafter,
            ST_expE,
            ST_expSign,
            ST_expnum,
            ST_end,
        };
        static const auto chartype = [](char &ch)
        {
            if (ch >= '0' and ch <= '9')
                return Char_num;
            else if (ch == '.')
                return Char_point;
            else if (ch == 'e' or ch == 'E')
                return Char_e;
            else if (ch == '+' or ch == '-')
                return Char_sign;
            else
                return Char_unknown;
        };
        unordered_map<Status, unordered_map<CharType, Status>>
            Transfer = {
                {
                    ST_begin,
                    {
                        {Char_num, ST_numbefore},
                        {Char_sign, ST_sign},
                        {Char_point, ST_numpoint_withoutprefixnum},

                    },
                },
                {
                    ST_sign,
                    {
                        {Char_num, ST_numbefore},
                        {Char_point, ST_numpoint_withoutprefixnum},
                    },
                },
                {
                    ST_numbefore,
                    {
                        {Char_num, ST_numbefore},
                        {Char_e, ST_expE},
                        {Char_point, ST_numpoint_withprefixnum},
                    },
                },
                {
                    ST_numpoint_withprefixnum,
                    {
                        {Char_num, ST_numafter},
                        {Char_e, ST_expE},
                    },
                },
                {
                    ST_numpoint_withoutprefixnum,
                    {
                        {Char_num, ST_numafter},
                    },
                },
                {
                    ST_numafter,
                    {
                        {Char_num, ST_numafter},
                        {Char_e, ST_expE},
                    },
                },
                {
                    ST_expE,
                    {
                        {Char_num, ST_expnum},
                        {Char_sign, ST_expSign},
                    },
                },
                {
                    ST_expSign,
                    {
                        {Char_num, ST_expnum},
                    },
                },
                {
                    ST_expnum,
                    {
                        {Char_num, ST_expnum},
                    },
                },
            };
        auto curstatus = ST_begin;
        for (auto &ch : s)
        {
            auto cp = chartype(ch);
            if (Transfer[curstatus].contains(cp))
            {
                curstatus = Transfer[curstatus][cp];
            }
            else
            {
                return false;
            }
        }
        return curstatus == ST_begin or
               curstatus == ST_end or
               curstatus == ST_expnum or
               curstatus == ST_numbefore or
               curstatus == ST_numafter or
               curstatus == ST_numpoint_withprefixnum;
    };
};
