#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    

    void traverse(unordered_map<int, int> &um,int &min, queue<pair <Node*,int> > &q)
    {
        pair <Node*,int> p = q.front();
        Node* node = p.first;
        if(!node)
            return;
        int pos = p.second;
        if(um.find(p.second)==um.end())
        {
            um[pos]=node->data;  
            // cout << "Inserted " << pos << " " << node->data << endl;
            if(min>p.second)
                min=p.second;
        }
        
        if(node->left)
            q.push(pair<Node*,int>(node->left, pos-1));
        if(node->right)
            q.push(pair<Node*,int>(node->right, pos+1));
        
        if(!q.empty())
        {
            q.pop();
            traverse(um,min,q);
        }
    }


    void topView(Node * root) {
        unordered_map<int, int> um; 
        int min=INT_MAX;
        queue<pair<Node*,int> > q;

        q.push(make_pair(root,0));

        traverse(um,min,q);

        while(um.find(min)!=um.end())
        {
            cout << um[min] << " ";
            min++;
        }

    }
}; //End of Solution