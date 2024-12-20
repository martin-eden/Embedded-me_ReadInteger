## What

(2024-10)

Arduino library to read integer from serial.

Yeah, it's quite boring but needs to be implemented somewhere.

## Reference output

```
[me_ReadInteger] Okay, we are here.
Awaiting byte [0, 255] until 0.
fdg
123
Got 123
Awaiting byte [0, 255] until 0.
1234
0
Got 000
Done.
Awaiting word [0, 65535] until 0.
0
Got 00000
Done.
Awaiting byte [-128, 127] until 0.
0
Got +000
Done.
Awaiting word [-32768, 32767] until 0.
0
Got +00000
Done.
[me_ReadInteger] Done.
```

## Code

* [Example][Example]
* [Interface][Interface]
* [Implementation][Implementation]


## Requirements

  * arduino-cli
  * bash


## Install/remove

Easy way is to clone [GetLibs][GetLibs] repo and run it's code.


## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Example]: examples/me_ReadInteger/me_ReadInteger.ino
[Interface]: src/me_ReadInteger.h
[Implementation]: src/me_ReadInteger.cpp

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
