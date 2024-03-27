
#include<iostream>
#include<cstring>
#include<regex>
using namespace std;
class dnode{
    public:
    char name[50];
    char gmail[50];
    char number[100];
    dnode* prev;
    dnode* next;
    dnode(char n[],char g[],char r[] ){
        strcpy(name, n);
         strcpy(number, g);           // # for copying the values of n, g, r in name gmail and number arrays
        strcpy(gmail, r);
        prev=NULL;
         next=NULL;                  // # indicating that they do not point to any other node currently
    }
    friend class dlist;               // implying that dlist will have access to private and protected members of class dnode

};
class dlist{
    dnode* head, * temp, *ptr;
    dnode* ptr1,* ptr2, *dup;
    public:
    dnode* prevn;

    void insert();
    void sort();
    void deletecontact(char n[100]);
    void deletesamenumber();
    void deletesamegmail();
    void deletesamename();
    void searchbyname(char p[20]);
    void searchbynumber(char no[20]);
    void searchbygmail(char g[50]);
    void accept();
    void display();
    void update(char u[19]);
     
    dlist(){
        head=NULL;                       //this is the constructor of the dlist class initializing everything to zero indicating that the list is empty
        temp=NULL;
        ptr=NULL;
        ptr1=NULL;
        ptr2=NULL;
        dup=NULL;

    }

};
bool isValidGmail(const string& gmail) {
    // Regular expression pattern to match Gmail address format
    regex pattern("[a-zA-Z0-9._%+-]+@gmail\\.com");

    // Check if the input string matches the pattern
    return regex_match(gmail, pattern);
}
void dlist::accept(){
    char name[50];
    char gmail[78];
    char number[45];
    char ans;
    do{
        cout<<"ENTER NAME :";
        cin>>name;
        cout<<endl;

        cout<<"ENTER NUMBER : ";
        cin>>number;
        cout<<endl;

        while(strlen(number) != 10){
            cout<<"ENTER VALID NUMBER : ";
            cin>>number;
            cout<<endl;

        }
         cout<<"Enter GMAIL :";
         cin>>gmail;
         cout<<endl;

         if(!isValidGmail(gmail)){
            cout<<"ENTER VALID GMAIL";
            cin>>gmail;
            cout<<endl;
         }

         temp= new dnode(name,number,gmail);
         if(head==NULL){
            head=temp;
         }
         else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->prev=ptr;
         }
         cout<<"DO YOU WANT TO CONTINUE : ";
         cin>>ans;
    }while(ans=='y');
}

void dlist::display(){
    ptr=head;
    while(ptr!=NULL){
        cout<<"NAME : "<<ptr->name<<endl;
        cout<<"GMAIL : "<<ptr->gmail<<endl;
        cout<<"CONTACT NUMBER : "<<ptr->number<<endl;;
    ptr=ptr->next;
    }
}
void dlist::insert(){
    accept();
}
void dlist::sort(){
    dnode*i,*j;
    int temp;
    char n[10];
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            temp=strcmp(i->name,j->name);
            if(temp>0){                             //if(temp > 0): Checks if the name of node i comes after the name of   node j lexicographically. If true, it means that i should be placed after j in sorted order.
                                                   // strcpy(n, i->name); strcpy(i->name, j->name); strcpy(j->name, n);: Swaps the names of nodes i and j if i->name is lexicographically greater than j->name. This rearranges the nodes in ascending order based on their names.
                strcpy(n,i->name);
                strcpy(i->name,j->name);
                strcpy(j->name,n);
            }
        }
    }
}
void dlist::deletecontact(char s[]){
    int c=0;
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(s,ptr->name)==0){
            c=1;
            break;
        }
        else{
            c=2;
        }
        ptr=ptr->next;
    }
    if(c==1 && ptr!=head && ptr->next==NULL){
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        delete(ptr);
        cout<<"SUCCESSFULLY DELETED"<<endl;
    }
    if(ptr==head){
        head=head->next;
        head->prev=NULL;
        delete(ptr);
        cout<<"SUCCESSFULLY DELETED"<<endl;
    }
    if(ptr->next==NULL){
        ptr->prev->next=NULL;
        ptr->prev=NULL;
        delete(ptr);
        cout<<"SUCCESSFULLY DELETED"<<endl;
    }
    if(c==2){
        cout<<"YOUR ENTERED NAME IS NOT IN THE LIST"<<endl;
    }
}
void dlist:: deletesamename(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr1=ptr2;
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->name,ptr2->next->name)==0){
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(ptr2->next);
            }
            else{
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist:: deletesamegmail(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr1=ptr2;
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->gmail,ptr2->next->gmail)==0){
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(ptr2->next);
            }
            else{
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist:: deletesamenumber(){
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr1=ptr2;
        while(ptr2->next!=NULL){
            if(strcmp(ptr1->number,ptr2->next->number)==0){
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(ptr2->next);
            }
            else{
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}
void dlist::searchbyname(char na[10]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(na,ptr->name)==0){
            cout<<"NAME FOUND , HERE ARE THE DETAILS"<<endl;
            cout<<"NAME : "<<ptr->name<<endl;
             cout<<"GMAIL : "<<ptr->gmail<<endl;
            cout<<"NUMBER : "<<ptr->number<<endl;
        }
        
            ptr=ptr->next;
        
    }
}
void dlist::searchbynumber(char nu[10]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(nu,ptr->number)==0){
            cout<<"NUMBER FOUND , HERE ARE THE DETAILS"<<endl;
            cout<<"NAME : "<<ptr->name<<endl;
            cout<<"NUMBER : "<<ptr->number<<endl;
            cout<<"GMAIL : " <<ptr->gmail<<endl;
        }
        
            ptr=ptr->next;
        
    }
}
void dlist::searchbygmail(char ga[40]){
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(ga,ptr->gmail)==0){
            cout<<"GMAIL FOUND , HERE ARE THE DETAILS"<<endl;
            cout<<"NAME : "<<ptr->name<<endl;
            cout<<"NUMBER : "<<ptr->number<<endl;
            cout<<"GMAIL : " <<ptr->gmail<<endl;
        }
        
            ptr=ptr->next;
        
    }
}
void dlist::update(char n[65]){
    int ans;
    int c;
    ptr=head;
    while(ptr!=NULL){
        if(strcmp(n,ptr->name)==0){
        do{
            cout<<"WHAT DO YOU WANT TO UPDATE? \n 1.NAME \n 2.NUMBER \n 3.GMAIL "<<endl;
            cin>>c;
            switch(c){
                case 1: 
                cout<<"ENTER NEW NAME \n"<<endl;
                cin>>ptr->name;
                break;
                case 2:
                cout<<"ENTER NEW NUMBER"<<endl;
                cin>>ptr->number;
                while(strlen(ptr->number)!=10){
                    cout<<"ENTER VALID NUMBER \n";
                    cin>>ptr->number;
                }
                break;
                case 3:
                cout<<" ENTER NEW GMAIL \n";
                cin>>ptr->gmail;
                break;

            }
            cout<<"DO YOU WANT TO CONTINUE UPDATING? \n";
            cin>>ans;
            cin.ignore();
        }while(ans=='y');
        
    }
    ptr=ptr->next;
    }
}
int main(){
    char n[20];
    char nam[40];
    char name[40];
    char number[18];
    char gmail[30];
    dlist d1;              //This line creates an instance of the dlist class named d1, which represents the phone book.
    int ch,a;
    char ans;
    cout<<"!!!!!!!!      PHONE BOOK         !!!!!!!!"<<endl;
    cout<<"WHAT IS YOUR NAME ?"<<endl;
    cin.get(name,20);
    cout<<" WELCOME "<< name <<endl;
    cout<<"LET'S CREATE YOUR PHONEBOOK "<< name<< endl;
    d1.accept();
    d1.sort();
    do{
    cout<<"\n\n\n\n 1] DISPLAY YOUR PHONEBOOK \n 2] INSERT NEW CONTACT \n 3] UPDATE EXISTING CONTACTS \n 4] DELETE CONTACT \n 5] DELETE CONTACTS WITH SAME NAME \n 6]DELETE CONTACTS WITH SAME NUMBER \n 7]DELETE CONTACTS WITH SAME GMAIL \n 8] SEARCH \n\n ";
    cin>>ch;
    switch(ch){
        case 2:
        d1.insert();
        d1.sort();
        break;
        case 1:
        d1.display();
        break;
        case 3:
        cout<<"ENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE \n ";
        cin>>n;
        d1.update(n);
        d1.sort();
        break;
        case 4:
        cout<<"ENTER THE NAME OF THE PERSON WHOSE DETAILS YOU WANT TO DELETE \n";
        cin>>name;
        d1.deletecontact(name);
        case 5:
        d1.deletesamename();
        d1.display();
        break;
        case 6:
        d1.deletesamenumber();
        d1.display();
        break;
        case 7:
        d1.deletesamegmail();
        d1.display();
        break;
        case 8:
        do{
            cout<<"SEARCH BY \n 1.NAME \n 2.NUMBER \n 3.GMAIL \n";
            cin>>a;
            switch(a){
                case 1:
                cout<<"ENTER THE NAME TO BE SEARCHED "<<endl;
                cin>>name;
                d1.searchbyname(name);
                
                break;
                case 2:
                cout<<" ENTER THE NUMBER TO BE SEARCHED "<<endl;
                cin>>number;
                while(strlen(number)!=10){
                    cout<<"ENTER VALID NUMBER \n";
                    cin>>number;      
                }
                d1.searchbynumber(number);
                
                break;
                case 3:
                cout<<"ENTER THE GMAIL TO BE SEARCHED \n";
                cin>>gmail;
                d1.searchbygmail(gmail);
                
                break;
                default: cout<<" \n NO PROPER INPUT GIVEN \n";
            }
            cout<<"DO YOU WANT TO CONTINUE SEARCHING??? \n";
            cin>>ans;
        }while(ans=='y');
        break;
        default: cout<<" \n NO PROPER INPUT GIVEN \n";
        
    }
    cout<<" \n DO YOU WANT TO CONTINUE OPERATIONS ";
    cin>>ans;
}while(ans=='y');
}

