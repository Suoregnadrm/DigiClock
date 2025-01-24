#include<stdio.h>
#include<unistd.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

int main()
{
    int hh,mm,ss,date,year;
    char day[7][10] = {"Monday",
                        "Tuesday",
                        "Wednesday",
                        "Thursday",
                        "Friday",
                        "Saturday",
                        "Sunday"};
    char monthh[][4] = {
                        "Jan",
                        "Feb",
                        "Mar",
                        "Apr",
                        "May",
                        "Jun",
                        "Jul",
                        "Aug",
                        "Sep",
                        "Oct",
                        "Nov",
                        "Dec",
                        };
    //char month;//[] = {};*/
    char dayyy[10],month[4];
    char *dayy,*monthhh;
    printf("Set the time(HH:MM:SS) : ");
    scanf("%d%d%d",&hh,&mm,&ss);
    printf("Set the date \n");
    printf("Day (Xxxxxx): ");scanf("%s",dayyy);
    dayy = dayyy;
    printf("Date: ");scanf("%d",&date);
    printf("Month (Xxx): ");scanf("%s",month);
    monthhh = month;
    printf("Year: ");scanf("%d",&year);
    //int sizeofday = strlen(dayy);
    system("cls");

    while(1)
    {
        system("color 2");
        clearScreen();
        gotoxy(57,5);
        printf("%02d:%02d:%02d",hh,mm,ss);
        /*gotoxy(5,6);
        printf("\t\t\t\t\t\t      %s",dayy);*/
        fflush(stdout);
        /*gotoxy(50,7);
        printf("%s, %d %s, %d",dayy,date,monthhh,year);*/

        gotoxy(58,6);
        printf("%s",dayy);
        fflush(stdout);
        gotoxy(55,7);
        printf("%d %s, %d",date,monthhh,year);

        fflush(stdout);
        ss++;
        if(ss==60)
        {
            mm++;
            ss=0;
        }
        if(mm==60)
        {
            hh++;
            mm=0;
        }
        if(hh==24)
        {
            hh=0;
            mm=0;
            ss=0;

            date++;
            for(int i=0;i<12;i++){
                if(strcmp(monthhh,monthh[i])==0){
                    if(strcmp(monthhh,"Jan")==0 || strcmp(monthhh,"Mar")==0 || strcmp(monthhh,"May")==0 || strcmp(monthhh,"Jul")==0 || strcmp(monthhh,"Aug")==0 || strcmp(monthhh,"Oct")==0 || strcmp(monthhh,"Dec")==0 )
                    {
                        if(date>31)
                        {
                            if(i == 11)
                            {
                                date=1;
                                year++;
                                monthhh = monthh[0];
                                break;
                            }
                            else{
                            date=1;
                            monthhh=monthh[i+1];
                            break;
                            }
                        }
                    }
                    else if(strcmp(monthhh,"Apr")==0 || strcmp(monthhh,"Jun")==0 || strcmp(monthhh,"Sep")==0 || strcmp(monthhh,"Oct")==0 || strcmp(monthhh,"Nov")==0 )
                    {
                        if(date>30)
                        {
                            date=1;
                            monthhh=monthh[i+1];
                            break;
                        }
                    }
                    else if(strcmp(monthhh,"Feb")==0)
                    {
                        if(date>28)
                        {
                            date=1;
                            monthhh=monthh[i+1];
                            break;
                        }
                    }
                }
            }

            for(int i=0;i<7;i++)
            {
                if(strcmp(dayy,day[i]) == 0)
                {
                    if(i == 6)
                    {
                        dayy = day[0];
                        break;
                    }
                    else
                    {
                        dayy = day[i+1];
                        break;
                    }
                }
            }
            /*for(int i=0;i<12;i++)
            {
                if(strcmp(monthhh,monthh[i]) == 0)
                {
                        if(i == 11)
                        {
                            year++;
                            monthhh = monthh[0];
                            break;
                        }
                        else
                        {
                            monthhh = monthh[i+1];
                            break;
                        }
                }
            }*/



        }
        sleep(1);

    }
    getch();



    /*start:
    for(hh;hh<24;hh++)
    {
        for(mm;mm<60;mm++)
        {
            for(ss;ss<60;ss++)
            {
                system("cls");
                printf("%02d:%02d:%02d",hh,mm,ss);
                sleep(1);
            }
            ss=0;
        }
        mm=0;
    }
    hh=0;
    goto start;*/
}
