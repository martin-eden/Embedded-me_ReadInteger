// [me_ReadInteger] Test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-01
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  InstallStandardStreams();

  printf("[me_ReadInteger] Okay, we are here.\n");
  RunTest();
  printf("[me_ReadInteger] Done.\n");
}

void loop()
{
}

// --

/*
  Tests of parsing numbers to different integer types.

  Enter 0 to finish current test.
*/
void RunTest()
{
  using namespace me_ReadInteger;

  /*
    This "while" cycle is copy-pasted four times.
    I'm missing first-class functions from Lua.
    Should try templates someday.
  */

  // TUint_1
  while (true)
  {
    printf("Awaiting byte [0, 255] until 0.\n");

    TUint_1 Uint_1;

    while (!Read_TUint_1(&Uint_1));

    printf("Got [%u].\n", Uint_1);

    if (Uint_1 == 0)
    {
      printf("Done.\n");
      break;
    }
  }

  // TUint_2
  while (true)
  {
    printf("Awaiting word [0, 65535] until 0.\n");

    TUint_2 Uint_2;

    while (!Read_TUint_2(&Uint_2));

    printf("Got [%u].\n", Uint_2);

    if (Uint_2 == 0)
    {
      printf("Done.\n");
      break;
    }
  }

  // TSint_1
  while (true)
  {
    printf("Awaiting byte [-128, 127] until 0.\n");

    TSint_1 Sint_1;

    while (!Read_TSint_1(&Sint_1));

    printf("Got [%d].\n", Sint_1);

    if (Sint_1 == 0)
    {
      printf("Done.\n");
      break;
    }
  }

  // TSint_2
  while (true)
  {
    printf("Awaiting word [-32768, 32767] until 0.\n");

    TSint_2 Sint_2;

    while (!Read_TSint_2(&Sint_2));

    printf("Got [%d].\n", Sint_2);

    if (Sint_2 == 0)
    {
      printf("Done.\n");
      break;
    }
  }
}

/*
  2024-10-01
*/
