#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<stdint.h>

/*
 * bcd-add.c
 * author:
 * date:
 *
 * Honor code:
 *
 */


uint32_t ato_bcd(char a[], int len) {
    int i, j = 0 ;
    uint32_t r = 0, d ;
    // finish this function
    for(i=0; i<len; i++)
    {
        d = a[i] - '0';
        //d=atoi(&a[i])
        r |= d;
        if(i<len-1)
            r<<=4;
    }
    return r ;
}

int bcd_toa( uint32_t d, char a[], int len ) {
    uint32_t bit, i;
    int l = 2*sizeof(uint32_t) ;
    uint32_t mask = 0xf;
    uint32_t dCopy1 = d;
    uint32_t dCopy2 = d;
    char c;
// finish this function
    int counter = 0;
    while(dCopy1 != 0)
    {
        counter++;
        dCopy1 = dCopy1 >> 4;
    }
    i=0;
    bit=0;
    while(i<counter)
    {
        bit = dCopy2&mask;
        dCopy2 >>= 4;
        c = bit + '0';
        int aIndex = counter-i-1;
        i++;
        a[aIndex] = c;
    }
    a[counter] = '\0';
    //printf("a: %s", a);

    return l ;
}


uint32_t bcd_add(uint32_t d1, uint32_t d2) {

// finish this function
    uint32_t dCopy = d1;
    uint32_t d1Copy1 = d1;
    uint32_t d2Copy1 = d2;
    //uint32_t d2Copy2 = d2;
    uint32_t mask = 0xf;
    uint32_t nibble_d1, nibble_d2, nibble_result, carry = 0;
    uint32_t output = 0;
    
    int counter = 8, i=0;
    /*while(dCopy != 0) //assuming d1 and d2 have the same number of digits
    {
        counter++;
        dCopy >>= 4;
    }*/
    
    while (i<counter)
    {
        nibble_d1 = d1Copy1&mask;
        nibble_d2 = d2Copy1&mask;
        nibble_result = nibble_d1+nibble_d2+carry;
        if(nibble_result >= 0xa)
        {
            nibble_result -= 0xa;
            carry = 1;
        }
        else {
            carry = 0;
        }
        nibble_result <<= (4*i);
        output |= nibble_result;
        i++;
        d1Copy1 >>= 4;
        d2Copy1 >>= 4;
    }
    return output;
}

uint32_t bcd_9complement(uint32_t d) {
    uint32_t d1 = 0 ;

// finish this function
    
    return d1 ;
}

uint32_t bcd_sub(uint32_t d1, uint32_t d2) {
    uint32_t d = 0  ;
    
// finish this function
    uint32_t dCopy = d1;
    uint32_t d1Copy1 = d1;
    uint32_t d2Copy1 = d2;
    //uint32_t d2Copy2 = d2;
    uint32_t mask = 0xf;
    uint32_t nibble_d1, nibble_d2, nibble_result, carry = 0;
    //uint32_t output = 0;
    
    int counter = 8, i=0;
    /*while(dCopy != 0) //assuming d1 and d2 have the same number of digits
    {
        counter++;
        dCopy >>= 4;
    }*/
    
    while (i<counter)
    {
        nibble_d1 = d1Copy1&mask;
        nibble_d2 = d2Copy1&mask;
        nibble_result = (nibble_d1+carry)-nibble_d2;
        if(nibble_d2>nibble_d1)
        {
            carry = 10;
            nibble_result = (nibble_d1+carry)-nibble_d2;
            carry = -1;
        }
        else {
            carry = 0;
        }
        nibble_result <<= (4*i);
        d |= nibble_result;
        i++;
        d1Copy1 >>= 4;
        d2Copy1 >>= 4;
    }
    return d ;
}

int main(int argc, char * argv[]) {
    uint32_t d1, d2, d_add, d_sub ;
    char s1[1*sizeof(int)+1] ;
    char s2[2*sizeof(int)+1] ;
    char s[2*sizeof(int)+1] ;
    int len ;

    char op = '+' ;

    //assert(argc==3) ;
    assert(sizeof(uint32_t)==4) ;
    
    d1 = ato_bcd(argv[1], strlen(argv[1])) ;
    //d1 = ato_bcd("130",3);
    d2 = ato_bcd(argv[2], strlen(argv[2])) ;
    
    len = bcd_toa(d1, s1, 2*sizeof(uint32_t)) ;
    s1[len] = '\0' ;
    len = bcd_toa(d2, s2, 2*sizeof(uint32_t)) ;
    s2[len] = '\0' ;

//    d_add = bcd_add(d1, d2) ;
//    d_sub = bcd_sub(d1, d2) ;
//
//    len = bcd_toa(d_add, s, 2*sizeof(uint32_t)) ;
//    s[len] = '\0' ;
//    printf("%s %c %s = %s\n", s1, '+', s2, s ) ;
//    len = bcd_toa(d_sub, s, 2*sizeof(uint32_t)) ;
//    s[len] = '\0' ;
//    printf("%s %c %s = %s\n", s1, '-', s2, s ) ;
//
    
     return 0 ;
 }
