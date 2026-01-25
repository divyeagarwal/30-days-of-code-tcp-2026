    class TreeNode

    {

    public:

        int data;

        TreeNode *left, *right;

        TreeNode() : data(0), left(NULL), right(NULL) {}

        TreeNode(int x) : data(x), left(NULL), right(NULL) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}

    };

*/

void preOrder(vector<int>&pre,TreeNode*root){

    if(root == nullptr){

        return ;

    }

    pre.push_back(root->data);

    preOrder(pre ,root->left);

    preOrder(pre ,root->right);

}

void inOrder(vector<int>&ino,TreeNode*root){

    if(root == nullptr){

        return ;

    }

    inOrder(ino ,root->left);

    ino.push_back(root->data);

    inOrder(ino,root->right);

}

 

void PostOrder(vector<int>&post,TreeNode*root){

    if(root == nullptr){

        return ;

    }

    PostOrder(post,root->left);

    PostOrder(post,root->right);

    post.push_back(root->data);

}

 

vector<vector<int>> getTreeTraversal(TreeNode *root){

    

    vector<int> ino, pre, post;

    inOrder(ino, root);

    PostOrder(post, root);

    preOrder(pre, root);

 

    vector<vector<int>>ans;

    ans.push_back(ino);

    ans.push_back(pre);

    ans.push_back(post);

    return ans; 

}