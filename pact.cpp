#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    string key;
    string val;
    Node* left;
    Node* right;
};

class Dictionary {
public:
    Node* root;
    Dictionary() { 
        root = NULL;
    }
    void createNode() {
        Node* temp = new Node;
        cout << "Enter Key :";
        cin >> temp->key ;
        cout<<"Enter Value :";
        cin >> temp->val;
        temp->left = temp->right = NULL;

        if (root == NULL) {
            root = temp;
        } else {
            InsertNode(temp, root);
        }
    }

    void InsertNode(Node* temp, Node* root) {
        if (root->key > temp->key) {
            if (root->left == NULL) {
                root->left = temp;
            } else {
                InsertNode(temp, root->left);
            }
        } else {
            if (root->right == NULL) {
                root->right = temp;
            } else {
                InsertNode(temp, root->right);
            }
        }
    }
    void Display(Node* root) {
        if (root == NULL) {
            cout << "Dictionary is empty!" << endl;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* crr = q.front(); 
            q.pop(); 
            cout << crr->key << " : " << crr->val << endl;
            if (crr->left != NULL) {
                q.push(crr->left);
            }
            if (crr->right != NULL) {
                q.push(crr->right);
            }
        }
    }
    void Search(Node* root){
        if(root==NULL){
         cout<<"root is NULL ";
         return;
        }
        string key;
        cout<<"Enter Key :";
        cin>>key;
        Node* temp=root;
        while(temp!=NULL){
          if(temp->key==key){
          cout<<temp->key<<" "<<temp->val<<endl;
           return;
         }
          else if(temp->key<key){
             temp=temp->right;
          }else{
             temp=temp->left;
          }
        }
        cout<<"Key not found";
    }
    
     Node* getKey(Node* root,string key){
        if(root==NULL){
           cout<<"root is NULL ";
           return NULL;
         }
        Node* temp=root;
        while(temp!=NULL){
          if(temp->key==key){
           return temp;
         }
          else if(temp->key<key){
             temp=temp->right;
          }else{
             temp=temp->left;
          }
        }
       return NULL;
    }
    
    void Update(Node* root){
     string key;
     cout<<"Enter Key to Update";
     cin>>key;
     string newVal;
     cout<<"Enter New value ";
     cin>>newVal;
     Node* crr=getKey(root, key);
     if(crr==NULL){
       cout<<"Key Not found ";
     }
     crr->val=newVal;
    }
};

int main() {
    Dictionary obj;
    obj.createNode();
    obj.createNode();
    obj.createNode();
    obj.createNode();
    obj.Display(obj.root);
    cout<<"Searching ";
    obj. Search(obj.root);
    obj.Update(obj.root);
    obj.Display(obj.root);
    return 0;
}

