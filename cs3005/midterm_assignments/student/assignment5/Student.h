#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
public:
  /* constructor */
  Student(int age, const char *last_name, const char *first_name, const char *email, const char *ssn, const char *grade);

  /* accessor methods */
  bool SetAge(int age);
  bool SetLastName(const char *last_name);
  bool SetFirstName(const char *first_name);

  bool SetEmail(const char *email);

  bool SetSsn(const char *ssn);

  bool SetGrade(const char *grade);

  int GetAge();

  char * GetLastName();

  char * GetFirstName();

  char * GetEmail();

  char * GetSsn();

  char * GetGrade();

  
private:
  /* data member */
  int mAge;
  char mLastName[128];
  char mFirstName[128];
  char mEmail[128];
  char mSSN[128];
  char mGrade[3]; 
};

#endif /* _STUDENT_H_ */
