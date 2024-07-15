/* Citation and Sources...
Final Project Milestone 5, Part 3
Module: Ticket
Filename: Ticket.cpp
Version 1.0
Author          Kelly Narine

Revision History
-----------------------------------------------------------
Date      Reason
2024/03/31  Preliminary release
-----------------------------------------------------------
*/

#include <iostream>
#include "Ticket.h"
using namespace std;
namespace seneca {
   Ticket::Ticket(int number) {
      m_number = number;
   }
   Time Ticket::time() const
   {
      return m_time;
   }
   int Ticket::number() const {
      return m_number;
   }
   void Ticket::resetTime() {
      m_time.reset();
   }
   std::ostream& Ticket::write(std::ostream& ostr) const {
      if (&ostr != &cout) {
         ostr << m_number << "," << m_time;
      }
      else {
         ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
      }
      return  ostr;
   }
   std::istream& Ticket::read(std::istream& istr) {
      istr >> m_number;
      istr.ignore();
      return istr >> m_time;
   }
}
