#include <xc.h>

#define _XTAL_FREQ 4000000


void Start_Signal(void);
__bit Check_Response();
__bit Read_Data(unsigned char* dht_data);
void DHT11();
