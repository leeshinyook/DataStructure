#include <iostream>
#define null 0
using namespace std;

class Tree;

class TreeNode {
    friend class Tree;
private:
    int data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int data = 0, TreeNode * left = null, TreeNode * right = null) {
        this->left = left;
        this->right = right;
        this->data = data;
    }
};
class Tree {
private:
    TreeNode * root;
    int dup_flag = 0; // 중복되는 값 체크하는 플레그
public:
    Tree(int data = 0) { // root를 설정 생성자
        root = new TreeNode(data);
    }
    void insertNode(TreeNode* node) {
        // 중복이 없을 때

        if (search(root, node->data)) {
            TreeNode *parent = null;
            TreeNode *current = root;
            // 작으면 왼쪽, 크면 오른쪽으로 이동,
            // 새 노드의 부모가 정해짐
            while (current) {
                parent = current;
                if (node->data < parent->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (node->data < parent->data) {
                parent->left = node;
            } else {
                parent->right = node;
            }
            cout << "Inserted " << node->data << endl;
        }
    }
    TreeNode *getRoot() {
        return root;
    }
    void preorder(TreeNode* current) { // 전위순회
        if(current){
            visit(current);
            preorder(current -> left);
            preorder(current -> right);
        }
    }
    void visit(TreeNode *current) {
        cout << current -> data << " ";
    }
    TreeNode * search(TreeNode *current, int data) {
        if(!current) return null;
        if(data == current -> data) {
            return current;
        } else if (data < current -> data) {
            search(current -> left, data);
        } else {
            search(current -> right, data);
        }

    }
};
int main() {
    Tree tree(8); // root > 8
    tree.insertNode(new TreeNode(8));
    tree.insertNode(new TreeNode(3));
    tree.insertNode(new TreeNode(2));
    tree.insertNode(new TreeNode(5));
    tree.insertNode(new TreeNode(10));
    tree.insertNode(new TreeNode(14));
    tree.insertNode(new TreeNode(11));
    tree.insertNode(new TreeNode(16));
    cout<< "Preorder >> ";
    tree.preorder(tree.getRoot());

}
