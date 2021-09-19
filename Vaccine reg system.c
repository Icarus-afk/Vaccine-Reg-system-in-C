#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

void gotoxy(int x, int y);
void description();
void WelcomeScreen();
void TitleScreen();
void HospitalList();
int PasswordProc(char str[20]);
void Register();
void Menu();
void Adminlogin();
void adminallrec();
void hospmenu();
void AdminMenu();

int ok;
int b, valid = 0; //Global Variable//


struct User
{
    int age;
    long long int Password;
    char Gender;
    char First_name[20];
    char Last_name[20];
    char Contact_no[15];
    char Address[30];
    char Email[50];
    char Hospital[30];
    int date1;
    int month1;
    int year1;
    int date2;
    int month2;
    int year2;
};
struct User p;

void main()//main function//
{
    system("cls");
    system("COLOR 70");
    WelcomeScreen();
    Menu();
}

void gotoxy(int x, int y)
{
    COORD pos = {x,y}; //set co-ordinates (x,y)//
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void description()//small description//
{
    printf("\n\n\n\n\n\n\t\t\t\tClean your hands often");
    printf("\n\n\t\t\t\tCough or sneeze in your bent elbow - not your hands!");
    printf("\n\n\t\t\t\tAvoid touching your eyes, nose and mouth");
    printf("\n\n\t\t\t\tLimit social gatherings and time spent in crowded places");
    printf("\n\n\t\t\t\tAvoid close contact with someone who is sick");
    printf("\n\n\t\t\t\tClean and disinfect frequently touched objects and surfaces");
}

void WelcomeScreen()//weclome screen function//
{
    printf("\n\n\n\n\t\t\t\t################################################");
    printf("\n\t\t\t\t#     Covid-19 Vaccine Registration System     #");
    printf("\n\t\t\t\t################################################");
    printf("\n\n\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE");
    description();
    getch();
    system("cls");//clears screen
}

void TitleScreen()//title screen function//
{
    printf("\n\n\t\t---------------------------------------------------");
    printf("\n\t\t\t    Covid 19 Vaccine Registration      ");
    printf("\n\t\t---------------------------------------------------");
}

void HospitalList()//hospital names//
{
    printf("\t\t\t1. Square Hospital\n");
    printf("\t\t\t2. Apollo Hospital\n");
    printf("\t\t\t3. Labaid Hospital\n");
    printf("\t\t\t4. Ibn Sina Hospital\n");
    printf("\t\t\t5. Popular Hospital\n");
    printf("\t\t\t6. Birdem Hospital\n");
    printf("\t\t\t7. BSMMU Hospital\n");
    printf("\t\t\t8. DMC\n");
    printf("\t\t\t9. National Hospital\n");
    printf("\t\t\t10. CMH");
}

int PasswordProc(char str[20])//password encryption//
{
        long long int sum=0;
        for (int i=0; i< strlen(str); i++)
        {

            sum = sum + str[i];
        }
        return(sum*2441139);
}

void Register()//register function//
{
    system("cls");
    TitleScreen();
    char ans;
    FILE*ek;
    ek=fopen("Record.dat", "a");//append mode//
    printf("\n\n\t\t\t________________Register________________\n");

//First Name//
A:
    printf("\n\n\t\tFirst Name: ");
    scanf("%s", p.First_name);
    p.First_name[0]=toupper(p.First_name[0]);
    if(strlen(p.First_name)>20 || strlen(p.First_name)<2)
    {
        printf("\n\tInvalid:(\t Range is 2 characters to 20 characters");
        goto A;
    }
    else
    {
        for(b=0; b<strlen(p.First_name); b++)
        {
            if (isalpha(p.First_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contains invalid characters: (Enter again)");
            goto A;
        }

    }
//Last Name//
B:
    printf("\n\t\tLast Name: ");
    scanf("%s", p.Last_name);
    p.Last_name[0]=toupper(p.Last_name[0]);
    if(strlen(p.Last_name)>20 || strlen(p.Last_name)<2)
    {
        printf("\n\t\tInvalid:(\t Range is 2 characters to 20 characters");
        goto B;
    }
    else
    {
        for(b=0; b<strlen(p.Last_name); b++)
        {
            if (isalpha(p.Last_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contains invalid characters: (Enter again)");
            goto B;
        }
    }
    //Gender//
    do
    {
        char gend;
        printf("\n\t\tGender[F/M]: ");
        scanf(" %c", &gend);
        p.Gender=toupper(gend);
        if(toupper(p.Gender)=='M'||toupper(p.Gender)=='F')
        {
            ok=1;
        }
        else
        {
            ok=0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contains Invalid Character: (Enter [F/M]");
        }
    }
    while(!ok);
//Age//
    printf("\n\t\tEnter Age: ");
    scanf("%d", &p.age);
    if(p.age<40)
    {
        system("COLOR 4F");
        printf("\n\t\tYou are not eligible for Vaccine right now");
        getch();
        main();
    }
//Address//
C:
    do
    {
        printf("\n\t\tAdress(Thana): ");
        scanf("%s", p.Address);
        p.Address[0]=toupper(p.Address[0]);
        if(strlen(p.Address)>20||strlen(p.Address)<4)
        {
            printf("\n\tInvalid :( max range 20, minimum range 4");
            goto C;
        }
    }
    while(!valid);
//Contact//

    char number[15];
D:
    printf("\n\t\tContact No: ");
    scanf(" %s", number);
    if(strlen(number)!=11)
    {
        printf("\n\t\tSorry :( Must Contain 11 Digits)\n");
        goto D;
    }
    while(fscanf(ek,"%s", p.Contact_no )!=EOF)
    {
        if(strcmp(p.Contact_no, number)==0)
        {
            system("COLOR 4F");
            printf("\n\n\t\tUser already exists, you can't register twice");
            getch();
            main();
        }
        break;
    }

    strcpy(p.Contact_no, number);

//email//
G:
    printf("\n\t\tEmail: ");
    scanf("%s", p.Email);
//Password//

    {
        char PassW[20];
        printf("\n\t\tPassword(Account): ");
        scanf(" %s", &PassW);
        p.Password = PasswordProc(PassW);
    }

//hospital List//
X:
    system("cls");
    TitleScreen();
    printf("\n\n");
    int option;

    HospitalList();
    printf("\n");
    printf("\n\t\tPlease check where you want to get vaccinated\n");
    printf("\n\t\tEnter the number in front of your desired hospital\n");
    scanf("%d", &option);
    switch(option)
    {
    case 1:
        strcpy(p.Hospital, "Square_Hospital");
        break;
    case 2:
        strcpy(p.Hospital, "Apollo_Hospital");
        break;
    case 3:
        strcpy(p.Hospital, "LabAid_Hospital");
        break;
    case 4:
        strcpy(p.Hospital, "Ibn_Sina_Hospital");
        break;
    case 5:
        strcpy(p.Hospital, "Popular_Hospital");
        break;
    case 6:
        strcpy(p.Hospital, "Birdem_Hospital");
        break;
    case 7:
        strcpy(p.Hospital, "BSMMU_Hospital");
        break;
    case 8:
        strcpy(p.Hospital, "Dhaka_Medical");
        break;
    case 9:
        strcpy(p.Hospital, "National_Hospital");
        break;
    case 10:
        strcpy(p.Hospital, "CMH_Hospital");
        break;
    default:
        printf("\n\t\t\tinvalid choice");
        goto X;
        break;

    }

//date//
    system("cls");
    TitleScreen();
    int numofdays_feb ;
    int tempd, tempm, tempy;
    printf("\n\n\t\tPlease follow the given format for date : [DD/MM/YYYY]\n");
    printf("\n\n\t\tPlease enter a suitable date : ");
    scanf("%d/%d/%d", &tempd, &tempm, &tempy );
    p.date1=tempd;
    p.month1=tempm;
    p.year1=tempy;
    switch(tempm)
    {
    case 1 :
    {
        if ( tempy%400 == 0 )
        {
            numofdays_feb = 29 ;
        }
        else if ( tempy%100 == 0 )
        {
            numofdays_feb = 28 ;
        }
        else if ( tempy%4 == 0 )
        {
            numofdays_feb = 29 ;
        }
        else
        {
            numofdays_feb = 28 ;
        }

        if (numofdays_feb == 28)
        {
            tempd = tempd + 9 ;
            if (tempd == 28)
            {
                tempm = tempm + 1 ;
            }
            else if (tempd > 28)
            {
                tempd = tempd - 28 ;
                tempm = tempm + 2 ;
            }
            else
            {
                tempm = tempm + 1 ;
            }
        }
        else
        {
            tempd = tempd + 9 ;
            if (tempd == 29)
            {
                tempm = tempm + 1 ;
            }
            else if (tempd > 29)
            {
                tempd = tempd - 29 ;
                tempm = tempm + 2 ;
            }
            else
            {
                tempm = tempm + 1 ;
            }
        }
        break ;
    }
    case 2 :
    {
        if ( tempy%400 == 0 )
        {
            numofdays_feb = 29 ;
        }
        else if ( tempy%100 == 0 )
        {
            numofdays_feb = 28 ;
        }
        else if ( tempy%4 == 0 )
        {
            numofdays_feb = 29 ;
        }
        else
        {
            numofdays_feb = 28 ;
        }

        if (numofdays_feb == 28)
        {
            tempd = tempd + 12 ;
            if (tempd == 31)
            {
                tempm = tempm + 1 ;
            }
            else if (tempd > 31)
            {
                tempd = tempd - 31 ;
                tempm = tempm + 2 ;
            }
            else
            {
                tempm = tempm + 1 ;
            }
        }
        else
        {
            tempd = tempd + 11 ;
            if (tempd == 31)
            {
                tempm = tempm + 1 ;
            }
            else if (tempd > 31)
            {
                tempd = tempd - 31 ;
                tempm = tempm + 2 ;
            }
            else
            {
                tempm = tempm + 1 ;
            }
        }
        break ;
    }
    case 3 :
    {
        tempd = tempd + 9 ;
        if (tempd == 30)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 30)
        {
            tempd = tempd - 30 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 4 :
    {
        tempd = tempd + 10 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 5 :
    {
        tempd = tempd + 9 ;
        if (tempd == 30)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 30)
        {
            tempd = tempd - 30 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 6 :
    {
        tempd = tempd + 10 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 7 :
    {
        tempd = tempd + 9 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 8 :
    {
        tempd = tempd + 9 ;
        if (tempd == 30)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 30)
        {
            tempd = tempd - 30 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 9 :
    {
        tempd = tempd + 10 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 10 :
    {
        tempd = tempd + 9 ;
        if (tempd == 30)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 30)
        {
            tempd = tempd - 30 ;
            tempm = tempm + 2 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 11 :
    {
        tempd = tempd + 10 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = 1 ;
            tempy = tempy + 1 ;
        }
        else
        {
            tempm = tempm + 1 ;
        }
        break ;
    }
    case 12 :
    {
        tempy = tempy + 1 ;
        tempd = tempd + 9 ;
        if (tempd == 31)
        {
            tempm = tempm + 1 ;
        }
        else if (tempd > 31)
        {
            tempd = tempd - 31 ;
            tempm = 2 ;
        }
        else
        {
            tempm = 1 ;
        }
        break ;
    }
    default :
    {
        printf("\nNot a valid date.");
    }
    }
    p.date2 = tempd ;
    p.month2 = tempm ;
    p.year2 = tempy ;
    printf("\n\t\tThe date for second dose is: %d/%d/%d", p.date2, p.month2, p.year2);

    fprintf(ek,"%s %s %c %d %s %s %s %s %d/%d/%d %d/%d/%d %lld\n", p.First_name, p.Last_name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Hospital, p.date1, p.month1, p.year1, p.date2, p.month2, p.year2, p.Password);
    fclose(ek);//file close korbe//
    system("COLOR 2F");
    printf("\n\n\t\tRegistration Sucessful!!\n");
    printf("\n\n\t\tLogin to view your Information\n");
    description();
    printf("\n\n\n\n\t\tPRESS ANY KEY TO GO TO MENU");
    getch();
    Menu();
}

void Login()//Login function user//
{
    char number[20];
    char passW[20];
    long long int HashPass;
    system("cls");
    TitleScreen();

    FILE*ek;
    ek=fopen("Record.dat", "r+");
    printf("\n\n\t\t\tEnter contact number: ");
    scanf("%s", &number);

    printf("\n\n\t\t\tPassword: ");
    scanf("%s", &passW);
    HashPass=PasswordProc(passW);
    system("cls");
    TitleScreen();
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %d/%d/%d %d/%d/%d %lld\n", p.First_name, p.Last_name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Hospital, &p.date1, &p.month1, &p.year1, &p.date2, &p.month2, &p.year2, &p.Password)!=EOF)
    {
        if((strcmp(number, p.Contact_no)==0)&&(HashPass == p.Password))
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(18,15);
            printf("Gender");
            gotoxy(27,15);
            printf("Age");
            gotoxy(35,15);
            printf("Address");
            gotoxy(47,15);
            printf("Contact No");
            gotoxy(62,15);
            printf("Email");
            gotoxy(82,15);
            printf("Hospital");
            gotoxy(100,15);
            printf("Date 1");
            gotoxy(112,15);
            printf("Date 2\n");
            printf("==================================================================================================================================");
            gotoxy(1,18);
            printf("%s %s", p.First_name, p.Last_name);
            gotoxy(21,18);
            printf("%c", p.Gender);
            gotoxy(27,18);
            printf("%d", p.age);
            gotoxy(35,18);
            printf("%s", p.Address);
            gotoxy(46,18);
            printf("%s", p.Contact_no);
            gotoxy(62,18);
            printf("%s", p.Email);
            gotoxy(82,18);
            printf("%s", p.Hospital);
            gotoxy(100,18);
            printf("%d/%d/%d", p.date1, p.month1, p.year1);
            gotoxy(112,18);
            printf("%d/%d/%d", p.date2, p.month2, p.year2);
            printf("\n\n");
            break;
        }
     }

     if((strcmp(number, p.Contact_no)!=0)||(HashPass != p.Password))
        {
        system("COLOR 4F");
        printf("\n\n\t\t\tNo registered User!");
        getch();
        }
    fclose(ek);
    char ans;
    printf("\n\n\n\n\t\t\tLog out(press 'y')");
    scanf(" %c", &ans);
    system("cls");
    if(toupper(ans)=='Y')
    {
        description();
        getch();
        Menu();
    }
}

void Menu()//Main menu function//
{
    system("COLOR 70");
    system("cls");
    TitleScreen();
    int ch;
    printf("\n\n\t\t\t1.Register\n\n\t\t\t2.Login\n\n\t\t\t\n\n\n\n\n\n\t\t\t3.Login(admin)\n\n");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        Register();
        break;
    case 2:
        Login();
        break;
    case 3:
        Adminlogin();
        break;
    default:
        WelcomeScreen();
        break;
    }
}

void Adminlogin()//admin login function//
{
    system("cls");
    int e=0;
    char username[20];
    char password[20];
    char OGusername[20]="ULAB";
    char OGpassword[20]="1201";
    do
    {
        printf("\n\n\n\t\t\tEnter Username & Password");
        printf("\n\n\n\t\t\tUSERNAME: ");
        scanf("%s", &username);
        printf("\n\n\n\t\t\tPASSWORD: ");
        scanf("%s", &password);
        if(strcmp(username,OGusername)==0&&strcmp(password, OGpassword)==0)
        {
            printf("\n\n\n\t\t\t...Login Sucessful...");
            getch();
            AdminMenu();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword is Incorrect... try again");
            e++;
            getch();
        }
    }
    while(e<=2);

    if(e>=2)
    {
        system("COLOR 4F");
        printf("\n\n\t\t\tYou have crossed the limit. you can't log in now");
        getch();
    }
    system("cls");
    Menu();
}

void adminallrec()//admin all record//
{
    int row;
    system("cls");
    TitleScreen();
    FILE*ek;
    ek=fopen("Record.dat", "r");
    printf("\n\n\t\t\t.......ALL RECORD.......");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(18,15);
    printf("Gender");
    gotoxy(27,15);
    printf("Age");
    gotoxy(33,15);
    printf("Address");
    gotoxy(46,15);
    printf("Contact No");
    gotoxy(62,15);
    printf("Email");
    gotoxy(82,15);
    printf("Hospital");
    gotoxy(100,15);
    printf("Date 1");
    gotoxy(112,15);
    printf("Date 2\n");
    printf("==============================================================================================================================");
    row=17;
    while(fscanf(ek,"%s %s %c %d %s %s %s %s %d/%d/%d %d/%d/%d %lld\n", p.First_name, p.Last_name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Hospital, &p.date1, &p.month1, &p.year1, &p.date2, &p.month2, &p.year2, &p.Password)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s", p.First_name, p.Last_name);
        gotoxy(20,row);
        printf("%c", p.Gender);
        gotoxy(27,row);
        printf("%d", p.age);
        gotoxy(33,row);
        printf("%s", p.Address);
        gotoxy(46,row);
        printf("%s", p.Contact_no);
        gotoxy(62,row);
        printf("%s", p.Email);
        gotoxy(82,row);
        printf("%s", p.Hospital);
        gotoxy(100,row);
        printf("%d/%d/%d", p.date1, p.month1, p.year1);
        gotoxy(112,row);
        printf("%d/%d/%d\n", p.date2, p.month2, p.year2);
        row+=2;
    }

    fclose(ek);
    getch();
    AdminMenu();
}

void hospmenu()//hospital wise record show//
{
    int choice, row;
    system("cls");
    char hosp[30];
    TitleScreen();
    FILE*ek=fopen("Record.dat","r");
    printf("\n\n\n\t\t\t.......Hospitals.......\n\n");
    HospitalList();
    printf("\n\n");
    scanf("\n\t\t\t%d", &choice);
    printf("\n\n");
    switch(choice)
    {
    case 1:
        strcpy(hosp, "Square_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 2:
        strcpy(hosp, "Apollo_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 3:
        strcpy(hosp, "LabAid_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 4:
        strcpy(hosp, "Ibn_Sina_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 5:
        strcpy(hosp, "Popular_Hospital");;
        system("cls");
        TitleScreen();
        break;
    case 6:
        strcpy(hosp, "Birdem_hospital");
        system("cls");
        TitleScreen();
        break;
    case 7:
        strcpy(hosp, "BSMMU_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 8:
        strcpy(hosp, "Dhaka_Medical");
        system("cls");
        TitleScreen();
        break;
    case 9:
        strcpy(hosp, "National_Hospital");
        system("cls");
        TitleScreen();
        break;
    case 10:
        strcpy(hosp, "CMH_Hospital");
        system("cls");
        TitleScreen();
        break;
    default:
        system("COLOR 4F");
        printf("\n\n\t\t\tInvalid input");
    }


    gotoxy(1,15);
    printf("Full Name");
    gotoxy(18,15);
    printf("Gender");
    gotoxy(27,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(46,15);
    printf("Contact No");
    gotoxy(62,15);
    printf("Email");
    gotoxy(82,15);
    printf("Hospital");
    gotoxy(100,15);
    printf("Date 1");
    gotoxy(112,15);
    printf("Date 2\n");
    printf("============================================================================================================================");
    row=17;

    while(fscanf(ek,"%s %s %c %d %s %s %s %s %d/%d/%d %d/%d/%d %lld\n", p.First_name, p.Last_name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Hospital, &p.date1, &p.month1, &p.year1, &p.date2, &p.month2, &p.year2, &p.Password)!=EOF)
    {
        if(strcmp(p.Hospital,hosp)==0)
        {
            gotoxy(1,row);
            printf("%s %s", p.First_name, p.Last_name);
            gotoxy(21,row);
            printf("%c", p.Gender);
            gotoxy(27,row);
            printf("%d", p.age);
            gotoxy(37,row);
            printf("%s", p.Address);
            gotoxy(46,row);
            printf("%s", p.Contact_no);
            gotoxy(62,row);
            printf("%s", p.Email);
            gotoxy(82,row);
            printf("%s", p.Hospital);
            gotoxy(100,row);
            printf("%d/%d/%d", p.date1, p.month1, p.year1);
            gotoxy(112,row);
            printf("%d/%d/%d\n", p.date2, p.month2, p.year2);
            row+=2;
        }
    }
    fclose(ek);
    getch();
    AdminMenu();

}

void AdminMenu()//admin main menu//
{
    int option;
x:
    system("cls");
    TitleScreen();
    printf("\n\n\n\t\t\t1. Show all records");
    printf("\n\n\n\t\t\t2. Show records by Hospital");
    printf("\n\n\n\t\t\t3. Log out\n");
    scanf("\n\n\n\t\t\t%d", &option);
    switch(option)
    {
    case 1:
        adminallrec();
        break;
    case 2:
        hospmenu();
        break;
    case 3:
        Menu();
        break;
    default:
        goto x;
    }
}

