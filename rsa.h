#include <stdint.h>

int64_t getE(int64_t n);

int64_t getD(int64_t e, int64_t N);

int64_t encrypt(int64_t M, int64_t e, int64_t N);

int64_t decrypt(int64_t C, int64_t d, int64_t N);
