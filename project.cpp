#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
//Structure
struct donor{
    string name;
    int age;
    string blood_group,gender,address,phone_number;
};
donor donors[100];
int countdonors=0;
//color function
void setcolor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void clr(){
		cout<<"Enter any key for go to main"<<endl;
getch();
system("cls");
	
}
//Donation Function

void donation(){
		system("color 4F"); //Screen color
	cout<<right<<setw(40)<<"BLOOD DONATION PORTION"<<endl;

    if(countdonors>=100){
    	setcolor(0x1E);
        cout<<"Donor list is full"<<endl;
        setcolor(7);
        return; 
    }
    donor d;
    cin.ignore();
    cout<<"Enter your name: ";
    getline(cin, d.name);
    cout<<"Enter your age: ";
    cin>>d.age;
    cin.ignore();

    // BLOOD GROUP SELECTION
    int bgChoice;
    string bloodGroups[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};

    cout << "\nSelect Blood Group:\n";
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << bloodGroups[i] << endl;
    }
    while (true) {
        cout << "Enter choice (1-8): ";
        cin >> bgChoice;
        if (bgChoice < 1 || bgChoice > 8) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please select a number from 1 to 8.\n";
        } else {
            cin.ignore();
            break;
        }
    }
    d.blood_group = bloodGroups[bgChoice - 1];

	cout<<"Enter your Gender: ";
    getline(cin, d.gender);
    cout<<"Enter your Address: ";   
    getline(cin, d.address);  
    cout<<"Enter your Phone Number: "; 
    getline(cin, d.phone_number);
    donors[countdonors]=d;
    countdonors++;
    cout<<"\t\t\tAdding";
    for(int i=0;i<5;i++){
    	cout<<".";
    	cout.flush();
    	Sleep(1000);
	}
	system("cls");//screen reset
 system("color 4F");
	cout<<"\n\t\t\t Donotion Added Successfully"<<endl<<endl;
	cout<<"Enter any key for go to main"<<endl;
getch();
system("cls");
}
void view_donors(){
 system("color 4F");
        if(countdonors==0){
        cout<<endl;
             cout<<"\t\t\t\t ****No donors available****";
          	cout<<"\n\tEnter any key for go to main: ";
getch();
system("cls");
             cout<<endl;
            return;
        }
        system("color 2F");
 
    cout<<left<<setw(20)<<"Name"<<setw(10)<<"Age"<<setw(15)<<"Blood Group"<<setw(10)<<"Gender"<<setw(30)<<"Address"<<setw(15)<<"Phone Number"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
  for(int i=0;i<countdonors;i++){    
        cout<<left<<setw(20)<<donors[i].name;        
        cout<<setw(10)<<donors[i].age;       
        cout<<setw(15)<<donors[i].blood_group;      
        cout<<setw(10)<<donors[i].gender;        
         cout<<setw(13)<<donors[i].address;    
        cout<<setw(15)<<donors[i].phone_number<<endl;
    }
cout<<"\n\n";
clr();
}
///display 2 exerect
void display2(string needed){
int serial=1;
int se=1;//serial number;
int store[100];
system("color 3F");
cout<<"\nExact Match donors:\n";
 cout << left << setw(20) << "Name" << setw(10) << "Age"   
         << setw(15) << "Blood Group" << setw(10) << "Gender"   
         << setw(30) << "Address" << setw(15) << "Phone Number" << endl;  

    cout << "-----------------------------------------------------------------------------------------------------" << endl;  

  for (int i = 0; i < countdonors; i++){
  
   if(donors[i].blood_group==needed)
    {    
        cout << left<<setw(5)<<se << setw(20) << donors[i].name;    
        cout << setw(10) << donors[i].age;   
        cout << setw(15) << donors[i].blood_group;   
        cout << setw(10) << donors[i].gender;    
        cout << setw(30) << donors[i].address;   
        cout << setw(15) << donors[i].phone_number << endl;  
    store[se-1]=i;
    se++;
    } }

    if(se==1){
    	cout<<"No Exact match donors found.\n";
    	return;
	}
	int choice;
	cout<<"Enter serial number of donor to take: ";
	cin>>choice;
	if(choice<1 || choice>=se){
		cout<<"Invalid choice!n";
		return;
	}    system("cls");
	system("color 4F");
	//delete
	int index=store[choice-1];
	for(int j=index;j<countdonors-1;j++)
	donors[j]=donors[j+1];
	countdonors--;
	cout<<"Selected Donor Remove from List.\n";
	clr();	
}
void display3(string needed){
	int  se=1;
	int store[100];
	cout<<"\nCompatible Donors:\n";
 cout << left << setw(20) << "Name" << setw(10) << "Age"   
         << setw(15) << "Blood Group" << setw(10) << "Gender"   
         << setw(30) << "Address" << setw(15) << "Phone Number" << endl;  

    cout << "-----------------------------------------------------------------------------------------------------" << endl;  

for(int i=0;i<countdonors;i++){
	bool compti=false ; //compatibility check
	if(needed == donors[i].blood_group)
	compti=true;
	 else if(
            (needed=="AB+" && (donors[i].blood_group=="A+" || donors[i].blood_group=="B+" || donors[i].blood_group=="AB-"  
		||	donors[i].blood_group=="O+" || donors[i].blood_group=="A-" || donors[i].blood_group=="B-" || donors[i].blood_group=="O-")) ||
            (needed=="A+" && (donors[i].blood_group=="A-" || donors[i].blood_group=="O+" || donors[i].blood_group=="O-")) ||
            (needed=="B+" && (donors[i].blood_group=="B-" || donors[i].blood_group=="O+" || donors[i].blood_group=="O-")) ||
            (needed=="A-" && donors[i].blood_group=="O-") ||
            (needed=="B-" && donors[i].blood_group=="O-") ||
            (needed=="AB-" && (donors[i].blood_group=="A-" || donors[i].blood_group=="B-" || donors[i].blood_group=="O-")))  
			compti=true;
  if(compti)
{
	
	 cout << left<<setw(5)<<se << setw(20) << donors[i].name;    
        cout << setw(10) << donors[i].age;   
        cout << setw(15) << donors[i].blood_group;   
        cout << setw(10) << donors[i].gender;    
        cout << setw(30) << donors[i].address;   
        cout << setw(15) << donors[i].phone_number << endl;  
    store[se-1]=i;
    se++;
    } }
    if(se==1){
    	cout<<"No Compatible donors found.\n";
    	return;
	}
		int choice;
	cout<<"Enter serial number of donor to take: ";
	cin>>choice;
	if(choice<1 || choice>=se){
		cout<<"Invalid choice!n";
		return;
	}
	//delete
	int index=store[choice-1];
	for(int j=index;j<countdonors-1;j++)
	donors[j]=donors[j+1];
	countdonors--;
	cout<<"Selected Donor Remove from List.\n";
}
	
void getblood(){
	if(countdonors ==0){
		system("color 4F");
		cout<<"\n\n\n\n\n\n\n\n"; 
			cout<<setw(65)<<"NO Donors available.\n"; 
			clr();
		return;	
	}
	system("color 8F");
	string needed;
	cin.ignore();
	cout<<"Enter the blood type you need: ";
	getline(cin,needed);
	bool Exact=false ; // exaxt match exists
	for(int i=0;i<countdonors;i++)
	if(donors[i].blood_group == needed)
	{
		Exact=true;
		break;
	}
	if(Exact)
	{
		display2(needed);
	}
	else{
		display3(needed);
	}
	clr();
}

//delete funtion

void deleteblood(){
	system("color 4F");
	if (countdonors==0){
	cout<<"\n\t\t\t\t\tNO blood in list want to delete\n\n";
	clr();	}

	else{
	system("color 0C");
    string name,bg;
    cin.ignore();
    cout<<"Enter name you want to delete";
    getline(cin,name);
    cout<<"Enter blood group";
    getline(cin,bg);
    for(int i=0;i<countdonors;i++){
        if(name==donors[i].name && bg==donors[i].blood_group){
            for(int j=i;j<countdonors-1;j++){
                donors[j]=donors[j+1];
            }
            clr();
            system("color 4F");
            countdonors--;
            setcolor(0x4F);
            cout<<"\n\t\t***Donor Deleted successfully***";
            //return;
            setcolor(7);
            cout<<endl;
            clr();
            return;
    }    
	}
    }}

using namespace std;
int main(){
    int n;
    system("color 1F");
    cout<<"\n\t\t***Welcome to Blood Matching System***\n"; 
  while (n != 5) {  
	    cout<<setw(15)<<"_____________________________________________________________________________"<<endl; 
        cout <<right<<setw(35)<< "1. Donation" << endl;  
        cout <<right<<setw(38)<< "2. View donors" << endl;  
        cout <<right<<setw(36)<< "3. Get blood" << endl;  
        cout <<right<<setw(39)<< "4. Delete blood" << endl;  
        cout <<right<<setw(31)<< "5. Exit" << endl;
		cout<<setw(15)<<"_____________________________________________________________________________"<<endl<<endl;   
        cout << "Enter your choice: ";  
        cin >> n; 
		system("cls"); 
	    switch(n){
        case 1:
            donation();
            break;
            case 2:
            	setcolor(0x2F);
            cout<<"\n\t\t\t\t***List of Donors***";
            setcolor(7);
            cout<<endl;
             view_donors();
            break;
            case 3:
            	getblood();
            	break;
                case 4:
                deleteblood();
                	break;
                	system("color 5F");
                	case 5:
					cout<<"\n\n\n\n";               	
               		cout<<setw(78)<<"Goood bye";
               		break;
               		clr();
            
    }
}
return 0;
}
