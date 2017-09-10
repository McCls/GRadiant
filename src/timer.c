#include "Timer.h"

void Timer_Run(Timer_t *instance, void *context)
{
  unsigned int currentTime = millis();

  if(currentTime > (instance.lastCount + instance.period))
  {
    instance.callback(context);
  }
}

void Timer_Init(
  Timer_t *instance,
  unsigned int periodCounts,
  TimerCallback_t callback)
{
  instance->lastCount = millis();
  instance->period = periodCounts;
  instance->callback = callback;
}
