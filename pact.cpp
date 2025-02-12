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
     
    Node* Max(Node* left){
      while(root->right!=NULL){
        root=root->right;
      }
      return root;
    }
    
    Node* getNode(Node* root,string u_key){
      Node* crr=root;
      if(crr->key==u_key){
         return crr;
      }else if(crr->key<u_key){
         crr=crr->right;
      }else{
         crr=crr->left;
      }
      return NULL;
    }
    
    void Delete(Node* root,string u_key){
      if(root==NULL){
        return;
      }else{
         Node* toDel=getNode(root,u_key);
         if(toDel->left==NULL && toDel->right==NULL){
           delete toDel;
         }else if(toDel->)
         
      }
    
      
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
    string key;
    cout<<"Enter Key to Update";
    cin>>key;
    string newVal;
    cout<<"Enter New value ";
    cin>>newVal;
    obj.Update(obj.root,key,newVal);
    obj.Display(obj.root);
    return 0;
}
