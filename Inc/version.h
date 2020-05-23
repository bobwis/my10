/*
 * version.h
 *
 *  Created on: 20Mar.,2018
 *      Author: bob
 */

#ifndef VERSION_H_
#define VERSION_H_

#define MAJORVERSION 0
#define MINORVERSION 7

// TESTING Speeds up the frequency of status packets
#if		0
#define TESTING
#endif

// piggy back splat board ver 1 present
#if 1
#define SPLAT1
#endif

#ifdef TESTING
#define MY_UID 1055	// 16 bits  "serial number" of the lightning detector
#else
#define MY_UID 1001	// 16 bits  "serial number" of the lightning detector
#endif

#ifdef SPLAT1
// Pressures sensor type fitted
#if 0
#define MPL115A2
#endif

#if 1
#define MPL3115A2
#endif

#endif	/* SPLAT1 */
#endif /* VERSION_H_ */


// If we want localtime (+10H) not UTC, define LOCALTIME
#if 1
#define LOCALTIME
#endif
