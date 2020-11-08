/*
 * RTC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef RTC_H_
#define RTC_H_

extern void init_i2c();
extern unsigned char read_i2c();
extern void write_i2c(unsigned char ch);
extern void start();
extern void stop();
extern void rtc_write(char dev_addr,char dev_loc,char dev_data);
extern unsigned char rtc_read(char dev_addr,char dev_loc);
extern void tx( unsigned char data );
extern char rx();
extern void init_serial();
extern void str_serial(char *str);
extern void disp_time_date();


#endif /* RTC_H_ */
