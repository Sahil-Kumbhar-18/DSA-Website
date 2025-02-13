#include<iostream>
#define maxS 20
using namespace std;

class Patient{
  public:
    int priority;
    string name;
};

class P_Queue{
  Patient arr[maxS];
  int front=-1;
  int rear=-1;
  public:
    bool isFull(){
      if(rear==maxS-1){
         return true;
      }
      return false;
    }
    
    bool isEmpty(){
      if(front==rear){
       return true;
      }
      return false;
    }
    
    void Enqueue(Patient p){
      if(isFull()){
        cout<<"Queue Overflow ";
      }
      else{
        int i=rear;
        while(i>=0 && p.priority>arr[i].priority){
           arr[i+1]=arr[i];
           i--;
        }
        arr[i+1]=p;
        rear++;
      }
    }
    
    string Prio(int priority){
      if(priority==1){
        return "General Patient Patient";
      }else if(priority==2){
        return "Non Serious Patient";
      }else if(priority==3){
        return "Serious Patient ";
      }
      return "Invalid";
    }
    
    void Dequeue(){
      if(isEmpty()){
        cout<<"Queue Empty ";
      }
      else{
       front++;
       cout<<"Name of Patient :"<<arr[front].name<<"  "<<"Type :"<<Prio(arr[front].priority)<<endl;
      }
    }
};

int main(){
    P_Queue obj;
    int n;
    cout<<"Enter Number of Patients :";
    cin>>n;
    for(int i=0;i<n;i++){
       Patient p;
       cout<<"Enter Name of Patient :";
       cin>>p.name;
       cout<<"Enter Priority between 1 to 3 :";
       cin>>p.priority;
       obj.Enqueue(p);
    }
    while(!obj.isEmpty()){
       obj.Dequeue();
    }
    return 0;
}
