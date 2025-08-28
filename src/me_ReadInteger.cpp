// Reading integers from serial

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>

#include <me_SerialTokenizer.h> // getting chunk from stdin
#include <me_ParseInteger.h> // ASCII to integer

using namespace me_ReadInteger;

/*
  Read integer in range [0, 65535] in decimal notation in ASCII.

  Input

    Uses stdin

  Output

    TUint_2 * Result
*/
TBool me_ReadInteger::Read_TUint_2(TUint_2 * Result)
{
  const TUint_1 BufferSize = 5;
  TUint_1 Buffer[BufferSize];

  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  TAddressSegment Capture;

  me_SerialTokenizer::TSerialTokenizer Tokenizer;

  if (!Tokenizer.GetEntity(&Capture, BuffSeg))
    return false;

  if (!me_ParseInteger::AsciiToUint2(Result, Capture))
    return false;

  return true;
}

/*
  Read integer in range [-32768, 32767] in decimal notation in ASCII.

  Input

    Uses stdin

  Output

    TSint_2 * Result
*/
TBool me_ReadInteger::Read_TSint_2(TSint_2 * Result)
{
  const TUint_1 BufferSize = 6;
  TUint_1 Buffer[BufferSize];

  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  TAddressSegment Capture;

  me_SerialTokenizer::TSerialTokenizer Tokenizer;

  if (!Tokenizer.GetEntity(&Capture, BuffSeg))
    return false;

  if (!me_ParseInteger::AsciiToSint2(Result, Capture))
    return false;

  return true;
}

/*
  Read integer in range [0, 255] in decimal notation in ASCII.

  Input

    Uses stdin

  Output

    TUint_1 * Uint_1
*/
TBool me_ReadInteger::Read_TUint_1(TUint_1 * Uint_1)
{
  TUint_2 Uint_2;

  if (!Read_TUint_2(&Uint_2))
    return false;

  if (Uint_2 > 255)
    return false;

  *Uint_1 = Uint_2;

  return true;
}

/*
  Read integer in range [-128, 127] in decimal notation in ASCII.

  Input

    Uses stdin

  Output

    TSint_1 * Sint_1
*/
TBool me_ReadInteger::Read_TSint_1(TSint_1 * Sint_1)
{
  TSint_2 Sint_2;

  if (!Read_TSint_2(&Sint_2))
    return false;

  if (Sint_2 < -128)
    return false;

  if (Sint_2 > 127)
    return false;

  *Sint_1 = Sint_2;

  return true;
}

/*
  2024-10-01 Took them from [me_RgbStripeConsole]
  2024-10-05
  2024-10-14 Rule: No dynamic memory for fixed buffers
*/
