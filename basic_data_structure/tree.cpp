#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

/*
* The way of tree encoding and decoding is use the pre-order traverse to build
*/
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:
    string s="";
    void dfs(TreeNode* root)
    {
        if (root == NULL)
        {
            s += "#,";
            return;
        }
        stringstream tmp;
        tmp << root->val;
        s += tmp.str();
        s += ',';
        dfs(root->left);
        dfs(root->right);
        return;
    };
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string r = "";
        if (!root)
            return "";
        dfs(root);
        return s.substr(0,s.size()-1);
    };

    queue<string> seperate(string data)
    {
        queue<string> result;
        string tmp = "";
        for(int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                result.push(tmp);
                tmp = "";
            }
            else
            {
                tmp += data[i];
            }
        }
        result.push(tmp);
        return result;
    };
    TreeNode* ddfs(queue<string>& r)
    {
        if (r.size() < 1)
            return NULL;
        string tmp = r.front();
        r.pop();
        if (tmp == "#")
        {
            return NULL;
        }
        TreeNode* result = new TreeNode(atoi(tmp.c_str()));
        result->left = ddfs(r);
        result->right = ddfs(r);
        return result;
    };
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        queue<string> r = seperate(data);
        return ddfs(r);
    }
};

int main(int argc, const char * argv[]) {
	Codec codec;
	string tmp = "1,2,3,#,4,#,5,6,#"; 
	TreeNode* t = codec.deserialize(tmp);
	string s = codec.serialize(t);
	cout << "original one" << tmp << endl;
	cout << "after enconding:" << s << endl;
    return 0;
}
