#ifndef _TRACK_H_
#define _TRACK_H_

class Track
{
public:
  /* constructor */
  Track(double length_in, const char *title_in);

  /* accessor methods */
  double GetLength();
  bool SetLength(double length_in);
  
  char * GetTitle();
  bool SetTitle(const char *title_in);
  
private:
  /* data members */
  double mLength;
  char mTitle[128];
};

#endif /* _TRACK_H_ */