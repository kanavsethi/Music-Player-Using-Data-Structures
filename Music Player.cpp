#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
}*top,*temp,*top1;

void tofile(char a[])
{
    fstream f1;
    f1.open("playlist.txt",ios::out|ios::app);
    f1<<a<<endl;
    f1.close();
}

void add_node(struct node *first)
    {
    char a[100];
    while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next=(struct node*)malloc(sizeof(struct node));
    first->prev=first;
    first=first->next;
    cout<<"\n\a\a\a\aEnter Song name-  ";
    scanf("%s",&a);
    strcpy(first->song,a);
    tofile(a);
    first->next=NULL;
}

void add_node_file(struct node *first,string a)
    {
    while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next=(struct node*)malloc(sizeof(struct node));
    first->prev=first;
    first=first->next;
    strcpy(first->song,a.c_str());
    first->next=NULL;
}

void delete_file(char a[])
{
    fstream f1,f2;
    string line;
    int x=0;
    f1.open("playlist.txt",ios::in|ios::out);
    f2.open("temp.txt",ios::in|ios::out);
    while(!f1.eof())
    {
        getline(f1,line);
        if(strcmp(a,line.c_str())!=0)
        f2<<line<<endl;
        else if (strcmp(a,line.c_str())==0)
        x=1;
    }
    f1.close();
    f2.close();
    remove("playlist.txt");
    rename("temp.txt","playlist.txt");
    if(x==0)
        {
        cout << "There is no song with name you entered." << endl;
        }
    else
        {
        cout << "Song has been deleted." << endl;
        }
    }


void del_node(struct node *first)
{
    while((first->next)->next!=NULL)
    {
        first=first->next;
    }
    struct node *temp;
    temp=(first->next)->next;
    first->next=NULL;
    free(temp);
   cout<<"Deleted"<<endl;
}

void printlist(struct node *first)
{
    cout<<"\nPlaylist Name- ";
    while(first->next!=NULL)
    {
        cout<<first->song<<endl;
        first=first->next;
    }
    cout<<first->song<<endl;
}

void count_nodes(struct node *first)
{
    int i=0;
    while (first->next!=NULL)
    {
        first=first->next;
        i++;
    }
    i++;
    cout<<"\nTotal songs-  "<<i-1<<endl;
}


struct node  *del_pos(struct node *pointer, int pos)
{

           struct node *n1,*prev1,*temp;
           prev1= ( struct node *)malloc(sizeof(node));
           temp= (struct node *)malloc(sizeof(node));
           int i=0;

           if(pos==1)
           {
                temp=pointer;
                delete_file(temp->song);
                pointer=pointer->next;
                pointer->prev = NULL;
                free(temp);
                 printf("\nThe list is updated\nUse the display function to check\n");
                 return pointer;
           }
           while(i<pos-1)
           {
               prev1=pointer;
               pointer=pointer->next;
                i++;

            }

            if(pointer->next==NULL)
            {

            temp=pointer;
            delete_file(temp->song);

            prev1->next->prev=NULL;
            prev1->next=NULL;

            free(temp);
             printf("\nThe list is updated\nUse the display function to check\n");
          }

            else
            {
            temp=pointer;
            delete_file(temp->song);
            prev1->next=temp->next;
            temp->next->prev=prev1;
            free(temp);
             printf("\nThe list is updated\nUse the display function to check\n");
            }

}

void search1(struct node *first)
{
    char song[100];
    cout<<"\n\a\a\a\aEnter song To be Searched- ";
    scanf("%s",&song);
    int flag=0;

    while(first!=NULL)
    {
        if(strcmp(first->song,song)==0)
        {
            cout<<"\n\a\a\a\a#Song Found"<<endl;
            flag++;
            break;
        }
        else
        {
            first=first->next;
        }
    }
    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}

void create()
{
    top = NULL;
}

void push(char data[])
{
    if (top == NULL)
    {
        top =(struct node *)malloc(sizeof(struct node));
        top->next = NULL;
        strcpy(top->song,data);
    }
    else if (strcmp(top->song,data)!=0)
    {
        temp =(struct node *)malloc(sizeof(struct node));
        temp->next = top;
        strcpy(temp->song,data);
        top = temp;
    }
}

void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n\a\a\a\a=>NO recently played tracks.\n");
        return;
    }
    printf("\n\a\a\a\a#Recently played tracks-\n");
    while (top1 != NULL)
    {
        printf("%s", top1->song);
        printf("\n");
        top1 = top1->next;
    }
 }

void play(struct node *first)
{
    char song[100];
    printlist(first);
    cout<<"\n\a\a\a\aChoose song you wish to play- ";
    scanf("%s",song);
    int flag=0;

    while(first!=NULL)
    {
        if(strcmp(first->song,song)==0)
        {
            cout<<"\n\a\a\a\a=>Now Playing......"<<song<<endl;
            flag++;
            push (song);
            break;
        }
        else
        {
            first=first->next;
        }
    }
    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}

void recent()
{
display();
}

void topelement()
{
    top1=top;
    if(top1==NULL)
    {
        printf("\n\a\a\a\a#NO last played tracks.\n");
        return;
    }
    cout<<"\n=>Last Played Song - "<<top->song<<endl;
}


void sort( node *&pointer)
{

struct node *a = NULL;
struct node *b = NULL;
struct node *c = NULL;
struct node *e = NULL;
struct node *tmp = NULL;
while(e != pointer->next)
{
    c = a = pointer;
    b = a->next;
    while(a != e)
        {
            if(strcmp(a->song,a->song))
            {
                if(a == pointer)
                {
                    tmp = b -> next;
                    b->next = a;
                    a->next = tmp;
                    pointer = b;
                    c = b;
                }
            else
            {
                tmp = b->next;
                b->next = a;
                a->next = tmp;
                c->next = b;
                c = b;
            }
        }
        else
        {
            c = a;
            a = a->next;
        }
        b = a->next;
        if(b == e)
            e = a;
        }
    }
}
void addplaylist(struct node *start)
{
    fstream f1;
    string line;
    f1.open("playlist.txt",ios::in);
    while(!f1.eof())
    {
        getline(f1,line);
        add_node_file(start,line);
    }
    cout<<"Playlist Added"<<endl;
    f1.close();
}

void del_search(struct node *start)
{
    char song[100];
    printlist(start);
    cout<<"\n\a\a\a\aChoose song you wish to delete- ";
    scanf("%s",song);
    int flag=0;
    while(start!=NULL)
    {
        if(strcmp(start->song,song)==0)
        {
            cout<<"\n\a\a\a\a#Song Found"<<endl;
            struct node *temp;
            temp= (struct node *)malloc(sizeof(node));
            temp=start;
            delete_file(temp->song);
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            flag++;
            break;
        }
        else
        {
            start=start->next;
        }
    }
    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}

void deletemenu(struct node *start)
{
    int c;
    cout<<"Which type of delete do you want?\n1.By Search\n2.By Position"<<endl;
    cin>>c;
    switch(c)
    {
    case 1:del_search(start);
    break;
    case 2:int pos;
            printf("\nEnter the pos of the song : ");
            scanf("%d",&pos);
            del_pos(start,pos-1);
    break;
    }
}

main()
{
    int choice,loc;
    char song[100];
    struct node *start,*hold;
    start=(struct node *) malloc(sizeof(struct node));
    cout<<"\t\t\t\a\a\a\a**WELCOME**"<<endl;
    cout<<"\n**please use '_' for space."<<endl;
    cout<<"\n\n\a\a\a\aEnter your playlist name-  ";
    cin.getline(start->song,100);
    start->next=NULL;
    hold=start;
    create();

    do{
        cout<<"\n1.Add  New Song\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.Search Song\n6.Play Song\n7.Recently Played List\n8.Last Played\n9. Sorted playlist\n10.Add From File\n11.Exit"<<endl;
        cout<<("\n\a\a\a\aEnter your choice- ");
        cin>>choice;

        switch(choice)
        {
            case 1:add_node(start);
            break;
            case 2:deletemenu(start);
            break;
            case 3:printlist(start);
            break;
            case 4:count_nodes(hold);
            break;
            case 5:search1(start);
            break;
            case 6:play(start);
            break;
            case 7:recent();
            break;
            case 8:topelement();
            break;
            case 9:sort(start->next);
            printlist(start);
            break;
            case 10:addplaylist(start);
            break;
            case 11:exit(0);
        }
    }while(choice!=11);
}
