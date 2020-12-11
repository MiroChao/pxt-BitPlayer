#include "pxt.h"

using namespace pxt;
namespace bitplayer {
    bool initialized = false;

    //%
    void init() {
        if (initialized) return;
        
        #if MICROBIT_CODAL
            Button  buttonP5;
            Button  buttonP11;
            
            buttonP5(io.P5, DEVICE_ID_IO_P5, DEVICE_BUTTON_ALL_EVENTS, ACTIVE_LOW);
            buttonP11(io.P11, DEVICE_ID_IO_P11, DEVICE_BUTTON_ALL_EVENTS, ACTIVE_LOW);


        #else
            #define ALLOC_PIN_BUTTON(id) new MicroBitButton(getPin(id)->name, id, MICROBIT_BUTTON_ALL_EVENTS, PullUp);
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P5)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P11)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P12)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P13)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P14)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P15)
                ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P16)
            #undef ALLOC_PIN_BUTTON
        #endif
    // mount buttons on the pins with a pullup mode
    // TODO: fix this issue in the DAL itself
        //#define ALLOC_PIN_BUTTON(id) new MicroBitButton(getPin(id)->name, id, MICROBIT_BUTTON_ALL_EVENTS, PullUp);
        //   ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P13)
        //    ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P14)
        //    ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P15)
        //    ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P5)
        //    ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P11)
        //    ALLOC_PIN_BUTTON(MICROBIT_ID_IO_P16)
        //#undef ALLOC_PIN_BUTTON

        initialized = true;
    }
}
