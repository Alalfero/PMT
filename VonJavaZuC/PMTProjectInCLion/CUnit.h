#ifndef __CUnit__H__
#define __CUnit__H__

#include <stdbool.h>

#define assertTrue(m,v)(assertTrueLine(__LINE__,m,v))
#define assertIntEq(m,v1,v2)(assertIntEqLine(__LINE__,m,v1,v2))
#define assertDoubleEq(m,v1,v2)(assertDoubleEqLine(__LINE__,m,v1,v2))
#define assertStringEq(m,s,v)(assertStringEqLine(__LINE__,m,s,v))

#define RESULTSIZE 1024

typedef struct {
  char name[255];
  char result[RESULTSIZE];
  int errorcount;
} Test;

typedef struct {
  Test *tests;
  int testcount;
} TestResults;

extern double dEpsilon;
extern unsigned int testidx;
extern TestResults results;

bool assertTrueLine(int line,char* message, bool val);
bool assertIntEqLine(int line,char* message, int expected, int found);
bool assertDoubleEqLine(int line,char* message, double expected, double found);
bool assertStringEqLine(int line,char* message,char* expected,char* this);

int createOrUpdateTest(const char *name, char* result);
void testDeclare(const char *name);
void testStart(const char *name);
void shutdown();

void writeResults();

typedef struct {
    char *buffer;
    int bufSize;
    int currentLen;
} StringBuffer;

void sbprintf(StringBuffer *strBuf, const char *format, ...);
#endif
