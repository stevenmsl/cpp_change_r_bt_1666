
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <stack>
#include <string>
using namespace std;
namespace sol1666
{
    class Solution
    {
    private:
    public:
        Node *reroot(Node *root, Node *leaf);
    };
}
#endif