
#include "mbed.h"

#define LOG(...)    { pc.printf(__VA_ARGS__); }

#define LED_GREEN   p21
#define LED_RED     p22
#define LED_BLUE    p23

#define UART_TX     p9
#define UART_RX     p11
#define UART_CTS    p8
#define UART_RTS    p10

/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)

DigitalOut blue(LED_BLUE);
DigitalOut green(LED_GREEN);
DigitalOut red(LED_RED);

Serial pc(UART_TX, UART_RX);

void tick(void)
{
    static uint32_t count = 0;
    static uint8_t  led_count = 0;
    
    LOG("%d\r\n", count++);
    blue  = 1;
    green = 1;
    red   = 1;
    if (led_count == 1) {
        green = 0;
    } else if (led_count == 2) {
        blue = 0;
    } else if (led_count == 3) {
        red = 0;
    } else {
        led_count = 0;
    }
    led_count++;
}

int main(void)
{
    blue  = 1;
    green = 1;
    red   = 1;

    pc.baud(115200);
    wait(1);
    
    LOG("---- Seeed Tiny Demo ----\n");
    
    Ticker ticker;
    ticker.attach(tick, 1);

    while (true) {
        ;
    }
}
