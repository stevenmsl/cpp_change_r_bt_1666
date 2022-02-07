#include "solution.h"

#include <functional>
#include <unordered_set>
using namespace sol1666;
using namespace std;

/* takeaways
   - use an example (testfixture1) to explain is easier:
        \
         2
        / \
       7   4
    - if we start from node 7, node 2 will become node
      7's left (per the requirement). You need to remove
      node 7 from being node 2 child when done visiting
      node 7 as it will be node 2's new parent
    - you need to do the same if we are starting from
      node 4
    - that's why when we move up the tree and visit node 2,
      it is guaranteed that node 2 will only have one child
      due to the tie has been cut when we are visiting
      node 7 or node 4
      - this is why the instruction says cur has one child
    - so since we need to reserve node's left to store
      its old parent while re-rooting the tree, if it's
      not empty (as you are visiting from the right),
      we need to move it to the right child, which should
      be empty.

   - so in the end the tree should look like this
            7
           /
          2
         /
        5
       /
      3
     - old parent should be left child of the new parent
*/

Node *Solution::reroot(Node *root, Node *leaf)
{
  Node *newParent = nullptr;
  Node *cur = leaf;

  while (cur != root)
  {
    /*
      - read the reroot code down below first
        or it will be quite confusing why
        we are doing this
    */

    /*
      - we are moving up the tree and
        one of the two children will
        become empty as we are cutting
        the tie from the previous round
      - why we only care about the left?
        - it's reserved to point to the
          old parent (the parent will become
          cur's left per the requirement)
        - don't touch the right child if
          it's not empty (left must be
          empty in this case)

    */
    if (cur->left != nullptr)
    {
      /*
        - right must be empty so we can do this
          confidently
      */
      cur->right = cur->left;
    }
    /* reroot!
      - the parent becomes the left child
        per the requirement
      - refrain yourself from changing
        any thing on the old parent
        other than cutting the tie
        of the cur from it; or the
        code will become difficult
        to write
    */
    cur->left = cur->parent;
    /* cut the tie from the old parent */
    if (cur->parent->left == cur)
      /* cur is from the left child */
      cur->parent->left = nullptr;
    else
      /* from the right */
      cur->parent->right = nullptr;
    /*
      - set the new parent now as
        we no longer need info
        from the old parent
    */
    cur->parent = newParent;
    /*
      - set cur as the new parent
        for the next round
      - move up the tree
        - don't forget the left child
          of cur is now the old parent
    */
    newParent = cur;
    cur = cur->left;
  }

  /* set root's parent to its child
    - ok we only set the root as its child's left
      and exit the loop
    - newParent still points to root's child
  */
  root->parent = newParent;
  return leaf;
}