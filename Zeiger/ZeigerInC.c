#include "ZeigerInC.h"
#include <stdlib.h>
#include <stdbool.h>

void reverse(int* xs,int length){
    for (int i = 0; i < length / 2; i++) {
        int temp = xs[i];
        xs[i] = xs[length - 1 - i];
        xs[length - 1 - i] = temp;
    }
}int fold(int xs [],int length,int op(int,int),int startV){
    for (int i = 0; i < length; i++) {
        startV = op(startV, xs[i]);
    }
    return startV;
}
int length(char* text){
    int i = 0;
    while (text[i] != '\0') {
        i++;
    }
    return i;
}
bool isPallindrom(char* text){
    int l= length(text);
    for (int i = 0; i < l / 2; i++) {
        if (text[i] != text[l- 1 - i]) return false;
    }
    return true;
}

int leseAlsZahl(char* text){
    int result = 0;
    for (int i = 0; text[i] != '\0'; i++)  result = result * 10 + (text[i] - '0');
    return result;

}
char* concat(char* text1,char* text2){
    int length1 = length(text1);
    int length2 = length(text2);
    char* result = (char*)malloc((length1 + length2 + 1) * sizeof(char));
    if (result == NULL) return NULL;
    for (int i = 0; i < length1; i++) result[i] = text1[i];

    for (int i = 0; i < length2; i++) result[length1 + i] = text2[i];
    result[length1 + length2] = '\0';
    return result;
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
    if (i >= 0 && i < this.size) return this.store[i];
    return (E)0;
}void alRemove(AL* this, int i) {
    if (i >= 0 && i < this->size) {
        for (int j = i; j < this->size - 1; j++) {
            this->store[j] = this->store[j + 1];
        }
        this->size--;
    }
}void alAddAll(AL* this, AL that) {
    for (int i = 0; i < that.size; i++) alAdd(this, that.store[i]);
}bool alContainsWith(AL this,Predicate pred) {
    for (int i = 0; i < this.size; i++) {
        if (pred(this.store[i])) return true;
    }
    return false;
}AL alSublist(AL this, int i, int l) {
    AL result = alNew();
    for (int j = 0; j < l && (i + j) < this.size; j++) alAdd(&result, this.store[i + j]);
    return result;
}bool alStartsWith(AL this,AL that,EQ eq) {
    if (that.size > this.size) return false;
    for (int i = 0; i < that.size; i++) {
        if (!eq(this.store[i], that.store[i])) return false;
    }
    return true;
}bool alEndsWith(AL this,AL that,EQ eq) {
    if (that.size > this.size) return false;
    int offset = this.size - that.size;
    for (int i = 0; i < that.size; i++) {
        if (!eq(this.store[offset + i], that.store[i])) return false;
    }
    return true;
}void alReverse(AL* this) {
    for (int i = 0; i < this->size / 2; i++) {
        E temp = this->store[i];
        this->store[i] = this->store[this->size - 1 - i];
        this->store[this->size - 1 - i] = temp;
    }
}void alInsert(AL* this,int i, E e) {
    if (i >= 0 && i <= this->size) {
        if (this->size >= this->capacity) {
            this->capacity += 5;
            this->store = (E*)realloc(this->store, this->capacity * sizeof(E));
        }
        for (int j = this->size; j > i; j--) this->store[j] = this->store[j - 1];
        this->store[i] = e;
        this->size++;
    }
}void alSortBy(AL* this,Comparator cmp) {
//habs versucht. Hab keine Kraft mehr

}
