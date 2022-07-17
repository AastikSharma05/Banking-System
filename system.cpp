#include <bits/stdc++.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cstdio>
#include <windows.h>
using namespace std;
// header files
// class for details of customer
class customer
{
    char account_no[17];
    char name[25];
    char address[25];
    char phone[11];
    float balance;
    char ac_type[20]; // account type
public:
    void input();        // function to input details
    void display();      // function to display details
    char *ret_ac();      // function to return account no
    float ret_amt();     // function to return balance
    char *ret_type();    // function to return account type
    void upd(float amt); // function to update balance
};
// function to input details
void customer ::input()
{
    cout << "account no. : ";
    cin >> account_no;
    cout << "name : ";
    cin >> name;
    cout << "address : ";
    cin >> address;
    cout << "phone no. : ";
    cin >> phone;
    cout << "account balance : ";
    cin >> balance;
    cout << "account type : ";
    cin >> ac_type;
}
// function to display details
void customer ::display()
{
    cout << "account no. : ";
    cout << account_no << endl;
    cout << "name : ";
    cout << name << endl;
    cout << "address : ";
    cout << address << endl;
    cout << "phone no. : ";
    cout << phone << endl;
    cout << "account balance : ";
    cout << balance << endl;
    cout << "account type : ";
    cout << ac_type << endl;
}
// function to return account no
char *customer ::ret_ac()
{
    return account_no;
}
// function to return balance
float customer ::ret_amt()
{
    return balance;
}
// function to return account type
char *customer ::ret_type()
{
    return ac_type;
}
// function to update balance
void customer ::upd(float amt)
{
    balance = amt;
}
// FUNCTION FOR MAKING FRONT PAGE
void front()
{

    for (int i = 0; i < 50; ++i)
        cout << '*';
    int c, r = 20;

    cout << "WELCOME TO SABKA BANK";
    c = 65;
    for (int i = 0; i < 50; ++i)
    {
        cout << '*';
        c--;
    }
}

// function for loading
void load()
{

    printf("%s", "\n LOADING....");
    for (int i = 1; i <= 60; ++i)
    {
        printf("%s", ".");
        _sleep(80);
    }
    printf("%s", ".... 100% completed");
    cout << endl << endl << endl;
}
// function for password
void password()
{

    char pass[10] = "123", p[10];
    int i;

    cout << "\nenter your password : ";

    for (i = 0; p[i] != 13; i++)
    {
        p[i] = getch();
        if (p[i] == 13)
            break;

        cout << "*";
    }
    p[i] = '\0';
    cout << "\n";

    if (strcmp(pass, p))
    {
        cout << "\n";
        cout << " ";

        printf("%s", "INCORRECT PASSWORD");
        getch();
        exit(0);
    }
    else
    {
        cout << "\n";
        cout << " ";
        printf("%s", "CORRECT PASSWORD");
        getch();

        cout << endl;
        cout << "\n";
        cout << " ";

        printf("%s", "LOGIN ACCESSED !!!");
        getch();
        load(); // call statement of laoding function
    }
}
// function for cash withdrawl
void withdrawl()
{

    customer c;
    float amount;
    int flag = 0;
    char ac[17];
    cout << "\naccount no. : ";
    cin >> ac;
    cout << endl;

    cout << "how much amount you want to withdraw: " << endl;

    cin >> amount;
    char account[17];
    float amt;
    fstream file;
    int count = 0;
    file.open("ban1.dat", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        count++;
        strcpy(account, c.ret_ac());
        if (!strcmpi(account, ac))
        {
            flag = 1;
            amt = c.ret_amt();
            amt -= amount;
            c.upd(amt);
            file.seekp((count - 1) * sizeof(c));
            file.write((char *)&c, sizeof(c));
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\nthis account details does not exist";
        getch();
    }
    else if (flag == 1)
    {
        cout << "\namount withdrawal successfully !!!";

        cout << "\nyour balance : " << amt;
        getch();
    }
    file.close();
}
// function for deposit through cash
void cash()
{

    customer c;
    int flag = 0;
    float amount;
    char ac[17];

    cout << "\naccount no. : ";
    cin >> ac;

    cout << "\nhow much amount you want to deposit: ";

    cin >> amount;
    float amt;
    int count = 0;
    char account[17];
    fstream file;
    file.open("ban1.dat", ios::out | ios::in | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        count++;
        strcpy(account, c.ret_ac());
        if (!strcmpi(account, ac))
        {
            flag = 1;
            amt = c.ret_amt();
            amt += amount;
            c.upd(amt);
            file.seekp((count - 1) * sizeof(c));
            file.write((char *)&c, sizeof(c));
            break;
        }
    }

    if (flag == 1)
    {
        cout << "\nAmount Deposited successfully !!!";

        cout << "\nCurrent balance : " << amt;
    }
    else if (flag == 0)
        cout << "\nthis account does not exist !!!";
    getch();
    file.close();
}
// function for account statement generation
void generation()
{
    customer c;
    char ac[17];
    int flag = 0;

    cout << "\nEnter the Account no. whose statement to be generated account no. : ";
    cin >> ac;
    char account[17];
    fstream file;
    file.open("ban1.dat", ios::in | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        strcpy(account, c.ret_ac());
        if (!strcmpi(account, ac))
        {
            flag = 1;
            c.display();
            getch();
        }
    }
    if (flag == 0)
        cout << "\nthis account details does not exist";
    file.close();
}
// function for account to account transfer
void transfer()
{
    customer c;
    int flag = 0;
    float amount;
    char ac1[17], ac2[17];

    cout << "\naccount no. from where money is to be transfer : ";
    cin >> ac1;
    cout << endl;

    cout << "account no. where the money is transferred : ";
    cin >> ac2;
    cout << endl;

    cout << "how much amount you want to transfer : " << endl;

    cin >> amount;
    float amt;
    int count = 0;
    fstream file;
    file.open("ban1.dat", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        count++;
        if (!strcmpi(ac1, c.ret_ac()))
        {
            flag = 1;
            amt = c.ret_amt();
            amt -= amount;
            c.upd(amt);
            file.seekp((count - 1) * sizeof(c));
            file.write((char *)&c, sizeof(c));
        }
    }
    file.close();
    file.open("ban1.dat", ios::in | ios::out | ios::binary);
    count = 0;
    if (flag == 1)
        while (!file.eof())
        {
            file.read((char *)&c, sizeof(c));
            if (!file)
                break;
            count++;
            if (!strcmpi(ac2, c.ret_ac()))
            {
                amt = c.ret_amt();
                amt += amount;
                c.upd(amt);
                file.seekp((count - 1) * sizeof(c));
                file.write((char *)&c, sizeof(c));
            }
        }
    cout << endl;

    cout << ac1;

    printf("%s", " >>>>>>");
    cout << " Rs. " << amount;

    printf("%s", " >>>>>>");
    puts(ac2);
    getch();
    file.close();
}
// function to add a customer
void add()
{
    customer c;
    char ch = 'y';
    fstream file;
    file.open("ban1.dat", ios::app | ios::binary);
    while (ch == 'y' || ch == 'Y')
    {
        c.input();
        file.write((char *)&c, sizeof(c));
        cout << "DO YOU WANT ADD MORE RECORDS? (Y/N)" << endl;
        cin >> ch;
    }
    file.close();
}
// function to modify details of customer
void modify()
{
    fstream file;
    char ac[17];
    customer c;
    int counter = 0;
    file.open("ban1.dat", ios::in | ios::out | ios::binary);

    cout << "\nEnter the Account no. whose account details are to be modified";

    cout << "\naccount no. : ";
    cin >> ac;

    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        counter++;
        if (!strcmpi(c.ret_ac(), ac))
        {
            file.seekp((counter - 1) * sizeof(c));
            c.input();
            file.write((char *)&c, sizeof(c));
        }
    }
    file.close();
}
// function to delete the record of customer
void del()
{
    fstream file, tfile;
    file.open("ban1.dat", ios::in | ios::binary);
    tfile.open("details.dat", ios::out | ios::binary);
    customer c;
    char ac[17];

    cout << "\n Enter the Account no. whose account is to be deleted";

    cout << "\naccount no. : ";
    cin >> ac;
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (strcmpi(c.ret_ac(), ac))
            tfile.write((char *)&c, sizeof(c));
    }

    cout << "\n account deleted successfully !!!";
    getch();
    file.close();
    tfile.close();
    remove("ban1.dat");
    rename("details.dat", "ban1.dat");
}
// function to display the list of customers
void disp()
{
    fstream file;
    file.open("ban1.dat", ios::in | ios::binary);
    customer c;
    int i = 0;
    while (!file.eof())
    {
        i++;
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        cout << "\nDetails of customer " << i << endl;
        c.display();
        cout << endl;
    }
    file.close();
}
// function to display the list of customer whose minimum balance is 5000
void fine()
{
    fstream file;
    file.open("ban1.dat", ios::in | ios::binary);
    customer c;
    int i = 0, flag = 0;
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        if (!file)
            break;
        if (c.ret_amt() < 5000)
        {
            flag = 1;
            i++;
            cout << i << ". ";
            c.display();
        }
    }
    if (flag == 0)
        cout << "\n no account with balance below 5000 exist !!!";
    getch();
    file.close();
}
// function to add interest
void interest()
{
    customer c;
    int count = 0, flag = 0;
    float ri; // ri=rate of interest
    float amt;
    char ac[17];

    cout << "\n account no. : ";
    cin >> ac;
    fstream file;
    file.open("ban1.dat", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        count++;
        if (!file)
            break;
        if (!(strcmpi(ac, c.ret_ac())))
        {
            flag = 1;
            if (!(strcmpi(c.ret_type(), "fd")))
            {
                amt = c.ret_amt();
                ri = (7.0 / 100) * amt;
                amt += ri;
            }
            else if (!strcmpi(c.ret_type(), "savings"))
            {
                amt = c.ret_amt();
                ri = (6.0 / 100) * amt;
                amt += ri;
            }
            else if (!strcmpi(c.ret_type(), "rd"))
            {
                amt = c.ret_amt();
                ri = (8.0 / 100) * amt;
                amt += ri;
            }
        }
        if (flag == 1)
        {
            c.upd(amt);
            file.seekp((count - 1) * sizeof(c));
            file.write((char *)&c, sizeof(c));
        }
    }

    cout << "\nAMOUNT UPDATED SUCCESSFULLY !!!" << endl;

    cout << "\nCURRENT BALANCE : " << amt;
    file.close();
}
// function for menu
void menu()
{
    front();
    password();
    cout << endl;
    int choice;

    do
    {

        cout << "\n1. Cash Withdrawl." << endl;
        cout << "2. Cash Deposit." << endl;
        cout << "3. Account Statement Generation." << endl;
        cout << "4. Account to Account Transfer." << endl;
        cout << "5. Add a Customer." << endl;
        cout << "6. Modify Details of Customer." << endl;
        cout << "7. Delete Details of Customer." << endl;
        cout << "8. Display List of Customers." << endl;
        cout << "9. Diplay List of Customers whose ";
        cout << "Minimum Balance is Rs.5000." << endl;
        cout << "10. Adding Interest." << endl;
        cout << "11. Exit." << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            withdrawl();
            break;
        }
        case 2:
        {
            cash();
            break;
        }
        case 3:
        {
            generation();
            break;
        }
        case 4:
        {
            transfer();
            break;
        }
        case 5:
        {
            add();
            break;
        }
        case 6:
        {
            modify();
            break;
        }
        case 7:
        {
            del();
            break;
        }
        case 8:
        {
            disp();

            break;
        }
        case 9:
        {
            fine();
            getch();
            break;
        }
        case 10:
        {
            interest();
            break;
        }
        case 11:
            exit(0);
        default:
            cout << "invalid option!!!";
        }
    } while (choice < 12);
}
// main function
int main()
{
    menu();
    return 0;
}
