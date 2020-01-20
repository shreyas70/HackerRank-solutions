

/*
Binary tree find number of turns needed from node a to node b



1. Find LCA
2. t1 = turns(LCA,n1)
3. t2 = tuns(LCA,n2)
4. if(LCA is one of the values) return t1+t2
    else return t1+t2+1

*/

Node* findLca(Node* node,int first, int second)
{
    if(!node)
        return NULL;
        
    if(node->key==first || node->key==second)
        return node;
    
    Node* l = findLca(node->left,first,second);
    Node* r = findLca(node->right,first,second);
    
    if(l && r)
        return node;
    
    if(l)
        return l;
        
    if(r)
        return r;
        
    return NULL;
        
}

int turns(Node* node, int val, int leftFlag)
{
    if(!node)
        return -1;
    
    if(node->key==val)
        return 0;
        
    int l = turns(node->left,val,1);
    if(l>-1)
    {
        if(leftFlag==-1) //only for toor
            return l;
        else if(leftFlag)
            return l;
        else
            return l+1;
    }
    
     int r = turns(node->right,val,0);
    if(r>-1)
    {
        if(leftFlag==-1) //only for root
            return r;
        else if(leftFlag)
            return r+1;
        else
            return r;
    }
    return -1;
    
}
int NumberOFTurn(struct Node* root, int first, int second)
{
	Node* lca = findLca(root,first,second);
	int throughLCA=1;
	if(lca->key == first || lca->key == second)
	    throughLCA=0;
	int t1 = turns(lca,first,-1);
	int t2 = turns(lca,second,-1);
	
	if(throughLCA)
	    return t1+t2+1; 
	else
	    return t1+t2;
}