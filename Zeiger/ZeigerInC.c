#include "ZeigerInC.h"
#include <stdlib.h>
#include <stdbool.h>

void reverse(int* xs,int length){
}int fold(int xs [],int length,int op(int,int),int startV){
    return startV;
}
int length(char* text){
    return 0;
}
bool isPallindrom(char* text){
    return true;
}

int leseAlsZahl(char* text){
    int result=0;

}
char* concat(char* text1,char* text2){
    return NULL;
}AL alNew(){
    AL this;
    this.size = 0;
    this.capacity = 5;
    this.store = (E*)malloc(this.capacity*sizeof(E));
    return this;
}
void alDelete(AL this){
    free(this.store);
}

void alAdd(AL* this, E e){
    if (this->size>=this->capacity){
        this->capacity =5+this->capacity;
        this->store = (E*)realloc(this->store,(this->capacity)*sizeof(E));
    }

    this->store[this->size++] = e;
}
void alForEach(AL this, void f(E)){
    unsigned int i;
    for (i=0;i<this.size;i++) f(this.store[i]);
}
E alFold(AL this, E start, void op(E,E)){
    unsigned int i;
    for (i=0;i<this.size;i++)
        op(start,this.store[i]);
    return start;
}
E alGet(AL this, int i) {
    /* ToDo */
    return NULL;
}void alRemove(AL* this, int i) {
    /* ToDo */
}void alAddAll(AL* this, AL that) {
    /* ToDo */
}bool alContainsWith(AL this,Predicate pred) {
    /* ToDo */
    return false;
}AL alSublist(AL this, int i, int l) {
    /* ToDo */
    return result;
}bool alStartsWith(AL this,AL that,EQ eq) {
    /* ToDo */
    return true;
}bool alEndsWith(AL this,AL that,EQ eq) {
    /* ToDo */
    return true;
}void alReverse(AL* this) {
    /* ToDo */
}void alInsert(AL* this,int i, E e) {
    /* ToDo */
}void alSortBy(AL* this,Comparator cmp) {
    /* ToDo */
}