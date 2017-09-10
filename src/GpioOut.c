
void GPIO_On(Led_t *instance)
{
  instance->state = HIGH;
  digitalWrite(instance->pin, HIGH);
}

void GPIO_Off(Led_t *instance)
{
  instance->state = LOW;
  digitalWrite(instance->pin, LOW);
}

void GPIO_Toggle(Led_t *instance)
{
  instance->state = !instance->state;
  digitalWrite(instance->pin, instance->state);
}

void GPIO_Init(
  GPIO_t *instance,
  int pinId,
  bool initialState)
{
  instance->pin = pinId;
  instance->state = initialState;

  pinMode(pinId, OUTPUT);
}
