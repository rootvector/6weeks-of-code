#ifndef TERCONT_H_
#define TERCONT_H_

/* Terminal escape sequences allow programs to control cursor position, colors, and screen content by sending specific byte sequences, typically starting with the Escape character (\e or \033, hex 0x1B) followed by a bracket [ (Control Sequence Introducer, CSI) or other indicators. */


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

/* CURSOR MOVEMENT MACROS */	
/* ESC [ n A (CUU): Moves the cursor up n rows
 * ESC [ n B (CUD): Moves the cursor down n rows. 
 * ESC [ n C (CUF): Moves the cursor forward (right) n columns. 
 * ESC [ n D (CUB): Moves the cursor backward (left) n columns. 
 * ESC [ n ; m H (CUP): Moves the cursor to specific row n and column m (1-based indexing). 
 * ESC [ n E (CNL): Moves cursor to the beginning of the line n rows down. 
 * ESC [ n F (CPL): Moves cursor to the beginning of the line n rows up. 
 * ESC [ n G (CHA): Moves the cursor to column n in the current row. */

#define MOVE_UP(N) printf("\033[%dA", (N));
#define MOVE_DOWN(N) printf("\033[%dB", (N));
#define MOVE_FORWARD(N) printf("\033[%dC", (N));
#define MOVE_BACKWARD(N) printf("\033[%dD", (N));
#define MOVE_TO(N,M) printf("\033[%d;%dH", (N), (M));
#define MOVE_DOWN_BEG(N) printf("\033[%dE", (N));
#define MOVE_UP_BEG(N) printf("\033[%dF", (N));
#define MOVE_COLIN_ROW(N) printf("\033[%dG", (N));

/*Screen Control and State
 * Beyond movement, these sequences manage the display environment:
 *
 * ESC [ n J (ED): Erases part of the screen. 0 clears from cursor to end, 1 clears from start to cursor, and 2 clears the entire screen. 
 * ESC [ n K (EL): Erases part of the line. 0 clears to end, 1 clears to start, and 2 clears the whole line. 
 * ESC [ ? 25 l: Hides the cursor. 
 * ESC [ ? 25 h: Shows the cursor. 
 * ESC s: Saves the current cursor position. 
 * ESC u: Restores the cursor to the previously saved position. */

#define CLEAR_SCREEN(N) printf("\033[%dJ", (N));
#define CLEAR_IN_LINE(N) printf("\033[%dK", (N));
#define HIDE_CURSOR() printf("\033[? 25 l");
#define SHOW_CURSOR() printf("\033[? 25 h");
#define SAVE_CURSOR_POS() printf("\033s");
#define RESTORE_CURSOR_POS() printf("\033u");



/*Implementation
 * In programming languages like C, Python, or Bash, these are often represented using escape sequences such as \e[3A or \033[3A. For example, \e[10;20H moves the cursor to row 10, column 20. Note that support can vary slightly between terminal emulators (e.g., xterm, iTerm2, Windows Terminal) and operating systems. */


#endif
