#include <iostream>
 
using namespace std;
 
struct list
{
    int data;
    list *next;
};
 
void initlist(list *A)
{
    A = new list;
    A->next = NULL;
}
 
void addver(list *A, int X)
{
    list *T = new list;
    T->data = X;
    T->next = A->next;
    A->next = T;
}
 
void addkon(list *A, int X)
{
    list *T = new list, *T1 = A;
    T->data = X;
    T->next = NULL;
    while(T1->next!=NULL) T1 = T1->next;
    T1->next = T;
}
 
int top(list *A)
{
    return A->next->data;
}
 
void printlist(list *A)
{
    list *T = A->next;
    cout << "list\t";
    while(T)
    {
        cout << T->data << "  ";
        T = T->next;
    }
    cout << endl;
}
 
void delver(list *A)
{
    list *q;
    if(A->next)
    {
        q = A->next;
        A->next = q->next;
        delete q;
    }
    else cout << "Spisok pustoy";
}
 
int main()
{ list *Q = new list, *D;
    Q->next = NULL;
    int n,x, imax, max;
    cout << "N = "; cin >> n;
    cin >> x;
    max = x;
    imax = n;
    addver(Q,x);
    for(int i = n-1; i > 0;i--)
    {
        cin >> x;
        if(x > max)
        {max = x;
        	imax = i;
        }
        addver(Q,x);
 
    }
 
    printlist(Q);
    D = Q;
    for(int i = 1; i <= imax; i++)
    D = D->next;
    addver(D,0);
    //delver(Q);
    cout << Q << endl << top(Q) << endl;
    printlist(Q);
    delete [] Q;
        return 0;
}
