#include <cstring>
#include "Track.h"

Track::Track(double length_in, const char *title_in)
{
  this->mLength = length_in;
  if(std::strlen(title_in) < sizeof(this->mTitle))
    {
      std::strcpy(this->mTitle, title_in);
    }
  else
    {
      std::strcpy(this->mTitle, "Too Long");
    }
}

double Track::GetLength()
{
  //return (*this).mLength;
  return this->mLength;
}

bool Track::SetLength(double length_in)
{
  if(length_in >= 0)
    {
      this->mLength = length_in;
      return true;
    }
  return false;
}

char * Track::GetTitle()
{
  return this->mTitle;
}

bool Track::SetTitle(const char *title_in)
{
  if(std::strlen(title_in) < sizeof(this->mTitle))
    {
      std::strcpy(this->mTitle, title_in);
      return true;
    }
  return false;
}