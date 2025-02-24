#include <iostream>
#include <string>
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
        temp->left = NULL;
        temp->right=NULL;
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
        if(root==NULL){
          return;
        }
        Display(root->left);
        cout<<root->key<<" "<<root->val<<endl;
        Display(root->right);
    }
    
    void Search(Node* root){
        int count=0;
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
          count++;
          cout<<temp->key<<" "<<temp->val<<endl;
          cout<<"Number of comparisions :"<<count<<endl;
          return;
         }
          else if(temp->key<key){
             count++;
             temp=temp->right;
          }else{
             count++;
             temp=temp->left;
          }
        }
        cout<<"Key not found";
    }
        
    void Update(Node* root,string key,string newVal){
     if(root->key==key){
       root->val=newVal;
     }else if(root->key>key){
        Update(root->left,key,newVal);
      }else{
        Update(root->right,key,newVal);
      }
    }
};

int main() {
    Dictionary obj;
    int choice;
    do {
        cout << "\n1. Insert Node\n2. Display Dictionary\n3. Search Key\n4. Update Value\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.createNode();
                break;
            case 2:
                obj.Display(obj.root);
                break;
            case 3:
                obj.Search(obj.root);
                break;
            case 4:
                string key, newVal;
                cout << "Enter Key to Update: ";
                cin >> key;
                cout << "Enter New Value: ";
                cin >> newVal;
                obj.Update(obj.root, key, newVal);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice, try again.";
        }
    } while (choice != 5);
    return 0;
}
