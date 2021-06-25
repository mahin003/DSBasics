#include<bits/stdc++.h>
using namespace std;
//Every thing we need to about Linked List

struct Node
{
    int data;
    Node* next;
};
Node *head;
void insertAtFront(int value)
{
    Node* temp= (Node*)(malloc(sizeof(struct Node)));
    temp->data=value;
    temp->next=head;
    head=temp;

}
void insertAtNth(int value, int pos)
{
    //taking n-1 as pos
    if(head==NULL && pos>1)
    {
        cout<<"cant enter at this pos"<<endl;
        return;
    }

    Node* temp= (Node*)(malloc(sizeof(struct Node)));
    Node* temp2=head ;

    for(int i=0; i<pos-1; i++)
    {
        cout<<"text "<<temp->data<<endl;
        temp2=temp2->next;

    }
    temp->data=value;
    temp->next=temp2->next;
    temp2->next=temp;


}
void forwordPrint()
{
    cout<<"RESULTS \n";
    Node* temp2= head;
    while(temp2!=NULL)
    {
        cout<<"value "<<temp2->data<<endl;
        temp2=temp2->next;
    }
}
void insertAtEnd(int val)
{
    Node* temp= (Node*) malloc(sizeof(struct Node));
    Node* temp2= head;
    while(temp2->next!=NULL)
    {
        temp2= temp2->next;
    }

    temp->data=val;
    temp->next=NULL;
    temp2->next=temp;
}
void DeleteFromFront()
{
    Node* temp= head;
    head= temp->next;
    free(temp);
}
void DeletFromNth(int pos)
{
    Node* temp= head;
    for(int i=0; i<pos-2; i++)
    {
        temp= temp->next;
    }
    Node* temp2=temp;
    temp2=temp2->next;
    temp->next=temp2->next;
    free(temp2);
}
void DeleteFromEnd()
{
    Node* temp= head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    Node* temp2= temp;
    temp2->next=NULL;
    free(temp->next);
}
void ReverseTheList()
{
    Node* temp= head;
    Node *prev=NULL, *curr;

    while(temp!=NULL)
    {

        curr= temp->next;
        temp->next= prev;
        prev= temp;
        temp=curr;

    }

    head= prev;

}
void forwardReccursion(Node *temp){

   if(temp==NULL){
      return;
   }
   cout<<temp->data<<endl;
   forwardReccursion(temp->next);

}
void ReverseReccursion(Node *temp){

   if(temp==NULL){
      return;
   }

   ReverseReccursion(temp->next);
   cout<<temp->data<<endl;


}
int main()
{
    head=NULL;
    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    insertAtFront(4);
    insertAtFront(11);
    insertAtFront(22);
    insertAtFront(33);
    insertAtFront(44);

    //Instert at Nth
    forwordPrint();
    insertAtNth(9, 2);
    cout<<"afetr inserting 3 at 2nt pos"<<endl;
    forwordPrint();
    cout<<"afetr inserting at the end"<<endl;

    insertAtEnd(10);
    insertAtEnd(120);
    forwordPrint();

    //Delte
    cout<<"deleting from front"<<endl;
    DeleteFromFront();
    forwordPrint();
    cout<<"Deleting from Nth pos";
    DeletFromNth(3);
    forwordPrint();
    DeletFromNth(2);
    forwordPrint();
    cout<<"Deleting from end\n";
    DeleteFromEnd();
    forwordPrint();

    cout<<"Reversing the List\n";
    ReverseTheList();
    forwordPrint();
    //cout<<head;
    cout<<"Reversing second time too get the original\n";
    ReverseTheList();
    forwordPrint();

    //forwardorder with reccusrion
    cout<<"forwar print with reccursion\n";
    forwardReccursion(head);
    cout<<"reverse print with reccursion\n";
    ReverseReccursion(head);
}
