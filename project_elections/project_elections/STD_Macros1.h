/*
 * STD_Macros1.h
 *
 * Created: 19/04/2024 05:45:51 م
 *  Author: Amira Al-wakeel
 */ 


#ifndef STD_MACROS1_H_
#define STD_MACROS1_H_

#define Register_Size 8
#define SET_BIT(reg , bit) reg|=(1<<bit)
#define CLR_BIT(reg , bit) reg&=(~(1<<bit))
#define TOG_BIT(reg , bit) reg^=(1<<bit)
#define READ_BIT(reg , bit) ((reg&(1<<bit))>>bit)

#endif /* STD_MACROS1_H_ */