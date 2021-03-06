/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2017 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __ETL_ATOMIC_GCC__
#define __ETL_ATOMIC_GCC__

#include <stdint.h>
#include "../../../external/etl/char_traits.h"
#include "../../../external/etl/nullptr.h"
#include "../../../external/etl/platform.h"
#include "../../../external/etl/static_assert.h"
#include "../../../external/etl/type_traits.h"

namespace etl
{
  //***************************************************************************
  // Atomic type for pre C++11 GCC compilers that support the builtin 'fetch' functions.
  // Only integral and pointer types are supported.
  //***************************************************************************
  template <typename T>
  class atomic
  {
  public:

    STATIC_ASSERT(etl::is_integral<T>::value, "Only integral types are supported");

    atomic()
      : value(0)
    {
    }

    atomic(T v)
      : value(v)
    {
    }

    // Assignment
    T operator =(T v)
    {
      __sync_lock_test_and_set(&value, v);

      return v;
    }

    T operator =(T v) volatile
    {
      __sync_lock_test_and_set(&value, v);

      return v;
    }

    // Pre-increment
    T operator ++()
    {
      return fetch_add(1) + 1;
    }

    T operator ++() volatile
    {
      return fetch_add(1) + 1;
    }

    // Post-increment
    T operator ++(int)
    {
      return fetch_add(1);
    }

    T operator ++(int) volatile
    {
      return fetch_add(1);
    }

    // Pre-decrement
    T operator --()
    {
      return fetch_sub(1) + 1;
    }

    T operator --() volatile
    {
      return fetch_sub(1) + 1;
    }

    // Post-decrement
    T operator --(int)
    {
      return fetch_sub(1);
    }

    T operator --(int) volatile
    {
      return fetch_sub(1);
    }

    // Add
    T operator +=(T v)
    {
      return fetch_add(v) + v;
    }

    T operator +=(T v) volatile
    {
      return fetch_add(v) + v;
    }

    // Subtract
    T operator -=(T v)
    {
      return fetch_sub(v) - v;
    }

    T operator -=(T v) volatile
    {
      return fetch_sub(v) - v;
    }

    // And
    T operator &=(T v)
    {
      return fetch_and(v) & v;
    }

    T operator &=(T v) volatile
    {
      return fetch_and(v) & v;
    }

    // Or
    T operator |=(T v)
    {
      return fetch_or(v) | v;
    }

    T operator |=(T v) volatile
    {
      return fetch_or(v) | v;
    }

    // Exclusive or
    T operator ^=(T v)
    {
      return fetch_xor(v) ^ v;
    }

    T operator ^=(T v) volatile
    {
      return fetch_xor(v) ^ v;
    }

    // Conversion operator
    operator T () const
    {
      return __sync_fetch_and_add(const_cast<T*>(&value), 0);
    }

    operator T() volatile const
    {
      return __sync_fetch_and_add(const_cast<T*>(&value), 0);
    }

    // Is lock free?
    bool is_lock_free() const
    {
      return true;
    }

    bool is_lock_free() const volatile
    {
      return true;
    }

    // Store
    void store(T v)
    {
      __sync_lock_test_and_set(&value, v);
    }

    void store(T v) volatile
    {
      __sync_lock_test_and_set(&value, v);
    }

    // Load
    T load()
    {
      return __sync_fetch_and_add(&value, 0);
    }

    T load() volatile
    {
      return __sync_fetch_and_add(&value, 0);
    }

    // Fetch add
    T fetch_add(T v)
    {
      return __sync_fetch_and_add(&value, v);
    }

    T fetch_add(T v) volatile
    {
      return __sync_fetch_and_add(&value, v);
    }

    // Fetch subtract
    T fetch_sub(T v)
    {
      return __sync_fetch_and_sub(&value, v);
    }

    T fetch_sub(T v) volatile
    {
      return __sync_fetch_and_sub(&value, v);
    }

    // Fetch or
    T fetch_or(T v)
    {
      return __sync_fetch_and_or(&value, v);
    }

    T fetch_or(T v) volatile
    {
      return __sync_fetch_and_or(&value, v);
    }

    // Fetch and
    T fetch_and(T v)
    {
      return __sync_fetch_and_and(&value, v);
    }

    T fetch_and(T v) volatile
    {
      return __sync_fetch_and_and(&value, v);
    }

    // Fetch exclusive or
    T fetch_xor(T v)
    {
      return __sync_fetch_and_xor(&value, v);
    }

    T fetch_xor(T v) volatile
    {
      return __sync_fetch_and_xor(&value, v);
    }

    // Exchange
    T exchange(T v)
    {
      return __sync_lock_test_and_set(&value, v);
    }

    T exchange(T v) volatile
    {
      return __sync_lock_test_and_set(&value, v);
    }

    // Compare exchange weak
    bool compare_exchange_weak(T& expected, T desired)
    {
      T old = __sync_val_compare_and_swap(&value, expected, desired);

      if (old == expected)
      {
        return true;
      }
      else
      {
        expected = old;
        return false;
      }
    }

    bool compare_exchange_weak(T& expected, T desired) volatile
    {
      T old = __sync_val_compare_and_swap(&value, expected, desired);

      if (old == expected)
      {
        return true;
      }
      else
      {
        expected = old;
        return false;
      }
    }

    // Compare exchange strong
    bool compare_exchange_strong(T& expected, T desired)
    {
      T old = expected;

      while (!compare_exchange_weak(old, desired))
      {
        if (memcmp(&old, &expected, sizeof(T)))
        {
          expected = old;
          return false;
        }
      }

      return true;
    }

    bool compare_exchange_strong(T& expected, T desired) volatile
    {
      T old = expected;

      while (!compare_exchange_weak(old, desired))
      {
        if (memcmp(&old, &expected, sizeof(T)))
        {
          expected = old;
          return false;
        }
      }

      return true;
    }

  private:

    atomic& operator =(const atomic&);
    atomic& operator =(const atomic&) volatile;

    T value;
  };

  //***************************************************************************
  // Specialisation for pointers.
  //***************************************************************************
  template <typename T>
  class atomic<T*>
  {
  public:

    atomic()
      : value(nullptr)
    {
    }

    atomic(T v)
      : value(v)
    {
    }

    // Assignment
    T operator =(T* v)
    {
      __sync_lock_test_and_set(&value, v);

      return v;
    }

    T operator =(T* v) volatile
    {
      __sync_lock_test_and_set(&value, v);

      return v;
    }

    // Pre-increment
    T operator ++()
    {
      return fetch_add(1) + 1;
    }

    T operator ++() volatile
    {
      return fetch_add(1) + 1;
    }

    // Post-increment
    T operator ++(int)
    {
      return fetch_add(1);
    }

    T operator ++(int) volatile
    {
      return fetch_add(1);
    }

    // Pre-decrement
    T operator --()
    {
      return fetch_sub(1) + 1;
    }

    T operator --() volatile
    {
      return fetch_sub(1) + 1;
    }

    // Post-decrement
    T operator --(int)
    {
      return fetch_sub(1);
    }

    T operator --(int) volatile
    {
      return fetch_sub(1);
    }

    // Add
    T* operator +=(std::ptrdiff_t v)
    {
      return fetch_add(v) + v;
    }

    T* operator +=(std::ptrdiff_t v) volatile
    {
      return fetch_add(v) + v;
    }

    // Subtract
    T* operator -=(std::ptrdiff_t v)
    {
      return fetch_sub(v) - v;
    }

    T* operator -=(std::ptrdiff_t v) volatile
    {
      return fetch_sub(v) - v;
    }

    // Conversion operator
    operator T () const
    {
      return __sync_fetch_and_add(const_cast<T**>(&value), 0);
    }

    operator T() volatile const
    {
      return __sync_fetch_and_add(const_cast<T**>(&value), 0);
    }

    // Is lock free?
    bool is_lock_free() const
    {
      return true;
    }

    bool is_lock_free() const volatile
    {
      return true;
    }

    // Store
    void store(T v)
    {
      __sync_lock_test_and_set(&value, v);
    }

    void store(T v) volatile
    {
      __sync_lock_test_and_set(&value, v);
    }

    // Load
    T load()
    {
      return __sync_fetch_and_add(&value, 0);
    }

    T load() volatile
    {
      return __sync_fetch_and_add(&value, 0);
    }

    // Fetch add
    T* fetch_add(std::ptrdiff_t v)
    {
      return __sync_fetch_and_add(&value, v);
    }

    T* fetch_add(std::ptrdiff_t v) volatile
    {
      return __sync_fetch_and_add(&value, v);
    }

    // Fetch subtract
    T* fetch_sub(std::ptrdiff_t v)
    {
      return __sync_fetch_and_sub(&value, v);
    }

    T* fetch_sub(std::ptrdiff_t v) volatile
    {
      return __sync_fetch_and_sub(&value, v);
    }

    // Exchange
    T exchange(T v)
    {
      return __sync_lock_test_and_set(&value, v);
    }

    T exchange(T v) volatile
    {
      return __sync_lock_test_and_set(&value, v);
    }

    // Compare exchange weak
    bool compare_exchange_weak(T& expected, T desired)
    {
      return __sync_bool_compare_and_swap(&value, expected, desired);
    }

    bool compare_exchange_weak(T& expected, T desired) volatile
    {
      return __sync_bool_compare_and_swap(&value, expected, desired);
    }

    // Compare exchange strong
    bool compare_exchange_strong(T& expected, T desired)
    {
      T old = expected;

      while (!compare_exchange_weak(old, desired))
      {
        if (memcmp(&old, &expected, sizeof(T)))
        {
          expected = old;
          return false;
        }
      }

      return true;
    }

    bool compare_exchange_strong(T& expected, T desired) volatile
    {
      T old = expected;

      while (!compare_exchange_weak(old, desired))
      {
        if (memcmp(&old, &expected, sizeof(T)))
        {
          expected = old;
          return false;
        }
      }

      return true;
    }

  private:

    atomic& operator =(const atomic&);
    atomic& operator =(const atomic&) volatile;

    T* value;
  };

  typedef etl::atomic<char>                atomic_char;
  typedef etl::atomic<signed char>         atomic_schar;
  typedef etl::atomic<unsigned char>       atomic_uchar;
  typedef etl::atomic<short>               atomic_short;
  typedef etl::atomic<unsigned short>      atomic_ushort;
  typedef etl::atomic<int>                 atomic_int;
  typedef etl::atomic<unsigned int>        atomic_uint;
  typedef etl::atomic<long>                atomic_long;
  typedef etl::atomic<unsigned long>       atomic_ulong;
  typedef etl::atomic<long long>           atomic_llong;
  typedef etl::atomic<unsigned long long>  atomic_ullong;
  typedef etl::atomic<wchar_t>             atomic_wchar_t;
  typedef etl::atomic<char16_t>            atomic_char16_t;
  typedef etl::atomic<char32_t>            atomic_char32_t;
  typedef etl::atomic<uint8_t>             atomic_uint8_t;
  typedef etl::atomic<int8_t>              atomic_int8_t;
  typedef etl::atomic<uint16_t>            atomic_uint16_t;
  typedef etl::atomic<int16_t>             atomic_int16_t;
  typedef etl::atomic<uint32_t>            atomic_uint32_t;
  typedef etl::atomic<int32_t>             atomic_int32_t;
  typedef etl::atomic<uint64_t>            atomic_uint64_t;
  typedef etl::atomic<int64_t>             atomic_int64_t;
  typedef etl::atomic<int_least8_t>        atomic_int_least8_t;
  typedef etl::atomic<uint_least8_t>       atomic_uint_least8_t;
  typedef etl::atomic<int_least16_t>       atomic_int_least16_t;
  typedef etl::atomic<uint_least16_t>      atomic_uint_least16_t;
  typedef etl::atomic<int_least32_t>       atomic_int_least32_t;
  typedef etl::atomic<uint_least32_t>      atomic_uint_least32_t;
  typedef etl::atomic<int_least64_t>       atomic_int_least64_t;
  typedef etl::atomic<uint_least64_t>      atomic_uint_least64_t;
  typedef etl::atomic<int_fast8_t>         atomic_int_fast8_t;
  typedef etl::atomic<uint_fast8_t>        atomic_uint_fast8_t;
  typedef etl::atomic<int_fast16_t>        atomic_int_fast16_t;
  typedef etl::atomic<uint_fast16_t>       atomic_uint_fast16_t;
  typedef etl::atomic<int_fast32_t>        atomic_int_fast32_t;
  typedef etl::atomic<uint_fast32_t>       atomic_uint_fast32_t;
  typedef etl::atomic<int_fast64_t>        atomic_int_fast64_t;
  typedef etl::atomic<uint_fast64_t>       atomic_uint_fast64_t;
  typedef etl::atomic<intptr_t>            atomic_intptr_t;
  typedef etl::atomic<uintptr_t>           atomic_uintptr_t;
  typedef etl::atomic<size_t>              atomic_size_t;
  typedef etl::atomic<ptrdiff_t>           atomic_ptrdiff_t;
  typedef etl::atomic<intmax_t>            atomic_intmax_t;
  typedef etl::atomic<uintmax_t>           atomic_uintmax_t;
}

#endif
