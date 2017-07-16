#ifndef TESSET_LIB_H
#define TESSET_LIB_H

#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static uint64_t passed = 0;
static uint64_t failed = 0;

//==============================================================================

#define assert_bool(func, expected, fail)                                                               \
  do                                                                                                    \
  {                                                                                                     \
    bool res = (func);                                                                                  \
    if (res != (expected))                                                                              \
    {                                                                                                   \
      printf("========================\n");                                                             \
      printf("FAILED: %s didn't pass the test.\n", #func);                                              \
      printf("REASON: expected %s got %s.\n", (expected) ? "true" : "false", (res) ? "true" : "false"); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);                                                  \
      failed++;                                                                                         \
      if (fail)                                                                                         \
        exit(0);                                                                                        \
    }                                                                                                   \
    else                                                                                                \
    {                                                                                                   \
      passed++;                                                                                         \
      printf("========================\n");                                                             \
      printf("SUCCESS: %s passed the test successfully.\n", #func);                                     \
    }                                                                                                   \
  } while (0)

//==============================================================================

#define assert_int(func, expected, fail)                                     \
  do                                                                         \
  {                                                                          \
    int64_t res = (func);                                                    \
    if (res != (expected))                                                   \
    {                                                                        \
      printf("========================\n");                                  \
      printf("FAILED: %s didn't pass the test.\n", #func);                   \
      printf("REASON: expected %ld got %ld.\n", (int64_t)(expected), (res)); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);                       \
      failed++;                                                              \
      if (fail)                                                              \
        exit(0);                                                             \
    }                                                                        \
    else                                                                     \
    {                                                                        \
      passed++;                                                              \
      printf("========================\n");                                  \
      printf("SUCCESS: %s passed the test successfully.\n", #func);          \
    }                                                                        \
  } while (0)

//==============================================================================

#define assert_uint(func, expected, fail)                                     \
  do                                                                          \
  {                                                                           \
    uint64_t res = (func);                                                    \
    if (res != (expected))                                                    \
    {                                                                         \
      printf("========================\n");                                   \
      printf("FAILED: %s didn't pass the test.\n", #func);                    \
      printf("REASON: expected %lu got %lu.\n", (uint64_t)(expected), (res)); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);                        \
      failed++;                                                               \
      if (fail)                                                               \
        exit(0);                                                              \
    }                                                                         \
    else                                                                      \
    {                                                                         \
      passed++;                                                               \
      printf("========================\n");                                   \
      printf("SUCCESS: %s passed the test successfully.\n", #func);           \
    }                                                                         \
  } while (0)

//==============================================================================

#define assert_string(func, expected, fail)                                            \
  do                                                                                   \
  {                                                                                    \
    const char *sres = (const char *)(func);                                           \
    uint64_t res = strcmp(sres, (const char *)(expected));                             \
    if (res != 0)                                                                      \
    {                                                                                  \
      printf("========================\n");                                            \
      printf("FAILED: %s didn't pass the test.\n", #func);                             \
      printf("REASON: expected \"%s\" got \"%s\".\n", (const char *)(expected), sres); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);                                 \
      failed++;                                                                        \
      if (fail)                                                                        \
        exit(0);                                                                       \
    }                                                                                  \
    else                                                                               \
    {                                                                                  \
      passed++;                                                                        \
      printf("========================\n");                                            \
      printf("SUCCESS: %s passed the test successfully.\n", #func);                    \
    }                                                                                  \
  } while (0)

//==============================================================================

#define assert_char(func, expected, fail)                           \
  do                                                                \
  {                                                                 \
    char res = (char)(func);                                        \
    if (res != (char)(expected))                                    \
    {                                                               \
      printf("========================\n");                         \
      printf("FAILED: %s didn't pass the test.\n", #func);          \
      printf("REASON: expected '%c' got '%c'.\n", (expected), res); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);              \
      failed++;                                                     \
      if (fail)                                                     \
        exit(0);                                                    \
    }                                                               \
    else                                                            \
    {                                                               \
      passed++;                                                     \
      printf("========================\n");                         \
      printf("SUCCESS: %s passed the test successfully.\n", #func); \
    }                                                               \
  } while (0)

//==============================================================================

#define assert_double(func, expected, fail)                                       \
  do                                                                              \
  {                                                                               \
    double res = (double)(func);                                                  \
    if (res != (double)(expected))                                                \
    {                                                                             \
      printf("========================\n");                                       \
      printf("FAILED: %s didn't pass the test.\n", #func);                        \
      printf("REASON: expected %lf got %lf.\n", (double)(expected), (double)res); \
      printf("WHERE : %s : %d\n", __FILE__, __LINE__);                            \
      failed++;                                                                   \
      if (fail)                                                                   \
        exit(0);                                                                  \
    }                                                                             \
    else                                                                          \
    {                                                                             \
      passed++;                                                                   \
      printf("========================\n");                                       \
      printf("SUCCESS: %s passed the test successfully.\n", #func);               \
    }                                                                             \
  } while (0)

//==============================================================================

#define check_bool(func, expected) assert_bool(func, expected, false)
#define check_int(func, expected) assert_int(func, expected, false)
#define check_uint(func, expected) assert_uint(func, expected, false)
#define check_string(func, expected) assert_string(func, expected, false)
#define check_char(func, expected) assert_char(func, expected, false)
#define check_double(func, expected) assert_double(func, expected, false)

#define expect_bool(func, expected) assert_bool(func, expected, true)
#define expect_int(func, expected) assert_int(func, expected, true)
#define expect_uint(func, expected) assert_uint(func, expected, true)
#define expect_string(func, expected) assert_string(func, expected, true)
#define expect_char(func, expected) assert_char(func, expected, true)
#define expect_double(func, expected) assert_double(func, expected, true)

//==============================================================================

#define begin_tests() \
  failed = 0;         \
  passed = 0;

#define finish_tests()                   \
  printf("========================\n");  \
  printf("    == Statistics ==\n");      \
  printf("========================\n");  \
  printf("Failed tests: %ld\n", failed); \
  printf("Passed tests: %ld\n", passed); \
  printf("========================\n");


#endif /* TESSET_LIB_H */