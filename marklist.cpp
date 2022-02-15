#include<iostream>


using namespace std;

struct Student {

    int roll,mark[5];
    string name, branch;

}S;

void Enter_studentDetails(int R,string N,string C)
{

    S.roll=R;
    S.name=N;
    S.branch=C;

    cout<<"\n\tStudent Details successfully stored";

}

void Enter_Marks()
{
    cout<<"\nEnter Mark for engineering mechanics : ";
    cin>>S.mark[0];
    cout<<"\nEnter Mark for calculus: ";
    cin>>S.mark[1];
    cout<<"\nEnter Mark for graphics  : ";
    cin>>S.mark[2];
    cout<<"\nEnter Mark for physics: ";
    cin>>S.mark[3];
    cout<<"\nEnter Mark for chemistry : ";
    cin>>S.mark[4];

     cout<<"\n\tMarks for 5 subjects successfully stored";
}

void Delete_Mark(int key)
{

    if(key>5){
        cout<<"Invalid option pressed.";
    }
    else
    {
        S.mark[key-1]=-1;

         cout<<"\n\tMark of Subject "<<key<<" is Deleted.";
    }
}

void Insert_Mark(int key)
{

    if(key>5){
        cout<<"Invalid option pressed.";
    }
    else
    {
        if(S.mark[key-1]==-1){
            cout<<"\nEnter the mark that is need to be instered as the mark of Subject "<<key<<" : ";
            cin>>S.mark[key-1];
            cout<<"\n\tMark of Subject "<<key<<" is Inserted successfully.";
        }
        else{
            cout<<"\n\tMark is already inserted for Subject "<<key<<".";
        }
    }
}

void Modify_Mark(int key)
{
    int value;
    if(key>5){
        cout<<"\nInvalid option pressed.";
    }
    else
    {
        if(S.mark[key-1]!=-1)
        {
        cout<<"\nEnter the NEW mark of Subject "<<key<<" : ";
        cin>>value;
        S.mark[key-1]=value;
        cout<<"\n\tMark of Subject "<<key<<" is Modified successfully.";
        }
        else
        cout<<"\n\tMark is not inserted for Subject "<<key<<". Please select INSERT Operation.";
    }
}

void Mark_operations()
{

    int op_choice,sub_choice;


     while (op_choice != 9) {

        cout << "\n\n\tPress"
                "\n\t1 To DELETE the Mark of a subject"
                "\n\t2 To INSERT the Mark of a subject"
                "\n\t3 To MODIFY the Mark of a subject"
                "\n\t"
                "\n\t9 to Exit to main menu\n";
        cout << "\nEnter your Choice\n";
        cin>>op_choice;

        switch (op_choice) {
            case 1: {
               cout << "\n\n\tPress the appropriate key to DELETE mark of the corresponding subject"
                "\n\t1 for engineering mechanics"
                "\n\t2 for calculus "
                "\n\t3 for graphics"
                "\n\t4 for physics"
                "\n\t5 for chemistry\n";
                cout << "\nEnter your Choice\n";
                cin>>sub_choice;

                Delete_Mark(sub_choice);
                break;
            }
            case 2: {
                cout << "\n\n\tPress the appropriate key to INSERT mark of the corresponding subject"
                "\n\t1 for engineering mechanics"
                "\n\t2 for calculus"
                "\n\t3 for graphics"
                "\n\t4 for physics"
                "\n\t5 for chemistry\n";
                cout << "\nEnter your Choice\n";
                cin>>sub_choice;

                Insert_Mark(sub_choice);
                break;
            }
            case 3: {
                cout << "\n\n\tPress the appropriate key to MODIFY the marks of the corresponding subject"
                "\n\t1 for engineering mechanics"
                "\n\t2 for calculus"
                "\n\t3 for graphics"
                "\n\t4 for physics"
                "\n\t5 for chemistry\n";
                cout << "\nEnter your Choice\n";
                cin>>sub_choice;

                Modify_Mark(sub_choice);
                break;
            }
            case 9: {
                cout<<"\nExiting back to main menu..";
                break;
            }
            default:
                cout<<"invalid entry";
                break;
        }

     }
}
void Show_mark(int key){
    if(S.mark[key-1]==-1)
    cout<<"\n\tMark unavailable/Deleted";
    else
    cout<<"\n\tSubject "<<key<<" : "<<S.mark[key-1];
}
void Show_Student()
{
    cout<<"\n\tStudent Name : "<<S.name;
    cout<<"\n\tStudent Class : "<<S.branch;
    cout<<"\n\tStudent Roll No : "<<S.roll;

    cout<<"\n\n\tLatest Marks of the 5 Subjects\n";

    Show_mark(1);
    Show_mark(2);
    Show_mark(3);
    Show_mark(4);
    Show_mark(5);

}

int main()
{

    string Name,Class;
    int Roll;

    // Menu-driven program
    while (true) {
        cout << "\n\n\tPress"
                "\n\t1 To Enter details of the Student"
                "\n\t2 To Enter the Marks of this Student"
                "\n\t3 To Delete/Insert/Modify the Mark of the student"
                "\n\t4 to View Student Details with all the marks"
                "\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;

        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "Enter Roll Number of Student\n";
            cin >> Roll;
            cout << "Enter Branch of Student \n";
            cin >> Class;

            Enter_studentDetails(Roll, Name, Class);
        }
        else if (Choice == 2) {

            Enter_Marks();
        }
        else if (Choice == 3) {

            Mark_operations();
        }
        else if (Choice == 4) {

            Show_Student();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}
