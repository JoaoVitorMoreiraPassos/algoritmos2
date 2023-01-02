#include <stdio.h>
#include "myString.h"


char *strcpy(char *s1, const char *s2){
    int t = 0;
    while(s2[t] != '\0'){
        s1[t] = s2[t];
        t ++;
    }
    s1[t] = '\0';
    // while (s1[t1] != 0)
    // {
    //     t1 ++;
    // }
    // int t2 = 0;
    // while (s2[t2] != '\0')
    // {
    //     s1[t2] = s2[t2];
    //     t2 ++;
    // }
    // int c;
    // if(t1 > t2){
    //     for (c = t2; c < t1; c ++){
    //         s1[c] = '\0';
    //     }
    // }
    // s1[t2] = '\0';
    // return s1;
}


char *strncpy(char *s1, const char *s2, size_t n){
    int c;
    for (c = 0; c < n; c ++ ){
        s1[c] = s2[c];
    }
    return s1;
}


char *strcat(char *s1, const char *s2){
    int t1 = 0;
    while (s1[t1] != '\0')
    {
        t1 ++;
    }
    int t2 = 0;
    while (s2[t2] != '\0')
    {
        s1[t1] = s2[t2];
        t1 ++;
        t2 ++;
    }
    s1[t1] = '\0';
    return s1;
}


char *strncat(char *s1, const char *s2, size_t n){
    int t1 = 0;
    while (s1[t1] != '\0')
    {
        t1 ++;
    }
    int c,i;
    int t2 = t1+n;
    for (c = t1,i = 0; c < t2; c ++,i ++){
        s1[c] = s2[i];
    }
    s1[c+1] = '\0';
    return s1;
}


int strcmp(const char *s1, const char *s2){
    int t;
    t = 0;
    
    while (s1[t] != '\0' && s2[t] != '\0'){
        if(s1[t] != s2[t]){
            if(s1[t] > s2[t]){
                return 1;
            }else if(s1[t] < s2[t]){
                return -1;
            }
        }
        t ++;
    }
    return 0;
}

int strncmp(const char *s1, const char *s2, size_t n){
    int t = 0, a = 1, b = -1;
    while (s1[t] != '\0' && s2[t] != '\0'){
        if (t == n){
            break;
        }
        if(s1[t] != s2[t]){
            if(s1[t] > s2[t]){
                return 1;
            }else if (s1[t] < s2[t]){
                return -1;
            }
        }
        t ++;
    }
    return 0;
}
