#ifndef _DTRACK_H_
#define _DTRACK_H_

#include <iostream>

class DTrack
{
public:
  /* constructor */
  DTrack(double length_in, const char *title_in);
  DTrack(const DTrack &src);
  ~DTrack();
  DTrack &operator=(const DTrack &rhs);
  bool operator==(const DTrack &rhs) const;
  bool operator!=(const DTrack &rhs) const;
  bool operator<(const DTrack &rhs) const;
  bool operator<=(const DTrack &rhs) const;
  bool operator>(const DTrack &rhs) const;
  bool operator>=(const DTrack &rhs) const;

  /* accessor methods */
  double GetLength() const;
  bool SetLength(double length_in);
  
  const char * GetTitle() const;
  bool SetTitle(const char *title_in);
  
private:
  /* data members */
  double mLength;
  char * mTitle;
};

std::ostream & operator<<(std::ostream &os, const DTrack &rhs);

#endif /* _DTRACK_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */