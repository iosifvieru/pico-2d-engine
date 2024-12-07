#include "Utils.h"

int abs(int x){
    int s = x >> 31;
    return (x ^ s) - s;
}