typedef struct
{
  int pin;
  bool state;
} GpioOut_t;

void GpioOut_Init(
  GpioOut_t *instance,
  int pinId,
  bool initialState);
