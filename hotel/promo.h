#include <cstdint>
#include <string>

using namespace std;

/// Promotion Parser
class Promo
{
public:
   /// Construct from vector of strings
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

   /// Get promotion text
   string get_promo_text() const;

   /// Return true if promotion data is successfully parsed, otherwise false
   ///
   /// Note: caller has to call this method after class construction, and only
   /// proceed when this function returns true, otherwise, behavior is undefined
   bool is_valid() const;

   /// Return true if current deal can be applied
   bool can_apply_deal(string const& hotel_name,
                       string const& start_date,
                       int32_t duration) const;

   /// Apply get the promotion total
   double get_promo_total(int32_t duration) const;

private:
   string m_hotel_name;
   double m_price;
   string m_promo_text;
   double m_deal_value;
   Promo_type m_type;
   string m_start_date;
   string m_end_date;

   /// Currently valid when type string is okay
   bool m_valid;
};

