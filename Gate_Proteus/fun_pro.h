/*
 * fun_pro.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Yara
 */

#ifndef FUN_PRO_H_
#define FUN_PRO_H_

#include "../_standard/datatypes.h"

extern void initials_LCD(void);
extern void initials_KeyPad(void);
extern void initials_7seg(void);
extern void initials_led_motor_buzzer(void);
extern u8 enter_pass(u8 *arr_pass);
extern u8 check(u8 * arr_realPass , u8 * arr_usePass , u8 Num_digit_realPass , u8 Num_digit_usePass);
extern void try3(u8 num_arr_real_pass ,u8 *arr_real_pass);
extern void Direc();


#endif /* FUN_PRO_H_ */
