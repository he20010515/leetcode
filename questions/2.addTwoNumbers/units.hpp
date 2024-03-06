#include <iostream>
#include <vector>
#include <tuple>
#include "env.hpp"

using namespace std;
using InputType = tuple<ListNode *, ListNode *>;
using OutputType = tuple<ListNode *>;

// 342+456 = 708;
int a_1[3] = {3, 4, 2}, b_1[3] = {4, 6, 5}, c_1[3] = {8, 0, 7};
ListNode *p1 = new ListNode(a_1, 3);
ListNode *q1 = new ListNode(b_1, 3);
ListNode *r1 = new ListNode(c_1, 3);

// 0+0 = 0;
int a_2[1] = {0}, b_2[1] = {0}, c_2[1] = {0};
ListNode *p2 = new ListNode(a_2, 1);
ListNode *q2 = new ListNode(b_2, 1);
ListNode *r2 = new ListNode(c_2, 1);

// 9999999+9999 = 10009998;
int a_3[7] = {9, 9, 9, 9, 9, 9, 9}, b_3[4] = {9, 9, 9, 9}, c_3[8] = {1, 0, 0, 0, 9, 9, 9, 8};
ListNode *p3 = new ListNode(a_3, 7);
ListNode *q3 = new ListNode(b_3, 4);
ListNode *r3 = new ListNode(c_3, 8);

vector<InputType> TEST_UNIT_INPUT = {
    {p1, q1},
    {p2, q2},
    {p3, q3},
};

vector<OutputType> TEST_UNIT_OUTPUT = {
    {{r1}},
    {{r2}},
    {{r3}},

};

std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    auto a = get<0>(input);
    auto b = get<1>(input);
    out << "a: " << a << "\t";
    out << "b: " << b;
    return out;
}

std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    auto c = get<0>(output);
    out << "c: " << c;
    return out;
}

bool compare(OutputType ground_truth, OutputType res)
{
    auto gt_ = get<0>(ground_truth);
    auto out_ = get<0>(res);
    return *gt_ == *out_;
}