#include <avr/io.h>
#include "master.h"
#include <avr/delay.h>
void main(void)
{
	_delay_ms(2000);
	i2c_init();
	i2c_start();
	i2c_write(0x10);
	_delay_ms(1000);
	i2c_write('y');
	_delay_ms(1000);
	i2c_write('a');
	_delay_ms(1000);
	i2c_write('r');
	_delay_ms(1000);
	i2c_stop();

	while(1)
	{

	}

}
