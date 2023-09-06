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


	return r ;
}

int bcd_toa( uint32_t d, char a[], int len ) {
	int bit, i ;
	int l = 2*sizeof(uint32_t) ;
	
// finish this function


	return l ;
}


uint32_t bcd_add(uint32_t d1, uint32_t d2) {

// finish this function 

	return 0 ;
}

uint32_t bcd_9complement(uint32_t d) {
	uint32_t d1 = 0 ;

// finish this function

	return d1 ;
}

uint32_t bcd_sub(uint32_t d1, uint32_t d2) {
	uint32_t d = 0  ;
	
// finish this function

	return d ;
}

int main(int argc, char * argv[]) {
	uint32_t d1, d2, d_add, d_sub ;
	char s1[1*sizeof(int)+1] ;
	char s2[2*sizeof(int)+1] ;
	char s[2*sizeof(int)+1] ;
	int len ;

	char op = '+' ;

	assert(argc==3) ;
	assert(sizeof(uint32_t)==4) ;
	
	d1 = ato_bcd(argv[1], strlen(argv[1])) ;
	d2 = ato_bcd(argv[2], strlen(argv[2])) ;
	
	len = bcd_toa(d1, s1, 2*sizeof(uint32_t)) ;
	s1[len] = '\0' ;
	len = bcd_toa(d2, s2, 2*sizeof(uint32_t)) ;
	s2[len] = '\0' ;

	d_add = bcd_add(d1, d2) ;
	d_sub = bcd_sub(d1, d2) ;

	len = bcd_toa(d_add, s, 2*sizeof(uint32_t)) ;
	s[len] = '\0' ;
	printf("%s %c %s = %s\n", s1, '+', s2, s ) ;
	len = bcd_toa(d_sub, s, 2*sizeof(uint32_t)) ;
	s[len] = '\0' ;
	printf("%s %c %s = %s\n", s1, '-', s2, s ) ;
	
	
 	return 0 ;
 }