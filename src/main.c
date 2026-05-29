#include <stdio.h>
#include <string.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(lab4, LOG_LEVEL_DBG);

extern void toggle_red_led();
extern void toggle_green_led();
extern void toggle_blue_led();
extern void red_led_on();
extern void red_led_off();
extern void green_led_on();
extern void green_led_off();
extern void blue_led_on();
extern void blue_led_off();

int main(void)
{
  while (1) {
    k_msleep(CONFIG_LED_BLINK_PERIOD);
  }

  return 0;
}
