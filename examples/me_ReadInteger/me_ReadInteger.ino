// [me_ReadInteger] Test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-12-20
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

void setup()
{
  me_Uart::Init(me_Uart::Speed_115k_Bps);

  Console.Print("[me_ReadInteger] Okay, we are here.");
  RunTest();
  Console.Print("[me_ReadInteger] Done.");
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
    Console.Print("Awaiting byte [0, 255] until 0.");

    TUint_1 Uint_1;

    while (!Read_TUint_1(&Uint_1));

    Console.Write("Got");
    Console.Print(Uint_1);
    Console.EndLine();

    if (Uint_1 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }

  // TUint_2
  while (true)
  {
    Console.Print("Awaiting word [0, 65535] until 0.");

    TUint_2 Uint_2;

    while (!Read_TUint_2(&Uint_2));

    Console.Write("Got");
    Console.Print(Uint_2);
    Console.EndLine();

    if (Uint_2 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }

  // TSint_1
  while (true)
  {
    Console.Print("Awaiting byte [-128, 127] until 0.");

    TSint_1 Sint_1;

    while (!Read_TSint_1(&Sint_1));

    Console.Write("Got");
    Console.Print(Sint_1);
    Console.EndLine();

    if (Sint_1 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }

  // TSint_2
  while (true)
  {
    Console.Print("Awaiting word [-32768, 32767] until 0.");

    TSint_2 Sint_2;

    while (!Read_TSint_2(&Sint_2));

    Console.Write("Got");
    Console.Print(Sint_2);
    Console.EndLine();

    if (Sint_2 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }
}

/*
  2024-10-01
  2024-12-20
*/
