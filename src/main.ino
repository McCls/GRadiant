/*
 * Project GRadiant_Burner
 * Description: "Hack the Home" Hackathon - 1st Build 9/9/17
 * Author: Christopher McClure
 * Date: 9/9/17
 */
typedef struct
{
  int pin;
  bool state;
} Led_t;

Led_t led_D0 = {
  .pin = D0,
  .state = false
};
bool messageSent = false;
int sysTimer = millis();
int executionPeriod = 10;
int blinkPeriod = 1000;
int blinkTimer = millis();

void Toggle(Led_t *led)
{
  if(led->state == HIGH)
  { led->state = LOW; }
  else
  { led->state = HIGH; }

  digitalWrite(led->pin, led->state);
}

void Run()
{
  if(!messageSent)
  {
    Particle.publish("debugMessage","success");
    messageSent = true;
  }

  if(millis() > (blinkTimer + blinkPeriod))
  {
    blinkTimer = millis();
    Toggle(&led_D0);
  }
}

// System Execution
void setup() {
  //GPIO define
  pinMode(led_D0.pin, OUTPUT);

  // NeoPixel define
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN_NEOPIXEL_STATUS, NEO_GRB + NEO_KHZ800);

  // Global var init
  messageSent = false;
}

void loop() {
  if(millis() > (sysTimer + executionPeriod))
  {
    sysTimer = millis();
    Run();
  }
}
