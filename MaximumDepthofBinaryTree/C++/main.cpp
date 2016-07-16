#include <iostream>

using namespace std;

class Solution {
    public:
    
    int maxDepth(ThreeNode* root) {
        
        if (root == NULL)
            return 0;
        else
            return max(maxDepth(root->left)+1, maxDepth(root->right)+1);

    }
}