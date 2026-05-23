#include "xparameters.h"
#include "xgpio.h"
#include "xstatus.h"
#include "sleep.h"

#define GPIO_DEVICE_ID XPAR_AXI_GPIO_0_DEVICE_ID
#define LED_CHANNEL 1

XGpio Gpio;

int main()
{
    int Status;

    Status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);

    if (Status != XST_SUCCESS)
    {
        return XST_FAILURE;
    }

    XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);

    while(1)
    {
        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0xAA); // 10101010
        sleep(1);

        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0x55); // 01010101
        sleep(1);
    }

    return 0;
}
