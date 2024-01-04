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

        int height(TreeNode* root) {
            if(!root) return 0;
            auto l = height(root->left);
            auto r = height(root->right);
            return 1+max(l,r);
        }

        pair<int,int> diameter(TreeNode* root) {
            if(!root) return {0,0};
            auto l = diameter(root->left);
            auto r = diameter(root->right);

            return {1+max(l.first,r.first),max(l.first+r.first,max(l.second,r.second))};
        }
    public:
        binaryTree() {
            // this->root = take_input_recursively();
            this->root = take_input_levelwise();
        }

        void height() {
            cout<<"Height of binary tree: "<<height(root)<<endl;
        }

        void diameter() {
            cout<<"Diameter of binary tree: "<<diameter(root).second<<endl;
        }
};

int main () {
    binaryTree t;
    t.height();
    t.diameter();
    return 0;
}

/*
           Time Complexity       Space Complexity
Height:         O(n)                 O(n) //Recursive stack space
Diameter:       O(n)                 O(n) //Recursive stack space
*/