#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 10

struct response
{
    char title[50];
    int stars;
    char name[30];
    char date[15];
    char response[300];
    struct response *link;
    struct response *left, *right;
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
struct response *starTree(struct response *listofresponse);

//MINOR FUNCTIONS.....
struct response *sortbystars(struct response *listofresponse);
struct response *sortbytitle(struct response *listofresponse);
void print2D(struct response *listofresponse);
void print2DUtil(struct response *listofresponse, int space);
void searchroot(struct response *listofresponse, int id);
/*
struct response *acceptDate(struct response *temp){
    printf("\n\t\tEnter date of submission (DD/MM/YYYY): ");
    scanf("%[^\n]s",(temp->date));
    if(strlen(temp->date) != 10){
        printf("\n\t\tDate entered is wrong!!");
        acceptDate(temp);
    }
    return temp;
}
*/
void header(){
    printf("\t\t******************************************\n");
    printf("\t\t******************************************\n");
    printf("\t\t**\tFEEDBACK MANAGEMENT SYSTEM\t**\n");
    printf("\t\t******************************************\n");
    printf("\t\t******************************************\n");
}

int i,n;

//MAIN FUNCTION.....
int main(){
    char item[50];
    int ch;
    struct response *listofresponse = NULL;
    header();

    while(1){
        printf("\n\t\tEnter choice-\n\t\t1)Create\n\t\t2)Display\n\t\t3)Insert at position\n\t\t4)Delete\n\t\t5)Delete at position\n\t\t6)Sort\n\t\t7)Search\n\t\t8)Modify\n\t\t9)Tree: ");
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
            scanf("%[^\n]s",item);
            listofresponse=delatposition(listofresponse,item);
            break;
        case 6:
            sort(listofresponse);
            break;
        case 7:
            printf("\n\t\tEnter title you want to search:");
            scanf("%[^\n]s",item);
            search(listofresponse,item);
            break;
        case 8:
            printf("\n\t\tEnter title you want to modify:");
            scanf("%[^\n]s",item);
            listofresponse=modify(listofresponse,item);
            break;
        case 9:
            starTree(listofresponse);
            break;
        default:
            printf("\n\t\tERROR!\n");

        }
    }
    return 0;
}
struct response *create(struct response *listofresponse)
{
    struct response *p,*temp;

    printf("\t\tEnter number of responses:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
       temp=(struct response *)malloc(sizeof(struct response));
       printf("\n\t\tEnter title name to review: ");
       scanf("%[^\n]s", temp->title);
       printf("\n\t\tEnter your name: ");
       scanf("%[^\n]s",(temp->name));
       //temp = acceptDate(temp);
       printf("\n\t\tReview by stars(1-100): ");
       scanf("%d",&(temp->stars));
       printf("\n\t\tEnter your Response / Feedback: ");
       scanf("%[^\n]s",(temp->response));

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
   return listofresponse;
}

void display (struct response *listofresponse)
{ struct response *p;

   if(listofresponse==NULL)
   {
       printf("\n\t\t**Order List is Empty**\n\n");
       return;
   }
  p=listofresponse;
  printf("%15s%15s%10s\t%d\t%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
  printf("\n------------------------------------------------------------------------");
  while(p!=NULL)
    {
        printf("\n\t%s\t\t%s\t\t%s\t\t%d\t\t%s",p->title, p->name, p->date, p->stars,p->response);
        p=p->link;

    }
    printf("\n");
}

struct response *insert(struct response *listofresponse)
{ int pos;
  struct response *p,*temp;
  temp=(struct response *)malloc(sizeof(struct response)*1);
  printf("\n\t\tEnter location you want to insert:");
  scanf("%d",&pos);

    if(pos==1)
      { printf("\n\t\tEnter title name to review: ");
        scanf("%[^\n]s",(temp->title));
        printf("\n\t\tEnter your name: ");
        scanf("%[^\n]s",(temp->name));
        //temp=acceptDate(temp);
        printf("\n\t\tReview %s by stars(1-100): ",temp->title);
        scanf("%d",&(temp->stars));
        printf("\n\t\tEnter your Response / Feedback: ");
        scanf("%[^\n]s",(temp->response));
        temp->link = listofresponse;
        listofresponse = temp;

        return listofresponse;
      }
     p = listofresponse;
     for(i=1;i<pos-1 && p!=NULL;i++)
        p=p->link;
     if(p==NULL)
        printf("\n\t\t**Less number of items**\n\n");

    else
    {   printf("\n\t\tEnter title name to review: ");
        scanf("%[^\n]s",(temp->title));
        printf("\n\t\tEnter your name: ");
        scanf("%[^\n]s",(temp->name));
        //temp=acceptDate(temp);
        printf("\n\t\tReview %s by stars(1-100): ",temp->title);
        scanf("%d",&(temp->stars));
        printf("\n\t\tEnter your Response / Feedback: ");
        scanf("%[^\n]s",(temp->response));
        temp->link=p->link;
        p->link=temp;
    }
   return listofresponse;
}

struct response *del(struct response *listofresponse)
{
    struct response *temp;
    temp=listofresponse;
    listofresponse=temp->link;
    free(temp);
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
      return listofresponse;
  }
  p=listofresponse;
  while(p->link!=NULL)
  { if(strcmp(p->link->title,item)==0)
      {
            temp=p->link;
            p->link=temp->link;
            free(temp);
            return listofresponse;
       }
     p=p->link;
   }
}

void sort(struct response *listofresponse){
    int sortch;
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
           printf("%15s%15s%10s%3d%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
           printf("------------------------------------------------------------------------");
           printf("%15s%15s%10s%3d%40s",p->title, p->name, p->date, p->stars, p->response);
           flag = 1;
       }
       while(p->link!=NULL)
        {
            if(strcmp(p->link->title,item)==0)
          {
            printf("\n\t\tITEM FOUND\n");
            printf("%15s%15s%10s%3d%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
            printf("------------------------------------------------------------------------");
            printf("%15s%15s%10s%3d%40s",p->title, p->name, p->date, p->stars, p->response);
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
        printf("%15s%15s%10s%3d%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
        printf("------------------------------------------------------------------------");
        printf("%15s%15s%10s%3d%40s",p->title, p->name, p->date, p->stars, p->response);
        do
        {
            printf("\n\t\tEnter choice:\n 1)MODIFY TITLE NAME\n 2)MODIFY STARS GIVEN\n 3)MODIFY YOUR NAME\n 4)MODIFY FEEDBACK / RESPONSE  ");
            scanf("%d",&choice);

          switch (choice)
          {
            case 1:
                printf("\n\t\tCURRENT TITLE NAME IS %s", p->title);
                printf("\n\t\tEnter new title name: ");
                scanf("%[^\n]s",(p->title));
                break;
            case 2:
                printf("\n\t\tCURRENT NUMBER OF STARS GIVEN TO %s", p->title);
                printf("\n\t\tEnter new number of stars to %s: ", p->title);
                scanf("%d",&(p->stars));
                break;
            case 3:
                printf("\n\t\tCURRENT NAME IS ", p->name);
                printf("\n\t\tEnter new name: ");
                scanf("%[^\n]s",(p->name));
            case 4:
                printf("\n\t\tEnter new Feedback for %s: ", p->title);
                scanf("%[^\n]s",(p->response));
            default:    printf("\n\t\tWRONG CHOICE");
           }
            printf("press 1 to continue modifying:");
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
                printf("%15s%15s%10s%3d%40s", "TITLE", "NAME", "DATE", "STARS", "RESPONSE");
                printf("------------------------------------------------------------------------");
                printf("%15s%15s%10s%3d%40s",p->title, p->name, p->date, p->stars, p->response);
                do
                {
                    printf("\n\t\tEnter choice:\n 1)MODIFY TITLE NAME\n 2)MODIFY STARS GIVEN\n 3)MODIFY YOUR NAME\n 4)MODIFY FEEDBACK / RESPONSE  ");
                    scanf("%d",&choice);

                    switch (choice)
                    {
                        case 1:
                            printf("\n\t\tCURRENT TITLE NAME IS %s", p->title);
                            printf("\n\t\tEnter new title name: ");
                            scanf("%[^\n]s",(p->title));
                            break;
                        case 2:
                            printf("\n\t\tCURRENT NUMBER OF STARS GIVEN TO %s", p->title);
                            printf("\n\t\tEnter new number of stars to %s: ", p->title);
                            scanf("%d",&(p->stars));
                            break;
                        case 3:
                            printf("\n\t\tCURRENT NAME IS ", p->name);
                            printf("\n\t\tEnter new name: ");
                            scanf("%[^\n]s",(p->name));
                        case 4:
                            printf("\n\t\tEnter new Feedback for %s: ", p->title);
                            scanf("%[^\n]s",(p->response));
                        default:    printf("\n\t\tWRONG CHOICE");
                    }
                    printf("press 1 to continue modifying:");
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

------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------

void starTree(struct response *listofresponse){
    int mid, low=0, high=1;
    struct response *temp = listofresponse;
    sortbystars(listofresponse);
    while(temp->link != NULL){
        high+=1;
        temp = temp->link;
    }
    searchroot();
    }

}

void searchroot(struct response *listofresponse, int id){
    if (root == NULL)
		return 0;
	if (root->id == id)
		return 1;
	if (root->id > id)
		return searchroot(root->left, id);
	if (root->id < id)
		return searchroot(root->right, id);
}
void print2DUtil(struct response *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process right child first
    print2DUtil(root->right, space);
    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->stars);
    // Process left child
    print2DUtil(root->left, space);
}

void print2D(struct response *root)
{
   print2DUtil(root, 0);
}
