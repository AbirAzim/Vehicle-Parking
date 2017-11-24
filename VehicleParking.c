#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 1000
#define SIZE 100

struct time
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliSecond;
};

typedef struct time Time;


struct information
{
    char name[20];
    char phoneNumber[20];
    char VIN[18];
    char serialnumber[7];
    char type[12];
    int  row;
    int  column;
    Time starttime;
};

typedef struct information Info;

struct Admin
{
    char admin_name[20];
    char password[20];
};

typedef struct Admin section;

section admin;
Info info[MAX];
char disp[SIZE][SIZE];
int total=0;
int totalCar = 0;
int totalBike = 0;
int totalAuto = 0;
int totalOthers = 0;
double entryCost = 0.0;
double cost = 0.0;
double lateCost = 0.0;
int Row;
int Column;
int count = 0;

void create_addmin_sec();
int checking();


void setMaininfo();
void changeMaininfo();

Time getCurrentTime();

void add();
Info createInfo();

void readfile();
void readmainfile();

void verifyvehicletypeinf(char*,int,int);
int verifyvehicletype(char*,int,int);
int verifyVIN(char*,char*);
int VerifyPhoneNumber(char*);

void searchvehicle();
int search(char*, char*);

void genaralDisplay();
void searchdisplay(int,int);
void searchingbydisplay();
int srarcbydisplay(int,int);

void departure();
int departuresearch(char*,char*);
void del(int);

void viewAll();

int getTotal(int);

int main (void)
{
    system("color 0a");
    FILE *f;
    f=fopen("total.txt","r");
    fscanf(f,"%d",&total);
    if(total != 0)
    {
       readfile();
    }
    else
    {
        readmainfile();
    }

    int choice;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int T;
    int ck;
    int i;
    system("cls");
    printf("\n\n\n%30sVEHICLE PARKING MANAGEMENT SYSTEM\n\n"," ");
    for(i=0;i<35;i++)
    {
        if(i==0)
        {
            printf("%30s"," ");
        }
        printf("%c",254);
    }
    int cek;
    cek = checking();
    if(cek==1)
    {
    do
    {
        system("cls");

        printf("\n\n\n");
        printf("%40sVEHICLE PARKING\n"," ");
        printf("%40s===============\n\n\n"," ");
        printf("%30sMain Menu >>>\n\n\n"," ");
        printf("%30s_______________________________\n"," ");
        printf("%30s-------------------------------\n"," ");
        printf("%30s|| [1] Add Vehicle%11s||\n%30s|| [2] Search Vehicle%8s||\n%30s|| [3] Total Vehicle Parked%2s||\n%30s|| [4] View All%14s||\n%30s|| [5] Departure Vehicle%5s||\n%30s|| [6] Set Main info%9s||\n%30s|| [7] Change Admin password%1s||\n%30s|| [0] Exit%18s||\n"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ");
        printf("%30s_______________________________\n\n"," ");
        printf("%30s  Enter Your Choice  :  "," ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            {
                system("cls");
                printf("\n\n%30s Add Vehicle >>>\n\n"," ");
                add();
                printf("\n\n%30sThere %s Total %d vehicle Entered \n\n"," ",total > 1 ? "Are" : "is",total);
                system("pause");
                break;
            }

        case 2 :
            {
                do
                {   system("cls");
                    printf("\n\n\n%30sSearch Menu >>>\n\n\n"," ");
                    printf("%30s----------------------------\n"," ");
                    printf("%30s| [1] General Search\n%30s| [2] Search By Display \n%30s| [3] Main Menu\n\n"," "," "," ");
                    printf("%30sEnter Your Choice : "," ");
                    scanf("%d",&choice2);
                    switch(choice2)
                    {
                    case 1:
                        {
                            searchvehicle();
                            printf("\n\n");
                            system("pause");
                            break;
                        }
                    case 2 :
                        {
                           system("cls");
                           searchingbydisplay();
                           system("pause");
                           break;
                        }
                    case 3 :
                        {
                            break;
                        }
                    default :
                        {
                            printf("\n\n%30sPlease Enter Valid Option \a! "," ");
                            system("pause");
                            break;
                        }
                    }

                }while(choice2!=3);
                break;
            }
      case 3 :
          {
              do
              {
                  system("cls");
                  printf("\n\n%30sTotal Parked >>>\n\n\n"," ");
                  printf("%30s----------------------------\n"," ");
                  printf("%30s| [1] Total Car \n%30s| [2] Total Bike \n%30s| [3] Total Auto \n%30s| [4] Total Others \n%30s| [5] Total \n%30s| [6] Main Menu\n\n"," "," "," "," "," "," ");
                  printf("%30sEnter Your Choice :  "," ");
                  scanf("%d",&choice3);
                  switch(choice3)
                  {
                  case 1 :
                    {

                        T = getTotal(1);
                        printf("\n\n\n%30sThere %s Total %d Car Parked\n\n"," ",T > 1 ? "Are" : "Is",T);
                        system("pause");
                        break;
                    }
                  case 2 :
                    {
                        T = getTotal(2);
                        printf("\n\n\n%30sThere %s Total %d Bike Parked\n\n"," ",T > 1 ? "Are" : "Is",T);
                        system("pause");
                        break;
                    }
                  case 3 :
                    {
                        T = getTotal(3);
                        printf("\n\n\n%30sThere %s Total %d Auto Parked\n\n"," ",T > 1 ? "Are" : "Is",T);
                        system("pause");
                        break;
                    }
                  case 4 :
                    {
                        T = getTotal(4);
                        printf("\n\n\n%30sThere %s Total %d Others Vehicle Parked\n\n"," ",T > 1 ? "Are" : "Is",T);
                        system("pause");
                        break;
                    }
                  case 5 :
                    {
                        T = getTotal(5);
                        printf("\n\n\n%30sThere %s Total %d Vehicle Parked\n\n"," ",T > 1 ? "Are" : "Is",T);
                        system("pause");
                        break;
                    }
                  case 6 :
                    {
                        break;
                    }
                default :
                    {
                        printf("\n\n%30sPlease Enter Valid Options ! "," ");
                        system("pause");
                        break;
                    }

                  }
              }while(choice3!=6);
               break;
          }

     case 4 :
         {
             system("cls");
             printf("\n\n\n%30s View All >>>\n\n\n"," ");
             viewAll();
             printf("\n\n\n");
             system("pause");
             break;
         }

     case 5 :
        {    system("cls");
             printf("\n\n\n%30sDeparture >>>\n\n"," ");
             departure();
             printf("\n\n\n");
             system("pause");
             break;
        }
     case 6 :
        {
            do
            {
                system("cls");
                printf("\n\n\n%30s Set Main Info >>>\n\n\n"," ");
                printf("%30s----------------------------\n"," ");
                printf("%30s|| [1] Set Main Info \n%30s|| [2] Change Main Info \n%30s|| [3] Main Menu\n\n"," "," "," ");
                printf("%30sEnter Your Choice :  "," ");
                scanf("%d",&choice4);
                switch(choice4)
                {
                case 1 :
                    {
                        system("cls");
                        setMaininfo();
                        printf("\n\n\n");
                        system("pause");
                        break;
                    }
                case 2 :
                    {
                        changeMaininfo();
                        printf("\n\n\n");
                        system("pause");
                        break;
                    }
                case 3 :
                    {
                        break;
                    }
                }

            }while(choice4!=3);
             break;
        }
    case 7 :
        {
            system("cls");
            int chk;
            chk = checking();
            if(chk==1)
            {
            create_addmin_sec();
            }
            else
            {
                return;
            }
            break;

        }
    case 0 :
        {
            break;
        }

       }
    }
    while(choice!=0);
    }

    else
    {
        system("cls");
        printf("\n\n\n%30sPlease enter right password\n\n"," ");
        system("pause");
        return main();
    }

    system("cls");
    printf("\n\n\n\n%70sThank You ! \a\n\n\n"," ");
    system("pause");
}

void setMaininfo()
{
    FILE *fp;
    int cnt=0;
    int i,j;
    fp = fopen("maininfo.txt","r+");
    if(fp==NULL)
    {
        changeMaininfo();
    }

    fp = fopen("maininfo.txt","r+");
    if(fp!=NULL)
    {

        fscanf(fp,"%d %d %lf %lf %lf",&Row,&Column,&entryCost,&cost,&lateCost);
    }

    printf("\n\n%30s App Information >>\n\n"," ");
    printf("%30s Selected Place : Row( %d ) Column ( %d )\n"," ",Row,Column);
    printf("%30s Entry Cost     : %.2lf\n"," ",entryCost);
    printf("%30s Cost           : %.2lf\n"," ",cost);
    printf("%30s Late Cost      : %.2lf\n\n\n"," ",lateCost);


    if(total==0)
    {
        for(i=0;i<Row;i++)
        {
            for(j=0;j<Column;j++)
            {
                if(disp[i][j]=='A' || disp[i][j]=='B' || disp[i][j]=='C' || disp[i][j]=='O')
                    cnt++;
            }
        }

    }



    fclose(fp);
}

void changeMaininfo()
{
    int decision;
    system("cls");
    printf("\n\n\n%30s Set App Info >>>\n\n\n"," ");
    printf("%30s Select Total Area \n\n"," ");
    printf("%30s Enter the Number of Row    : "," ");
    scanf("%d",&Row);
    printf("%30s Enter the Number of Column : "," ");
    scanf("%d",&Column);
    printf("%30s Free Parking ? \n"," ");
    printf("%30s [1] \"YES\" \n"," ");
    printf("%30s [2] \"NO\" \n"," ");
    printf("%30s Enter your Choice : "," ");
    scanf("%d",&decision);

    if(decision==2)
    {
        printf("\n\n%30sCOST SECTION\n\n"," ");
        printf("%30sEnter the Cost to Entry : "," ");
        scanf("%lf",&entryCost);
        printf("%30sEnter the Cost          : "," ");
        scanf("%lf",&cost);
        printf("%30sEnter the Late Cost     : "," ");
        scanf("%lf",&lateCost);
    }
    else if(decision==1)
    {
        entryCost = 0.0;
        cost      = 0.0;
        lateCost  = 0.0;
    }
    else
    {
        printf("%30s Invalid Selection \n\n"," ");
        entryCost = 0.0;
        cost      = 0.0;
        lateCost  = 0.0;
    }
       FILE *fp=fopen("maininfo.txt","w");
       fprintf(fp,"%d %d %.2lf %.2lf %.2lf",Row,Column,entryCost,cost,lateCost);
       FILE *file=fopen("information.txt", "w");
       count=1;
       int i;
       int j;
       total=0;
       totalCar = 0;
       totalBike = 0;
       totalAuto = 0;
       totalOthers = 0;
       for(i=0;i<Row;i++)
       {
           for(j=0;j<Column;j++)
           {
               disp[i][j]='x';
           }
       }

       fclose(fp);
       fclose(file);
}


Time getCurrentTime()
{
    Time TM;

    GetSystemTime(&TM);

    TM.wHour = TM.wHour + 6;

    if(TM.wHour>=24)
    {
        TM.wHour = TM.wHour - 24;
        TM.wDay  = TM.wDay + 1;
    }

    return TM;
}



Info createInfo()
{

    FILE *file;
    FILE *fp = fopen("maininfo.txt","r+");
    Time start;
    Info temp;
    char vehicletype[12];
    char vin[18];
    char serial_number[7];
    char pnum[20];
    int rw;
    int cl;
    int check;
    int check2;
    int check3;
    system("cls");
    if(fp==NULL)
    {
        printf("\n\n\n%40sPlease Set Main Info !\n"," ");
        count++;
        return;
    }

    file = fopen("information.txt", "r+");
    printf("\n\n\n\n");
    genaralDisplay();


    printf("%30sENTRY FORM \n\n\n"," ");
    printf("%30sEnter The Owners Name         :  "," ");
    scanf("%s",temp.name);
    do
    {
    printf("%30sEnter The Type of Vehicle     :  "," ");
    scanf("%s",temp.type);
    printf("\n%30sSelect Place  \n"," ");
    printf("%30sEnter the Valid Row Number    :  "," ");
    scanf("%d",&temp.row);
    printf("%30sEnter the Valid Column Number :  "," ");
    scanf("%d",&temp.column);
    rw = temp.row;
    cl = temp.column;
    strcpy(vehicletype,temp.type);
    check3=verifyvehicletype(vehicletype,rw,cl);
    }
    while(check3==-1);

    do
    {
    printf("%30sEnter VIN (17 chra)           :  "," ");
    scanf("%s",temp.VIN);
    printf("%30sEnter Serial Number(6 char)   :  "," ");
    scanf("%s",temp.serialnumber);
    strcpy(vin,temp.VIN);
    strcpy(serial_number,temp.serialnumber);
    check = verifyVIN(vin,serial_number);
    }
    while(check==-1);

    do
    {
    printf("%30sEnter the Phone Number        :  "," ");
    scanf("%s",temp.phoneNumber);
    strcpy(pnum,temp.phoneNumber);
    check2=VerifyPhoneNumber(pnum);
    }
    while(check2==-1);
    printf("\n\n");
    system("pause");

    start = getCurrentTime();
    temp.starttime = start;
    system("cls");
    printf("\n\n\n%30sVehicle Information >>>\n\n\n"," ");
    printf("%30s||Date                    : %d/%d/%d\n"," ",temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear);
    printf("%30s||Owners Name             : %s\n"," ",temp.name);
    printf("%30s||VIN                     : %s\n"," ",temp.VIN);
    printf("%30s||Serial Number           : %s\n"," ",temp.serialnumber);
    printf("%30s||Owners Phone Number     : %s\n"," ",temp.phoneNumber);
    printf("%30s||Vehicle Type            : %s\n"," ",temp.type);
    printf("%30s||Place                   : Row(%d) Column(%d)\n"," ",temp.row,temp.column);
    printf("%30s||Arrival Time            : %d-%d-%d\n\n\n"," ",temp.starttime.wHour,temp.starttime.wMinute,temp.starttime.wSecond);

    if(total==0)
    {
        file=fopen("information.txt", "w");
        fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",temp.name,temp.VIN,temp.serialnumber,temp.phoneNumber,temp.type,temp.row,temp.column,temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear,temp.starttime.wHour,temp.starttime.wMinute);

    }
    else
    {

        file=fopen("information.txt", "a");
        fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",temp.name,temp.VIN,temp.serialnumber,temp.phoneNumber,temp.type,temp.row,temp.column,temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear,temp.starttime.wHour,temp.starttime.wMinute);

    }
    genaralDisplay();
    fclose(fp);
    fclose(file);
    count=0;
    return temp;
}



void add()
{
    FILE *f;
    Info data = createInfo();
    info[total] = data;

    if(count==0)
    {
      total++;
    }
    f=fopen("total.txt","w");
    fprintf(f,"%d",total);
    fclose(f);

}



int verifyvehicletype(char *TYPE,int r,int c)
{

    char typecar[4]="car";
    char typebike[5]="bike";
    char typeauto[5]="auto";

    if(r-1>Row || c-1>Column)
    {
        return -1;
    }

    if(strcmp(TYPE,typecar)==0)
    {
        if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
        {
            printf("\n\n%30sNot Empty Try Another Location !\n\n"," ");
            return -1 ;
        }

        else
        {
            disp[r-1][c-1] = 'C';
            totalCar++;
            return 1;
        }
    }

   else if(strcmp(TYPE,typebike)==0)
    {
        if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
        {
            printf("%30sNot Empty Try another Location !\n"," ");
            return -1;
        }

        else
        {
            disp[r-1][c-1] = 'B';
             totalBike++;
             return 1;
        }

    }
   else if(strcmp(TYPE,typeauto)== 0)
    {
       if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
       {
         printf("%30sNot Empty Try another Location !\n"," ");
         return -1;
       }

       else
       {
           disp[r-1][c-1] = 'A';
           totalAuto++;
           return 1;
       }

    }
   else
    {
        if(disp[r-1][c-1] == 'O' || disp[r-1][c-1]== 'A' || disp[r-1][c-1]== 'B' || disp[r-1][c-1]== 'C')
        {
           printf("%30sNot Empty Try another Location !\n"," ");
           return -1;
        }

        else
        {
            disp[r-1][c-1] = 'O';
            totalOthers++;
            return 1;
        }

    }
}

void verifyvehicletypeinf(char *TYPE,int r,int c)
{
    char typecar[]="car";
    char typebike[]="bike";
    char typeauto[]="auto";

    if(strcmp(typecar,TYPE)== 0)
    {
        disp[r-1][c-1]='C';
        totalCar++;
    }
    else if(strcmp(typebike,TYPE)==0)
    {
        disp[r-1][c-1]='B';
        totalBike++;
    }
    else if(strcmp(typeauto,TYPE)==0)
    {
        disp[r-1][c-1]='A';
        totalAuto++;
    }
    else
    {
        disp[r-1][c-1]='O';
        totalOthers++;
    }


}

int verifyVIN(char *v_i_n,char *s_n)
{
    int len1 = strlen(v_i_n);
    int len2 = strlen(s_n);


    if(len2>len1 || len1<17 || len1>17 || len2>6 || len2<6)
    {
        printf("\n\n%30sInvalid VIN or Serial Number!! \n\n"," ");
        return -1;
    }

    if(strcmp(&v_i_n[len1-len2],s_n)==0)
        return 1;
    else
        {
            printf("\n\n%30sInvalid VIN or Serial Number!!\n\n"," ");
            return -1;
        }
}

int VerifyPhoneNumber(char *phnum)
{
    int len;
    char c;
    len = strlen(phnum);

    if(len > 11 || len < 11 || phnum[0]!='0' || phnum[1]!='1')
    {
        printf("\n\n%30sInvalid PhoneNumber!!\n\n"," ");
        return -1;
    }

    else
        return 1;
}


void genaralDisplay()
{
       int i,j,r=1,loop;


    printf("\t\t\t");
    for(loop=1;loop<=Column;loop++)
    {
        printf("      %d   ",loop);
    }

    printf("\n");
    printf("\t\t\t");

    for(loop=1;loop<=Column;loop++)
    {
        printf("..........");
    }
    printf("\n\n");
    printf("\t");
    for(i=0;i<Row;i++)
    {

        printf("\t%d |>  ",r);
        r++;
        for(j=0;j<Column;j++)
        {
            if(disp[i][j]=='x')
            {
                printf("   [     ]",disp[i][j]);
            }
            else if(disp[i][j]=='A' || disp[i][j]=='B' || disp[i][j]=='C' || disp[i][j]=='O')
            {
                printf("   [  %c  ]",disp[i][j]);

            }
            else
            {
                printf("   [   %c ]",disp[i][j]);
            }
        }
        printf("\n");
        printf("\t");
    }

    printf("\n\n%30s             DISPLAYING VEHICLE\n\n\n\n"," ");

}

int search(char *PHONE, char *VEHICLE)
{
    char pnum[12];
    char vehicle[7];
    int i;

    for(i=0;i<total;i++)
    {
        strcpy(pnum,info[i].phoneNumber);
        strcpy(vehicle,info[i].serialnumber);
        if(strcmp(pnum,PHONE)==0 && strcmp(vehicle,VEHICLE)==0)
            return i;
    }

    return -1;
}


void searchvehicle()
{
    char Pnum[12];
    char Vnum[7];
    int index;
    int R;
    int C;
    system("cls");
    printf("\n\n\n\n%30sSEARCH >>> \n\n"," ");
    printf("%30sEnter The Phone Number          : "," ");
    scanf("%s",Pnum);
    printf("%30sEnter The Vehicle Serial Number : "," ");
    scanf("%s",Vnum);


    index = search(Pnum,Vnum);

    system("cls");
    if(index!=-1)
    {
        printf("\n\n%30sVehicle Information >>>\n\n"," ");
        printf("%30s|| Arrival Date     : %d|%d|%d\n"," ",info[index].starttime.wDay,info[index].starttime.wMonth,info[index].starttime.wYear);
        printf("%30s|| Owners Name      : %s\n"," ",info[index].name);
        printf("%30s|| VIN              : %s\n"," ",info[index].VIN);
        printf("%30s|| Vehicle Type     : %s\n"," ",info[index].type);
        printf("%30s|| Position         : Row ( %d )  Column ( %d )\n"," ",info[index].row,info[index].column);
        printf("%30s|| Arrival Time     : %d-%d \n"," ",info[index].starttime.wHour,info[index].starttime.wMinute);
        printf("\n\n\n\n");
        R = info[index].row;
        C = info[index].column;

       searchdisplay(R,C);
    }
    else
    {
        printf("\n\n%30sSearch Items Do Not Match\n\n"," ");
    }

}

void searchdisplay(int RoW,int ColumN)
{
     int i,j,r=1,loop;


    printf("\t\t\t");
    for(loop=1;loop<=Column;loop++)
    {
        printf("      %d   ",loop);
    }

    printf("\n");
    printf("\t\t\t");

    for(loop=1;loop<=Column;loop++)
    {
        printf("..........");
    }
    printf("\n\n");
    printf("\t");
    for(i=0;i<Row;i++)
    {

        printf("\t%d |>  ",r);
        r++;
        for(j=0;j<Column;j++)
        {
            if(disp[i][j]=='x')
            {
                       printf("  [        ]",disp[i][j]);
            }
            else if(disp[i][j]=='A' || disp[i][j]=='B' || disp[i][j]=='C' || disp[i][j]=='O')
            {
                if(i==RoW-1 && j==ColumN-1)
                    {
                       printf("   [  *%c  ]",disp[i][j]);
                    }
                else
                       printf("   [  %c   ]",disp[i][j]);

            }
            else
            {
                printf("   [  %c   ]",disp[i][j]);
            }
        }
        printf("\n");
        printf("\t");
    }

    printf("\n\n%30s             *Searched Vehicle\n\n"," ");

}

void searchingbydisplay()
{

    printf("\n\n\n");
    genaralDisplay();
    int r;
    int c;
    int index;

    printf("\n\n");
    printf("%30sEnter the Row Number   :  "," ");
    scanf("%d",&r);
    printf("%30sEnter the Column Number:  "," ");
    scanf("%d",&c);
    printf("\n\n");

    system("cls");
    index=searchbydisplay(r,c);

    if(index!=-1)
    {

        printf("\n\n%30sVehicle Information >>>\n\n\n"," ");
        printf("%30sArrival Date     : %d/%d/%d\n"," ",info[index].starttime.wDay,info[index].starttime.wMonth,info[index].starttime.wYear);
        printf("%30sOwners Name      : %s\n"," ",info[index].name);
        printf("%30sPhone Number     : %s\n"," ",info[index].phoneNumber);
        printf("%30sVIN              : %s\n"," ",info[index].VIN);
        printf("%30sSerial Number    : %s\n"," ",info[index].serialnumber);
        printf("%30sVehicle Type     : %s\n"," ",info[index].type);
        printf("%30sArrival Time     : %d-%d\n\n\n"," ",info [index].starttime.wHour,info[index].starttime.wMinute);
        searchdisplay(r,c);
    }
    else
    {
        printf("\n\n\n%30sVehicle Not Found\n\n\n"," ");
    }

}

int searchbydisplay(int r,int c)
{
    int i;

    for(i=0;i<total;i++)
    {
        if(r==info[i].row && c==info[i].column)
            return i;
    }
    return -1;
}

int departuresearch(char *vinum,char *pnum)
{
    char vin[18];
    char pn[12];
    int i;

    for(i=0;i<total;i++)
    {
        strcpy(vin,info[i].VIN);
        strcpy(pn,info[i].phoneNumber);

        if(strcmp(vin,vinum)==0 && strcmp(pn,pnum)==0)
        {
            return i;
        }

    }
    return -1;
}

void departure()
{
    char vin[18];
    char pn[12];
    int check;
    int r,c;
    Time end;
    int duration_min;
    int duration_hour;
    int duration_day;
    int duration_month;
    int duration_year;
    double cost1;
    double cost2;
    double cost3;
    double Total_Cost;
    char typecar[]="car";
    char typebike[]="bike";
    char typeauto[]="auto";


    printf("\n%30sEnter the VIN                 :  "," ");
    scanf("%s",vin);
    printf("%30sEnter the Owners Phone Number :  "," ");
    scanf("%s",pn);

    check=departuresearch(vin,pn);
    printf("\n\n");
    system("pause");
    system("cls");

    if(check!=-1)
    {
        printf("\n\n%30sVehicle Description >>>\n\n\n"," ");
        printf("%30sArrival date     : %d|%d|%d \n"," ",info[check].starttime.wDay,info[check].starttime.wMonth,info[check].starttime.wYear);
        end = getCurrentTime();
        printf("%30sDeparture  Date  : %d|%d|%d \n"," ",end.wDay,end.wMonth,end.wYear);
        printf("%30sOwners Name      : %s\n"," ",info[check].name);
        printf("%30sVehicle's type   : %s\n"," ",info[check].type);
        printf("%30sVehicle's place  : Row ( %d ) Column ( %d ) \n"," ",info[check].row,info[check].column);
        printf("%30sArrival Time     : %d-%d\n\n"," ",info[check].starttime.wHour,info[check].starttime.wMinute);
        printf("%30sDeparture Time   : %d-%d\n\n"," ",end.wHour,end.wMinute);
        printf("%30sParking Deuration >>> \n\n\n"," ");

        if(info[check].starttime.wMinute > end.wMinute)
        {
            end.wMinute+=60;
            end.wHour--;
        }
        duration_min =end.wMinute - info[check].starttime.wMinute;

        if(info[check].starttime.wHour > end.wHour)
        {
            end.wDay--;
            end.wHour+=24;
        }
        duration_hour = end.wHour - info[check].starttime.wHour;

        if(info[check].starttime.wDay > end.wDay)
        {
            end.wMonth--;
            end.wDay+=30;
        }
        duration_day = end.wDay - info[check].starttime.wDay;

        if(info[check].starttime.wMonth > end.wMonth)
        {
            end.wYear--;
            end.wMonth+=12;
        }
        duration_month = info[check].starttime.wMonth-end.wMonth;
        duration_year  = info[check].starttime.wYear-end.wYear;

        printf("%30sDate Duration  = [%d Day] [%d Month] [%d Year] \n"," ",duration_day,duration_month,duration_year);
        printf("%30sTime Duration  = [%d hour]  [%d min] \n"," ",duration_hour,duration_min);
        duration_hour += (duration_day*24) + (duration_month*720) + (duration_year*8640);
        duration_day  += (duration_month*30) + (duration_year*365);
        printf("%30sCost Recite \n\n\n"," ");
        cost1 =  entryCost;
        cost2 = (double)cost * duration_hour;
        cost3 = (double)lateCost * duration_day;

        Total_Cost = cost1+cost2+cost3;
        printf("%30sEntry Cost     = %.2lf\n"," ",cost1);
        printf("%30sCost Per Hour  = %.2lf\n"," ",cost2);
        printf("%30sLate cost      = %.2lf\n"," ",cost3);
        printf("%30sTotal Cost     = %.2lf\n\n"," ",Total_Cost);
        r = info[check].row;
        c = info[check].column;

        char *tp;
        strcpy(tp,info[check].type);

        if(strcmp(tp,typecar)==0)
        {
            totalCar--;
        }
        else if(strcmp(tp,typebike)==0)
        {
            totalBike--;
        }
        else if(strcmp(tp,typeauto)== 0)
        {
            totalAuto--;
        }
        else
        {
            totalOthers--;
        }

        disp[r-1][c-1]='x';

        system("pause");

        del(check);
        system("cls");
        genaralDisplay();
        printf("\n\n\n%30s1 Vehicle has been Departured !\n\n\n\n"," ");
    }
    else
    {
        printf("\n\n\n%30sNo result found ! \n\n\n"," ");
    }
}



void del(int pos)
{
    int i;
    FILE *file = fopen("information.txt", "w");
    FILE *f;


    if(total!=1)
    {
        for(i=pos;i<total-1;i++)
           info[i]=info[i+1];
    }



    total--;
    if (total == 0)
    {
        f=fopen("total.txt","w");
        fprintf(f,"%d",total);
    }

    else
    {
    for(i=0;i<total;i++)
        {
            if(i==0)
            {
                fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",info[i].name,info[i].VIN,info[i].serialnumber,info[i].phoneNumber,info[i].type,info[i].row,info[i].column,info[i].starttime.wDay,info[i].starttime.wMonth,info[i].starttime.wYear,info[i].starttime.wHour,info[i].starttime.wMinute);
            }
            else
            {
                fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",info[i].name,info[i].VIN,info[i].serialnumber,info[i].phoneNumber,info[i].type,info[i].row,info[i].column,info[i].starttime.wDay,info[i].starttime.wMonth,info[i].starttime.wYear,info[i].starttime.wHour,info[i].starttime.wMinute);

            }

        }

    }


    printf("\n\n\n");

    if(total!=0)
    {
        f=fopen("total.txt","w");
        fprintf(f,"%d",total);
    }

    fclose(f);
    fclose(file);

}



void viewAll()
{
    int i;
    int year,month,day,hour,min;
    int duration_min;
    int duration_hour;
    int duration_day;
    int duration_month;
    int duration_year;
    Time end;
    end = getCurrentTime();
    genaralDisplay();

    for(i=0;i<total;i++)
    {
        printf("%20s|| Vehicle's type   : %s\n"," ",info[i].type);
        printf("%20s|| Arrival date     : %d | %d | %d\n"," ",info[i].starttime.wDay,info[i].starttime.wMonth,info[i].starttime.wYear);
        printf("%20s|| Owners Name      : %s\n"," ",info[i].name);
        printf("%20s|| Phone Number     : %s\n"," ",info[i].phoneNumber);
        printf("%20s|| Vehicle's place  : Row ( %d ) Column ( %d ) \n"," ",info[i].row,info[i].column);
        printf("%20s|| Arrival Time     : %d : %d\n"," ",info[i].starttime.wHour,info[i].starttime.wMinute);
        year = info[i].starttime.wYear;
        month = info[i].starttime.wMonth;
        day = info[i].starttime.wDay;
        hour = info[i].starttime.wHour;
        min = info[i].starttime.wMinute;

        if(min > end.wMinute)
        {
            end.wMinute+=60;
            hour--;
        }
        duration_min =end.wMinute - min;

        if(hour > end.wHour)
        {
            day--;
            end.wHour+=24;
        }
        duration_hour = end.wHour - hour;

        if(day > end.wDay)
        {
            month--;
            end.wDay+=30;
        }
        duration_day = end.wDay - day;

        if(month > end.wMonth)
        {
            year--;
            end.wMonth+=12;
        }


        duration_month = end.wMonth - month;
        duration_year  = end.wYear - year;
        printf("%20s|| Duration Time    : Hour = %d : Minute = %d \n"," ",duration_hour,duration_min);
        printf("%20s|| Duration Date    : Year = %d / Month = %d /Day = %d \n"," ",duration_year,duration_month,duration_day) ;
        printf("%20s________________________________________________________\n"," ");
        printf("\n\n\n");

    }

}

void readfile()
{
    int rw;
    int cl;
    int extra;
    char vehicletype[12];
    FILE *fp = fopen("maininfo.txt","r+");
    fscanf(fp,"%d %d %lf %lf %lf",&Row,&Column,&entryCost,&cost,&lateCost);

    FILE *file = fopen("information.txt", "r+");
    if(file!=NULL && count==0)
    {

            while(!feof(file))
            {
            fscanf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",info[count].name,info[count].VIN,info[count].serialnumber,info[count].phoneNumber,info[count].type,&info[count].row,&info[count].column,&info[count].starttime.wDay,&extra,&info[count].starttime.wYear,&info[count].starttime.wHour,&info[count].starttime.wMinute);
            info[count].starttime.wMonth=extra;
            strcpy(vehicletype,info[count].type);
            rw = info[count].row;
            cl = info[count].column;
            printf("%30s%s\n\n"," ");
            verifyvehicletypeinf(vehicletype,rw,cl);
            count++;
            }
    }
    else
    {
        return;
    }

    fclose(file);
    fclose(fp);

}


int getTotal(int Tc)
{
    if(Tc==1)
    {
        return totalCar;
    }
    else if(Tc==2)
    {
         return totalBike;
    }
    else if(Tc==3)
    {
        return totalAuto;
    }
    else if(Tc==4)
    {
        return totalOthers;
    }
    else
    {
        return total;
    }

}


void readmainfile()
{
    FILE *fp = fopen("maininfo.txt","r+");
    fscanf(fp,"%d %d %lf %lf %lf",&Row,&Column,&entryCost,&cost,&lateCost);

    fclose(fp);
}



void create_addmin_sec()
{
    FILE *adm;
    int index;
    printf("\n\n%30sAdmin Section >>>\n\n\n"," ");

    do
    {
        printf("%30sEnter the Admin name                   : "," ");
        scanf("%s",&admin.admin_name);
        printf("%30sEnter the password (8 to 10 characters): "," ");
        scanf("%s",admin.password);
        index = check(admin.password);
    }while(index==-1);


    adm=fopen("admin.txt","w");

    fprintf(adm,"%s %s",admin.admin_name,admin.password);
    printf("%30s Password restore successfully !\n\n"," ");
    printf("\n\n");
    system("pause");
    fclose(adm);

}

int check(char *p)
{
   int len ;
   len = strlen(p);
   if (len<=8)
   {
       return 1;
   }
   else if(len<8)
   {
       printf("\n\n%30sEnter minimum 8 characters !\n\n"," ");
       return -1;
   }
   else if(len>10)
   {
       printf("\n\n%30sEnter maximum 10 characters !\n\n"," ");
       return -1;
   }

}

int checking()
{
    printf("\n\n\n%30sAdmin Log-in >>>"," ");
    FILE *adm=fopen("admin.txt","r");

    if(adm==NULL)
    {
        return 1;
    }
    char temp[15];
    char temp2[15];
    char temp3[20];
    char temp4[20];
    fscanf(adm,"%s %s",temp3,temp2);
    printf("\n\n\n\n%30sEnter The Admin Name      : "," ");
    scanf("%s",temp4);
    printf("%30sPlease Enter The Password : "," ");
    scanf("%s",temp);

    if(strcmp(temp,temp2)==0 && strcmp(temp4,temp3)==0)
    {
        return 1;
    }
    else
    {
        printf("\n\n\n%40s Wrong Password\a\n\n"," ");
        system("pause");
        return -1;
    }
    fclose(adm);
}


