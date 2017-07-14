#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include "promo.h"

using namespace std;

namespace
{
   // Convert date string to tm struct
   void get_tm(string const& date, struct tm* t)
   {
      stringstream ss(date);
      string month, day, year;

      getline(ss, month, '/');
      getline(ss, day, '/');
      getline(ss, year, '/');

      memset(t, 0, sizeof(struct tm));
      t->tm_mday = stoi(day);
      t->tm_mon = stoi(month) - 1;
      t->tm_year = stoi(year) - 1900;
   }
}

Promo::Promo(vector<string> const& input)
   : m_hotel_name(input[0])
   , m_price(stod(input[1]))
   , m_promo_text(input[2])
   , m_deal_value(stod(input[3]))
   , m_type(Promo_type::UNKNOWN)
   , m_start_date(input[5])
   , m_end_date(input[6])
   , m_valid(true)
{
   // Set promotion type
   auto type = input[4];

   if (type == "rebate")
   {
      m_type = Promo_type::REBATE;
   }
   else if (type == "rebate_3plus")
   {
      m_type = Promo_type::REBATE_3PLUS;
   }
   else if (type == "pct")
   {
      m_type = Promo_type::PCT;
   }
   else
   {
      m_valid = false;
   }

   // TODO validate deal value
}

string Promo::get_promo_text() const
{
   return m_promo_text;
}

bool Promo::is_valid() const
{
   return m_valid;
}

bool Promo::can_apply_deal(string const& hotel_name,
                           string const& start_date,
                           int32_t duration) const
{
   if (hotel_name != """" && hotel_name != m_hotel_name)
   {
      return false;
   }

   if (start_date < m_start_date || start_date > m_end_date)
   {
      return false;
   }

   // Start date is inside of promotion time, so the only thing needs to be
   // checked is whether duration is more than 3 nights
   if (m_type == Promo_type::REBATE_3PLUS && duration < 3)
   {
      return false;
   }

   return true;
}

double Promo::get_promo_total(int32_t duration) const
{
   double retval = m_price;

   if (m_type == Promo_type::REBATE || m_type == Promo_type::REBATE_3PLUS)
   {
      return retval * duration - m_deal_value;
   }

   return retval * duration * (100 + m_deal_value) * 0.01;
}

