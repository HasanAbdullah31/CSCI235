/* Color.h - modifies stream output with colors */

#include <ostream>
namespace Color {
  enum Color_Code {   //ANSI escape codes ("color" codes)
    /* http://ascii-table.com/ansi-escape-sequences.php */
    RESET = 0,
    BOLD = 1,
    ITALICS = 3,
    UNDERLINE = 4,
    INVERSE = 7,
    STRIKETHROUGH = 9,
    /* F for foreground, B for background */
    F_BLACK = 30,        B_BLACK = 40,
    F_RED = 31,          B_RED = 41,
    F_GREEN = 32,        B_GREEN = 42,
    F_YELLOW = 33,       B_YELLOW = 43,
    F_BLUE = 34,         B_BLUE = 44,
    F_PURPLE = 35,       B_PURPLE = 45,
    F_CYAN = 36,         B_CYAN = 46,
    F_LIGHT_GRAY = 37,   B_LIGHT_GRAY = 47,
    F_DEFAULT = 39,      B_DEFAULT = 49
  };
  std::ostream &operator<<(std::ostream &output, Color_Code code) {
    return output<<"\033["<<(int)code<<"m";
  }
}

//Example: cout<<Color::F_RED<<"I'm red"<<Color::F_DEFAULT<<"I'm default";
