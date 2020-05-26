#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


//functions prototypes
void insert_record();
void search_student();
void list_student();
void delete_record();
void archived_students();
void edit_record(); 
int courses_menu();
int id_validation();
void save_file();
void read_file();
int reg_validation();
int choose_section(int );
void read_counters();
void save_counters();





//global index variable
int index=0;

//global index of archived Students 
int ar_index=0;

//variales 
int reg_number[400];
int id_number [400];
int course_sec [400];

string stu_name [400];
string stu_name2[400];
string course_name [400];


//variales of archived Students 
int ar_reg_number[400];
int ar_id_number [400];
int ar_course_sec [400];

string ar_stu_name [400];
string ar_stu_name2[400];
string ar_course_name [400];

// counters to limit the sections
int course1_1=0, course1_2=0,course1_3=0, course1_4=0, course1_5=0, course1_6=0, course1_7=0, course1_8=0, course1_9=0, course1_10=0;
int course2_1=0, course2_2=0,course2_3=0, course2_4=0, course2_5=0, course2_6=0, course2_7=0, course2_8=0, course2_9=0, course2_10=0;




int main()
{
	//reading all information in the files so we do not have to read it many times again 
	read_file();
	read_counters();
 
	int choice;
	cout<<" Welcome to our student storage system in Qatar Learning Center\n";
	cout<<"In our system you preform any of the following functions:\n";
	cout<<"-------------------------------------------------------"<<endl;


		do
		{
			cout<<"1)Insert New Record\n";
			cout<<"2)Search for a Student Information\n";
			cout<<"3)Edit a Record Information\n";
			cout<<"4)Delete a Record\n";
			cout<<"5)List All The Current Students\n";
			cout<<"6)List All The Deleted Students Information\n";
			cout<<"7)Exit \n"<<endl;

			cout<<"Which fuction would you like execute:";
			cin>>choice;
			cout<<endl<<endl;

				switch(choice)
				{
					case 1:  insert_record();
						break;

					case 2: read_file();search_student();
						break;

					case 3:  read_file();edit_record(); 
						break;

					case 4:
							delete_record();
						break;

					case 5: read_file(); list_student();
						break;

					case 6: archived_students();
						break;

					case 7: save_file();
								save_counters();
								break;

					default: cout<<"INVALID CHOICE\n";

						break;
			}


		}while(choice!=7);
        return 0;

}

//******************************************************************
//               Function to insert the new record                 *
//******************************************************************

void  insert_record()
{ 
int name_choice;
int answer;
do{

	cout<<"Enter the Following Information\n";
	cout<<"Registration Number:"; reg_number[index]= reg_validation();
	cout<<"Student's First Name:"; cin >> stu_name[index];
	cout<<"Student's Second Name:";cin >> stu_name2[index];
	cout<<"Student's ID number:"; id_number[index]=id_validation();

	//choosing course name
	cout<<"Select one of the following courses:"; 
 
	name_choice= courses_menu();
 
 
	switch(name_choice)
	{
		case 1: course_name [index]= "English1";
			break;

		case 2:course_name [index]= "C++";
			break;

		case 3:course_name [index]= "Calculus";
			break;

		case 4:course_name [index]= "Calculus2";
			break;

		case 5:course_name [index]= "Chemistry";
			break;

		case 6:course_name [index]= "Physics";
			break;

		case 7:course_name [index]= "Graphics";
			break;

		case 8:course_name [index]= "Calculus3";
			break;

		case 9:course_name [index]= "Statistics";
			break;

		case 10: course_name [index]= "Physics2";
			break;
	}
 
 
	cout<<"Select a Course Section:";course_sec[index]=choose_section(index);
	cout<<endl<<endl;

	index++;

	cout << "\n\nRecord ucessfully added\n\n";
	//repeation of funtion
	cout<<"To Enter Anohter Student Enter 1 to Contiue Select Any Other int Value:";

	cin >> answer;
}while(answer==1);
	// save inserted students 
	save_file();
	save_counters();
}

//*************************************************
//         Search for student information         *
//*************************************************

void search_student(){
	int id;
	int valid=3;
	cout<<"Enter The ID number:";
	id= id_validation();
	cout<<endl;

	cout<<"              The Student You Searched for                  "<<endl<<endl;
	cout<<left<<setw(10)<<"Reg Num"<<left<<setw(10)<<"First Name"<<"  "<<left<<setw(10)<<"last Name"<<left<<setw(10)
         <<"ID #"<<left<<setw(10) <<"Course"<<left<<setw(10)<<"Section"<<endl;
	cout<<"____________________________________________________________"<<endl;

		for (int i=0; i<index; i++)
		{

			if(id_number[i]==id)
			{
					cout<<left<<setw(10)<<reg_number[i]<<left<<setw(10)<<stu_name [i]<<"  "<<left<<setw(10)<<stu_name2[i]<<left<<setw(10)
						<< id_number [i]<<left<<setw(10) <<course_name [i]<<left<<setw(10)<<course_sec [i]<<endl<<endl;

					valid=5;
			}
		}
	cout<<endl;
	// if the funcion did not find the ID
	if(valid!=5)
	cout<<"STUDENT DOES NOT EXIST\n\n"<<endl;
 

}

//*************************************************
//         List all the current students          *
//*************************************************

void list_student()
{

	cout<<"              All Current Students                  "<<endl<<endl;
	cout<<left<<setw(10)<<"Reg Num"<<left<<setw(10)<<"First Name"<<"  "<<left<<setw(10)<<"last Name"<<left<<setw(10)
		<<"ID #"<<left<<setw(10) <<"Course"<<left<<setw(10)<<"Section"<<endl;
	cout<<"____________________________________________________________"<<endl;
		for (int i=0; i<index; i++)
		{
 

 
				cout<<left<<setw(10)<<reg_number[i]<<left<<setw(10)<<stu_name [i]<<"  "<<left<<setw(10)<<stu_name2[i]<<left<<setw(10)
					<< id_number [i]<<left<<setw(10) <<course_name [i]<<left<<setw(10)<<course_sec [i]<<endl<<endl;
 
 
		}

 
}


//*************************************************
//         delete student                         *
//*************************************************

void delete_record()
{
 

	int valid=3;
	int reg;
	cout<<"Enter Your  Registration Number :"<<endl;
	cin>>reg;
	cout<<endl;

 

		for (int i=0; i<index; i++)
		{
			if(reg_number[i]==reg)
			{
 
 
				//assiging the deleted record to the archived students arrays
				ar_reg_number[ar_index]=reg_number[i];
 
				ar_stu_name[ar_index]=stu_name [i];

				ar_stu_name2[ar_index]=stu_name2[i];  
 
				ar_id_number[ar_index]= id_number [i];
 
				ar_course_name[ar_index]=course_name [i];
 
				ar_course_sec[ar_index]=course_sec [i];
 
				ar_index++;

			// decrement the number of the deleted section
			if(course_name [i]== "English1")
			{
				if(course_sec [i]==1)
					course1_1 -=1;
				else if (course_sec [i]==2)
					course2_1-=1;
			}
				else if(course_name [i]=="C++")
				{
					if(course_sec [i]==1)
					course1_2 -=1;
				else if (course_sec [i]==2)
					course2_2-=1;
				}

				else if(course_name [i]=="Calculus")
				{
					if(course_sec [i]==1)
					course1_3-=1;
				else if (course_sec [i]==2)
					course2_3-=1;
				}
				
				else if(course_name [i]=="Calculus2")
				{
					if(course_sec [i]==1)
					course1_4 -=1;
				else if (course_sec [i]==2)
					course2_4 -=1;
				}
				
				else if(course_name [i]=="Chemistry")
				{
					if(course_sec [i]==1)
					course1_5 -=1;
				else if (course_sec [i]==2)
					course2_5-=1;
				}
				
				else if(course_name [i]=="Physics")
				{
					if(course_sec [i]==1)
					course1_6 -=1;
				else if (course_sec [i]==2)
					course2_6 -=1;
				}
				
				else if(course_name [i]=="Graphics")
				{
					if(course_sec [i]==1)
					course1_7 -=1;
				else if (course_sec [i]==2)
					course2_7-=1;
				}
				
				else if(course_name [i]=="Calculus3")
				{
					if(course_sec [i]==1)
					course1_8 -=1;
				else if (course_sec [i]==2)
					course2_8 -=1;
				}
				
				else if(course_name [i]=="Statistics")
				{
					if(course_sec [i]==1)
					course1_9 -=1;
				else if (course_sec [i]==2)
					course2_9 -=1;
				}
				
				else if(course_name [i]=="Physics2")
				{
					if(course_sec [i]==1)
					course1_10 -=1;
				else if (course_sec [i]==2)
					course2_10 -=1;
				}
 

				// fill the deleted array 
				for(int f=i; f<index; f++)
				{

				reg_number[f]=reg_number[f+1];
 
				stu_name[f]=stu_name [f+1];

				stu_name2[f]=stu_name2[f+1];  
 
				id_number[f]= id_number [f+1];
 
				course_name[f]= course_name [f+1];
 
				course_sec[f]=course_sec [f+1];
 
			}

			index--;

			cout<<"Recored Sucessfully Deleted \n\n";
			valid=5;
			}
 
			}
 
 
			cout<<endl;

	// if the funcion did not find the registration number
	if(valid!=5)
		cout<<"STUDENT NOT FOUND\n\n"<<endl;
	save_file();

}


//*************************************************
//        List all the archived students          *
//*************************************************

void archived_students()
{
	cout<<"              All Archived                  "<<endl<<endl;
	cout<<left<<setw(10)<<"Reg Num"<<left<<setw(10)<<"First Name"<<"  "<<left<<setw(10)<<"last Name"<<left<<setw(10)
		<<"ID #"<<left<<setw(10) <<"Course"<<left<<setw(10)<<"Section"<<endl;
	cout<<"____________________________________________________________"<<endl;
 

		for (int i=0; i<ar_index; i++)
		{
 
 
				cout<<left<<setw(10)<< ar_reg_number[i]<<left<<setw(10)<< ar_stu_name [i]<<"  "<<left<<setw(10)<<ar_stu_name2[i]<<left<<setw(10)
					<<  ar_id_number [i]<<left<<setw(10)<< ar_course_name [i]<<left<<setw(10)<< ar_course_sec [i]<<endl<<endl;
 
		}
}

//*************************************************
//                 Edit a record                  *
//*************************************************

void edit_record()
{
	bool course_choice=0;
	int valid=3, answer;
	int reg, sec;
	//int choice
	int user_choice;
	//string choice 
	string user_choice2, user_choice3;

	cout<<"Enter The Registration Number for the STudent you like to edit:";
	cin>>reg;
	cout<<endl;
	cout<<"              EDIT                 "<<endl<<endl;
	cout<<left<<setw(10)<<"Reg Num"<<left<<setw(10)<<"First Name"<<"  "<<left<<setw(10)<<"last Name"<<left<<setw(10)
		<<"ID #"<<left<<setw(10) <<"Course"<<left<<setw(10)<<"Section"<<endl;
	cout<<"____________________________________________________________"<<endl;
		for (int i=0; i<index; i++)
		{
			if(reg_number[i]==reg)
			{
 
				cout<<left<<setw(10)<<reg_number[i]<<left<<setw(10)<<stu_name [i]<<"  "<<left<<setw(10)<<stu_name2[i]<<left<<setw(10)
					<< id_number [i]<<left<<setw(10) <<course_name [i]<<left<<setw(10)<<course_sec [i]<<endl<<endl;
					do
					{
						cout<<"What Field You Want to Edit? (Select the Appropriate Choice)/n"<<endl;
						cout<<"1)Student Name\n2)ID Number\n3)Course Name\n4)Course Section\n5)Non of These Go Back\n";
						cout<<"Choice :";
						cin>>answer;
						cout<<endl;

						switch(answer)
						{
								case 1: cout<<"Enter The Student's New First Name :";
									cin>>user_choice2;
									cout<<endl;
									stu_name[i]=user_choice2;
									cout<<"Enter The Student's New Second Name :";
									cin>>user_choice2;
									cout<<endl;
									stu_name2[i]=user_choice2;
									break;

								case 2: cout<<"Enter The Student's New ID Number:";
 
									id_number [i]=id_validation();
									break;

								case 3:  cout<<"Choose The New Course:\n"; 
 
									user_choice= courses_menu();
 
 
										switch(user_choice)
										{
											case 1: course_name [i]= "English1";
												break;

											case 2:course_name [i]= "C++";
												break;

											case 3:course_name [i]= "Calculus";
												break;

											case 4:course_name [i]= "Calculus2";
												break;

											case 5:course_name [i]= "Chemistry";
												break;

											case 6:course_name [i]= "Physics";
												break;

											case 7:course_name [i]= "Graphics";
												break;

											case 8:course_name [i]= "Calculus3";
												break;

											case 9:course_name [i]= "Statistics";
												break;

											case 10: course_name [i]= "Physics2";
												break;

 
									}
 
		break;
	// endl of case 3
	case 4: 
	
	// decrement the number of the edited section
			if(course_name [i]== "English1")
			{
				if(course_sec [i]==1)
					course1_1 -=1;
				else if (course_sec [i]==2)
					course2_1-=1;
			}
				else if(course_name [i]=="C++")
				{
					if(course_sec [i]==1)
					course1_2 -=1;
				else if (course_sec [i]==2)
					course2_2-=1;
				}

				else if(course_name [i]=="Calculus")
				{
					if(course_sec [i]==1)
					course1_3-=1;
				else if (course_sec [i]==2)
					course2_3-=1;
				}
				
				else if(course_name [i]=="Calculus2")
				{
					if(course_sec [i]==1)
					course1_4 -=1;
				else if (course_sec [i]==2)
					course2_4 -=1;
				}
				
				else if(course_name [i]=="Chemistry")
				{
					if(course_sec [i]==1)
					course1_5 -=1;
				else if (course_sec [i]==2)
					course2_5-=1;
				}
				
				else if(course_name [i]=="Physics")
				{
					if(course_sec [i]==1)
					course1_6 -=1;
				else if (course_sec [i]==2)
					course2_6 -=1;
				}
				
				else if(course_name [i]=="Graphics")
				{
					if(course_sec [i]==1)
					course1_7 -=1;
				else if (course_sec [i]==2)
					course2_7-=1;
				}
				
				else if(course_name [i]=="Calculus3")
				{
					if(course_sec [i]==1)
					course1_8 -=1;
				else if (course_sec [i]==2)
					course2_8 -=1;
				}
				
				else if(course_name [i]=="Statistics")
				{
					if(course_sec [i]==1)
					course1_9 -=1;
				else if (course_sec [i]==2)
					course2_9 -=1;
				}
				
				else if(course_name [i]=="Physics2")
				{
					if(course_sec [i]==1)
					course1_10 -=1;
				else if (course_sec [i]==2)
					course2_10 -=1;
				}

				// allow the user to change his/her section number
				course_sec[i]=choose_section(i);
			 break;


		case 5:  
			break;

		default: cout<<"wrong choice\n";
            break;

					}
	cout<<"record successfuly edited\n\n";
		valid=4;

}while(answer!=5);
}
}
 
	cout<<endl;
	// if the funcion did not find the registration number
	if(valid!=4)
	cout<<"student not found\n\n"<<endl;
	// save edited information
	save_file();

}

//*************************
//      choosing section  *
//*************************
int choose_section(int i)
	{
		int sec;
		int choice;

		cout<<"\n1)Section 1\n2)Section 2\n"<<endl;
		
		cout<<"Section Choice:";
		cin>>sec;

		switch(sec)
		{
		case 1: if(course_name [i]== "English1")
				{
					if(course1_1<20)
						course1_1 +=1;

					else { cout<<"this section is full\n";
					cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
				    return sec;
				}

				else if(course_name [i]=="C++")
				{
					if(course1_2<20)
						course1_2 +=1;
					else {cout<<"this section is full\n\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}

				else if(course_name [i]=="Calculus")
				{
					if(course1_3<20)
						course1_3 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Calculus2")
				{
					if(course1_4<20)
						course1_4 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Chemistry")
				{
					if(course1_5<20)
						course1_5 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Physics")
				{
					if(course1_6<20)
						course1_6 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Graphics")
				{
					if(course1_7<20)
						course1_7 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Calculus3")
				{
					if(course1_8<20)
						course1_8+=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Statistics")
				{
					if(course1_9<20)
						course1_9 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Physics2")
				{
					if(course1_10<20)
						course1_10+=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}

			break;
		case 2:	
			if(course_name [i]== "English1")
				{
					if(course2_1<20)
						course2_1 +=1;

					else { cout<<"this section is full\n";
					cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}

				else if(course_name [i]=="C++")
				{
					if(course2_2<20)
						course2_2 +=1;
					else {cout<<"this section is full\n\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}

				else if(course_name [i]=="Calculus")
				{
					if(course2_3<20)
						course2_3 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Calculus2")
				{
					if(course2_4<20)
						course2_4 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Chemistry")
				{
					if(course2_5<20)
						course2_5 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Physics")
				{
					if(course2_6<20)
						course2_6 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Graphics")
				{
					if(course2_7<20)
						course2_7 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Calculus3")
				{
					if(course2_8<20)
						course2_8+=1;
					else {cout<<"this section is full\n";
					cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Statistics")
				{
					if(course2_9<20)
						course2_9 +=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}
				
				else if(course_name [i]=="Physics2")
				{
					if(course2_10<20)
						course2_10+=1;
					else {cout<<"this section is full\n";
				cout<<"1- Section 1\n2- Section 2\n"<<endl;
					cin>>sec;
					}
					return sec;
				}


			break;

		
	}
	}

//**********************************************
//                Menue of cources             *
//**********************************************
int courses_menu()
{
int x;
cout<<"\n1)English1\n2)C++\n3)Calculus\n4)Calculus2\n5)Chemistry\n6)Physics\n7)Graphics\n8)Calculus3\n9)Statistics\n10)Physics2\n";
 cout<<"\nChoice:";
cin>>x;
return x;
}


//*******************************************
//         Registration number  validation  *
//*******************************************
int reg_validation()
{
	int reg;
	cin>>reg;
	for(int i=0;i<index;i++)
	{
		while( reg_number[i]== reg || ar_reg_number[i]== reg)
		{
			cout<<"Registration number is already in use enter an other:";
			cin>>reg;
			cout<<endl;
		}
	}

return reg;
}





//*************************
//         ID validation  *
//*************************

int id_validation()
{
	int id;
	cin>>id;

// ID validation
	while(id<100000000 || id>999999999)
	{
		cout<<"ID NUMBER MUST CONTAIN DIGITS\n";
		cout<<"Enter another number:";
		cin>>id;
		cout<<endl;
	}
	return id;
}

//*****************************
//           save to file     *
//*****************************
void save_file()
{ 
ofstream ofile;
ofile.open("students.txt");
 
	for(int i=0; i<index;i++)
	{
 
		ofile<<left<<setw(10)<<reg_number[i]<<left<<setw(10)<<stu_name [i]<<left<<setw(10)<<stu_name2[i]<<left<<setw(10)<< id_number [i]<<left<<setw(10)
			<<course_name [i]<<left<<setw(10)<<course_sec [i]<<left<<setw(10);

		ofile<<endl;
 
	}

	ofile.close();

	// save archived students 
	ofstream ar_ofile;
 
	ar_ofile.open("archivedstudents.txt");
 

	for(int i=0; i<ar_index;i++)
	{
 
		ar_ofile<<setw(10)<<left<<ar_reg_number[i]<<setw(10)<<left<<ar_stu_name [i]<<setw(10)<<left<< ar_stu_name2[i]
			<<setw(10)<<left<< ar_id_number [i]<<setw(10)<<left<< ar_course_name [i]<<setw(10)<<left<< ar_course_sec [i]<<setw(10)<<left;
		ar_ofile<<endl;
 
	}

	ar_ofile.close();
}

//*********************
//    read from file  *
//*********************

void read_file()
{
 
ifstream infile;
       infile.open("students.txt");
      if (!infile)
       {
              cout << "\n Error opening file \n" << endl;
       }
 
       else
       { 
  
         
                 for(int i=index= 0;infile >>  reg_number [i] >> stu_name [i] >> stu_name2[i]>>id_number[i]>>course_name[i]>>course_sec[i] ; i++)
                     {
     index++;
                     }
  
}
       infile.close();
       
 
  //read achived students
  ifstream ar_infile;
       ar_infile.open("archivedstudents.txt");
 
       if (!ar_infile)
       {
              cout << "\n Error opening archive file \n" << endl;
       }
 
       else
       { 
                     for(int i=ar_index= 0; ar_infile >> ar_reg_number [i] >> ar_stu_name [i] >> ar_stu_name2[i]>>ar_id_number[i]>>ar_course_name[i]>>ar_course_sec[i]; i++)
                     {

                            ar_index++;
                    
                     }
 
       ar_infile.close();
       }





}

//save the conters of sections
	void save_counters()
	{
		ofstream ofile;
		ofile.open("counters.txt");
		
		ofile<<course1_1<<"\t"<<course1_2<<"\t"<<course1_3<<"\t"<< course1_4<<"\t"<< course1_5<<"\t"<< course1_6<<"\t"<< course1_7<<"\t"<< course1_8<<"\t"<< course1_9<<"\t"<< course1_10<<"\t";
		ofile<<endl;
		ofile<<course2_1<<"\t"<<course2_2<<"\t"<<course2_3<<"\t"<< course2_4<<"\t"<< course2_5<<"\t"<< course2_6<<"\t"<< course2_7<<"\t"<< course2_8<<"\t"<< course2_9<<"\t"<< course2_10<<"\t";
	
	}

	//read the conters of sections
	void read_counters()
	{
		ifstream ifile;
		ifile.open("counters.txt");
			ifile>>course1_1>>course1_2>>course1_3>> course1_4>> course1_5>> course1_6>> course1_7>> course1_8>> course1_9>> course1_10;
			ifile>>course2_1>>course2_2>>course2_3>> course2_4>> course2_5>> course2_6>> course2_7>> course2_8>> course2_9>> course2_10;
	}