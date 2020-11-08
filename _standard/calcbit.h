#ifndef calcbit
#define calcbit

#define setbit(reg,bitnumber) reg|=(1<<bitnumber)
#define clearbit(reg,bitnumber) reg&=(~(1<<bitnumber))
#define togglebit(reg,bitnumber) reg^=(1<<bitnumber)
#define getbit(reg,bitnumber) ((reg&(1<<bitnumber))>>bitnumber)

#endif