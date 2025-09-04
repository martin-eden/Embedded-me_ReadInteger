// Read integer from input stream

/*
  Author: Martin Eden
  Last mod.: 2025-09-01
*/

/*
  Read integer from serial in ASCII in decimal notation. Common task.

  All needed parts are already implemented, we're just binding
  them together.
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_ReadInteger
{
  // Read [0, 255]
  TBool Read_TUint_1(TUint_1 * Result, IInputStream *);

  // Read [0, 65535]
  TBool Read_TUint_2(TUint_2 * Result, IInputStream *);

  // Read [-128, 127]
  TBool Read_TSint_1(TSint_1 * Result, IInputStream *);

  // Read [-32768, 32767]
  TBool Read_TSint_2(TSint_2 * Result, IInputStream *);
}

/*
  2024-10-01
  2025-09-01 Contract change: reading from input stream
*/
