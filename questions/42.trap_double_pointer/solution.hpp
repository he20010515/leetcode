/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-19 15:54:34
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &height)
    {
        const int N = height.size();
        int left = 0, right = N - 1, LLmax = height[0], RRmax = height[N - 1];
        // int LRmax = 0, RLmax = 0; 这两个变量实际上是不需要的, 分别代表了left指针的rightmax, 和 right指针的leftmax;
        int ans = 0;
        while (left < right)
        {
            LLmax = max(height[left], LLmax);
            RRmax = max(height[right], RRmax);

            // 对于left来说, LLmax一定是针对于left的Lmax是准确的, LRmax不知道, 但是一定有LRmax>=RRmax;
            // 这是因为, LRmax 范围是 left指针右侧所有的数中的最大值, 包含了RRmax;
            // 所以一旦有LLmax < RRmax, 我们就能知道 LLmax<RRmax<LRmax,此时我们就能知道 left指针指向的位置可以存多少水了;
            if (LLmax < RRmax)
            {
                ans += LLmax - height[left];
                left++;
            }
            else
            {
                // 同样, 对于Right来说, RRmax针对于Right的Rmax是准确的, RLmax不知道, 但是一定有RLmax>=LLmax
                ans += RRmax - height[right];
                right--;
            }
        }
        return ans;
    }
};