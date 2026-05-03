#ifndef PERROR_H_
#define PERROR_H_

// Error Printing macro

#define RED "\033[0;31m"
#define NOR "\033[0m"

#define Perror(E) printf("%s%s%s\n", RED, E, NOR);

#endif
