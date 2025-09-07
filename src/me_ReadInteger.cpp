// Reading integers from stream

/*
  Author: Martin Eden
  Last mod.: 2025-09-07
*/

#include <me_ReadInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

#include <me_StreamTokenizer.h>
#include <me_StreamsCollection.h>

using namespace me_ReadInteger;

/*
  Read TUint_2 in ASCII decimal from stream
*/
TBool me_ReadInteger::Read_TUint_2(
  TUint_2 * Uint_2,
  IInputStream * InputStream
)
{
  const TUint_1 BufferSize = 5;
  TUint_1 Buffer[BufferSize];

  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  me_StreamTokenizer::TStreamTokenizer Tokenizer;
  me_StreamsCollection::TWorkmemInputStream TokenInStream;
  me_StreamsCollection::TWorkmemOutputStream TokenOutStream;

  Tokenizer.Init(InputStream);
  TokenOutStream.Init(BuffSeg);

  if (!Tokenizer.WriteEntity(&TokenOutStream))
    return false;

  TokenInStream.Init(TokenOutStream.GetProcessedSegment());

  if (!Freetown::Parse_TUint_2(Uint_2, &TokenInStream))
    return false;

  return true;
}

/*
  Read TUint_1
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
  Read TSint_2
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

  me_StreamsCollection::TWorkmemInputStream DataStream;

  if (!me_StreamTokenizer::GetEntity(&BuffSeg, InputStream))
    return false;

  DataStream.Init(BuffSeg);

  if (!Freetown::Parse_TSint_2(Sint_2, &DataStream))
    return false;

  return true;
}

/*
  Read TSint_1
*/
TBool me_ReadInteger::Read_TSint_1(
  TSint_1 * Sint_1,
  IInputStream * InputStream
)
{
  TSint_2 Sint_2;

  if (!Read_TSint_2(&Sint_2, InputStream))
    return false;

  if ((Sint_2 < TSint_1_Min) || (Sint_2 > TSint_1_Max))
    return false;

  *Sint_1 = (TSint_1) Sint_2;

  return true;
}

/*
  2024 # # # # # #
  2025-09-01
  2025-09-04
  2025-09-05
  2025-09-07
*/
