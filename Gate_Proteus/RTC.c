/*
 * RTC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

# include<avr/io.h>
# include<util/delay.h>


void init_i2c()
{
	TWSR = 0X00;
	TWBR = 0X47;
	TWCR = (1<<TWEN);
}

unsigned char read_i2c()
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

void write_i2c(unsigned char ch)
{
	TWDR = ch;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));
}

void start()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR &(1<<TWINT))==0);
}

void stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	_delay_ms(1);
}

void rtc_write(char dev_addr,char dev_loc,char dev_data)
{
	start();
	write_i2c(dev_addr);
	write_i2c(dev_loc);
	write_i2c(dev_data);
	stop();
	_delay_ms(10);
}

unsigned char rtc_read(char dev_addr,char dev_loc)
{
	char ch;

	start();

	write_i2c(dev_addr);
	write_i2c(dev_loc);

	start();
	write_i2c(dev_addr|0x01);
	ch = read_i2c();

	stop();
	return ch;
}

void tx( unsigned char data )
{
	while ( !(UCSRA & (1<<UDRE)) ); // wait until UDR is empty
	UDR = data;
}

char rx()
{
	while ( !(UCSRA & (1<<RXC)) ); // wait until UDR is empty
	return UDR;
}

void init_serial()
{
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<UCSZ1)|(1<<UCSZ0);
	UBRRL = 51;
}

void str_serial(char *str)
{
	while(*str)
	{
		tx(*str++);
		_delay_ms(1);
	}
}


void disp_time_date()
{
	char ch;

	tx(254);
	tx(128);

	str_serial("Time: ");

	ch = rtc_read(0xd0 , 0x02);//hour
	tx(ch/16+48);
	tx(ch%16+48);
	tx('-');

// 	ch = rtc_read(0xd0 , 0x01);//min
// 	tx(ch/16+48);
// 	tx(ch%16+48);
// 	tx('-');
//
// 	ch = rtc_read(0xd0 , 0x00);//sec
// 	tx(ch/16+48);
// 	tx(ch%16+48);
//
// 	tx(254);
// 	tx(192);
//
// 	str_serial("Date: ");
//
// 	ch = rtc_read(0xd0 , 0x04);
// 	tx(ch/16+48);
// 	tx(ch%16+48);
// 	tx('-');
//
// 	ch = rtc_read(0xd0 , 0x05);
// 	tx(ch/16+48);
// 	tx(ch%16+48);
// 	tx('-');
//
// 	ch = rtc_read(0xd0 , 0x06);
// 	tx(ch/16+48);
// 	tx(ch%16+48);



}
