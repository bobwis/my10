/*
 * splat1.h
 *
 *  Created on: 26Sep.,2019
 *      Author: bob
 */

#ifndef SPLAT1_H_
#define SPLAT1_H_

extern void initsplat(void);

extern void setpgagain(int gain);
extern uint32_t pressure, pressfrac, temperature, tempfrac;

extern uint32_t logampmode;

#endif /* SPLAT1_H_ */
