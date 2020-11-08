#include <avr/io.h>
#include "master.h"
#include <avr/delay.h>
#include "ADC.h"

static volatile int pulse = 0;
static volatile int i = 0;

void main(void)
{

	_delay_ms(5000);
	i2c_init();
	i2c_start();
	i2c_write(0x10);
	_delay_ms(5000);
	i2c_write(22);//////////
	//_delay_ms(5000);
	i2c_write(60);//0000000000
	_delay_ms(5000);
	i2c_write(22);//////////
		//_delay_ms(5000);
		i2c_write(60);//0000000000
		_delay_ms(5000);
		i2c_write(22);//////////
			//_delay_ms(5000);
			i2c_write(60);//0000000000
			_delay_ms(5000);
			i2c_write(22);//////////
				//_delay_ms(5000);
				i2c_write(60);//0000000000
				_delay_ms(5000);

	i2c_stop();

	while(1)
	{

	}

}
