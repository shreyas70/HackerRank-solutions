/*

Find distance between two given nodes a and b, present in a binary tree.

Note that its not a BST.

O(3n) solution. Approach:
Find LCA.
Answer = d1 + d2 - 2*d3
D1 = distance between a and root
D2 = distance between b and root
D3 = distance between lca and root
Find distance from root using preorder traversal

*/


struct Node
{
    int data;
    Node* left, * right;
}; 

struct Node* lca(Node* node, int a, int b)
{
    if(!node)
    return NULL;
    
    if(node->data == a || node->data == b)
    {
        return node;
    }
    
    struct Node* leftLCA = lca(node->left,a,b);
    struct Node* rightLCA = lca(node->right,a,b);
    
    if(leftLCA && rightLCA)
    {
        return node;
    }
    else
    {
        return leftLCA?leftLCA:rightLCA;
    }
}


// used BFS below, simpler solution using DFS(preorder)
int distance(struct Node* root, int a)
{
    if(!root)
        return -1;
        
    queue<struct Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    
    while(!q.empty())
    {
        struct Node* node = q.front();
        q.pop();
        
        if(!node)
        {
            count++;
            q.push(NULL);
        }
        
        else if(node->data ==a)
            return count;
        else
        {
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
        }
    
        
    }
    
    return -1; //not found
}


/* Should return minimum distance between a and b 
   in a tree with given root*/
int findDist(Node* root, int a, int b)
{
    // Your code here 
    // cout << a << b << endl;
    // cout << (lca(root,a,b))->data << endl;
    int found_lca = lca(root,a,b)->data;
    int d1 = distance(root,a);
    int d2 = distance(root,b);
    int d3 = distance(root,found_lca);
    
    return d1+d2-2*d3;
}