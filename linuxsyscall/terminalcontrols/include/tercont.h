#ifndef TERCONT_H_
#define TERCONT_H_

/* COLOR CODES 
 * range 30 to 37
 * syntax
 * \033[n;m
 * \e[n;m 
 */

#define NOR "\033[0m"	// normal color or default
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLO "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYANE "\033[0;36m"
#define WHITE "\033[0;37m"

/* BOLD TEXT COLORS 
 * syntax \033[1;31m  1 for bold and 0 for normal text */

#define BLACK_B "\033[1;30m"
#define RED_B "\033[1;31m"
#define GREEN_B "\033[1;32m"
#define YELLO_B "\033[1;33m"
#define BLUE_B "\033[1;34m"
#define PURPLE_B "\033[1;35m"
#define CYANE_B "\033[1;36m"
#define WHITE_B "\033[1;37m"



/* background colors
 * range 40 to 47 */
/* name_textcolorBackround */

#define BACK_BLACK "\1b[40m"
#define BACK_RED "\033[41m"
#define BACK_GREEN "\033[42m"
#define BACK_YELLO "\033[43m"
#define BACK_BLUE "\033[44m"
#define BACK_PURPLE "\033[45m"
#define BACK_CYANE "\033[46m"
#define BACK_WHITE "\033[47m"

#endif
