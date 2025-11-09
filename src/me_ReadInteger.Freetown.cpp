// Custom functions for reading integer from stream

/*
  Author: Martin Eden
  Last mod.: 2025-11-09
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_StreamTools.h>

using namespace me_ReadInteger;

/*
  "0".."9" -> 0..9
*/
TBool me_ReadInteger::Freetown::ToDigit(
  TUint_1 * Digit,
  TUint_1 Char
)
{
  if (Char < '0')
    return false;

  if (Char > '9')
    return false;

  *Digit = Char - '0';

  return true;
}

/*
  Multiply by 10 if it won't overflow
*/
TBool me_ReadInteger::Freetown::SafeMulBy10(
  TUint_2 * Result
)
{
  const TUint_2 MaxValue = TUint_2_Max / 10;

  if (*Result > MaxValue)
    return false;

  *Result = *Result * 10;

  return true;
}

/*
  Sum two numbers if they won't overflow
*/
TBool me_ReadInteger::Freetown::SafeAdd(
  TUint_2 * Result,
  TUint_2 Value
)
{
  TUint_2 MaxValue = TUint_2_Max - Value;

  if (*Result > MaxValue)
    return false;

  *Result = *Result + Value;

  return true;
}

/*
  Parse ASCII data to integer in range 0 .. 65535

  Leading zeroes are allowed: "001" -> 1
  Non-digits are not allowed: (" 1", "1a") -> nah
  Exceeding range is not allowed: "99999" -> nah
*/
TBool me_ReadInteger::Freetown::Parse_TUint_2(
  TUint_2 * Result,
  IInputStream * DataStream
)
{
  TUnit Byte;
  TUint_1 Digit;
  TUint_2 Value;

  Value = 0;

  while (DataStream->Read(&Byte))
  {
    if (!Freetown::ToDigit(&Digit, Byte))
      return false;

    if (!Freetown::SafeMulBy10(&Value))
      return false;

    if (!Freetown::SafeAdd(&Value, (TUint_2) Digit))
      return false;
  }

  *Result = Value;

  return true;
}

/*
  Parse ASCII data to integer in range -32768 .. 32767

  ASCII integer MAY start with "-".

  Example: "-1" -> -1
  Example: "--1" -> false
  Example: "-0" -> 0
*/
TBool me_ReadInteger::Freetown::Parse_TSint_2(
  TSint_2 * Sint_2,
  IInputStream * InputStream
)
{
  const TUint_2
    MaxPosValue = (TUint_2) TSint_2_Max,
    MaxNegValue = (TUint_2) TSint_2_Min;

  me_StreamTools::TRereadableInputStream DataStream;
  TUnit FirstChar;
  TBool IsNegative;
  TUint_2 Uint_2;

  DataStream.Init(InputStream);

  if (!DataStream.Read(&FirstChar))
    return false;

  IsNegative = (FirstChar == '-');

  if (!IsNegative)
    DataStream.Unread();

  if (!Parse_TUint_2(&Uint_2, &DataStream))
    return false;

  if (IsNegative)
  {
    if (Uint_2 > MaxNegValue)
      return false;

    *Sint_2 = -Uint_2;
  }
  else // if positive
  {
    if (Uint_2 > MaxPosValue)
      return false;

    *Sint_2 = Uint_2;
  }

  return true;
}

/*
  2024 # # # # # #
  2025-09-07
  2025-11-09
*/
