#include<iostream>
#include<stdio.h>//standard input output
#include<fstream>
#include<stdlib.h>//for rand() fflush
#include<conio.h>//console input output
#include<string.h>
#include<windows.h> //for sleep
#include<iomanip>//manipulate the output of C++
#include<time.h>//manipulte date and time info

using namespace std;
int password();
void menu();
void show();// Table header list
class Hospital
{
    int reg_num;
	int age;
	int temperature;
	int bloodPressure;
    char bloodGroup[100];
	char gender;
    char diagnosis[100];
    char symptoms[100];   
	char name[100];
	char bed_no[100];
	char profession[100];
	char address[100];
	char mobileNumber[100];
    char ward[100];
	public:
        int unique_num();
		void setData();//     Use this to set data on the record 
        void setInfo();
		void addNew();//      To add the record given within setData()-1 funtion and print successfully recorded
        void addHistory();
		void showData();//    This is to show the whole data which is recorded within the file given from setData() 
		void showList();//    This is the data to call for the table data Note: not the table header
		void searchData();//  Search the data option to get to a list to from which data type to search
		void modify();//
		void view_all();//
	    void del();//
        void patient_history();
        void show_history();
        void show_history_file();
        void patient_card();
        void date();

		void search_by_name();
    	void search_by_age();
    	void search_by_diagnosis();
    	void search_by_gender();

};
//----------------------------------------------------
void Hospital::date(){
    time_t rawtime;
    struct tm * timeinfo;
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    cout<<asctime(timeinfo);
}
//----------------------------------------
int Hospital::unique_num(){
    int n;
    srand(time(NULL));
    n=1000+(rand()%100000);
    return n;
}
//----------------------------------------
void Hospital::setData()
{    
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t ENTER THE PATIENT DETAILS ";
    cout<<"\n\t\t\t*****************************************\n\n";
    fflush(stdin);
        reg_num=unique_num();
        cout<<"\n\t\t Register number :-  ";
        cout<<reg_num;
        cout<<endl;
        cout<<"\n\t\t Enter your name :-  ";
        gets(name);
        cout<<"\n\t\t Enter your bed no :-  ";
        gets(bed_no);
        cout<<"\n\t\t Enter your gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your age:- ";
        cin>>age;
        again:
        int flag=0;
        cout<<"\n\t\t Enter patient Blood group :-"; 
        cin>>bloodGroup;
        if((strcmp(bloodGroup,"A+")==0)||(strcmp(bloodGroup,"a+")==0)||(strcmp(bloodGroup,"A-")==0)||(strcmp(bloodGroup,"a-")==0)||
        (strcmp(bloodGroup,"B+")==0)||(strcmp(bloodGroup,"b+")==0)||(strcmp(bloodGroup,"B-")==0)||(strcmp(bloodGroup,"b-")==0)||
        (strcmp(bloodGroup,"O+")==0)||(strcmp(bloodGroup,"o+")==0)||(strcmp(bloodGroup,"O-")==0)||(strcmp(bloodGroup,"o-")==0)||
        (strcmp(bloodGroup,"AB+")==0)||(strcmp(bloodGroup,"ab+")==0)||(strcmp(bloodGroup,"AB-")==0)||(strcmp(bloodGroup,"ab-")==0))
        {

            flag=1;
        }
        if(flag==0)
        {
            cout<<"\n\t\t Wrong Entry...Enter a valid Blood Group..Try Again..\n";
            goto again;
        }
        fflush(stdin);
        cout<<"\n\t\t Enter your profession :-  ";
        gets(profession);
        fflush(stdin);
        cout<<"\n\t\t Enter your permanent address :-  ";
        gets(address);
        cout<<"\n\t\t Enter your Mobile number :- ";
        gets(mobileNumber);
    system("cls");
    cout<<"\t\t\t\t\t\t\t\t\t-------------------***************-------------------------\n\n";
	Hospital::showData();
	cout<<"\n\n\t\t\t\t\t\t\t\t\t-------------------***************-------------------------";
        
}
//------------------------------------------------------
void Hospital::setInfo()
{
    fflush(stdin);
        cout<<"\n\t\t Symptoms :-  ";
        gets(symptoms);
        cout<<"\n\t\t Diagnosis :-  ";
        gets(diagnosis); 
        cout<<"\n\t\t B.P. :-  ";
        cin>>bloodPressure;
        cout<<"\n\t\t Body temperature:-  ";
        cin>>temperature;
        int num;
        char x[25];
        cout<<"\n\t\t Admission Required(Yes/No)? ";
        cin>>x;
        if(strcmp(x,"Yes")==0){
            cout<<"\n\t\t 1. General ward";
            cout<<"\n\t\t 2. Emergency ward";
            cout<<"\n\t\t 3. Intensive care unit ward";
            cout<<"\n\t\t Enter option 1, 2 or 3 :-";
            cin>>num; 
            switch(num)
            {
                case 1:
                    strcpy(ward,"General ward");
                    break;
                case 2:
                    strcpy(ward,"Emergency ward");
                    break;
                case 3:
                    strcpy(ward,"ICU");
                    break;
            }
        }
        else{
            strcpy(ward,"Not Required");
        }
        cout<<"\n\t\t\t*****************************************\n";
        cout<<"\t\t\t\t ";Hospital::date();
        cout<<"\n\t\t\t*****************************************\n\n";
        getch();
    system("cls");
}
//------------------------------------------------------
void Hospital::addNew()
{
    fstream outin;
    outin.open("Hospital.dat",ios::app|ios::out|ios::binary);//ios::out to write means to add the setData() recorded within a Hospital.txt file
    setData();
    outin.write((char*)this,sizeof(Hospital));
    cout<<"\n\n\t\t\t\t\t\t\t\t\t---------YOUR DATA HAS BEEN SUCCESSFULLY INSERTED--------- "<<endl;
    getch();
    outin.close();
}
//---------------------------------------------
void Hospital::addHistory(){
	ifstream infile("Hospital.dat",ios::binary|ios::in);
	int flag;
    int find1;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"Enter patient registration number: "<<endl;
  	cin>>find1;
    while(!infile.eof())
    {
	    if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))){
            if(reg_num==find1)
            {
                flag=1;
        	    cout<<"\n\nSearching.";
	            for(int i=0;i<=10;i++){
		            cout<<".";
		            Sleep(100);
                }
                fstream outfile;
                outfile.open("Patient_History.dat",ios::app|ios::out|ios::binary);
                cout<<"\n\t\t\t*****************************************\n";
                cout<<"\t\t\t\t ENTER DIAGNOSIS INFORMATION";
                cout<<"\n\t\t\t*****************************************\n\n";
                cout<<"\n\t\t Register number :-  ";
                cout<<reg_num;
                cout<<endl;
                cout<<"\n\t\t Name :-  ";
                cout<<name;
                cout<<endl;
                setInfo();
                outfile.write((char*)this,sizeof(Hospital)); 
                outfile.close();
                break;
            }
        }
    }
    if(flag==0){
        cout<<"data not found";
    }
}
//---------------------------------------------------------------
void Hospital ::showData()
{
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tPatient Card  ";
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t Register number : "<<reg_num<<endl;
 	cout<<"\t\t\t\t\t\t\t\t\t Name : "<<name<<endl;
   	cout<<"\t\t\t\t\t\t\t\t\t Bed number : "<<bed_no<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Your age  "<<age<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Profession  : "<<profession<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Gender  : "<<gender<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Blood group : "<<bloodGroup<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Address : "<<address<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Mobile number : "<<mobileNumber<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t";Hospital::date();
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n\n";  
}
//---------------------------------------
void Hospital::show_history(){
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tPatient History  ";
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t Name : "<<name<<endl;
 	cout<<"\t\t\t\t\t\t\t\t\t Symptoms : "<<symptoms<<endl;
   	cout<<"\t\t\t\t\t\t\t\t\t Diagnosis : "<<diagnosis<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Blood pressure  :"<<bloodPressure<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Body temperature  : "<<temperature<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t Admission : "<<ward<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t";Hospital::date();
    cout<<"\n\t\t\t\t\t\t\t\t\t*****************************************\n\n";  
}
//----------------------------------------------------
void Hospital::show_history_file(){
    fstream infile("Patient_History.dat",ios::binary|ios::in);
    while(!infile.eof()){
        if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))){
            show_history();
        }
    }
}
//------------------------------------------
void Hospital::showList()//  assigns each records in the table list after the header given by show() 
{
    cout<<"\n";
    cout<<setw(20)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<reg_num;
    cout<<setw(15)<<bed_no;
    cout<<setw(15)<<age;
    cout<<setw(15)<<profession;
    cout<<setw(15)<<bloodGroup;
    cout<<setw(15)<<gender;
    cout<<setw(15)<<mobileNumber;
    cout<<setw(15)<<address;
    cout<<setw(15)<<ward;
    
    
}
//--------------------------------------------------
void Hospital::patient_history()
{
	fstream infile("Patient_History.dat",ios::binary|ios::in);
	int check;
    int find1;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t Searching Patient History.... ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter patient registration number: "<<endl;
  	cin>>find1;
    while(!infile.eof())
    {
	    if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))){
            if(reg_num==find1)
            {
                check=1;
        	    cout<<"\n\nSearching.";
	            for(int i=0;i<=10;i++){
		            cout<<".";
		            Sleep(100);
                }
	            show_history_file();
                break;
            }
		    }
    }
    if(check==0)
    {
    cout<<"SORRY!! No patient was found."<<endl;
    }
    getch();
    infile.close();
}
void Hospital::patient_card()
{
	ifstream in;//read garna kholeko from file
	in.open("Patient_History.dat");
	int flag;
    int find2;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t Searching Patient Card.... ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter patient registration number: "<<endl;
  	cin>>find2;
    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(find2==reg_num)
        {
        	  cout<<"\n\nSearching.";
	for(int i=0;i<=10;i++){
		cout<<".";
		Sleep(100);
    }
        Hospital::show_history_file();	
        flag=1;
        fstream infile; 
        infile.open("Patient_History.dat",ios::app|ios::binary);
        setInfo();
        Hospital::date();
        infile.seekp((0)*sizeof(*this));
        infile.write(reinterpret_cast<char*>(this),sizeof(*this));
        infile.close();
        break;
        }
    }
    }
        if(flag==0)
		{
			cout<< "There is no record of such type";
		}
        in.close();      
}
//--------------------------------------------------------
void Hospital::searchData()//   menu when you enter search
{
    Hospital item;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\tSEARCHING STATISTICS";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"From which option you want to perform searching "<<endl;
    cout<<"\n\t\t 1. By Name. \t\t\t\t 2. By Age "<<endl;
    cout<<"\n\t\t 3. By Diagnosis \t\t\t 4. By Gender "<<endl;
    cout<<"\n\t\t 5. Back to Main Menu "<<endl;
    cout<<"\n\n\t\tEnter your choice : ";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        search_by_name();
        getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        getch();
        break;
    case 3:
        system("cls");
        search_by_diagnosis();
        getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        getch();
        break;
    case 5:
    	system("cls");
        menu();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
//------------------------------------------------
void Hospital::search_by_name()
{
    ifstream in;//read garna kholeko from file
	in.open("Hospital.dat");
	int flag;
    char cs[100];
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t NAME SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter your name: "<<endl;
  	fflush(stdin);
    gets(cs);

    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(cs,name)==0)
        {
        	  cout<<"\n\nSearching.";
	for(int i=0;i<=10;i++){
		cout<<".";
		Sleep(100);
	}
            
		    show();//table header list while showing data
            showList();//table header bhanda tala ko data 
            flag=1;
        }
		}
    }
    if(flag=0)
    {
    	    cout<<"Name you entered doesnot exist";
	}
    in.close();

}
//---------------------------------------------------
void Hospital::search_by_age()//6.2
{
   ifstream in;
   in.open("Hospital.dat");
    int flag =0;
    int a;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t AGE SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter Age by which you want to search "<<endl;
    cin>>a;
    
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(a==this->age)
        {	
		      cout<<"\n\nSearching.";
	for(int i=0;i<=10;i++){
		cout<<".";
		Sleep(100);
	}
		show();
            showList();
            flag=1; 
        }
		}
    }
    if(flag==0)
    {
    cout<<"Age you entered is not found"<<endl;
    }
    in.close();

}
//----------------------------------------------------------------------------------
void Hospital::search_by_diagnosis()
{
    ifstream in;
	in.open("Patient_History.dat");
    int flag =0;
    char pf[100];
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t DIAGNOSIS SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter Diagnosis by which you want to search:"<<endl;
    fflush(stdin);
    gets(pf);
    
   while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(strcmp(pf,diagnosis)==0)
        {	
		       cout<<"\n\nSearching.";
	for(int i=0;i<=10;i++){
		cout<<".";
		Sleep(100);
	}
		show();
            showList();
            flag=1;
            return;   
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this diagnosis was found."<<endl;
    }
    in.close();
}
//-------------------------------------------------------------------
void Hospital::search_by_gender()
{
    ifstream in("Hospital.dat");
    int flag =0;
    char g;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t GENDER SEARCHING ";
    cout<<"\n\t\t\t*****************************************\n\n";
    cout<<"Enter gender by which you want to search "<<endl;
    cin>>g;
    
    while(!in.eof())
	{
	if(in.read(reinterpret_cast<char*>(this),sizeof(*this))){

        if(g==this->gender)
        {	
		       cout<<"\n\nSearching.";
	for(int i=0;i<=10;i++){
		cout<<".";
		Sleep(100);
	}
		show();
            showList();
            flag=1;	
        }
		}
    }
    if(flag==0)
    {
    cout<<"SORRY!! No people by this Gender was found."<<endl;
    }
    in.close();
}
//---------------------------------------------------------
void Hospital::modify()
{
	ifstream in("Hospital.dat");
    int n;
    Hospital v;
    v.view_all();
    int i=0;
    in.seekg(0,ios::beg);
    while(in.read((char*)this,sizeof(Hospital)))
    {
    	i++;
	}
	in.close();
	cout<<"\nEnter the S.N. to modify:";
	cin>>n;
	if(n<=i&&n>0){
	
    cout<<"\t\t\t\t MODIFYING........................ ";
    	
		
		
            fstream infile; 
            infile.open("Hospital.dat",ios::in|ios::out|ios::binary);
            setData();
            infile.seekp((n-1)*sizeof(*this));
            infile.write(reinterpret_cast<char*>(this),sizeof(*this));
            infile.close();      
		    cout<<"\nSuccessfully Modified";
			
			getch();}
			else
			{
				cout<< "There is no record of such type";
				getch();
				}     
}
//------------------------------------------------------
void Hospital::view_all()
{
			fstream outfile;
			outfile.open("Hospital.dat",ios::binary|ios::in);//Opened to read
			if(!outfile){
				cout<<"File doesnot exist";
				getch();
			}
			else{
					cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    		cout<<"\n\t\t\t*****************************************\n";
    		cout<<"\t\t\t\t\tALL DATA ";
    		cout<<"\n\t\t\t*****************************************\n\n";
			show();//header
			while(!outfile.eof()){
				if(outfile.read(reinterpret_cast<char*>(this),sizeof(*this))){
					showList();//sab data dekhaidinxa
				}
				
			}
			cout<<"\n\n\t\tPRESS ANY KEY .... ";
			getch();
			}
		
			outfile.close();
}
//------------------------------------------------------------
void Hospital::del()
{
	cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t Delete in process..............";
    cout<<"\n\t\t\t*****************************************\n\n";
		ifstream in("Hospital.dat");
		fstream tmpfile("temp.dat",ios::out|ios::binary);//To write on it
        Hospital v;
        v.view_all();
         int n,i=0;
         cout<<"\n***Enter record number to delete: ";
         cin>>n;
    while(!in.eof())
    {
    	if(in.read(reinterpret_cast<char*>(this),sizeof(*this)))
    	{
    		i=i+1;
    		if(i!=n)
    		{ 
    		 tmpfile.write(reinterpret_cast<char*>(this),sizeof(*this));
			}
		}
	}
	
	
	getch();
    in.close();
    tmpfile.close();
    remove("Hospital.dat");
    rename("temp.dat","Hospital.dat");
}
//--------------------------------------------------------------------
//-----------------------------------------------------
void show()//  Header
{
	cout<<"\n\n\n";
	
    cout<<setw(20)<<setiosflags(ios::left)<<"Name";
    cout<<setw(20)<<"Registration number";
    cout<<setw(15)<<"Bed number";
    cout<<setw(15)<<"Age";
    cout<<setw(15)<<"Profession";
    cout<<setw(15)<<"Blood group";
    cout<<setw(15)<<"Gender";
    cout<<setw(15)<<"Mobile No";
    cout<<setw(15)<<"Address";
}
//-------------------------------------------------


//----------------------------------------------------------------------
int password()//
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\t\t\t\t\tPASSWORD:    ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\tCaptcha:-> "<<cap<<endl;
    cout<<" Please enter the valid captcha :-   ";
    cin>>capt;
    if( (strcmp(cname,"sigma")==0) && (strcmp(pass,"123")==0) && cap==capt)
        return 1;
    else
        return 0;
}
//----------------------------------------
void menu()//  display the functionalites of this program
{
    system("cls");
    cout<<"\n\n\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\t\t\t\t WELCOME TO THE MAIN MENU";
    cout<<"\n\t\t\t*****************************************\n";
    cout<<"\n\t\t1: Add New Record\t\t\t 2: View All Data"<<endl;
    cout<<"\n\t\t3: Search\t\t\t\t 4: Modify"<<endl;
    cout<<"\n\t\t5: Delete \t\t\t\t 6: Patient History"<<endl;
    cout<<"\n\t\t7: Patient card \t\t\t\t 9: Add History"<<endl;
	cout<<"\t\t\t\t\t8: Exit"<<endl;
    
}
//----------------------------------------
int main()//     MAINFUNCTION
 { 
    Hospital obj;
    system("Color 30");
    int k=3;
    int num_vac;
    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
    cout<<"\t\n\n Press any key to continue.............  "<<endl;
    getch();
    B:
    system("cls");
    cout<<"  \n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO LOGIN PAGE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    cout<<"\n\n\t\t\t\t*********************************************";
    cout<<"\n\t\t\t\t\tEnter User name and Password\n";
    cout<<"\t\t\t\t*********************************************\n";
    //Loading screen complete and here asks for username and password
    while(k>=1)
    {
    int c = password();
    if(c==1)
        break;
    else
        cout<<"\n\n\t\t Wrong Password Or User Name \n\n\t\t You Can try Only "<<k-1<<" times more";
    k--;
    if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
              system("cls");
              cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tYOU ARE BLOCKED FOR 1 MINUTE!!";
              cout<<"\n\n\n\n\n\n\t\t\t\t\tTRY AFTER "<<i<<" SECONDS.....";
              Sleep(1000);
            }
              k=3;
              goto B;
        }
    }
      int ch;
      do{
            cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 HOSPITAL MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"<<endl;
            menu();//List for showing the all the functions we can do . 
            cout<<"\n\t\n\tChoose according to your need : ";
            cin>>ch;
             Hospital v1;
      switch(ch)
       {
        case 1: system("cls");
	            obj.addNew();
                break;   
        case 2:system("cls");
            	obj.view_all();
                break;
        case 3:system("cls");
            	obj.searchData();
                break;
        case 4:system("cls");
            	obj.modify();
            	break;
        case 5:system("cls");
            	obj.del();
            	break;    
        case 6:system("cls");
                obj.patient_history();
                break;	
        case 7:system("cls");
                obj.patient_card();
                break;
        case 9:system("cls");
                obj.addHistory();
                break;
        case 8: system("cls");
                exit(0);
            
        default: system("cls");
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
                cout<<"\n\n\t\t\t\t\t****HAVE A NICE DAY*****";
                Sleep(3000);
                exit(0);
       }
      }while(ch!=0);

      return 0;
}
