// [me_ReadInteger] Test/demo

/*
  Author: Martin Eden
  Last mod.: 2025-09-04
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_StreamsCollection.h>
#include <me_Console.h>

void setup()
{
  Console.Init();

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
  me_StreamsCollection::TUartInputStream InputStream;

  InputStream.Init();

  /*
    This "while" cycle is copy-pasted four times.
    I'm missing first-class functions from Lua.
    Should try templates someday.
  */

  // TUint_2
  while (true)
  {
    Console.Print("Awaiting word [0, 65535] until 0.");

    TUint_2 Uint_2;

    while (!me_ReadInteger::Read_TUint_2(&Uint_2, &InputStream));

    Console.Write("Got");
    Console.Print(Uint_2);
    Console.EndLine();

    if (Uint_2 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }

  // TUint_1
  while (true)
  {
    Console.Print("Awaiting byte [0, 255] until 0.");

    TUint_1 Uint_1;

    while (!me_ReadInteger::Read_TUint_1(&Uint_1, &InputStream));

    Console.Write("Got");
    Console.Print(Uint_1);
    Console.EndLine();

    if (Uint_1 == 0)
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

    while (!me_ReadInteger::Read_TSint_2(&Sint_2, &InputStream));

    Console.Write("Got");
    Console.Print(Sint_2);
    Console.EndLine();

    if (Sint_2 == 0)
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

    while (!me_ReadInteger::Read_TSint_1(&Sint_1, &InputStream));

    Console.Write("Got");
    Console.Print(Sint_1);
    Console.EndLine();

    if (Sint_1 == 0)
    {
      Console.Print("Done.");
      break;
    }
  }

}

/*
  2024 # #
  2025-09-01
  2025-09-04
*/
