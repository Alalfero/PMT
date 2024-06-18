#include "CUnit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "MemoryTest.h"
#include <float.h>
#include <math.h>

double dEpsilon = DBL_EPSILON * 100;

unsigned int speicherAlloc=0;
unsigned int speicherFree=0;

unsigned int testidx = -1;
TestResults results = {
  NULL,
  0  
};

bool assertTrueLine(int line, char *message, bool val) {
    Test *test = &results.tests[testidx];

    if(test->errorcount > 0) {
      return val;
    }

    char buffer[RESULTSIZE];
    StringBuffer buf = {buffer, RESULTSIZE, 0};

    if (!val) {
        test->errorcount++;
        sbprintf(&buf, "    <failure message=\"true expected: (%d) fail: ", line);

        char* it;
        for (it= message;*it != '\0';it++) {
            switch (*it) {
                case '\n': sbprintf(&buf, " "); break;
                case '\"': sbprintf(&buf, "\\\""); break;
                default: sbprintf(&buf, "%c", *it);
            }
        }

        sbprintf(&buf," \">\n");
        sbprintf(&buf,"       (%d) fail: %s\n",line,message);
        sbprintf(&buf,"    </failure>\n");
    } else {
        sbprintf(&buf,"<success></success>\n");
    }

    strncpy(test->result, buf.buffer, sizeof(test->result) - 1);
    writeResults();
    return val;
}


bool assertIntEqLine(int line,char* message, int expected, int found){
  Test *test = &results.tests[testidx];

  if(test->errorcount > 0) {
    return true;
  }

  char buffer[RESULTSIZE];
  StringBuffer buf = {buffer, RESULTSIZE, 0};
  
  bool result = expected==found;
  if (!result){
    test->errorcount++;

    sbprintf(&buf,"    <failure message=\"line (%d) expected:&lt;%d&gt; but was:&lt;%d&gt;: ",line, expected,found);
    char* it;
    for (it= message;*it != '\0';it++) {
      switch (*it){
      case '\n': sbprintf(&buf," ");break;
      case '\"': sbprintf(&buf,"\\\"");break;
      default: sbprintf(&buf,"%c",*it);
      }
    }
    sbprintf(&buf,"\">\n");
    sbprintf(&buf,"    </failure>\n");
  } else {
    sbprintf(&buf,"<success></success>\n");
  }

  strncpy(test->result, buf.buffer, sizeof(test->result) - 1);
  writeResults();
  return result;
}

bool assertDoubleEqLine(int line,char* message, double expected, double found){
  Test *test = &results.tests[testidx];

  if(test->errorcount > 0) {
    return true;
  }

  char buffer[RESULTSIZE];
  StringBuffer buf = {buffer, RESULTSIZE, 0};

  bool result = fabs(expected - found) <= dEpsilon;
  if (!result){
      test->errorcount++;
      sbprintf(&buf,"    <failure message=\"expected:&lt;%.20f&gt; but was:&lt;%.20f&gt;\">\n",expected,found);
      sbprintf(&buf,"      (%d) fail: %s, expected %f found %f\n",line,message,expected,found);
      sbprintf(&buf,"    </failure>\n");
  } else {
      sbprintf(&buf,"<success></success>\n");
  }

  strncpy(test->result, buf.buffer, sizeof(test->result) - 1);
  writeResults();
  return result;
}

bool assertStringEqLine(int line,char* message, char* expected,char* this){
  Test *test = &results.tests[testidx];
  
  if(test->errorcount > 0) {
    return true;
  }

  char buffer[RESULTSIZE];
  StringBuffer buf = {buffer, RESULTSIZE, 0};

  bool result = strcmp(expected,this)==0;
  if (!result){
    test->errorcount++;
    sbprintf(&buf,"    <failure message=\"siehe Details\">\n");
    sbprintf(&buf,"      (%d) fail: %s, expected <pre><![CDATA[\"%s\"]]>]<![CDATA[]></pre> but found  <pre><![CDATA[\"%s\"]]>]<![CDATA[]></pre>\n",line,message,expected,this);
    sbprintf(&buf,"    </failure>\n");
  } else {
    sbprintf(&buf,"<success></success>\n");
  }

  strncpy(test->result, buf.buffer, sizeof(test->result) - 1);
  writeResults();
  return result;
}

void writeResults() {
  char* filename = "cunit_results.xml";

  // open the file for writing
  FILE *fp = fopen(filename, "w");
  if (fp == NULL){
    printf("Error opening the file %s", filename);
    return;
  }
  
  fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n");
  fprintf(fp,"<testsuite>\n");

  for(int i = 0; i < results.testcount; i++) {
    fprintf(fp,"  <testcase name=\"%s\">\n",results.tests[i].name);
    fprintf(fp, "%s", results.tests[i].result);
    fprintf(fp,"  </testcase>\n");
  }

  fprintf(fp,"<storage allocated=\"%d\" free=\"%d\"/>\n",speicherAlloc,speicherFree);
  fprintf(fp,"</testsuite>");
  fclose(fp);
}

void shutdown(){
  if(results.tests != NULL) {
    free(results.tests);
  }
}

void testDeclare(const char *name) {
  createOrUpdateTest(name, "<pending></pending>\n");
}

void testStart(const char *name) {
  testidx = createOrUpdateTest(name, "<started></started>\n");
}

int createOrUpdateTest(const char *name, char *result) {

  int idx = -1;
  for(int i = 0; i < results.testcount; i++) {
    if(strcmp(name, results.tests[i].name) == 0) {
      idx = i;
      break;
    }
  }

  if(idx == -1) {
    results.tests = realloc(results.tests, (results.testcount + 1) * sizeof(Test));
    if (results.tests == NULL) {
      perror("realloc in testStart failed");
      exit(1);
    }
    idx = results.testcount;
    results.testcount++;
  } 

  strncpy(results.tests[idx].name, name, sizeof(results.tests[idx].name) - 1);
  strncpy(results.tests[idx].result, result, sizeof(results.tests[idx].result) - 1);
  results.tests[idx].errorcount = 0;
  writeResults();

  return idx;
}

void sbprintf(StringBuffer *strBuf, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(strBuf->buffer + strBuf->currentLen, strBuf->bufSize - strBuf->currentLen, format, args);
    va_end(args);
    if (len > 0) {
        strBuf->currentLen += len;
    }
}