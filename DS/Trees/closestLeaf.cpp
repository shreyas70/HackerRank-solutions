


/*
Question is to find the value of the closest leaf from a given node.
Closest leaf can be reached through parent node aswell.

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
     
    TreeNode* findNode(TreeNode* node, int target)
    {
        if(!node)
            return NULL;
        
        if(node->val==target)
        {
            return node;
        }
        
        TreeNode* smallAns1 = (findNode(node->left,target));
        
        if(smallAns1)
            return smallAns1;
            
        smallAns1 = (findNode(node->right,target));
        
        if(smallAns1)
            return smallAns1;
        
        return NULL;
    }
    void downwardLeaf(TreeNode* node, int &minDist,int level, TreeNode* &closestLeaf)
    {
        if(!node)
            return;
        
        if(!node->left && !node->right)
        {
            if(minDist>level)
            {
                closestLeaf = node;
                minDist=level;
            }
            return;
        }
        
        downwardLeaf(node->left,minDist,level+1,closestLeaf);
        downwardLeaf(node->right,minDist,level+1,closestLeaf);
        
        return;
        
    }
    
    int fromParentLeaf(TreeNode* node, int& minDist, int target, TreeNode* &closestLeaf)
    {
        if(!node)
            return -1;
          
        // distance from val node is zero
        if(node->val==target)
            return 0;
        
        // l will contain distance of target node from current node 
        // if it exists in the left subtree
        // otherwise returns -1
        int l = fromParentLeaf(node->left,minDist,target,closestLeaf);
        
        if(l>-1)
        {
        	// if target node is present in leftsubtree, serach in right subtree
            downwardLeaf(node->right,minDist,l+2,closestLeaf);
            return l+1;
        }
        
        int r = fromParentLeaf(node->right,minDist,target,closestLeaf);
        
        if(r>-1)
        {
            downwardLeaf(node->right,minDist,r+2,closestLeaf);
            return r+1;
        }

        // no match of target node
        return -1;
    }

    int findClosestLeaf(TreeNode * root, int k) {
        int minDist=INT_MAX;
        TreeNode* closestLeaf = NULL;
        TreeNode* x = findNode(root,k);
        cout << x->val << endl;
        downwardLeaf(x,minDist,0,closestLeaf);
        cout << minDist << endl;
        
        fromParentLeaf(root,minDist,k,closestLeaf);
        return closestLeaf->val;
        // Write your code here
    }
};