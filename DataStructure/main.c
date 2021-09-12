//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
////
//// Created by 15066 on 2021/9/11.
////
//#include "include/TreeMap.h"
//int *random(unsigned int length) { // remember to free the array
//    int* a = malloc(4 * length);
//    for (int i = 0; i < length; i++) {
//        a[i] = i;
//    }
//    srand((unsigned int)time(NULL));
//    while (--length) {
//        int temp = rand()%(length+1);
//        int t = a[length];
//        a[length] = a[temp];
//        a[temp] = t;
//    }
//    return a;
//}
//int main() {
//    unsigned int lang = 500000;
//    int *b = random(lang);
//    for (int ii = 0; ii < 1000000; ii++) {
//        clock_t start = clock();
//        TreeMap tr = Tree_NewTreeMap();
//        for (int i = 0; i < lang; i++) {
//            Tree_Insert(tr, b[i], 0);
//        }
//        printf_s("%d\n",clock()-start);
//        start = clock();
//        for (int i = 0; i < lang; i++) {
//            Tree_Get(tr, b[i]);
//        }
//        printf_s("%d\n",clock()-start);
//        start = clock();
//        for (int i = 0; i < lang; i++) {
//            Tree_Delete(tr, b[i]);
//        }
//        printf_s("%d\n",clock()-start);
//        start = clock();
//        puts("=====================");
//        free(tr);
//        //Tree_Destroy(tr);
//    }
//    free(b);
//    system("pause");
//    system("pause");
//    system("pause");
//    system("pause");
//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// Created by 15066 on 2021/9/11.

#include "include/HashMap.h"
#include "include/DCQueue.h"

long long unsigned *random(long long unsigned int length) { // remember to free the array
    long long unsigned *a = (long long unsigned*)malloc(sizeof(long long unsigned)* length);
    if(a == NULL){
        return NULL;
    }
    for (long long unsigned i = 0; i < length; i++) {
        a[i] = i;
    }
    srand((unsigned int) time(NULL));
    long long unsigned temp = rand() % (length + 1);
    while (--length) {
        temp = rand() % (length + 1);
        long long unsigned t = a[length];
        a[length] = a[temp];
        a[temp] = t;
    }
    return a;
}

int main() {
    unsigned int lang = 5000000;
    long long unsigned* a = random(lang);
    if (a == NULL) {
        return -1;
    }
    DCQueue queue = DCQueue_New();
    for(long long i = 0;i<lang;i++){
        if(a[i] % 2 == 0){
            DCQueue_PushToLast(queue,a[i]);
        }else{
            DCQueue_PushToNext(queue,a[i]);
        }
    }
    for(long long i = 0;i<lang;i++){
        printf_s("%d\n", DCQueue_PopToLast(queue));
    }
    free(queue);
    DCQueue_Destroy(queue);
//    clock_t start = clock();
//    for (int ii = 0; ii < 1000; ii++) {
//        HashMap ha = HashMap_New(lang);
//        if (ha == NULL) {
//            puts("Too lang !");
//            system("pause");
//            return 0;
//        }
//        for (long long unsigned i = 0; i < lang; i++) {
//            if(!HashMap_Set(ha, a[i], i)){
//                puts("??????");
//            }
//        }
//        printf_s("%d\n", clock() - start);
//        start = clock();
//        for (long long unsigned i = 0; i < lang; i++) {
//            if(HashMap_Get(ha, a[i])!=i){
//                puts("ok");
//            }
//        }
//        printf_s("%d\n", clock() - start);
//        start = clock();
//        for (long long unsigned i = 0; i < lang; i++) {
//            HashMap_Erase(ha, a[i]);
//        }
//        printf_s("%d\n", clock() - start);
//        start = clock();
//        HashMap_Destroy(ha);
//        puts("==============");
//    }
    free(a);
    system("pause");
    return 0;
}
