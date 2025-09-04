// Reading integers from serial

/*
  Author: Martin Eden
  Last mod.: 2025-09-04
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

#include <me_StreamTokenizer.h>
#include <me_StreamsCollection.h>
#include <me_AddrsegTools.h>
#include <me_ParseInteger.h> // ASCII to integer

using namespace me_ReadInteger;

/*
  [Internal] Write entity to address segment
*/
TBool GetEntity(
  TAddressSegment * BuffSeg,
  IInputStream * InputStream
)
{
  me_StreamsCollection::TWorkmemOutputStream BuffStreamOut;
  me_StreamTokenizer::TStreamTokenizer Tokenizer;

  if (!BuffStreamOut.Init(*BuffSeg))
    return false;

  Tokenizer.Init(InputStream);

  if (!Tokenizer.WriteEntity(&BuffStreamOut))
    return false;

  if (!BuffStreamOut.IsFull())
    me_AddrsegTools::ChopRightAt(BuffSeg, BuffStreamOut.GetWriteAddr());

  return true;
}

/*
  Read integer in range [0, 65535] in decimal notation in ASCII.
*/
TBool me_ReadInteger::Read_TUint_2(
  TUint_2 * Uint_2,
  IInputStream * InputStream
)
{
  const TUint_1 BufferSize = 5;
  TUint_1 Buffer[BufferSize] = { 0 };

  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  if (!GetEntity(&BuffSeg, InputStream))
    return false;

  if (!me_ParseInteger::AsciiToUint2(Uint_2, BuffSeg))
    return false;

  return true;
}

/*
  Read integer in range [0, 255] in decimal notation in ASCII.
*/
TBool me_ReadInteger::Read_TUint_1(
  TUint_1 * Uint_1,
  IInputStream * InputStream
)
{
  TUint_2 Uint_2;

  if (!Read_TUint_2(&Uint_2, InputStream))
    return false;

  if (Uint_2 > TUint_1_Max)
    return false;

  *Uint_1 = (TUint_1) Uint_2;

  return true;
}

/*
  Read integer in range [-32768, 32767] in decimal notation in ASCII.
*/
TBool me_ReadInteger::Read_TSint_2(
  TSint_2 * Sint_2,
  IInputStream * InputStream
)
{
  const TUint_1 BufferSize = 6;
  TUint_1 Buffer[BufferSize];

  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  if (!GetEntity(&BuffSeg, InputStream))
    return false;

  if (!me_ParseInteger::AsciiToSint2(Sint_2, BuffSeg))
    return false;

  return true;
}

/*
  Read integer in range [-128, 127] in decimal notation in ASCII.
*/
TBool me_ReadInteger::Read_TSint_1(
  TSint_1 * Sint_1,
  IInputStream * InputStream
)
{
  TSint_2 Sint_2;

  if (!Read_TSint_2(&Sint_2, InputStream))
    return false;

  if (Sint_2 < TSint_1_Min)
    return false;

  if (Sint_2 > TSint_1_Max)
    return false;

  *Sint_1 = (TSint_1) Sint_2;

  return true;
}

/*
  2024-10-01 Took them from [me_RgbStripeConsole]
  2024-10-05
  2024-10-14 Rule: No dynamic memory for fixed buffers
  2025-09-01
  2025-09-04
*/
