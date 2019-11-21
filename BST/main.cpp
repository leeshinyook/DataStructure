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
    int deleteNode(TreeNode *root, int data) {
        // 경우의 수 : 3가지
        // 1. 자식이 없는 노드를 지울 때
        // 2. 자식이 하나만 있는 노드를 지울 때
        // 3. 자식이 두개 다 있는 노드를 지울 때
        TreeNode * t = root;
        TreeNode * parent = NULL;
        TreeNode * child, *succ_p, *succ;

        while(t != NULL && t->data != data) {
            parent = t;
            t = (t -> data > data) ? t -> left : t -> right;
        }

        if(t == NULL) {
            return 0;
        }
        if(t -> left == NULL && t -> right == NULL) { // 1. 자식이 없는 노드일때
            if(parent != NULL) {
                if(parent -> left == t) parent -> left = NULL; // 왼쪽이면 왼쪽 삭제
                else parent -> right = NULL; // 오른쪽이면 오른쪽삭제
            }
        } else if(t -> left == NULL || t -> right  == NULL) { // 2. 자식이 하나만 있는 노드를 지울 떄
            child = (t->left == NULL) ? t->left : t->right; // 위치에 맞게 child 할당

            if (parent != NULL) { // t를 건너 뛰고 child로 바로 연결
                if (parent->left == t) parent->left = child;
                else parent->right = child;
            } else root = child;
        } else { // 3. 자식이 두개 다 있는 노드를 지울때
            succ_p = t;
            succ = t -> right;

            while(succ -> left != NULL) {
                succ_p = succ;
                succ = succ -> left;
            }
            if(succ_p -> left = succ) succ_p -> left = succ_p -> right;
            else succ_p -> right = succ -> right;

            t -> data = succ -> data;
            t = succ;
        }
        free(t);
        return 0;
    }
    TreeNode * search(TreeNode *current, int data) {
        if(current== NULL){
            return NULL;}
        if(data == current -> data) {
            return current;
        } else if (data < current -> data) {
            search(current -> left, data);
        } else {
            search(current -> right, data);
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
    void inorder(TreeNode* current) {
        if(current) {
            inorder(current -> left);
            visit(current);
            inorder(current -> right);
        }
    }
    void postorder(TreeNode* current) {
        if(current) {
            postorder(current -> left);
            postorder(current -> right);
            visit(current);
        }

    }
    void visit(TreeNode *current) {
        cout << current -> data << " ";
    }

};
int main() {
    Tree tree(8); // root > 8
    tree.insertNode(new TreeNode(12));
    tree.insertNode(new TreeNode(3));
    tree.insertNode(new TreeNode(2));
    tree.insertNode(new TreeNode(5));
    tree.insertNode(new TreeNode(10));
    tree.insertNode(new TreeNode(14));
    tree.insertNode(new TreeNode(11));
    tree.insertNode(new TreeNode(16));
    tree.preorder(tree.getRoot());
    tree.inorder(tree.getRoot());
    tree.postorder(tree.getRoot());
    tree.deleteNode(tree.getRoot(), 11);
    tree.preorder(tree.getRoot());

}
