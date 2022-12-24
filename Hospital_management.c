/*
        DATE : APRIL 2022

        TOPIC : HOSPITAL MANAGEMNET SOFTWARE

        SECTION : IT - B

        FACULTY : DIVYA L
        
        DONE BY : A. MANOJ          ( 1602-21-737-94 )
                  BHANU TEJA V. V.  ( 1602-21-737-121 )


*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
        char name[40],gender,grp[4];
        int age;
        char  phnum[11];
}s1,s;

void login(char [30]);
void account(int);
void appoint (int );
void choice(int );
void records(int);
int Signup();
int Login();
int doclog();
char acc1[30]="grey.txt";
char acc2[30]="yang.txt";
char acc3[30]="glassman.txt";
char acc4[30]="karev.txt";
char acc5[30]="sloan.txt";
char acc6[30]="lim.txt";
char acc7[70]="murphy.txt";
char password[7][30]={"qwerty","qwerty","qwerty","qwerty","qwerty","qwerty","qwerty"};


FILE *d1,*d2,*d3,*d4,*d5,*d6,*d7;
int main()
{
    int p;
home:   system("clear"); 
        printf("\n\n\n");
    printf(" \t\t\t--------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t\t|                                                               HOSPITAL                                                                   |\n");
    printf(" \t\t\t--------------------------------------------------------------------------------------------------------------------------------------------");
rep: printf("\n\n\n");
    printf("\n\t1. Signup\n\t2. Login\n\t3. Staff Login");
    printf("\n\nChoose Option : ");
    scanf("%d",&p);
    switch(p)
    {
        case 1: system("clear");
                Signup(); 
                goto home;
                break;
        case 2: system("clear");
                Login(); break;
        case 3: doclog();break;
        default :   system("clear");
                    printf("--> Invalid Choice");
                  goto rep;
    }
}

int bk(int a)
{
    switch(a)
    {
        case 1 : return 12;
        case 2 : return 1;
        case 3 : return 2;
        case 4 : return 4;
        case 5 : return 5;
        case 6 : return 6;
    }
    return 1;
}

int book(char id[10],char id2[10])
{


    int i,j,time;
    FILE *AA;
    int a[6];
    AA=fopen(id2,"r");
    for(i=0;i<6;i++)
        fscanf(AA,"%d",&a[i]);
    fclose(AA);
    
pg: printf("\n\t1. 12:00 PM");
    if(a[0]==1)
        printf(" (Reserved) ");
    printf("\n\t2. 1:00 PM");
    if(a[1]==1)
        printf(" (Reserved) ");
    printf("\n\t3. 2:00 PM");
    if(a[2]==1)
        printf(" (Reserved) ");
    printf("\n\t4. 4:00 PM");
    if(a[3]==1)
        printf(" (Reserved) ");
    printf("\n\t5. 5:00 PM");
    if(a[4]==1)
        printf(" (Reserved) ");
    printf("\n\t6. 6:00 PM");
    if(a[5]==1)
        printf(" (Reserved) ");
    printf("\n\tChoose the time slot : ");
    scanf("%d",&time);
    switch(time)
    {
        case 1 : if(a[0]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[0]=1;break;


        case 2 : if(a[1]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[1]=1;break;
        case 3 : if(a[2]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[2]=1;break;
        case 4 : if(a[3]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[3]=1;break;
        case 5 : if(a[4]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[4]=1;break;
        case 6 : if(a[5]==1)
                    {
                        printf(" \n\t--> RESERVED \n\n");
                        goto pg;
                    }
                    else
                    a[5]=1;break;
        default : printf("\n\tChoose valid option ");
                                  goto pg;

        }
        AA=fopen(id2,"w");
    for(i=0;i<6;i++)
        fprintf(AA,"%d\n",a[i]);
    fclose(AA);
    return time;
}

void details(char *id)
{
    int cnt=0;
    char ch;
    FILE *fp;
    
    fp=fopen(id,"r");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t ------::::::: [    HOME    ] :::::::------ \n\n");
    printf("\tName : ");
    while((ch=getc(fp))!=EOF)
        {
            if(ch=='\n')
            {
                cnt++;
            }
            if(cnt==5)
                break;

            printf("%c",ch);
             if(ch=='\n')
            {
                switch(cnt)
                {
                    
                    case 1: printf("\n\tAge : ");break;
                    case 2: printf("\n\tGender: ");break;
                    case 3: printf("\n\tBlood group  : ");break;
                    case 4: printf("\n\tPhone number : ");
                }
            }
        }
        fclose(fp);

        return ;
}

int Login()
{
    int count=0,cnt=0,option,action=0,act=0,choice,tm;
    char ch,id[20],pass[30],pass2[30],pass3[30],temp[30],id2[20],id3[20],report;
    
    printf("\n\n\n\t\t\t\t\t\t   =========================== ------|    LOGIN    |------ ===========================\n");
rp: printf("\tUser ID : ");
    scanf("%s",id);
    FILE *fp=NULL;
    fp=fopen(id,"r");
    if(fp==NULL)
        {   system("clear");
            printf("\n\t\t\t\t\t\t\t\t\t -------- ]] User ID not found [[ --------\n\n");
            goto rp;
        }
    else
    {
        while(!feof(fp))
            fgets(pass2,30,fp);
rd:     printf("\n\tEnter Password : ");
        scanf("%s",pass);
        if(strcmp(pass,pass2))
        {   system("clear");
            printf("\n\t\t\t\t\t\t\t\t\t -------- ]] Incorrect Password [[ --------\n");
            count++;
            if(count==3)
                {   system("clear");
                    fclose(fp);
                    printf("\n\n\t\t\t\t\t\t\t\t\t    ******** Attempts Exceeded ********\n");
                    printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
                    return 0;
                }        
            goto rd;
        }
    }
    system("clear");
    rewind(fp);
    FILE *Q,*J,*W,*rep;
    printf("\n\t\t\t\t\t\t\t\t\t       ------[    WELCOME    ]------ \n\n");
    printf("\tName : ");
    while((ch=getc(fp))!=EOF)
        {
            if(ch=='\n')
            {
                cnt++;
            }
            if(cnt==5)
                break;

            printf("%c",ch);
             if(ch=='\n')
            {
                switch(cnt)
                {
                    
                    case 1: printf("\n\tAge : ");break;
                    case 2: printf("\n\tGender: ");break;
                    case 3: printf("\n\tBlood group  : ");break;
                    case 4: printf("\n\tPhone number : ");
                }
            }
        }
        fclose(fp);
page:   
        printf("\n\n");
        printf("\n\t1. Book appointment    2. Current appointment    3. Check previous reports    4. Change password    5. Logout\n\n");
        printf("\tSelect Option : ");
        scanf("%d",&option);
        strcpy(id2,id);
        strcat(id2,"_report");
        strcpy(id3,id);
        strcat(id3,"_appointment");
        switch(option)
        {   
            case 1: system("clear");
                    printf("\n\n\t\t\t\t\t      =========================== ------|    APPOINTMENT BOOKING    |------ ===========================\n\n");
            cho:    printf("\t1.    Dr. Meredith Grey        General surgeon  \n");
                    printf("\t2.    Dr. Cristina Yang        cardiothoracic surgeon  \n");
                    printf("\t3.    Dr. Aaron glassman       Neuro surgeon\n");
                    printf("\t4.    Dr. Alex Karev           Pediatric surgeon\n");
                    printf("\t5.    Dr. Mark sloan           Plastic surgeon\n ");
                    printf("\t6.    Dr. Audrey Lim           Orthopedic surgeon\n");
                    printf("\t7.    Dr. Shaun Murphy         General medicine\n\n");

                    printf("\tSelect Option : ");
                    scanf("%d",&choice);
                    
                    J=fopen(id3,"w");
                    switch(choice)
                    {
                        case 1: tm=book("acc1.txt","ap1.txt");
                                fprintf(J,"Dr. Meredith Grey        General surgeon  \nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report1.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 2: tm=book("acc2.txt","ap2.txt");
                                fprintf(J,"Dr. Cristina Yang        cardiothoracic surgeon  \nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report2.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 3: tm=book("acc3.txt","ap3.txt");
                                fprintf(J,"Dr. Aaron glassman       Neuro surgeon\nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report3.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 4: tm=book("acc4.txt","ap4.txt");
                                fprintf(J,"Dr. Alex Karev           Pediatric surgeon\nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report4.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 5: 
                                tm=book("acc5.txt","ap5.txt");
                                fprintf(J,"Dr. Mark sloan           Plastic surgeon\nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report5.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 6: tm=book("acc6.txt","ap6.txt");
                                fprintf(J,"Dr. Audrey Lim           Orthopedic surgeon\nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report6.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        case 7: tm=book("acc7.txt","ap7.txt");
                                fprintf(J,"Dr. Shaun Murphy         General medicine\nDate : %s\nTime : %d:00 PM",__DATE__,bk(tm));
                                rep=fopen("report7.txt","a");
                                fprintf(rep,"\n%s",id);
                                fclose(rep);
                                break;
                        default : printf("\n\tChoose valid option ");
                                  goto cho;
                    }
                    fclose(J);
                    
                    printf("\n\nEnter 1 (Go back) or 0 (Logout) : ");
                        scanf("%d",&action);
                        if(action==1)
                        {   system("clear");
                            details(id);
                            goto page;
                        } 
                        else
                            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
                    
                    break;
            
            case 2: system("clear");
                    W=fopen(id3,"r");
                    printf("\n\n\t\t\t\t\t\t  =========================== ------|    APPOINTMENT    |------ ===========================\n\n\t");
                    act=0;
                    while((report=fgetc(W))!=EOF)
                    {   if(report=='`')
                            {
                                act++;
                                printf("--> ");
                                continue;
                            }
                        printf("%c",report);
                        if(report=='\n')
                            printf("\t");
                    }  
                    fclose(W);
                        if(act==0)
                            printf("\n\nEnter 1 (To cancel) or 0 (Go back) : ");
                        else
                         {   
                            
                            details(id);
                            goto page;
                         }                                  
                        scanf("%d",&action);
                        if(action==1)
                            {
                                W=fopen(id3,"w");
                                fprintf(W,"`No Appointments\n");
                                fclose(W);
                                printf("\n\t--> Appointment Cancelled");
                                details(id);
                                goto page; 
                            }
                        else
                        {   
                            goto page;
                        }  
                     break;
            
            case 3: Q=fopen(id2,"r");
                    system("clear");
                    printf("\n\n\t\t\t\t\t\t     =========================== ------|    REPORTS    |------ ===========================\n\n\t");
                    while((report=fgetc(Q))!=EOF)
                    {   
                        printf("%c",report);
                        if(report=='\n')
                            printf("\t");
                    }  
                    fclose(Q);
                        printf("\n\nEnter 1 (Go back) or 0 (Logout) : ");
                        scanf("%d",&action);
                        if(action==1)
                        {   system("clear");
                            details(id);
                            goto page;
                        }  
                        else
                            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
                     break;
            
            case 4:    J=fopen(id,"r");
                        fgets(s1.name,40,J);
                        fscanf(J,"%d %c %s %s %s ",&s1.age,&s1.gender,s1.grp,s1.phnum,pass);
                        fclose(J);
            change:     printf("\n\n\tEnter new password: ");
                        scanf("%s",pass3);
                        if(!strcmp(pass,pass3))
                        {   
                            printf("\n\n\t\t\t\t\t\t\t\t\t  ******** Enter different password ********\n");
                            goto change;
                        }
                        printf("\n\tConfirm your password : ");
                        scanf("%s",pass2);
                        if(strcmp(pass3,pass2))
                        { 
                            printf("\n\t\t\t\t\t\t\t\t\t  -------- Password does not match --------");
                            goto change;
                        }
                        J=fopen(id,"w");
                        fputs(s1.name,J);
                        fprintf(J,"%d\n%c\n%s\n%s\n%s",s1.age,s1.gender,s1.grp,s1.phnum,pass3);
                        fclose(J);
                        printf("\n--> Password changed successfully\n");
                        printf("\n\nEnter 1 (Go back) or 0 (Logout) : ");
                        scanf("%d",&action);
                        if(action==1)
                        {   system("clear");
                            details(id);
                            goto page;
                        } 
                        else
                            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
                        break;
                       
            case 5: printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n\n");
        }         
    return 0; 
}


int Signup()
{
        FILE * fp;
        char id[20],pass[30],pass2[30],str[12],id2[20],id3[20];
        printf("\n\t\t\t\t\t\t  =========================== ------|    SIGNUP    |------ ===========================\n\n");
read:   printf("\n\nEnter user id : ");
        scanf("%s",id);

        fp=fopen(id,"r");
        if(fp==NULL)
        {
                fclose(fp);
                FILE * f;
                f=fopen(id,"w");
                strcpy(id2,id);
                strcat(id2,"_report");
                strcpy(id3,id);
                strcat(id3,"_appointment");
                fp=fopen(id2,"w");
                fclose(fp);
                fp=fopen(id3,"w");
                fclose(fp);
                printf("\n\n\tName : ");
                getchar();
                scanf("%[^\n]s",s.name);
                printf("\tAge : ");
                scanf("%d",&s.age);
                printf("\tGender (M/F) : ");
                scanf(" %c",&s.gender);
                printf("\tBlood group : ");
                scanf("%s",s.grp);
                fprintf(f,"%s\n%d\n%c\n%s\n",s.name,s.age,s.gender,s.grp);
                printf("\tPhone number : ");
                scanf("%s",s.phnum);    
                fprintf(f,"%s",s.phnum);
            
            rp: printf("\n\n\tCreate your password : ");
                scanf("%s",pass);
                printf("\n\tConfirm your password : ");
                scanf("%s",pass2);
                if(strcmp(pass,pass2))
                { 
                    printf("\n\t\t\t\t\t\t\t\t\t-------- Password does not match --------");
                    goto rp;
                }
                else
                    printf("\n\t\t\t\t\t\t\t    ============= ------| Thank you for registering |------ =============\n");
                
                FILE *W;
                W=fopen(id3,"w");
                fprintf(W,"`No Appointments\n");
                fclose(W);
                
                fprintf(f,"\n%s",pass);
                fclose(f);
                W=fopen(id2,"w");
                fprintf(W,"`No Reports\n");
                fclose(W);
                
                fprintf(f,"\n%s",pass);
                fclose(f);
        }
        else
        {
                fclose(fp);
                system("clear");
                printf("\n\n\t\t\t\t\t\t\t\t\t     ******** User ID exists ********\n");
                goto read;
        } 
        return 0;
}
int doclog(void)
{
        char id[30];
        system("clear");
        printf ("\n\n\n\tENTER YOUR LOGIN ID:  ");
        scanf ("%s",id);
        printf("\n\n");
        int i;
        for (i=0;id[i]!='\0';i++);
        id[i]='.';
        id[++i]='t';
        id[++i]='x';
        id[++i]='t';
        id[++i]='\0';
        login(id);
        return 0;
}
void login(char id[30])
{
        char p1[10],p2[10],p3[10],p4[10],p5[10],p6[10],p7[10];
        if (!strcmp(id,acc1))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); 
                scanf("%[^\n]s",p1);
                if (!strcmp(p1,password[0]))
                {
                        puts("\n\n\n\t\t\t\t\t\t\t\t\t\t** CORRECT PASSWORD :) **");
                        d1=fopen(acc1,"r");
                }
        account(1);
        }
        else if (!strcmp(id,acc2))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p2);
                if (!strcmp(p2,password[1]))
                {
                        puts("\t\t\t\t\t\t\t\t\t\t**CORRECT PASSWORD :) **");
                        d2=fopen(acc2,"r");
                }
        account(2);
        }
        else if (!strcmp(id,acc3))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p3);
                if (!strcmp(p3,password[2]))
                {
                        puts("\t\t\t\t\t\t\t\t\t\t\t** CORRECT PASSWORD :) **");
                        d3=fopen(acc3,"r");
                }
        account(3);
        }
        else if (!strcmp(id,acc4))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p4);
                if (!strcmp(p4,password[3]))
                {
                        puts("\t\t\t\t\t\t\t\t\t\t** CORRECT PASSWORD :) **");
                        d4=fopen(acc4,"r");
                }
        account(4);
        }
        else if (!strcmp(id,acc5))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p5);
                if (!strcmp(p5,password[4]))
                {
                        puts("\t\t\t\t\t\t\t\t\t\t\t** CORECT PASSWORD :)  **");
                        d5=fopen(acc5,"r");
                }
        account(5);
        }
         else if (!strcmp(id,acc6))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p6);
                if (!strcmp(p6,password[5]))
                {
                        puts("\t\t\t\t\t\t\t\t\t** CORRECT PASSWORD :) **");
                        d6=fopen(acc2,"r");
                }
        account(6);
        }
         else if (!strcmp(id,acc7))
        {
                printf ("\tENTER YOUR PASSWORD:  ");
                getchar(); scanf("%[^\n]s",p7);
                if (!strcmp(p7,password[6]))
                {
                        puts("\t\t\t\t\t\t\t\t** CORRECT PASSWORD :) **");
                        d7=fopen(acc2,"r");
                }
        account(7);
        }

        else printf ("YOUR ACCOUNT DOES'NT EXIST... TRY AGAIN");
}
void account(int n)
{
        switch (n)
        {
                char ch;
                case (1):
                        ch=fgetc(d1);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d1);
                        }
                        fclose (d1);
                        choice(1);
                        break;
                case (2):
                        ch=fgetc(d2);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d2);
                        }
                        fclose (d2);
                        choice (2);
                        break;
                case (3):
                        ch=fgetc(d3);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d3);
                        }
                        fclose (d3);
                        choice(3);
                        break;
                case (4):
                        ch=fgetc(d4);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d4);
                        }
                        fclose (d4);
                        choice(4);
                        break;
                case (5):
                        ch=fgetc(d5);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d5);
                        }
                        fclose (d5);
                        choice(5);
                        break;
                 case (6):
                        ch=fgetc(d6);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d6);
                        }
                        fclose (d6);
                        choice(6);
                        break;
                case (7):
                        ch=fgetc(d7);
                        while (ch!=EOF)
                        {
                                printf ("%c",ch);
                                ch=fgetc(d7);
                        }
                        fclose(d6);
                        choice(7);
                         break;
                default : printf ("ERROR\n");
        }
}
void choice(int q)
{
        int o;
        switch (q)
        {
        case 1:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear"); 
                if (o==1) appoint(1);
                else if (o==2) records(1);
                else if (o==3) main();
                break;

        case 2:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(2);
                else if (o==2) records(2);
                else if (o==3) main();
                break;

        case 3:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(3);
                else if (o==2) records(3);
                else if (o==3) main();
                break;

        case 4:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(4);
                else if (o==2) records(4);
                else if (o==3) main();
                break;

        case 5:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(5);
                else if (o==2) records(5);
                else if (o==3) main();
                break;

        case 6:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(6);
                else if (o==2) records(6);
                else if (o==3) main();
                break;

        case 7:
                printf ("ENTER YOUR CHOICE:     ");
                scanf ("%d",&o);
                system("clear");
                if (o==1) appoint(7);
                else if (o==1) records(7);
                else if (o==3) main();
                break;

        }
}

void appoint(int k)
{
        int n,i;
        char ch;
        FILE *fp,*ap;
        char t1[6][30]={"\n\t\t\t\t\t\t\t 12:00 PM \t\t\t\t\t\t\t    ","\n\t\t\t\t\t\t\t 01:00 PM \t\t\t\t\t\t\t    ","\n\t\t\t\t\t\t\t 02:00 PM \t\t\t\t\t\t\t    ","\n\t\t\t\t\t\t\t 04:00 PM \t\t\t\t\t\t\t    ","\n\t\t\t\t\t\t\t 05:00 PM \t\t\t\t\t\t\t    ","\n\t\t\t\t\t\t\t 06:00 PM \t\t\t\t\t\t\t    "};
        char a[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR MEREDITH GREY\t\t\t\t\t\t\t\t\t\tGENERAL\n"};
        char b[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR CRISTINA YANG\t\t\t\t\t\t\t\t\t\tCARDIOTHORACICS\n"};
        char c[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR AARON GLASSMAN\t\t\t\t\t\t\t\t\t\tNEURO\n"};
        char d[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR ALEX KAREV\t\t\t\t\t\t\t\t\t\tPEDIATRICS\n"};
        char e[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR MARK SLOAN\t\t\t\t\t\t\t\t\t\tPLASTICS\n"};
        char f[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR AUDREY LIM\t\t\t\t\t\t\t\t\t\tORTHOPEDICS\n"};
        char g[]={"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t YOUR APPOINTMENTS FOR TODAY\n\t\t\t\t\t\t\t\t\t\t-----------------------------\n\n\t\t\t\t\t      DR SHAUN MURPHY\t\t\t\t\t\t\t\t\t\tGENERAL MEDICINE\n"};
        switch (k)
        {
        case 1:
                fp=fopen("app1.txt","w");
                fputs(a,fp);
                ap=fopen ("ap1.txt","r");
                
                
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app1.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;
        case 2:
                fp=fopen("app2.txt","w");
                fputs(b,fp);

                ap=fopen ("ap2.txt","r");
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app2.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;
        case 3:
                fp=fopen("app3.txt","w");
                fputs(c,fp);
                ap=fopen ("ap3.txt","r");
                
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app3.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;

        case 4:
                fp=fopen("app4.txt","w");
                fputs(d,fp);
                ap=fopen ("ap4.txt","r");
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app4.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;

        case 5:
                fp=fopen("app5.txt","w");
                fputs(e,fp);
                ap=fopen ("ap5.txt","r");
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app5.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;
        case 6:
                fp=fopen("app6.txt","w");
                fputs(f,fp);
                ap=fopen ("ap6.txt","r");
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app6.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;

        case 7:
                fp=fopen("app7.txt","w");
                fputs(g,fp);
                ap=fopen ("ap7.txt","r");
                for (i=0;i<6;i++)
                {
                        fscanf (ap,"%d",&n);
                        if (n==1)
                        {
                                fputs(t1[i],fp);
                                fputs("RESERVED\n\n",fp);
                        }
                        else
                        {
                                fputs (t1[i],fp);
                                fputs("NOT RESERVED\n\n",fp);
                        }
                }
                fclose(ap);
                fclose(fp);
                fp=fopen ("app7.txt","r");
                while((ch=fgetc(fp))!=EOF)
                    printf("%c",ch);
                fclose(fp);
                break;
        }
}
void records(int w)
{
    system("clear"); 
    FILE * fp;
    int i=1,id,num;
    char name[20],ch,pnt[20],data;
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tYOUR PATIENTS\n\n");
    switch(w)
    {   
        case 1: fp=fopen("report1.txt","r");break;
        case 2: fp=fopen("report2.txt","r");break;
        case 3: fp=fopen("report3.txt","r");break;
        case 4: fp=fopen("report4.txt","r");break;
        case 5: fp=fopen("report5.txt","r");break;
        case 6: fp=fopen("report6.txt","r");break;
        case 7: fp=fopen("report7.txt","r");break;
    }
    while(!(feof(fp)))
    { 
        fscanf(fp,"%s",name);
        printf("\n\t%d. %s\n",i,name);
        i++;
    }
    here:
    printf("\n\nENTER THE PAITIENT CODE OR  0 TO EXIT : ");
    scanf("%d",&id);
    if( (id<0) || (id>=i) )
    {
        printf("--> Enter valid option\n\n");
        goto here;
    }
    else if(id==0)
        {
            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
            return ;
        }
    
    rewind(fp);
    while(id--)
    {
        fscanf(fp,"%s",name);
    }
    fclose(fp);
    strcat(name,"_report");
    fp=fopen(name,"r");
    ch=fgetc(fp);
    fclose(fp);
    
    if(ch=='`')
    {   printf("\n--> NO PREVIOUS REPORTS\n\n");
        printf("Write Report (enter 1) or Exit (enter 2) : ");
        scanf("%d",&num);
        if(num==1)
        {   
            fp=fopen(name,"w");
            printf("\n\n\tEnter Data (# To End report) : ");
            while(((data=getchar())!='#'))
                fprintf(fp,"%c",data);
            fclose(fp);
        }
        else if (num==2)
        {
           account(w);
            return ; 
        }
    }
    
    else
    {   system("clear"); 
        printf("\n\n\t\t\t\t\t\t     =========================== ------|    REPORTS    |------ ===========================\n\n\t");
        fp=fopen(name,"r");
        while((data=fgetc(fp))!=EOF)
        {   
            printf("%c",data);
            if(data=='\n')
                printf("\t");
        }
        fclose(fp);
        printf("\n\n\n\n\t1. Write New Report  \t2. Append report \t3. Go back \n\n\tChoose option : ");
        scanf("%d",&num);
        if(num==1)
        {   
            fp=fopen(name,"w");
            printf("\n\n\tEnter Data (# To End report) : ");
            getchar();
            while(((data=getchar())!='#'))
                fprintf(fp,"%c",data);
            fclose(fp);
            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
        }
        else if (num==2)
        {
            fp=fopen(name,"a");
            printf("\n\n\tEnter Data (# To End report) : ");
            getchar();
            while(((ch=getchar())!='#'))
                fprintf(fp,"%c",ch);
            fclose(fp);
            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
        }
        else if(num==3)
        {
            printf("\n\t\t\t\t\t\t\t        ============= ------| WISHING YOU WELL :) |------ =============\n");
            return ;
        }
    }
    
    return ;
}
