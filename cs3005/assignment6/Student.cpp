#include <cstring>
#include "Student.h"

Student::Student(int age, const char *last_name, const char *first_name, const char *email, const char *ssn)
{
	this->mAge = age;
  this->mLastName = new char[std::strlen(last_name)+1];
  if(this->mLastName)
    {
      std::strcpy(this->mLastName, last_name);
    }
  this->mFirstName = new char[std::strlen(first_name)+1];
  if(this->mFirstName)
    {
      std::strcpy(this->mFirstName, first_name);
    }
  this->mEmail = new char[std::strlen(email)+1];
  if(this->mEmail)
    {
      std::strcpy(this->mEmail, email);
    }
  this->mSSN = new char[std::strlen(ssn)+1];
  if(this->mSSN)
    {
      std::strcpy(this->mSSN, ssn);
    }
}

// Comparison Operators //

// Default Constructor for Student
Student::Student()
  : Last(0), First(0), Email(0), Age(0)
{
  strcpy(ssn, "000-00-0000");
}

Student::~Student()
{
  if(this->mLastName)
    {
      delete [] this->mLastName;
      this->mLastName = 0;
    }
  if(this->mFirstName)
    {
      delete [] this->mFirstName;
      this->mFirstName = 0;
    }
  if(this->mEmail)
    {
      delete [] this->mEmail;
      this->mEmail = 0;
    }
  if(this->mSSN)
    {
      delete [] this->mSSN;
      this->mSSN = 0;
    }
}

Student &Student::operator=(const Student &rhs)
{
  this->mAge = rhs.mAge;
  this->SetLastName(rhs.mLastName);
  this->SetFirstName(rhs.mFirstName);
  this->SetEmail(rhs.mEmail);
  this->SetSsn(rhs.mSSN);
  return *this;
}

bool Student::operator==(const Student &rhs) const
{
  if(this->mAge == rhs.mAge)
    {
      return true;
    }
  return false;
}

bool Student::operator!=(const Student &rhs) const
{
  return !(*this == rhs);
}

bool Student::operator<(const Student &rhs) const
{
  return (this->mAge < rhs.mAge);
}

bool Student::operator<=(const Student &rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

bool Student::operator>(const Student &rhs) const
{
  return (this->mSSN > rhs.mSSN);
}

bool Student::operator>=(const Student &rhs) const
{
  return (*this > rhs) || (*this == rhs);
}

// set methods
bool Student::SetAge(int age_in)
{
    if(age_in >= 0)
    {
      this->mAge = age_in;
      return true;
    }
  return false;
}

bool Student::SetLastName(const char* last_name_in)
{
  if( this->mLastName )
    {
      delete [] this->mLastName;
    }
  this->mLastName = new char [std::strlen(last_name_in)+1];
  if(this->mLastName)
    {
      std::strcpy(this->mLastName, last_name_in);
      return true;
    }
  else
    {
      return false;
    }
}

bool Student::SetFirstName(const char* first_name_in)
{
  if( this->mFirstName )
    {
      delete [] this->mFirstName;
    }
  this->mFirstName = new char [std::strlen(first_name_in)+1];
  if(this->mFirstName)
    {
      std::strcpy(this->mFirstName, first_name_in);
      return true;
    }
  else
    {
      return false;
    }
}

bool Student::SetEmail(const char* email_in)
{
  if( this->mEmail )
    {
      delete [] this->mEmail;
    }
  this->mEmail = new char [std::strlen(email_in)+1];
  if(this->mEmail)
    {
      std::strcpy(this->mEmail, email_in);
      return true;
    }
  else
    {
      return false;
    }
}

bool Student::SetSsn(const char* ssn_in)
{
  if( this->mSSN )
    {
      delete [] this->mSSN;
    }
  this->mSSN = new char [std::strlen(ssn_in)+1];
  if(this->mSSN)
    {
      std::strcpy(this->mSSN, ssn_in);
      return true;
    }
  else
    {
      return false;
    }
}

// get methods
int Student::GetAge() const
{
  return this->mAge;
}

const char*  Student::GetLastName() const
{
  return this->mLastName;
}

const char*  Student::GetFirstName() const
{
  return this->mFirstName;
}

const char*  Student::GetEmail() const
{
  return this->mEmail;
}

const char*  Student::GetSsn() const
{
  return this->mSSN;
}

std::ostream & operator<<(std::ostream &os, const Student &rhs)
{
  os << rhs.GetLastName() << ", " << rhs.GetFirstName();
  return os;
}