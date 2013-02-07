#include <cstring>
#include "Student.h"

Student::Student(int age, const char *last_name, const char *first_name, const char *email, const char *ssn)
{
	this->mAge = age;
  this->mLastName = last_name;
  this->mFirstName = first_name;
  this->mEmail = email;
  this->mSSN = ssn;
}

// set methods
bool Student::SetAge(int age)
{
  this->mAge = age;
  return true;
}

bool Student::SetLastName(char *last_name)
{
  this->mLastName = last_name;
  return true;
}

bool Student::SetFirstName(char *first_name)
{
  this->mFirstName = first_name;
  return true;
}

bool Student::SetEmail(char *email)
{
  this->mEmail = email;
  return true;
}

bool Student::SetSsn(char *ssn)
{
  this->mSSN = ssn;
  return true;
}

// get methods
int Student::GetAge()
{
  return mAge;
}

char * Student::GetLastName()
{
  return mLastName;
}

char * Student::GetFirstName()
{
  return mFirstName;
}

char * Student::GetEmail()
{
  return mEmail;
}

char * Student::GetSsn()
{
  return mSSN;
}