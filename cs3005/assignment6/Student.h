#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

class Student
{
public:
  /* constructor */
  Student(int age, const char *last_name, const char *first_name, const char *email, const char *ssn);
  Student(const Student &src);
  ~Student();
  Student &operator=(const Student &rhs);
  bool operator==(const Student &rhs) const;
  bool operator!=(const Student &rhs) const;
  bool operator<(const Student &rhs) const;
  bool operator<=(const Student &rhs) const;
  bool operator>(const Student &rhs) const;
  bool operator>=(const Student &rhs) const;

  /* assignment methods */
  bool SetAge(int age);
  bool SetLastName(const char *last_name);
  bool SetFirstName(const char *first_name);
  bool SetEmail(const char *email);
  bool SetSsn(const char *ssn);

  /* accessor methods */
  int GetAge() const;
  const char * GetLastName() const;
  const char * GetFirstName() const;
  const char * GetEmail() const;
  const char * GetSsn() const;
  
private:
  /* data member */
  int mAge;
  char* mLastName;
  char* mFirstName;
  char* mEmail;
  char* mSSN;
};

std::ostream & operator<<(std::ostream &os, const Student &rhs);

#endif /* _STUDENT_H_ */