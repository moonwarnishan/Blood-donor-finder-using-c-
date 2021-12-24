#include <bits/stdc++.h>
using namespace std;

int menu()
{
    //system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t================================\n";
    cout << "\t\t\t\t\t| Blood Bank Management System |\n";
    cout << "\t\t\t\t\t================================\n\n";
    cout << "\t\t\t\t\t    :: Enter Your Choice ::\n\n";
    cout << "\t\t\t\t      >>\tTo Add New Donar\t(1)\n";
    cout << "\t\t\t\t      >>\tTo View List of Donar\t(2)\n";
    cout << "\t\t\t\t      >>\tTo Search Donar\t\t(3)\n";
    cout << "\t\t\t\t      >>\tTo Exit\t\t\t(4)\n";
    int choice;
    cin >> choice;
    return choice;
}

struct date
{
    int day;
    int month;
    int year;
};

struct donar
{
    string name;
    int id;
    string blood_group;
    double age;
    date last_donation;
    donar *next;
};
donar *head,*tail;
static int serial;

void createdonar()
{
    system("cls");
    donar *tmp=new donar;

    cout << "\n\n\n\n\n\n\t\t\t\t\tEnter Donar Name :\t";
    cin >> tmp->name;
    cout << "\t\t\t\t\tEnter Donar blood_group :\t";
    cin >> tmp->blood_group;
    cout << "\t\t\t\t\tEnter Donar Age :\t";
    cin >> tmp->age;
    cout << "\t\t\t\t\tEnter Donar Last Donation : (day,month,year)\t";
    cin >> tmp->last_donation.day >> tmp->last_donation.month >> tmp->last_donation.year;
    tmp->id=++serial;


    tmp->next=NULL;
    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
        tmp=NULL;
    }
    else
    {
        tail->next=tmp;
        tail=tmp;
    }
}

void display()
{
    donar *tmp=new donar;
    tmp=head;
    while(tmp!=NULL)
    {
        cout << "\n\n\n\n\n\n\t\t\t\t\tDonar Name :\t" << tmp->name << '\n';
        cout << "\t\t\t\t\tDonar Id :\t" << tmp->id << '\n';
        cout << "\t\t\t\t\tDonar blood_group :\t" << tmp->blood_group << '\n';
        cout << "\t\t\t\t\tDonar Age :\t"<<tmp->age<<'\n';
        cout << "\t\t\t\t\tDonar Last Donation : \t"<< tmp->last_donation.day <<"/"<< tmp->last_donation.month <<"/"<< tmp->last_donation.year << '\n';
        tmp=tmp->next;
    }
}

void searchdonar()
{
    string str;
    cout << "\n\n\n\n\n\n\t\t\t\t\tEnter blood group you need :\t";
    cin >> str;
    donar *tmp=new donar;
    tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->blood_group==str)
        {
            cout << "\n\n\n\n\n\n\t\t\t\t\tDonar Name :\t" << tmp->name << '\n';
            cout << "\t\t\t\t\tDonar Id :\t" << tmp->id << '\n';
            cout << "\t\t\t\t\tDonar blood_group :\t" << tmp->blood_group << '\n';
            cout << "\t\t\t\t\tDonar Age :\t"<<tmp->age<<'\n';
            cout << "\t\t\t\t\tDonar Last Donation : \t"<< tmp->last_donation.day <<"/"<< tmp->last_donation.month <<"/"<< tmp->last_donation.year << '\n';
        }
        tmp=tmp->next;
    }
}

int main()
{
    int choice;

    head=NULL;
    tail=NULL;

    do
    {
        choice=menu();
        if(choice==1)
            createdonar();
        else if(choice==2)
            display();
        else if(choice==3)
            searchdonar();
    }
    while(choice!=4);
}
