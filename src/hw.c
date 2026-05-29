#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(led, LOG_LEVEL_DBG);

K_MUTEX_DEFINE(red_mutex);
K_MUTEX_DEFINE(green_mutex);
K_MUTEX_DEFINE(blue_mutex);

typedef struct {
    int state;
    struct k_mutex *mutex;
    const char *str;
} led_ctrl;

led_ctrl red_ctrl = {
    .state = 0,
    .mutex = &red_mutex,
    .str = "Red"
};

led_ctrl green_ctrl = {
    .state = 0,
    .mutex = &green_mutex,
    .str = "Green"
};

led_ctrl blue_ctrl = {
    .state = 0,
    .mutex = &blue_mutex,
    .str = "Blue"
};

void toggle_led(led_ctrl *ctrl)
{
    k_mutex_lock(ctrl->mutex, K_FOREVER);
    ctrl->state ^= 1;
    LOG_INF("%s %s", ctrl->str, ctrl->state?"ON":"OFF");
    k_mutex_unlock(ctrl->mutex);
}

void set_led(led_ctrl *ctrl, bool on)
{
    k_mutex_lock(ctrl->mutex, K_FOREVER);
    ctrl->state = on?1:0;
    LOG_INF("%s %s", ctrl->str, ctrl->state?"ON":"OFF");
    k_mutex_unlock(ctrl->mutex);
}

void toggle_red_led()
{
    toggle_led(&red_ctrl);
}

void toggle_green_led()
{
    toggle_led(&green_ctrl);
}

void toggle_blue_led()
{
    toggle_led(&blue_ctrl);
}

void red_led_on()
{
    set_led(&red_ctrl, true);
}

void red_led_off()
{
    set_led(&red_ctrl, false);
}

void green_led_on()
{
    set_led(&green_ctrl, true);
}

void green_led_off()
{
    set_led(&green_ctrl, false);
}

void blue_led_on()
{
    set_led(&blue_ctrl, true);
}

void blue_led_off()
{
    set_led(&blue_ctrl, false);
}

