#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol1666
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node *parent;
        Node(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
        Node(int val, Node *parent) : val(val), left(nullptr), right(nullptr), parent(parent) {}
    };
}
#endif