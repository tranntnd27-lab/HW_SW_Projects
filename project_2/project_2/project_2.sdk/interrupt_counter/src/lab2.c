#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"
#include "sleep.h"

int main()
{
    XGpio push;
    int statusPush;
    u32 psb_check;

    xil_printf("\r\n--- Start of Program ---\r\n");

    // Initialize AXI GPIO
    statusPush = XGpio_Initialize(&push, XPAR_AXI_GPIO_0_DEVICE_ID);

    if (statusPush != XST_SUCCESS)
    {
        xil_printf("GPIO Initialization Failed\r\n");
        return XST_FAILURE;
    }

    xil_printf("GPIO Initialization Success\r\n");

    // Channel 1 as input
    XGpio_SetDataDirection(&push, 1, 0xFFFFFFFF);

    while(1)
    {
        // Read push button value
        psb_check = XGpio_DiscreteRead(&push, 1);

        xil_printf("Push Button Status = 0x%08X\r\n", psb_check);

        sleep(1);
    }

    return 0;
}