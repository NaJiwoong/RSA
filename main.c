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

#include "mod.h"
#include "rsa.h"

int64_t totient(int64_t p, int64_t q){
	return (p-1)*(q-1);
}

int main(void){
	FILE *fp;
	fp = fopen("./output.txt", "wt");
	if (fp ==NULL){
		printf("Error: cannot open file\n");
		return -1;
	}

	int64_t p1, p2, q1, q2, M1, M2;
	int64_t e1, e2, d1, d2, N1, N2;
	int64_t C1, C2, D1, D2;
	int64_t n1, n2;
	p1 = 2357;
	q1 = 2551;
	M1 = 1234;
	p2 = 885320963;
	q2 = 238855417;
	M2 = 1234567l;
	n1 = p1*q1;
	n2 = p2*q2;

	/* CASE 1 */
	N1 = totient(p1, q1);
	e1 = getE(N1);
	d1 = getD(e1, N1);
	C1 = encrypt(M1, e1, n1);
	D1 = decrypt(C1, d1, n1);


	fprintf(fp, "< RESULT FOR RSA > \n");
	fprintf(fp, "20170201 NaJiwoong \n");

	fprintf(fp, "\n < CASE 1 RESULT > \n\n");
	
	fprintf(fp, "N: %li\n", n1);
	fprintf(fp, "phi(n): %li\n", N1);
	fprintf(fp, "Encyption key: %li\n", e1);
	fprintf(fp, "Decyption key: %li\n", d1);
	fprintf(fp, "Plain Text: %li\n", M1);
	fprintf(fp, "Encryption: %li\n", C1);
	fprintf(fp, "Decryption: %li\n", D1);

	fprintf(fp, "\n----------------------------------------------\n\n");

	/* CASE 2 */
	
	N2 = totient(p2, q2);
	e2 = getE(N2);
	d2 = getD(e2, N2);
	C2 = encrypt(M2, e2, n2);
	D2 = decrypt(C2, d2, n2);

	fprintf(fp, "\n < CASE 2 RESULT > \n\n");
	
	fprintf(fp, "N: %li\n", n2);
	fprintf(fp, "phi(n): %li\n", N2);
	fprintf(fp, "Encyption key: %li\n", e2);
	fprintf(fp, "Decyption key: %li\n", d2);
	fprintf(fp, "Plain Text: %li\n", M2);
	fprintf(fp, "Encryption: %li\n", C2);
	fprintf(fp, "Decryption: %li\n", D2);

	fclose(fp);
	
	return 0;
}




