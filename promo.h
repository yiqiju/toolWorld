#include <cstdint>
#include <string>

using namespace std;

class Promo
{
public:
   Promo(vector<string> const& text_data);
   ~Promo() = default;

   /// Promotion types
   enum class Promo_type : uint8_t
   {
      UNKNOWN,
      REBATE,
      REBATE_3PLUS,
      PCT
   };

   string get_promo_text() const;

   // Return true if promotion data is successfully parsed, otherwise false
   bool is_valid() const;

   // Return true if current deal can be applied
   bool can_apply_deal(string const& hotel_name,
                       string const& start_date,
                       int32_t duration) const;

   double get_promo_total(int32_t duration) const;

private:
   string m_hotel_name;
   double m_price;
   string m_promo_text;
   double m_deal_value;
   Promo_type m_type;
   string m_start_date;
   string m_end_date;
   bool m_valid;
};
