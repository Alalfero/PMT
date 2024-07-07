#include "MemoryTest.h"

#include "CUnit2.h"
#include "ZeigerInC.h"
#include <stdio.h>

#define assertALEq(m,s,v,eq,p)(assertALEqLine(__LINE__,m,s,v,eq,p))
#define assertArrayEq(m,s,v,l1,l2)(assertArrayEqLine(__LINE__,m,s,v,l1,l2))

typedef void Print(Object);

int add(int x,int y){return x+y;}
int mult(int x,int y){return x*y;}

bool alCmp(AL this,AL that,EQ eq){
    if (this.size!=that.size) return false;
    int i;
    for (i=0;i<this.size;i++)if (!eq(alGet(this,i),alGet(that,i))) return false;
    return true;
}

bool arrayCmp(int* this,int* that, unsigned int thislength, unsigned int thatlength){
    if (thislength!=thatlength) return false;
    int i;
    for (i=0;i<thislength;i++)if (this[i]!=that[i]) return false;
    return true;
}

void alPrint(AL this,Print p){
    fprintf(fp,"[");
    int i;
    for(i=0;i<this.size;i++){
        if(i>0) fprintf(fp,", ");
        p(alGet(this,i));
    }
    fprintf(fp,"]");
}


void arrayPrint(int* this,unsigned int length){
    fprintf(fp,"[");
    int i;
    for(i=0;i<length;i++){
        if(i>0) fprintf(fp,", ");
        fprintf(fp,"%d",this[i]);
    }
    fprintf(fp,"]");
}


bool assertArrayEqLine(int line,char* message,int* expected,int* this,unsigned int thatlength,unsigned int thislength){
    testcount++;
    bool result = arrayCmp(expected,this,thislength,thatlength);
    if (!result){
        errorcount++;
        fprintf(fp,"    <failure type=\"AssertionFailedError\">\n");
        fprintf(fp,"      (%d) fail: %s, expected ",line,message);
        arrayPrint(expected,thatlength);
        fprintf(fp," but found ");
        arrayPrint(this,thislength);
        fprintf(fp,"\n");
        fprintf(fp,"    </failure>\n");
        fflush(stdout);
    }
    return result;
}


bool assertALEqLine(int line,char* message,AL expected,AL this,EQ eq, Print p){
    testcount++;
    bool result = alCmp(expected,this,eq);
    if (!result){
        errorcount++;
        fprintf(fp,"    <failure type=\"AssertionFailedError\">\n");
        fprintf(fp,"      (%d) fail: %s, expected ",line,message);
        alPrint(expected,p);
        fprintf(fp," but found ");
        alPrint(this,p);
        fprintf(fp,"\n");
        fprintf(fp,"    </failure>\n");
        fflush(stdout);
    }
    return result;
}


bool eqIntObject(Object o1,Object o2){
    int* i1 = (int*)o1;
    int* i2 = (int*)o2;
    return *i1==*i2;
}

int cmpIntObject(Object o1,Object o2){
    int* i1 = (int*)o1;
    int* i2 = (int*)o2;
    return *i1-*i2;
}

void printIntObject(Object o){
    int* i = (int*)o;
    fprintf(fp,"%d ",*i);
}

int is[]={1,2,3,4,5,6,7,8,9};
int js[]={9,8,7,6,5,4,3,2,1};

AL xs;
AL ys;

void initXs(){
    xs = alNew();
    int i;
    for (i=0;i<9;i++)
        alAdd(&xs,is+i);
}
void initYs(){
    ys = alNew();
    int i;
    for (i=0;i<9;i++)
        alAdd(&ys,js+i);
}

bool fuenferTeiler(Object o){
    int* i =(int*)o;
    return *i % 5 == 0;
}
bool zehnerTeiler(Object o){
    int* i =(int*)o;
    return *i % 10 == 0;
}

int main(int argc, char** args){
    printHeader();

    testStart("reverseArray");
    int as[] = {1,2,3,4,5};
    int bs[] = {5,4,3,2,1};
    reverse(as,5);
    assertArrayEq("reverse funktioniert nicht für Array", (int*)as, (int*)bs, 5, 5);
    testEnd();

    testStart("fold 1");
    assertIntEq("fold mit Summe geht nicht", fold(as,5,add,0), 15);
    testEnd();

    testStart("fold 2");
    assertIntEq("fold mit Produkt geht nicht", fold(as,5,mult,1), 120);
    testEnd();

    testStart("length 1");
    assertIntEq("Stringlänge falsch", length("hallo"), 5);
    testEnd();

    testStart("length 2");
    assertIntEq("Stringlänge falsch", length(""), 0);
    testEnd();

    testStart("isPallindrom 1");
    assertTrue("isPallindrom \"lagerregal\" falsch",isPallindrom("lagerregal"));
    testEnd();

    testStart("isPallindrom 2");
    assertTrue("isPallindrom \"\" falsch",isPallindrom(""));
    testEnd();

    testStart("leseAlsZahl 1");
    assertIntEq("leseAlsZahl \"42\"", leseAlsZahl("42"), 42);
    testEnd();

    testStart("leseAlsZahl 2");
    assertIntEq("leseAlsZahl \"0000\"", leseAlsZahl("0000"), 0);
    testEnd();

    testStart("concat 1");
    char* result = concat("hallo ","welt");
    assertStringEq("concat von String falsch",result, "hallo welt");
    free(result);
    testEnd();

    testStart("concat 2");
    result = concat("","welt");
    assertStringEq("concat von String falsch",result, "welt");
    free(result);
    testEnd();

    testStart("concat 3");
    result = concat("","");
    assertStringEq("concat von String falsch",result, "");
    free(result);
    testEnd();

    testStart("get 1");
    initXs();
    int* i1 = alGet(xs,5);
    assertIntEq("get holt falsches Elenent", 6, *i1);
    testEnd();
    alDelete(xs);

    testStart("remove 1");
    initXs();
    ys = alNew();
    alRemove(&xs,0);
    int i;
    for (i=1;i<9;i++)
        alAdd(&ys,is+i);
    assertALEq("remove des ersten Elements falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("remove 2");
    initXs();
    ys = alNew();
    alRemove(&xs,8);

    for (i=0;i<8;i++)
        alAdd(&ys,is+i);
    assertALEq("remove des letzten Elements falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("remove 3");
    initXs();
    ys = alNew();
    alRemove(&xs,5);

    for (i=0;i<9;i++)
        if (i!=5)alAdd(&ys,is+i);
    assertALEq("remove des sechsten Elements falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);


    testStart("addALL 1");
    initXs();
    ys = alNew();
    alAddAll(&xs,ys);
    assertALEq("addAll mit leerer Liste falsch",xs,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("addALL 2");
    initXs();
    ys = alNew();
    alAddAll(&ys,xs);
    assertALEq("addAll auf leerer Liste falsch",xs,ys,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("addALL 3");
    initXs();
    ys = alNew();
    alAddAll(&xs,xs);
    for (i=0;i<9;i++) alAdd(&ys,is+i);
    for (i=0;i<9;i++) alAdd(&ys,is+i);

    assertALEq("addAll falsch",xs,ys,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);


    testStart("containWith");
    initXs();
    assertTrue("sollte 5 teilbare Zahl enthalten",alContainsWith(xs,fuenferTeiler));
    testEnd();
    alDelete(xs);

    testStart("containWith");
    initXs();
    assertTrue("sollte keine 10 teilbare Zahl enthalten",!alContainsWith(xs,zehnerTeiler));
    testEnd();
    alDelete(xs);

    testStart("containWith");
    xs = alNew();
    assertTrue("leere Liste sollte keine 5 teilbare Zahl enthalten",!alContainsWith(xs,fuenferTeiler));
    testEnd();
    alDelete(xs);

    testStart("sublist 1");
    initXs();
    AL r = alSublist(xs,0,10);
    assertALEq("sublist falsch",xs,r,eqIntObject,printIntObject);
    alDelete(r);
    r = alSublist(xs,0,100);
    assertALEq("sublist falsch",xs,r,eqIntObject,printIntObject);
    alDelete(r);
    r = alSublist(xs,2,1);
    ys = alNew();
    alAdd(&ys,is+2);
    assertALEq("sublist falsch",ys,r,eqIntObject,printIntObject);
    testEnd();
    alDelete(r);
    alDelete(ys);
    alDelete(xs);

    testStart("sublist 2");
    xs = alNew();
    r = alSublist(xs,0,10);
    assertALEq("sublist falsch",xs,r,eqIntObject,printIntObject);
    testEnd();
    alDelete(r);
    alDelete(xs);

    testStart("sublist 3");
    initXs();
    r = alSublist(xs,4,3);
    ys = alNew();
    for (i=4;i<7;i++)alAdd(&ys,is+i);
    assertALEq("sublist falsch",ys,r,eqIntObject,printIntObject);
    testEnd();
    alDelete(r);
    alDelete(xs);
    alDelete(ys);


    testStart("startsWith 1");
    initXs();
    ys = alNew();
    assertTrue("jede Liste startet mit leerer Liste!",alStartsWith(xs,ys,eqIntObject));
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("startsWith 2");
    initXs();
    assertTrue("jede Liste startet mit sich selbst!",alStartsWith(xs,xs,eqIntObject));
    testEnd();
    alDelete(xs);

    testStart("startsWith 3");
    initXs();
    ys = alNew();
    for (i=0;i<7;i++)alAdd(&ys,is+i);
    assertTrue("Präfix nicht erkannt",alStartsWith(xs,ys,eqIntObject));
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("startsWith 4");
    initXs();
    ys = alNew();
    assertTrue("die leere Liste hat nur sich als Präfix",!alStartsWith(ys,xs,eqIntObject));
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("startsWith 5");
    initXs();
    initYs();
    assertTrue("fehlerhafter Präfix erkannt",!alStartsWith(ys,xs,eqIntObject));
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("startsWith 6");
    ys = alNew();
    assertTrue("jede Liste startet mit leerer Liste!",alStartsWith(ys,ys,eqIntObject));
    testEnd();
    alDelete(ys);


    testStart("reverse 1");
    initXs();
    initYs();
    alReverse(&xs);
    assertALEq("reverse falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);


    testStart("reverse 2");
    xs = alNew();
    ys = alNew();

    alReverse(&xs);
    assertALEq("reverse falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);


    testStart("sortBy 1");
    initXs();
    initYs();
    alSortBy(&ys,cmpIntObject);
    assertALEq("sortiert falsch",xs,ys,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);


    testStart("sortBy 2");
    initXs();
    ys = alNew();
    for (i=0;i<9;i++)alAdd(&ys,is+i);

    alSortBy(&xs,cmpIntObject);
    assertALEq("sortiert falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    testStart("sortBy 3");
    xs = alNew();
    ys = alNew();
    alSortBy(&xs,cmpIntObject);
    assertALEq("sortiert falsch",ys,xs,eqIntObject,printIntObject);
    testEnd();
    alDelete(xs);
    alDelete(ys);

    printResults();
    printStorage();

    printFoot();
    return 0;
}
