#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
public:
  /* constructor */
  Student(int age, char *last_name, char *first_name, char *email, char *ssn);

  /* accessor methods */
  bool SetAge(int age);
  bool SetLastName(const char *last_name);
  bool SetFirstName(const char *first_name);

  bool SetEmail(const char *email);

  bool SetSsn(const char *ssn);

  int GetAge();

  char * GetLastName();

  char * GetFirstName();

  char * GetEmail();

  char * GetSsn();

  
// private:
//   /* data members */
//   double mLength;
//   char mTitle[128];
};

#endif /* _STUDENT_H_ */