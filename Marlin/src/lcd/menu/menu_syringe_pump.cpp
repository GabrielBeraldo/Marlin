
#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU

#include "menu.h"
#include "../../module/planner.h"
 
/**
 *
 * initialize seringe pump routine
 *
 */
void initialize_seringe_pump(){
  enqueue_and_echo_commands_P(PSTR(
    "M23 " INITIALIZE_SERINGE_PUMP_PATH "\n"
    "M24\n"
    ));
}

void flush_seringe_pump(){
  enqueue_and_echo_commands_P(PSTR(
    "M23 " FLUSH_SERINGE_PUMP_PATH "\n"
    "M24\n"
    ));
}

/**
 *
 * "Pump" submenu
 *
*/
void lcd_pump_menu(){
  START_MENU();
  MENU_BACK(MSG_BACK);

  MENU_ITEM(function, MSG_INIT_PUMP, initialize_seringe_pump);

  MENU_ITEM(function, MSG_FLUSH_PUMP, flush_seringe_pump);

  END_MENU();
}

#endif