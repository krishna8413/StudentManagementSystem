#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student ::menu() //Menu Driven for the options
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t---------Student Management System----" << endl;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t 1. Enter new Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit Record" << endl;

    cout << "\t\t\t ---------------------------------------------" << endl;
    cout << "\t\t\t Choose Option: [1/2/3/4/5/6]" << endl;
    cout << "Enter Your Choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            /* code */
            insert();
            cout << "\n\t\t\t Add Another Student (Y,N):";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);

    default:
        cout << "\t\t\t Invalid Choice  \t\t\t" << endl;
    }
    getch();
    goto menustart;
}
void student ::insert() // adding student details
{
    system("cls");
    fstream file;
    cout << "\n--------------------------------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------------------------------Add Student Details-------------------" << endl;
    cout << "\t\t\t  Enter Name: ";
    cin >> name;
    cout << "\t\t\t  Enter Roll_no: ";
    cin >> roll_no;
    cout << "\t\t\t  Enter Course: ";
    cin >> course;
    cout << "\t\t\t  Enter E-mail ID: ";
    cin >> email_id;
    cout << "\t\t\t  Enter Contact_no: ";
    cin >> contact_no;
    cout << "\t\t\t  Enter Address: ";
    cin >> address;
    file.open("studentrecord.txt", ios::app | ios::out);
    file <<name<< " " << roll_no << " " << course << " " << email_id << " " << contact_no << "\n";
    file.close();
}
void student ::display() //To Display Data of Students
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n -----------------------------------------------------------------------------" << endl;
    cout << " -----------------------------------------Student Record Table-----------------------------------------" << endl;
    file.open("studentrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No data is Present...";
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t\t Student No. :" << total++ << endl;
            cout << "\n\n\t\t\t\t Student Name : " << name << endl;
            cout << "\n\n\t\t\t\t Student Roll No. : " << roll_no << endl;
            cout << "\n\n\t\t\t\t Student Course :" << course << endl;
            cout << "\n\n\t\t\t\t Student Email : " << email_id << endl;
            cout << "\n\n\t\t\t\t Student Contact No: " << contact_no << endl;
            cout << "\n\n\t\t\t\t Student Address : " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t\t No Data is Present.....";
        }
    }
    file.close();
}
void student ::modify() //To Modify Data of Students
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string rollno;
    cout << "\n--------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------Student Modify Details -------------------------" << endl;
    file.open("studentrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t No Data is Present...";
        file.close();
    }
    else
    {
        cout << "\n Enter Roll no. of Student which you want to Modify :";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                cout << "\t\t\t Enter Name: ";
                cin >> name;
                cout << "\t\t\t Enter Roll No. :";
                cin >> roll_no;
                cout << "\t\t\t Enter Course :";
                cin >> course;
                cout << "\t\t\t Enter Email_id :";
                cin >> email_id;
                cout << "\t\t\t Enter Contact No :";
                cin >> contact_no;
                cout << "\t\t\t Enter Address :";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t\t Student Roll no not found...";
            }
        }
        file1.close();
        file.close();
        remove("studentrecord.txt");
        rename("Record.txt", "studentrecord.txt");
    }
}
void student ::search() //To search Data of Students
{
    system("cls");
    fstream file;
    int found=0;
    file.open("studentrecord.txt", ios::in);
    if (!file)
    {
        cout << "\n----------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------Student Search Data---------------------------" << endl;
        cout << "\n\t\t\t\t No Datat Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n--------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------Student Search Data---------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search :";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\t\t Student Name : " << name << endl;
                cout << "\n\n\t\t\t\t Student Roll No. : " << roll_no << endl;
                cout << "\n\n\t\t\t\t Student Course :" << course << endl;
                cout << "\n\n\t\t\t\t Student Email : " << email_id << endl;
                cout << "\n\n\t\t\t\t Student Contact No: " << contact_no << endl;
                cout << "\n\n\t\t\t\t Student Address : " << address << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if(found==0)
        {
            cout<<"\n\t\t\t\t Student Roll No Not Found..";
        }
        file.close();
    }
}
void student ::deleted()//To delete Data of Students..
{
    system("cls");
    fstream file,file1;
    string rollno;
    int found =0;
    cout<<"\n---------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------Delete Student Data Details --------------------------"<<endl;
    file.open("studentrecord.txt", ios::in);
    if (!file)
    {
        cout<<"\n\t\t\t\t No Data is Present...";
    }
    else{
        cout<<"\n Enter Roll no. of Student which You Want to Delete :";
        cin>>rollno;
        file1.open("record.txt", ios::app | ios::out);
        file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 <<" "<<name<<" "<<roll_no<<" "<<course<<" "<<email_id<<" "<<contact_no<<" "<<address<<"\n";
            }
            file>>name>>roll_no>>course>>email_id>>contact_no>>address;
        }
        if (found == 0)
        {
            cout<<"\n\t\t\t\t Student Roll No not found...";
        }
        file1.close();
        file.close();
        remove("studentrecord.txt");
        rename("record.txt","studentrecord.txt");
        
    }
    
}
main()
{
    student project;
    project.menu();
    return 0;
}