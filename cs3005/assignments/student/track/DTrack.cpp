#include <cstring>
#include "DTrack.h"

DTrack::DTrack(double length_in, const char *title_in)
{
  this->mLength = length_in;
  
  this->mTitle = new char[std::strlen(title_in)+1];
  if(this->mTitle)
    {
      std::strcpy(this->mTitle, title_in);
    }
}

DTrack::DTrack(const DTrack &src)
  : mTitle(0)
{
  *this = src;
}

DTrack::~DTrack()
{
  if(this->mTitle)
    {
      delete [] this->mTitle;
      this->mTitle = 0;
    }
}

DTrack &DTrack::operator=(const DTrack &rhs)
{
  this->mLength = rhs.mLength;
  this->SetTitle(rhs.mTitle);
  return *this;
}

bool DTrack::operator==(const DTrack &rhs) const
{
  if((this->mLength == rhs.mLength) &&
     (std::strcmp(this->mTitle, rhs.mTitle) == 0))
    {
      return true;
    }
  return false;
}

bool DTrack::operator!=(const DTrack &rhs) const
{
  return !(*this == rhs);
  /*
  if((this->mLength != rhs.mLength) ||
     (std::strcmp(this->mTitle, rhs.mTitle) != 0))
    {
      return true;
    }
  return false;
  */
}

bool DTrack::operator<(const DTrack &rhs) const
{
  return (this->mLength < rhs.mLength);
  /*
  if(this->mLength < rhs.mLength)
    {
      return true;
    }
  return false;
  */
}

bool DTrack::operator<=(const DTrack &rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

bool DTrack::operator>(const DTrack &rhs) const
{
  return (this->mLength > rhs.mLength);
  /*
  if(this->mLength > rhs.mLength)
    {
      return true;
    }
  return false;
  */
}

bool DTrack::operator>=(const DTrack &rhs) const
{
  return (*this > rhs) || (*this == rhs);
}


double DTrack::GetLength() const
{
  return this->mLength;
}

bool DTrack::SetLength(double length_in)
{
  if(length_in >= 0)
    {
      this->mLength = length_in;
      return true;
    }
  return false;
}

const char * DTrack::GetTitle() const
{
  return this->mTitle;
}

bool DTrack::SetTitle(const char *title_in)
{
  if( this->mTitle )
    {
      delete [] this->mTitle;
    }
  this->mTitle = new char [std::strlen(title_in)+1];
  if(this->mTitle)
    {
      std::strcpy(this->mTitle, title_in);
      return true;
    }
  else
    {
      return false;
    }
}

std::ostream & operator<<(std::ostream &os, const DTrack &rhs)
{
  os << rhs.GetLength() << " " << rhs.GetTitle();
  return os;
}