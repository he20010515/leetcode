

#include <array>
#include <cstdint>
#include <iostream>
#include <regex>
using namespace std;

// 点分10进制转uint32
const uint32_t dot10(const string s)
{
    static auto pattern = regex(R"(^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$)");
    smatch matchres;
    uint32_t res = 0;
    if (std::regex_match(s, matchres, pattern))
    {
        int p1, p2, p3, p4;
        p1 = std::stoi(matchres[1].str());
        p2 = std::stoi(matchres[2].str());
        p3 = std::stoi(matchres[3].str());
        p4 = std::stoi(matchres[4].str());
        if (p1 <= 255 and p2 <= 255 and p3 <= 255)
        {
            res = p1 << 3 * 8 |
                  p2 << 2 * 8 |
                  p3 << 1 * 8 |
                  p4 << 0 * 8;
            return res;
        }
        else
        {
            throw "illegal";
        }
    }
    else
    {
        throw "illegal";
    }
}

enum ipv4type
{
    A = 0,
    B,
    C,
    D,
    E,
};

ipv4type checkip(uint32_t addr)
{
    static uint32_t A_begin = dot10("1.0.0.0");
    static uint32_t A_end = dot10("126.255.255.255");
    static uint32_t B_begin = dot10("128.0.0.0");
    static uint32_t B_end = dot10("191.255.255.255");
    static uint32_t C_begin = dot10("192.0.0.0");
    static uint32_t C_end = dot10("223.255.255.255");
    static uint32_t D_begin = dot10("224.0.0.0");
    static uint32_t D_end = dot10("239.255.255.255");
    static uint32_t E_begin = dot10("240.0.0.0");
    static uint32_t E_end = dot10("255.255.255.255");

    bool isinA = addr >= A_begin and addr <= A_end;
    bool isinB = addr >= B_begin and addr <= B_end;
    bool isinC = addr >= C_begin and addr <= C_end;
    bool isinD = addr >= D_begin and addr <= D_end;
    bool isinE = addr >= E_begin and addr <= E_end;

    if (isinA)
    {
        return ipv4type::A;
    }
    if (isinB)
    {
        return ipv4type::B;
    }
    if (isinC)
    {
        return ipv4type::C;
    }
    if (isinD)
    {
        return ipv4type::D;
    }
    if (isinE)
    {
        return ipv4type::E;
    };
    return ipv4type::A;
}
bool isprivate(uint32_t addr)
{
    static uint32_t part1_start = dot10("10.0.0.0");
    static uint32_t part1_end = dot10("10.255.255.255");
    static uint32_t part2_start = dot10("172.16.0.0");
    static uint32_t part2_end = dot10("172.31.255.255");
    static uint32_t part3_start = dot10("192.168.0.0");
    static uint32_t part3_end = dot10("192.168.255.255");
    bool isinp1 = addr >= part1_start and addr <= part1_end;
    bool isinp2 = addr >= part2_start and addr <= part2_end;
    bool isinp3 = addr >= part3_start and addr <= part3_end;
    return isinp1 or isinp2 or isinp3;
}

bool ismask(uint32_t mask)
{
    if (mask == ~((uint32_t)0) or mask == 0)
        return false;
    int counter = 0;
    while ((mask & 1) == 0)
    {
        mask >>= 1;
        counter++;
    }
    for (int i = 0; i < 32 - counter; i++)
    {
        if ((!(mask & 1)) == 1)
            return false;
    }
    return true;
};

int main()
{

    string add_and_mask;
    array<int, 7> counter = {0};
    while (cin >> add_and_mask)
    {
        auto p = add_and_mask.find('~');
        uint32_t address;
        bool isilligal = false;
        try
        {
            address = dot10(add_and_mask.substr(0, p));
        }
        catch (string s)
        {
            isilligal = true;
        }
        try
        {
            auto mask = dot10(add_and_mask.substr(p + 1,
                                                  add_and_mask.size() - p - 1));
            if (!ismask(mask))
            {
                isilligal = true;
            }
        }
        catch (string s)
        {
            isilligal = true;
        }

        if (isilligal)
        {
            counter[5]++;
            continue;
        }
        auto type = checkip(address);
        counter[type]++;
        if (isprivate(address))
            counter[6]++;
    }

    for (int i = 0; i < 7; i++)
    {
        cout << counter[i] << " ";
    }
}
// 64 位输出请用 printf("%lld")