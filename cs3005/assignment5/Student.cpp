#include <cstring>
#include "Student.h"

Student::Student(int age, const char *last_name, const char *first_name, const char *email, const char *ssn)
{
	this->mAge = age;
  std::strcpy(this->mLastName, last_name);
  std::strcpy(this->mFirstName, first_name);
  std::strcpy(this->mEmail, email);
  std::strcpy(this->mSSN, ssn);
}

// set methods
bool Student::SetAge(int age)
{
  this->mAge = age;
  return true;
}

bool Student::SetLastName(const char* last_name)
{
  std::strcpy(this->mLastName, last_name);
  return true;
}

bool Student::SetFirstName(const char* first_name)
{
  std::strcpy(this->mFirstName, first_name);
  return true;
}

bool Student::SetEmail(const char* email)
{
  std::strcpy(this->mEmail, email);
  return true;
}

bool Student::SetSsn(const char* ssn)
{
  std::strcpy(this->mSSN, ssn);
  return true;
}

// get methods
int Student::GetAge()
{
  return this->mAge;
}

char*  Student::GetLastName()
{
  return this->mLastName;
}

char*  Student::GetFirstName()
{
  return this->mFirstName;
}

char*  Student::GetEmail()
{
  return this->mEmail;
}

char*  Student::GetSsn()
{
  return this->mSSN;
}