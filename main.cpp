#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1666;

Node *buildTree()
{
  auto tree = new Node(3);
  tree->left = new Node(5, tree);
  tree->left->left = new Node(6, tree->left);
  tree->left->right = new Node(2, tree->left);
  tree->left->right->left = new Node(7, tree->left->right);
  tree->left->right->right = new Node(4, tree->left->right);

  tree->right = new Node(1, tree);
  tree->right->left = new Node(0, tree->right);
  tree->right->right = new Node(8, tree->right);
  return tree;
}

tuple<Node *, Node *> testFixture1()
{
  auto tree = buildTree();
  /* node 7 */
  auto leaf = tree->left->right->left;
  return make_tuple(tree, leaf);
}

tuple<Node *, Node *> testFixture2()
{
  auto tree = buildTree();
  /* node 0 */
  auto leaf = tree->right->left;
  return make_tuple(tree, leaf);
}

void test1()
{
  auto fixture = testFixture1();

  auto tree = get<0>(fixture);
  auto leaf = get<1>(fixture);

  cout << "Test 1 - expect to see 7 as the root" << endl;
  Solution sol;

  auto result = sol.reroot(tree, leaf);

  cout << "result: use debugger to verify" << endl;
}

void test2()
{
  auto fixture = testFixture2();

  auto tree = get<0>(fixture);
  auto leaf = get<1>(fixture);

  cout << "Test 1 - expect to see 0 as the root" << endl;
  Solution sol;

  auto result = sol.reroot(tree, leaf);

  cout << "result: use debugger to verify" << endl;
}
main()
{
  test1();
  test2();
  return 0;
}