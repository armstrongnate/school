#include <iostream>
#include "Student.h"
#include <fstream>

int main()
{ 
	char mLastName[15];
	char mFirstName[15];
	char mEmail[30];
	char mSsn[12];
	int mAge;

	std::ifstream myfile;
	myfile.open("testnames.txt");
	while(! myfile.eof())
	{

		myfile >> mLastName >> mFirstName >> mSsn >> mEmail >> mAge >> std::ws;
		Student nStudent(mLastName, mFirstName, mSsn, mEmail, mAge);
		Student mNStudent;
		StudentLinkedList sList;
		if(!sList.Exists(nStudent))
		{
			sList.AddStudent(nStudent);
			mNStudent = sList.RetrieveStudent(nStudent);
			std::cout << mNStudent.GetSsn() << std::endl;
		}
	}
	myfile.close();
  
return 0;
}

