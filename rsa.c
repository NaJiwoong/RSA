/* 20170201 NaJiwoong */
/* 2020 May 21th */

/*   Environment
 *	 
 *	 Ubuntu 16.04.12
 *	 gcc 5.4.0 
 */

/* 		Execution
 *
 *	 	"make"
 *	 	 - make execution file, and output.txt
 *	 	"make clean"
 *	 	 - clean execution file, and output.txt
 */

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#include "mod.h"


/* Function for get random public key e */

uint64_t getE(uint64_t n){
	
	srand((uint32_t)(time(NULL)));
	uint64_t seed = (uint64_t)(rand()%16384);
	uint64_t e = (seed+1)*n/16385llu;

	uint64_t cd = 0;
	while (cd != 1){
		cd = gcd(e, n);
		e--;
	}
	e++;
	
	if (e == 1 || e==0){
		printf("Error: Cannot find appropriate e\n");
		exit(-1);
	}

	return e;
}


/* Function for get private key d */
uint64_t getD(uint64_t e, uint64_t N){
		return inverse(e, N);
}

/* Function for Encyprtion */
uint64_t encrypt(uint64_t M, uint64_t e, uint64_t N){
	return mod(N, M, e);
}

uint64_t decrypt(uint64_t C, uint64_t d, uint64_t N){
	return mod(N, C, d);
}
