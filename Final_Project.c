//HEADER FILES.....
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#define COUNT 10

struct response
{
    char title[50];
    int stars;
    char name[30];
    char date[15];
    char response[300];
    struct response *link;
};
struct starTree
{
  int stars;
  struct starTree *left;
  struct starTree *right;
};


//MAJOR FUNCTIONS.....
struct response *create(struct response *listofresponse);
void display(struct response *listofresponse);
struct response *del(struct response *listofresponse);
void sort(struct response *listofresponse);
struct response *insert(struct response *listofresponse);
struct response *delatposition(struct response *listofresponse, char item []);
void *search(struct response *listofresponse, char item[]);
struct response *modify(struct response *listofresponse, char item[]);
void TreePrint(struct starTree *root);

//MINOR FUNCTIONS.....
struct response *sortbystars(struct response *listofresponse);
struct response *sortbytitle(struct response *listofresponse);
//TREE FUNCTIONS.....
struct starTree *node;
struct starTree *root;
struct starTree *getTree();
void sortTree(int arr[],int n);
struct starTree *getnode(int x);
struct starTree *BalancedBst(int arr[],int s,int e);
void TreePrint2(struct starTree *root, int space);


struct response *acceptDate(struct response *temp){
    printf("\n\t\tEnter date of submission (DD/MM/YYYY): ");
    scanf(" %[^\n]s",(temp->date));
    if(!(isdigit(temp->date[0]) && isdigit(temp->date[1]) && isdigit(temp->date[3]) && isdigit(temp->date[4]) && isdigit(temp->date[6]) && isdigit(temp->date[7]) && isdigit(temp->date[8]) && isdigit(temp->date[9]))){
        printf("\n\t\tDate entered is wrong!!");
        acceptDate(temp);
    }
    if(strlen(temp->date) != 10){
        printf("\n\t\tDate entered is wrong!!");
        acceptDate(temp);
    }
    return temp;
}
void header(){
    printf("\n");
    printf("\t\t\t\t******************************************\n");
    printf("\t\t\t\t******************************************\n");
    printf("\t\t\t\t**\tFEEDBACK MANAGEMENT SYSTEM\t**\n");
    printf("\t\t\t\t******************************************\n");
    printf("\t\t\t\t******************************************\n");
}

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void AccessGrant(){
    char ch=20,a[8]={0,0,0,0,0,0,0,0},password[8]={'A','b','h','i','s','h','e','k'};
    int i=0;
    printf("\n\n\t\t\tENTER YOUR PASSWORD:  ");
    while (ch!=13){

        if(ch==13)
            break;
        a[i]=getch();
        printf("*");
        i++;
    }
    if(a[0]==password[0] && a[1]==password[1] && a[2]==password[2] && a[3]==password[3] && a[4]==password[4] && a[5]==password[5] && a[6]==password[6] && a[7]==password[7]){
        printf("\n-------------------------------------------------------------------------------------------------------------------------");
        printf("\n\n\t\t\t\t\tACCESS GRANTED");
        delay(1);
        printf("\n\n\t\t\t\t\t    WELCOME");
        delay(1);
    }
    else{
        printf("\n\t\t\tWRONG PASSWORD!");
        delay(1);
        printf("\n\n\t\t\t     EXITING...");
        exit(0);
    }
}

int i,n;

//MAIN FUNCTION.....
int main(){
    char item[50];
    int ch;
    struct response *listofresponse = NULL;
    AccessGrant();

    while(1){
        system("cls");
        header();
        printf("\n\t\tENTER YOUR CHOICE-\n\t\t1)CREATE\n\t\t2)DISPLAY\n\t\t3)INSERT AT POSITION\n\t\t4)DELETE\n\t\t5)DELETE AT POSITION\n\t\t6)SORT\n\t\t7)SEARCH\n\t\t8)MODIFY\n\t\t9)DISPLAY TREE OF STARS\n\t\t10)EXIT: ");
        scanf("%d",&ch);

        switch (ch){
        case 1:
            listofresponse=create(listofresponse);
            break;
        case 2:
            display(listofresponse);
            break;
        case 3:
            listofresponse=insert(listofresponse);
            break;
        case 4:
            listofresponse = del(listofresponse);
            break;
        case 5:
            printf("\n\t\tEnter title you want to delete:");
            scanf(" %[^\n]s",item);
            listofresponse=delatposition(listofresponse,item);
            break;
        case 6:
            sort(listofresponse);
            break;
        case 7:
            system("cls");
            printf("\n\t\tEnter title you want to search:");
            scanf(" %[^\n]s",item);
            search(listofresponse,item);
            break;
        case 8:
            system("cls");
            printf("\n\t\tEnter title you want to modify:");
            scanf(" %[^\n]s",item);
            listofresponse=modify(listofresponse,item);
            break;
        case 9:
            TreePrint(getTree(listofresponse));
            break;
        case 10:
            exit(0);
        default:
            printf("\n\t\tERROR!\n");
            delay(1);
            printf("\n\t\tCHOOSE AGAIN...");
        }
    }
    return 0;
}
struct response *create(struct response *listofresponse)
{
    struct response *p,*temp;
    system("cls");
    printf("\n\t\tEnter number of responses:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
       temp=(struct response *)malloc(sizeof(struct response));
       printf("\n\n\t\tEnter title name to review: ");
       scanf(" %[^\n]s", temp->title);
       printf("\n\t\tEnter your name: ");
       scanf(" %[^\n]s",(temp->name));
       temp = acceptDate(temp);
       printf("\n\t\tReview by stars(1-100): ");
       scanf("%d",&(temp->stars));
       printf("\n\t\tEnter your Response / Feedback: ");
       scanf(" %[^\n]s",(temp->response));

       if(listofresponse == NULL){
            listofresponse = temp;
            temp->link=NULL;
       }
      else{
           p=listofresponse;
           while(p->link!=NULL)
           p=p->link;
           p->link=temp;
           temp->link=NULL;
       }
   }
   printf("\n\n\t\t\tINSERTION WAS SUCCESSFULL..\n");
   delay(2);
   return listofresponse;
}

void display (struct response *listofresponse){
    char c;
    struct response *p;
    system("cls");
    if(listofresponse==NULL)
    {
        printf("\n\t\t**Order List is Empty**\n\n");
        return;
    }
    p=listofresponse;
    printf("\n%20s%20s%20s\t%s%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
    printf("\n\t\t--------------------------------------------------------------------------------------------------------");
    while(p!=NULL)
    {
        printf("\n%20s%20s%20s\t%d%40s\n",p->title, p->name, p->date, p->stars, p->response);
        p=p->link;

    }
    delay(5);
    printf("\n");
}

struct response *insert(struct response *listofresponse){
    int pos;
    system("cls");
    struct response *p,*temp;
    temp=(struct response *)malloc(sizeof(struct response)*1);
    printf("\n\t\tEnter location you want to insert:");
    scanf("%d",&pos);
    if(pos==1)
    {
        printf("\n\t\tEnter title name to review: ");
        scanf(" %[^\n]s",(temp->title));
        printf("\n\t\tEnter your name: ");
        scanf(" %[^\n]s",(temp->name));
        temp=acceptDate(temp);
        printf("\n\t\tReview %s by stars(1-100): ",temp->title);
        scanf("%d",&(temp->stars));
        printf("\n\t\tEnter your Response / Feedback: ");
        scanf(" %[^\n]s",(temp->response));
        temp->link = listofresponse;
        listofresponse = temp;

        return listofresponse;
    }
    p = listofresponse;
    for(i=1;i<pos-1 && p!=NULL;i++)
        p=p->link;
    if(p==NULL)
        printf("\n\t\t**LESS NUMBER OF ITEMS**\n\n");
    else
    {   printf("\n\t\tEnter title name to review: ");
        scanf(" %[^\n]s",(temp->title));
        printf("\n\t\tEnter your name: ");
        scanf(" %[^\n]s",(temp->name));
        temp=acceptDate(temp);
        printf("\n\t\tReview %s by stars(1-100): ",temp->title);
        scanf("%d",&(temp->stars));
        printf("\n\t\tEnter your Response / Feedback: ");
        scanf(" %[^\n]s",(temp->response));
        temp->link=p->link;
        p->link=temp;
    }
    n++;
   return listofresponse;
}

struct response *del(struct response *listofresponse)
{
    struct response *temp;
    temp=listofresponse;
    listofresponse=temp->link;
    free(temp);
    n--;
    display(listofresponse);
    return listofresponse;
}

struct response *delatposition(struct response *listofresponse,char item[])
{
  struct response *temp,*p;
  if(strcmp(listofresponse->title,item)==0)
  {
      temp=listofresponse;
      listofresponse=temp->link;
      free(temp);
      n--;
      return listofresponse;
  }
  p=listofresponse;
  while(p->link!=NULL)
  { if(strcmp(p->link->title,item)==0)
      {
            temp=p->link;
            p->link=temp->link;
            free(temp);
            n--;
            return listofresponse;
       }
     p=p->link;
   }
}

void sort(struct response *listofresponse){
    int sortch;
    system("cls");
    printf("\n\t\tWant to sort by Title(1) or by stars(2): ");
    scanf("%d",&sortch);
    if(sortch == 1){
        sortbytitle(listofresponse);
        display(listofresponse);
    }
    else if(sortch == 2){
        sortbystars(listofresponse);
        display(listofresponse);
    }
    else{
        printf("\n\t\tWrong choice!!!");
        sort(listofresponse);
    }
}

struct response *sortbystars(struct response *listofresponse)
{   struct response *p,*q,*temp;
    temp=(struct response *)malloc(sizeof(struct response));

    for(p=listofresponse;p->link!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {

        if(p->stars > q->stars)
          {
             temp->stars = p->stars;
             p->stars = q->stars;
             q->stars = temp->stars;
             strcpy(temp->title , p->title);
             strcpy(p->title , q->title);
             strcpy(q->title , temp->title);
             strcpy(temp->name , p->name);
             strcpy(p->name , q->name);
             strcpy(q->name , temp->name);
             strcpy(temp->date , p->date);
             strcpy(p->date , q->date);
             strcpy(q->date , temp->date);
             strcpy(temp->response , p->response);
             strcpy(p->response , q->response);
             strcpy(q->response , temp->response);

          }
       }
    }
}

struct response *sortbytitle(struct response *listofresponse)
{   struct response *p,*q,*temp;
    temp=(struct response *)malloc(sizeof(struct response));

    for(p=listofresponse;p->link!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {

        if(strcmp(p->title, q->title) > 0)
          {
             temp->stars = p->stars;
             p->stars = q->stars;
             q->stars = temp->stars;
             strcpy(temp->title , p->title);
             strcpy(p->title , q->title);
             strcpy(q->title , temp->title);
             strcpy(temp->name , p->name);
             strcpy(p->name , q->name);
             strcpy(q->name , temp->name);
             strcpy(temp->date , p->date);
             strcpy(p->date , q->date);
             strcpy(q->date , temp->date);
             strcpy(temp->response , p->response);
             strcpy(p->response , q->response);
             strcpy(q->response , temp->response);
          }
       }
    }
}

void *search(struct response *listofresponse,char item[])
{
    struct response *p;
    int flag=0;
    p=listofresponse;
    if(strcmp(p->title,item) == 0){
        printf("\n\t\tITEM FOUND\n");
        printf("\n%20s%20s%20s\t%s%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
        printf("\n\t\t--------------------------------------------------------------------------------------------------------");
        printf("\n%20s%20s%20s\t%d%40s",p->title, p->name, p->date, p->stars, p->response);
        flag = 1;
    }
    while(p->link!=NULL)
    {
        if(strcmp(p->link->title,item)==0)
        {
        printf("\n\t\tITEM FOUND\n");
        printf("\n%20s%20s%20s\t%s%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
        printf("\n\t\t--------------------------------------------------------------------------------------------------------");
        printf("\n%20s%20s%20s\t%d%40s",p->link->title, p->link->name, p->link->date, p->link->stars, p->link->response);
        flag = 1;
        }
        p=p->link;
    }
    if(flag==0)
        printf("\n\n\t\tTITLE NOT FOUND!\n");
}

struct response *modify(struct response *listofresponse,char item[])
{

    struct response *p;
    int choice;
    char ans1,ans2;
    int flag=0,chw=0;
    p=listofresponse;
    if(strcpy(p->title, item)==0){
        printf("\n\t\tITEM FOUND\n");
        printf("\n%20s%20s%20s\t%s%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
        printf("\n\t\t--------------------------------------------------------------------------------------------------------");
        printf("\n%20s%20s%20s\t%d%40s",p->title, p->name, p->date, p->stars, p->response);
        do
        {
            printf("\n\t\tEnter choice:\n 1)MODIFY TITLE NAME\n 2)MODIFY STARS GIVEN\n 3)MODIFY YOUR NAME\n 4)MODIFY FEEDBACK / RESPONSE  ");
            scanf("%d",&choice);

          switch (choice)
          {
            case 1:
                printf("\n\t\tCURRENT TITLE NAME IS %s", p->title);
                printf("\n\t\tEnter new title name: ");
                scanf(" %[^\n]s",(p->title));
                break;
            case 2:
                printf("\n\t\tCURRENT NUMBER OF STARS GIVEN TO %s", p->title);
                printf("\n\t\tEnter new number of stars to %s: ", p->title);
                scanf("%d",&(p->stars));
                break;
            case 3:
                printf("CURRENT NAME IS %s", p->name);
                printf("\n\t\tEnter new name: ");
                scanf(" %[\n]s",(p->name));
            case 4:
                printf("\n\t\tEnter new Feedback for %s: ", p->title);
                scanf(" %[^\n]s",(p->response));
            default:    printf("\n\t\tWRONG CHOICE");
           }
            printf("\n\n\t\tPRESS 1 TO CONTINUE MODIFICATION... ");
            scanf("%d",&chw);
        }while(chw==1);

        p=p->link;
        flag++;
        return listofresponse;
    }
       while(p->link!=NULL)
         {
            if(strcmp(p->link->title,item)==0)
            {
                printf("\n\t\tITEM FOUND\n");
                printf("\n%20s%20s%20s\t%s%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
                printf("\n\t\t--------------------------------------------------------------------------------------------------------");
                printf("\n%20s%20s%20s\t%d%40s",p->title, p->name, p->date, p->stars, p->response);
                do
                {
                    printf("\n\t\tEnter choice:\n 1)MODIFY TITLE NAME\n 2)MODIFY STARS GIVEN\n 3)MODIFY YOUR NAME\n 4)MODIFY FEEDBACK / RESPONSE  ");
                    scanf("%d",&choice);

                    switch (choice)
                    {
                        case 1:
                            printf("\n\t\tCURRENT TITLE NAME IS %s", p->title);
                            printf("\n\t\tEnter new title name: ");
                            scanf(" %[^\n]s",(p->title));
                            break;
                        case 2:
                            printf("\n\t\tCURRENT NUMBER OF STARS GIVEN TO %s", p->title);
                            printf("\n\t\tEnter new number of stars to %s: ", p->title);
                            scanf("%d",&(p->stars));
                            break;
                        case 3:
                            printf("\n\t\tCURRENT NAME IS%s ", p->name);
                            printf("\n\t\tEnter new name: ");
                            scanf(" %[^\n]s",(p->name));
                            break;
                        case 4:
                            printf("\n\t\tEnter new Feedback for %s: ", p->title);
                            scanf(" %[^\n]s",(p->response));
                            break;
                        default:    printf("\n\t\tWRONG CHOICE");
                    }
                    printf("\n\n\t\tPRESS 1 TO CONTINUE MODIFICATION... ");
                    scanf("%d",&chw);

                }while(chw==1);
            }
            p = p->link;
            flag++;
            return listofresponse;
        }
        if(flag == 0)
        printf("\n\n\t\tNOT FOUND!");
}

struct starTree *getTree(struct response *listofresponse)
{
  int arr[n];
  int point=0;
  struct response *temp = listofresponse;
  while(temp)
  {
    arr[point++]=temp->stars;
    temp=temp->link;
  }
    sortTree(arr,n);
    return BalancedBst(arr,0,n-1);
}
void sortTree(int arr[],int n)
{
  int temp;
  for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n-1-i); j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
struct starTree *getnode(int x)
{
  struct starTree *temp=(struct starTree*)malloc(sizeof(struct starTree));
  temp->stars=x;
  temp->left=temp->right=NULL;
  return temp;
}
struct starTree *BalancedBst(int arr[],int s,int e)
{
  if(s > e)
    return NULL;
  int mid=(s+e)/2;
  struct starTree *root=getnode(arr[mid]);
  root->left=BalancedBst(arr,s,mid-1);
  root->right=BalancedBst(arr,mid+1,e);
  return root;
}

void TreePrint2(struct starTree *root, int space)
{
    if (root == NULL)
        return;
    space+=COUNT;
    TreePrint2(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n\n", root->stars);
    TreePrint2(root->left, space);
}

void TreePrint(struct starTree *root)
{
    system("cls");
    printf("\n\n");
    TreePrint2(root, 0);
}
