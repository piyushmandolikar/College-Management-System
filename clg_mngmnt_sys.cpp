#include <iostream>
#include <string.h> 
#include<stdlib.h>
using namespace std;
class College {
public:
    char name[50], age[20], contact[11],roll[11];  
    void setCollegeDetails(char name[], char age[], char contact[]) {
        strcpy(this->name, name);  
        strcpy(this->age, age);  
        strcpy(this->contact, contact);
    }
    void displayCollegeDetails() { 
        cout << "Roll No: " << roll << endl; 
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
    }
};
class Student : public College {	
protected:
    char city[100];
public:
Student *first;
 Student *last;
    void setStudentDetails(char name[], char age[], char contact[],
                           char roll[], char city[]) {
        setCollegeDetails(name, age, contact);  
        strcpy(this->roll, roll);
        strcpy(this->city, city);
    }

    
    void displayStudentDetails() {  
        displayCollegeDetails();  
        cout << "City: " << city << endl;
    }
};

class CollegeAdministrationSystem {
private:
    Student *first,*last,*tmp;
    char c;
    int count;  

public:
    CollegeAdministrationSystem() {
        first=NULL;
        count = 0;
    }
    int check(char num[]) {
        if (strlen(num) != 10 || strcmp(num, "1000000000") == -1) {
            return 0;
        }
        for (int i = 0; i < 10; i++) {
            if (!isdigit(num[i])) {
                return 0;
            }
        }
        return 1;
    }
    int check2(char num[]) {
        if (strcmp(num, "0") == -1 || strcmp(num, "0") == 0) {
            return 0;
        }
        for (int i = 0; i < strlen(num); i++) {
            if (!isdigit(num[i])) {
                return 0;
            }
        }
        return 1;
    }
    int check1(char string[]) {   
        int n = strlen(string);
        for (int i = 0; i < n; i++) {
            if (isdigit(string[i])) {
                return 0;
            }
        }
        return 1;
    }
    void addStudent() {
       	system("cls");
        char name[50], roll[50], city[100], contact[11];
        char age[20];
        do
        {
         tmp=(Student *)malloc(sizeof(Student));
        cout << "Enter Roll no: ";
        cin >> roll;
        while (!check2(roll)) { 
            cout << "Invalid input. Please enter a valid Roll no: ";
            cin >> roll;
        }
        cout << "Enter Student Name: ";
        cin >> name;
        while (!check1(name)) { 
            cout << "Invalid input. Please enter a valid name: ";
            cin >> name;
        }
        cout << "Enter Age: ";
        cin >> age;
        while (!check2(age)) { 
            cout << "Invalid input. Please enter a valid age: ";
            cin >> age;
        }
        cout << "Enter Contact : ";
        cin >> contact;
        while (!check(contact)) { 
            cout << "Invalid input. Please enter a valid contact number: ";
            cin >> contact;
        }
        
        cout << "Enter city: ";
        cin >> city; 
        while (!check1(city)) { 
            cout << "Invalid input. Please enter a valid city: ";
            cin >> city;
        }
       

        tmp->setStudentDetails(name, age, contact, roll, city);
        tmp->last=NULL;
        tmp->first=last;
        if(first==NULL)
        {
            first=last=tmp;
        }
        else
        {
        last->last=tmp;
        last=tmp;
        }
        count++;
        cout << "Student added successfully!" << endl;
        cout<<"Do you want to exit y/n :\n";
        cin>>c;
        }while(c=='n'||c=='N');
        
    }
    
    void displayAllStudents() {
    	system("cls");
        int i=0;
        if (count == 0) {
            cout << "No Students to display." << endl;
//            return;
			goto e;
        }
        tmp=first;
        while(tmp!=NULL) {
            cout << "Student " << (i + 1) << ":" << endl;
            tmp->displayStudentDetails();  
            cout << "----------------------" << endl;
            tmp=tmp->last;
            i++;
        }
        
        e:cout<<"Do you want to exit y/n :"<<endl;
        cin>>c;
        if(c=='y'||c=='Y')
        {
        	return;
		}
		else if(c=='n'||c=='N')
		{
			goto e;
		}
		else
		{
			cout<<"Please choose between y/n"<<endl;
			goto e;
		}
    }
    void searchStudent() {
    	system("cls");
    	b:
        if (count == 0) {
            cout << "No Students to search." << endl;
//            return;
			goto e;
        }
        char RollNo[50];
        cout << "Enter Roll no to search: ";
        cin >> RollNo;  
        while (!check2(RollNo)) { 
            cout << "Invalid input. Please enter a valid Roll no: ";
            cin >> RollNo;
        } 
        tmp=first;
        while(tmp!=NULL) {
            if (strcmp(tmp->roll, RollNo) == 0) {
                cout << "Student found!" << endl;
                tmp->displayStudentDetails();
//                return;
			goto e;
            }
            tmp=tmp->last;
        }
        cout << "Student not found." << endl;
        e:cout<<"Do you want to exit y/n :"<<endl;
        cin>>c;
        if(c=='y'||c=='Y')
        {
        	return;
		}
		else if(c=='n'||c=='N')
		{
			goto b;
		}
		else
		{
			cout<<"Please choose between y/n"<<endl;
			goto e;
		}
    }
    void deleteStudent() {
    	system("cls");
    	del:
        if (count == 0) {
            cout << "No Students to delete." << endl;
//            return;
		goto f;
        }

        char DeleteRoll[50];
        cout << "Enter Roll no to delete: ";
        cin >> DeleteRoll; 
        while (!check2(DeleteRoll)) { 
            cout << "Invalid input. Please enter a number: ";
            cin >> DeleteRoll;
        } 
        if(strcmp(first->roll, DeleteRoll)==0)
        {
            
            tmp=first;
            if (count==1){
                    first=last=NULL;
                    goto a;
            }
            first=first->last;
            tmp->last=NULL;
            first->first=NULL;
            a:free(tmp);
            count--;
              cout << "Student deleted successfully!" << endl;
//                return;
			goto f;

        }
        else if(strcmp(last->roll, DeleteRoll)==0)
        {
            tmp=last;
            last=last->first;
            last->last=NULL;
            tmp->first=NULL;
            free(tmp);
            count--;
              cout << "Student deleted successfully!" << endl;
//                return;
			goto f;

        }
        else{
            tmp=first;
            while(tmp!=NULL)
            {
            if(strcmp(tmp->roll, DeleteRoll) == 0) {
                tmp->first->last=tmp->last;
                tmp->last->first=tmp->first;
                tmp->last=NULL;
                tmp->first=NULL;
                free(tmp);
                count--;
                cout << "Student deleted successfully!" << endl;
//                return;
				goto f;
            }
            tmp=tmp->last;
        }
        if(count==0){
            first=last=NULL;
        }
        cout << "Student not found." << endl;
        f:cout<<"Do you want to exit y/n :"<<endl;
        cin>>c;
        if(c=='y'||c=='Y')
        {
        	return;
		}
		else if(c=='n'||c=='N')
		{
			goto del;
		}
		else
		{
			cout<<"Please choose between y/n"<<endl;
			goto f;
		}
    }
    }
    void displayStudentCount() {
    	system("cls");
        cout << "Number of Students: " << count << endl;
        g:cout<<"Do you want to exit y/n :"<<endl;
        cin>>c;
        if(c=='y'||c=='Y')
        {
        	return;
		}
		else if(c=='n'||c=='N')
		{
			goto g;
		}
		else
		{
			cout<<"Please choose between y/n"<<endl;
			goto g;
		}
    }
};
int main() {
    char yesno,yup;
    int choice;
    int size,i,noclass;
    string *s;
    yup :
    system("cls");
    cout<<"Enter no of classes you want to create : ";
    cin>>size;
    CollegeAdministrationSystem sys[size+1];
    if(size<=0)
    {
    	system("cls");
    	cout<<"Please choose value above 0"<<endl;
    	oops :
    	cout<<"Do you want to go back? y/n"<<endl;
	 	cin>>yup;
    	if(yup=='y'||yup=='Y')
	 	{
	 		goto yup;
		}
		else if(yup=='n' || yup=='N')
		{
			goto oops;
		}
		else
		{
			cout<<"Please Enter valid alphabets."<<endl;
			goto oops;
		}
	}
	else
	{
    s=new string[size]; 
    for(i=0;i<size;i++)
    {	cout<<i+1<<". ";
    	cin>>s[i];
	}
	st :
	system("cls");
	cout<<"Classes Present in College :"<<endl;
	for(i=0;i<size;i++)
    {	
    	cout<<i+1<<". "<<s[i]<<endl;
	}
	cout<<size+1<<". "<<"Exit"<<endl;
	cout<<"Enter the no of class to see its data : ";
	cin>>noclass;
	  
	 if(noclass==0)
	 {
	 	system("cls");
	 	cout<<"Please choose a valid class"<<endl;
	 	cont :
	 	cout<<"Do you want to go back? y/n"<<endl;
	 	cin>>yesno;
	 	if(yesno=='y'||yesno=='Y')
	 	{
	 		goto st;
		}
		else if(yesno=='n' || yesno=='N')
		{
			goto cont;
		}
		else
		{
			cout<<"Please Enter valid alphabets."<<endl;
			goto cont;
		}
	 }
	 else if(noclass!=0 && noclass<=size)
	{
		for(i=0;i<noclass;i++)
		{		
		again :
    	system("cls");
        cout <<s[noclass-1]<< " Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Total no of Students" << endl;
        cout << "6. Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
		{
            case 1:
                sys[noclass].addStudent();
                break;
            case 2:
                sys[noclass].displayAllStudents();
                break;
            case 3:
                sys[noclass].searchStudent();
                break;
            case 4:
                sys[noclass].deleteStudent();
                break;
            case 5:
                sys[noclass].displayStudentCount();
                break;
            case 6:
                goto st;
            default:
                system("cls");
        	cout<<"Please enter numbers between 1 to 6"<<endl;
        	against :
	 		cout<<"Do you want to go back? y/n"<<endl;
	 		cin>>yesno;
	 		if(yesno=='y'||yesno=='Y')
	 		{
	 		goto again;
			}
			else if(yesno=='n' || yesno=='N')
			{
			goto against;
			}
			else
			{
			cout<<"Please Enter valid alphabets."<<endl;
			goto against;
			}
        }
        goto again;
		}
	}
	else if(noclass>size+1)
	{
		system("cls");
		cout<<"Please choose a valid class"<<endl;
	 	cout<<"Do you want to go back? y/n"<<endl;
	 	cin>>yesno;
	 	if(yesno=='y'||yesno=='Y')
	 	{
	 		goto st;
		}
		else if(yesno=='n' || yesno=='N')
		{
			goto cont;
		}
		else
		{
			cout<<"Please Enter valid alphabets."<<endl;
			goto cont;
		}
	}
	else if(size+1)
	{
		system("cls");
		cout<<"Successfully Exited from college administration system";
		return 0;
	}
	}
    return 0;
}

