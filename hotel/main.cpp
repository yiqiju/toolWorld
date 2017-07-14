#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "promo.h"

using namespace std;

namespace
{
   /// Supported column size on a line.
   uint8_t COL_SIZE = 7;
}

/// Split each column on a .csv line to a vector
vector<string> split(string const& line)
{
   vector<string> output;

   string tmp;
   for (auto each : line)
   {
      if (each == ',')
      {
         if (!tmp.empty())
         {
            output.push_back(tmp);
            tmp.clear();
         }
      }
      else
      {
         tmp.push_back(each);
      }
   }

   if (!tmp.empty())
   {
      output.push_back(tmp);
   }

   return output;
}

int main(int argc, char* argv[])
{
   if (argc != 5)
   {
      cout << "Usage: application data_file_path name start_date end_date" << endl;
      return 1;
   }

   string filename(argv[1]);
   string search_name(argv[2]);
   string start_date(argv[3]);
   string duration(argv[4]);

   fstream file(filename);

   bool is_header = true;

   // Default total price, the best deal provides the lowest price
   double min_total = -1.0;

   // Default promotion text if no deal is found
   string promo_text("no deal available");

   // Parse each line from the .csv file
   for (string line; getline(file, line);)
   {
      if (is_header)
      {
         // Skip header
         is_header = false;
         continue;
      }

      // Parse line
      auto line_data = split(line);

      if (line_data.size() < COL_SIZE)
      {
         // Too few columns, invalid .csv line, ignore
         continue;
      }

      // Parse promotion on current line
      Promo promotion(line_data);
      if (promotion.is_valid() &&
          promotion.can_apply_deal(search_name, start_date, stoi(duration)))
      {
         // Found a deal that fits the search criteria, get the promotion total
         auto total = promotion.get_promo_total(stoi(duration));
         {
            if (total < min_total || min_total == -1)
            {
               // Either first valid deal or a better deal;
               min_total = total;
               promo_text = promotion.get_promo_text();
            }
         }
      }
   }

   // Print out result
   cout << promo_text << endl;

   return 0;
}

