// Read integer from input stream

/*
  Author: Martin Eden
  Last mod.: 2025-09-07
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_ReadInteger
{
  // Read TUint_1
  TBool Read_TUint_1(TUint_1 * Result, IInputStream *);

  // Read TUint_2
  TBool Read_TUint_2(TUint_2 * Result, IInputStream *);

  // Read TSint_1
  TBool Read_TSint_1(TSint_1 * Result, IInputStream *);

  // Read TSint_2
  TBool Read_TSint_2(TSint_2 * Result, IInputStream *);

  namespace Freetown
  {
    TBool Parse_TUint_2(TUint_2 * Value, IInputStream *);
    TBool Parse_TSint_2(TSint_2 * Value, IInputStream *);

    TBool ToDigit(TUint_1 * Digit, TUint_1 Char);
    TBool SafeMulBy10(TUint_2 * Result);
    TBool SafeAdd(TUint_2 * Result, TUint_2 Value);
  }
}

/*
  2024 # # # #
  2025-09-01 Contract change: reading from input stream
  2025-09-07
*/
