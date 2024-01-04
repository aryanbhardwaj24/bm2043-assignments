#include <bits/stdc++.h>
using namespace std;

class binaryTree;

class TreeNode {
    private:
        int val;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(int val) : val(val), left(NULL), right(NULL) {}

        ~TreeNode() {
            delete this->left;
            delete this->right;
        }

        friend class binaryTree;
};

class binaryTree {
    private:
        TreeNode* root;

        TreeNode* take_input_recursively() {
            int data;
            cin>>data;
            if(data==-1) return NULL;

            TreeNode* root = new TreeNode(data);

            root->left = take_input_recursively();
            root->right = take_input_recursively();

            return root;
        }

        TreeNode* take_input_levelwise() {
            int data;
            cout<<"Enter root data: ";
            cin>>data;

            if(data==-1) return NULL;

            TreeNode* root = new TreeNode(data);

            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();

                int l;
                cout<<"Enter the data of left child of "<<var->val<<" : ";
                cin>>l;
                if(l==-1) var->left = NULL;
                else {
                    TreeNode* temp = new TreeNode(l);
                    var->left = temp;
                    q.push(temp);
                }

                int r;
                cout<<"Enter the data of right child of "<<var->val<<" : ";
                cin>>r;
                if(r==-1) var->right = NULL;
                else {
                    TreeNode* temp = new TreeNode(r);
                    var->right = temp;
                    q.push(temp);
                }
            }
            return root;
        }

        TreeNode* construct_tree_from_inorder_preorder(int inS, int inE, vector<int> &inorder, int preS, int preE, vector<int> &preorder) {
            if(inS>inE) return NULL;

            int val = preorder[preS];
            TreeNode* root = new TreeNode(val);

            int data_index=inS;
            for(int i=inS;i<=inE;i++) {
                if(inorder[i]==val) {
                    data_index = i;
                    break;
                }
            }

            root->left = construct_tree_from_inorder_preorder(inS,data_index-1,inorder,preS+1,preS+data_index-inS,preorder);
            root->right = construct_tree_from_inorder_preorder(data_index+1,inE,inorder,preE+data_index+1-inE,preE,preorder);

            return root;
        }
    public:
        binaryTree() {
            // this->root = take_input_recursively();
            // this->root = take_input_levelwise();
            this->root = NULL;
        }

        void construct_tree_from_inorder_preorder(vector<int> &inorder, vector<int> &preorder) {
            root = construct_tree_from_inorder_preorder(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder);
        }

        void print_tree_levelwise_modified() {
            if(!root) return;

            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);

            while(!q.empty()) {
                auto var = q.front();
                q.pop();

                if(!var) {
                    cout<<endl;
                    if(!q.empty()) q.push(NULL);
                }
                else {
                    cout<<var->val<<" ";
                    if(var->left) q.push(var->left);
                    if(var->right) q.push(var->right);
                }
            }
        }
};

int main () {
    int n;
    cin>>n;

    vector<int> inorder(n);
    for(auto &i:inorder) cin>>i;

    vector<int> preorder(n);
    for(auto &i:preorder) cin>>i;

    binaryTree t;
    t.construct_tree_from_inorder_preorder(inorder,preorder);
    t.print_tree_levelwise_modified();
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) //Recursive stack space
*/