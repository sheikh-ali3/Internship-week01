#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace  std;

int main()
{
	string section, n;
	char c;
	int students, s;
	vector<string> names;
	vector<float> start, end, diff;
	
	cout<<"Welcome to Student Weight Management System\n";
	cout<<"Choose one from below menu:\n";
	cout<<" Enter 1 to add a new record\n Enter 2 to view records \n";
	here:
	c=_getwch();
	
	if(c == '1')
	{		
		cout<<"eneter the name of section: ";
		getline(cin, section);
				
		cout<<"enter the number of students in class: ";
		cin>>students;
	
		for(int i=0; i<students; i++)
		{
			cout<<"enter student name: ";
			cin.ignore();
			getline(cin, n);
			names.push_back(n);
			
			cout<<"enter weight at begining of term: ";
		again:
			cin>> s;
			if(s >= 0)
			{
				start.push_back(s);
			}
			else
			{
				cout<<"you enetred an invalid number .... retry!!";
				goto again;
			}
			cout<<"Enter weight at end of term: ";
		retry:
			cin>>s;
			if(s >= 0)
			{
				end.push_back(s);
			}
			else
			{
				cout<<"you entered an invalid number .... retry!!";
				goto retry;
			}
			
			for(int i=0; i<start.size(); i++)
			{
				diff[i] = start[i]-end[i];
			}
		}
			
		ofstream file;
		file.open(section + ".txt");
		for(int i=0; i<students; i++)	
		{
			file<<names[i]<<" : ";
			file<<start[i]<<" ; ";
			file<<end[i]<<"\n";
		}
		file.close();	
	}			
	else if(c =='2')
	{
		string line;
		cout<<"Enter name of section to view record: ";
		cin>>section;
			
		ifstream file;
		file.open(section + ".txt");
		while(!file.eof())
		{
			getline(file, line);
			cout<<line<<"\n";
		}
		file.close();
	}
	else
	{
		cout<<"wrong choice retry!!\n";
		goto here;
	}
	
	return 0;
}