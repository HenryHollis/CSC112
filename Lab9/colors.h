/** 
 *  @file colors.cpp
 *  @author Nomed Nocaed  
 *  @date   11/1/2018  
 *  
 *  @brief CSC 112, different Xterm terminal colors.  
 *
 *  Add the #define statements for each color, then use with
 *  << operator and ostream. Note, color remains until next
 *  color "code" given to the stream.
 *
 */

#ifndef COLORS_H  
#define COLORS_H  

#define GRAY_BACKGROUND "\033[47m" 
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"  

#define GREEN  "\033[32m" 
#define RED    "\033[31m" 
#define WHITE  "\033[37m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m" 
#define PURPLE "\033[35m"
#define PINK   "\033[35m"
#define CYAN   "\033[36m"

#define BOLD_GREEN  "\033[1;32m" 
#define BOLD_RED    "\033[1;31m" 
#define BOLD_WHITE  "\033[1;37m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE   "\033[1;34m" 
#define BOLD_PURPLE "\033[1;35m"
#define BOLD_PINK   "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"

#define NORM "\033[0m" 

#endif  


