# nanotime [![Build Status](https://secure.travis-ci.org/lstrojny/nanotime.png)](http://travis-ci.org/lstrojny/nanotime)

A small C library for nanosecond precise, cross platform timestamps

## Examples

### Include file

Include `nanotime.h` to use

```C
#include <nanotime.h>
```

### Get current timestamp

Get current UNIX timestamp as a `long double` with nanotime precision.

```C
long double timestamp;
if (NANO_UNEXPECTED(nano_time(&timestamp)) {
    // Error handling
}
printf("Current time: %f\n", timestamp);
```

### Get current nanosecond

Get current nanosecond as an `unsigned long`.

```C
unsigned long sec;
if (NANO_UNEXPECTED(nano_second(&sec)) {
    // Error handling
}
printf("Current time: %Ld\n", sec);
```
