#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX3(X,Y) ((X) > (Y) ? (X) : (Y))
#define TIME 2000000000

int max1(int a, int b) {
  if(a > b)
    return a;
  return b;
}

int max2(int x, int y) {return x ^ ((x ^ y) & -(x < y));}

int max4(int a, int b) { int i  =  -(a > b); return (a & i)|(b & ~i); }

void tmax1() {
    int nu;
    long j;
    /*double t, t1;*/
    /*t = time(NULL);*/
    for(j = 0; j<TIME; j++) {
        int a = rand()%256-128;
        int b = rand()%256-128;
        nu = max1(a, b);
    }
    /*t1 = time(NULL);*/
    /*printf("%lf\n", difftime(t1,t));*/
}

void tmax2() {
    int nu;
    long j;
    /*double t, t1;*/
    /*t = time(NULL);*/
    for(j = 0; j<TIME; j++) {
        int a = rand()%256-128;
        int b = rand()%256-128;
        nu = max2(a, b);
    }
    /*t1 = time(NULL);*/
    /*printf("%lf\n", difftime(t1,t));*/
}

void tmax3() {
    int nu;
    long j;
    /*double t, t1;*/
    /*t = time(NULL);*/
    for(j = 0; j<TIME; j++) {
        int a = rand()%256-128;
        int b = rand()%256-128;
        nu = MAX3(a, b);
    }
    /*t1 = time(NULL);*/
    /*printf("%lf\n", difftime(t1,t));*/
}

void tmax4() {
    int nu;
    long j;
    /*double t, t1;*/
    /*t = time(NULL);*/
    for(j = 0; j<TIME; j++) {
        int a = rand()%256-128;
        int b = rand()%256-128;
        nu = max4(a, b);
    }
    /*t1 = time(NULL);*/
    /*printf("%lf\n", difftime(t1,t));*/
}

int main() {
    srand((unsigned)time(NULL));
    /*tmax1();*/
    /*tmax2();*/
    /*tmax3();*/
    tmax4();

    return 0;
}
