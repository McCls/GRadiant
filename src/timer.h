/*
Written by: Christopher McClure
Function: Basic timer calls
*/

typedef void (*TimerCallback_t)(void *context);

typedef struct
{
  unsigned int lastCount;
  unsigned int period;
  TimerCallback_t callback;
} Timer_t;

void Timer_Init(
  Timer_t *instance,
  unsigned int periodCounts,
  TimerCallback_t callback);
