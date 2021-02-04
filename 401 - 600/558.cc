// 104ms, 75.90%
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;

        Node *tLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *tRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *bLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *bRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (tLeft->val == tRight->val && tLeft->val == bLeft->val && tLeft->val == bRight->val && tLeft->isLeaf &&
            tRight->isLeaf && bLeft->isLeaf && bRight->isLeaf) {
            return new Node(tLeft->val, true, nullptr, nullptr, nullptr, nullptr);
        } else {
            return new Node(false, false, tLeft, tRight, bLeft, bRight);
        }
    }
};
