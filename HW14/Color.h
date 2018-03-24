/* Hasan Abdullah: Color.h - class Color to color the output */

#ifndef COLOR
#define COLOR

#include <ostream>
using namespace std;

enum Color_Code {   //ANSI escape codes ("color" codes)
  /* http://ascii-table.com/ansi-escape-sequences.php */
  RESET=0, BOLD=1, ITALICS=3, UNDERLINE=4, STRIKETHROUGH=9,
  /* F_ for foreground, B_ for background */
  F_BLACK=30,      B_BLACK=40,
  F_RED=31,        B_RED=41,
  F_GREEN=32,      B_GREEN=42,
  F_YELLOW=33,     B_YELLOW=43,
  F_BLUE=34,       B_BLUE=44,
  F_PURPLE=35,     B_PURPLE=45,
  F_CYAN=36,       B_CYAN=46,
  F_LIGHT_GRAY=37, B_LIGHT_GRAY=47,
  F_DEFAULT=39,    B_DEFAULT=49
};

class Color {
private:
 Color_Code code;
public:
 Color() { code=RESET; }
 Color(Color_Code x) { code=x; }
 friend ostream &operator<<(ostream &output, const Color &color) {
    return output<<"\033["<<(int)color.code<<"m";
 }
 /* Example:
    Color red=Color(F_RED); Color reset=Color(RESET);
    cout<<red<<"<red output>"<<reset<<"<default output color>"<<endl; */
};

#endif /* COLOR */
