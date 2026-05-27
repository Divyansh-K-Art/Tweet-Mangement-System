#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NODE
{
public:
    string ID;
    string UNAME;
    string TWEET;
    NODE *NEXT;
        NODE(string x, string y, string z){
            ID = x;
            UNAME = y;
            TWEET = z;
            NEXT = nullptr;
    }
};
class LinkList
{
public:
    string TID;
    int TCNT;
    string UNAME,UTWEET;
    NODE *start, *end;
    int countNode;
    LinkList(){
        TCNT = 1001;
        countNode = 0;
        start = nullptr;
        end = nullptr;
    }
    void getData()
    {
        TID = "TWEET"+ to_string(TCNT);
        cout<<"\nEnter TID -- "<<TID<<endl;
        cout<<"Enter User Name -- ";
        getline(cin,UNAME);
        cout<<"Enter Tweet -- ";
        getline(cin,UTWEET);
    }
    char continueCheck()
    {
        char c;
        cout<<"\n\nAre you.. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Previous Menu\n";
        cout<<"3. Go to Main Menu..\n";
        cout<<"4. Exit\n";
        c = getch();
        if ( c == '4'){
            thanksLine();
            exit(0);
        }else{
            return (c);
        }
     }

     //*****insertion*****/

     int insertnode(int opr)
     {
         if ( opr == 1){
             cout<<"\n\nInsert At Beginning . \n\n";
             getData();
             NODE *tempnode = new NODE(TID, UNAME, UTWEET);
             if (tempnode == nullptr){
                 cout<<"\nMemory Not Available\n\n";
                 return 0;
             }
             if ( start == nullptr){
                 start = end = tempnode;
             }
             else{
                 tempnode->NEXT = start;
                 start = tempnode;
             }
             countNode++;
             TCNT++;
         }
         else if ( opr == 2){
             cout<<"\n\nInsert At End . \n\n";
             getData();
             NODE *tempnode = new NODE(TID, UNAME, UTWEET);
             if (tempnode == nullptr){
                 cout<<"\nMemory Not Available\n\n";
                 return 0;
             }
             if ( start == nullptr){
                 start = end = tempnode;
             }
             else{
                 end->NEXT = tempnode;
                 end = tempnode;
             }
             countNode++;
             TCNT++;}
         else if ( opr == 3){
             cout<<"\n\nInsert At Position . \n\n";
             cout<<"Total Number of Nodes -- "<<countNode<<" Nodes Available\n\n";
             int pos;
             cout<<"Enter Position between (0) to ("<<countNode<<") -- ";
             cin>>pos;

             NODE *tempnode = new NODE(TID, UNAME, UTWEET);
             if(tempnode == nullptr){
                 cout<<"\nMemory Not Available\n\n";
                 return 0;
             }
             int i;
             NODE *tempnode1 = start;
             for(i=2;i<pos;i++){
                 tempnode1 = tempnode1->NEXT;
             }
             if(start==nullptr){
                    start = end = tempnode;
            }
            else{
                tempnode->NEXT = tempnode1->NEXT;
                tempnode1->NEXT = tempnode; 
                if(tempnode1 == end){
                    end = tempnode1->NEXT;
                }
            }
            countNode++;
            TCNT++;
         }
         char c = continueCheck();
         if(c == '1')
            insertnode(opr);
         else if ( c == '2')
            insertionOperation();
         else if ( c == '3')
            MainMenu();
     } 
     void showNodes()
     {
        cout<<"\n\nLink List --\n\n";
        cout<<"* Head -> ";
        NODE *tempnode = start;
        if ( start == nullptr){
            cout<<"null \n\nlist is empty...\n";
        }
        else{
            while ( tempnode != nullptr){
                cout<<"["<<tempnode->ID<<", ";
                cout<<tempnode->UNAME<<", ";
                cout<<tempnode->TWEET<<"] -> ";
                tempnode = tempnode->NEXT;
            }
            cout<<"Null";
        }
     }
     void countNodes()
     {
        system("cls");
        cout<<"Count Nodes Module --\n\n";
        cout<<"Total  "<<countNode<<" Nodes are  Available...\n\n";
     }
     int insertionOperation()
     {
        system("cls");
        cout<<"\nInsertion Operation -- \n\n";
        cout<<"1. Insert At Beginning.\n";
        cout<<"2. Insert At End.\n";
        cout<<"3. Insert After data.\n";
        cout<<"4. Go to Main Menu.\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if( c =='1'){
            insertnode(1);
        }
        else if ( c == '2'){
            insertnode(2);
        }
        else if ( c == '3'){
            insertnode(3);
        }
        else if ( c == '4'){
            MainMenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
     }
     //*****deletion*****

     int deleteNode(int opr)
     {
        NODE *tempnode;
        if (opr ==1){
             cout<<"\n\nDelete From Beginning . \n\n";
            if(start == nullptr){
                cout<<"\n\nList is Empty...\n\n";
                return 0;
            }
            else if ( start->NEXT == nullptr){
                delete start;
                start = end = nullptr;
            }
            else{
                tempnode = start;
                start = start->NEXT;
            }
            countNode--;
            delete(tempnode);
            cout<<"\nNode Deleted Successfully\n\n";
        }
        else if (opr == 2){
            cout<<"\n\ndelete from end . \n\n";
            if ( start == nullptr){
                cout<<"LinkList IS Empty...\n\n";
                return 0;
            }
            else if ( start->NEXT == nullptr){
                tempnode = start;
                start = end = nullptr;
            }
            else{
                tempnode = start;
                while ( tempnode->NEXT != end){
                    tempnode = tempnode->NEXT;
                }
                NODE *tempnode1 = end;
                tempnode->NEXT = nullptr;
                end = tempnode;
                cout<<end->UNAME<<endl;
                delete(tempnode1);
            }
            countNode--;
            cout<<"\nNode Deleted Successfully\n\n";
        }
        else if(opr ==3){
            cout<<"\n\nDelete From Given Position . \n\n";

            if(start == nullptr)
            {
                cout<<"\n\nLinkList is Enpty...\n\n";
                return 0;
            }
            int pos;
            cout<<"Enter position for delete (1 - "<<countNode<<") -- ";
            cin>>pos;
            if(pos == 1 && start == end)
            {
                tempnode = start;
                start = end = nullptr;
            }
            else{
                tempnode = start;
                for (int i = 2 ; i < pos ; i++){
                    tempnode = tempnode->NEXT;
                }
                if(tempnode->NEXT==end){
                    NODE *tempnode1 =end;
                    tempnode->NEXT = nullptr;
                    end = tempnode;
                }
                else{
                    NODE *tempnode1 = tempnode->NEXT;
                    tempnode->NEXT = tempnode1->NEXT;
                    delete(tempnode1);
                }
            }
            countNode--;
             cout<<"\nNode Deleted Successfully\n\n";
        }
        char c = continueCheck();
        if ( c == '1')
            deleteNode(opr);
        else if ( c == '2')
            deleteOperation();
        else if ( c == '3')
            MainMenu();
     }
     int deleteOperation()
     {
        system("cls");
        cout<<"\nDelete Operation -- \n\n";
        cout<<"1. Delete From Beginning\n";
        cout<<"2. Delete From End\n";
        cout<<"3. Delete From Given Position\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit\n";
        char c = getch();
        if ( c == '1')
            deleteNode(1);
        else if ( c == '2')
            deleteNode(2);
        else if ( c == '3')
            deleteNode(3);
        else if ( c == '4')
            MainMenu();
        else if ( c == '5'){
             thanksLine();
             exit(0);
         }
    }   

    //*****searching*****

    int searchTweetInNode()
    {
        cout<<"\n\nSearch Tweet in Nodes -- \n\n";
        cout<<"* Head -> ";
        NODE *tempnode = start;
        if ( start == nullptr){
            cout<<"null \n\nlist is empty\n";
            return 0;
        }
        else{
            cout<<"\n\nEnter User Name To Find Tweets -- ";
            string uname;
            int counter = 0;
            getline(cin,uname);
            while ( tempnode!= nullptr){
                if (tempnode->UNAME == uname)
                {
                    cout<<"\n["<<tempnode->ID<<", ";
                    cout<<tempnode->UNAME<<", ";
                    cout<<tempnode->TWEET<<"]\n";
                    counter++;
                }
                tempnode = tempnode->NEXT;
            }
            if ( counter == 0){
                cout<<"\nNo Tweet Found..\n\n";
            }
        }
        char c ;
        cout<<"\n\nAre you.. \n";
        cout<<"1. Continue with Same\n";
        cout<<"2. Go to Main Previous Menu\n";
        cout<<"3. Exit\n";
        c = getch();
        if ( c == '1')
            searchTweetInNode();
        else if ( c == '2')
            MainMenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);
         }
    }

    int MainMenu()
    {
        system("cls");
        cout<<"========== LinkList Operation ==========\n\n";
        cout<<"1. Insertion Operation\n";
        cout<<"2. Traversal Operation\n";
        cout<<"3. Delete Operation\n";
        cout<<"4. Search Operation\n";
        cout<<"5. Count Nodes\n";
        cout<<"6. Go to Home Menu\n";
        cout<<"7. Exit\n";
        cout<<"Choose One of them -- ";
        char c = getch();
        if ( c == '1')
            insertionOperation();
        else if ( c == '2')
            showNodes();
        else if ( c == '3')
            deleteOperation();
        else if ( c == '4')
            searchTweetInNode();
        else if ( c == '5')
            countNodes();
    /* else if ( c == '6')
            MainLinkList::MainLinkListModule();*/
        else if ( c == '7'){
            thanksLine();
            exit(0);
        }
        cout<<"\n\nDo you want to continue .. press 1 else any key..";
        c = getch();
        if ( c == '1')
            MainMenu();
    }
    void thanksLine()
    {
        cout<<"\n\nThanks for Using My APP...\n\n";
    }
};
int main()
{
    LinkList l;
    l.MainMenu();
    cout<<"\n\nThanks for Using My APP...\n\n";
    return 0;
}