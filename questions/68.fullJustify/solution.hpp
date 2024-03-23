/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 17:59:04
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> sol(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        auto curword = 0;
        bool lastline = false;
        while (true)
        {
            // 先拿单词
            vector<string> thislinewords;
            int cur_word_length = 0;
            while (cur_word_length + words[curword].size() + thislinewords.size() <= maxWidth)
            // 如果加了下一个词, 就出现了curwordlength + thislinewords.length, 说明这行放不下了
            {
                cur_word_length += words[curword].length();
                thislinewords.push_back(words[curword]);
                if (curword == words.size() - 1)
                {
                    lastline = true;
                    break;
                }
                curword++;
            }
            if (lastline)
            {
                res.push_back(fulloneLine(thislinewords, maxWidth, cur_word_length, lastline));
                break;
            }
            else
                res.push_back(fulloneLine(thislinewords, maxWidth, cur_word_length, false));
        }
        return res;
    };
    string fulloneLine(vector<string> &linewords, int maxWidth, int cur_word_length, bool lastline = false)
    {
        string line(maxWidth, ' ');
        if (linewords.size() == 1)
        {
            line.replace(0, linewords[0].size(), linewords[0]);
            return line;
        };
        if (lastline)
        {
            int wordpos = 0;
            for (auto &word : linewords)
            {
                line.replace(wordpos, word.size(), word);
                wordpos = wordpos + word.size() + 1;
            }
            return line;
        }

        auto average_black_num = (maxWidth - cur_word_length) / (linewords.size() - 1); // 平均要插入的空格数量
        auto left_black_num = (maxWidth - cur_word_length) % (linewords.size() - 1);    // 空格余数, 在每一次里面加一个
        int wordpos = 0;
        for (auto &word : linewords)
        {
            line.replace(wordpos, word.size(), word);
            wordpos = wordpos + word.size() + average_black_num;
            if (left_black_num != 0)
            {
                wordpos += 1;
                left_black_num--;
            }
        }
        return line;
    }
};