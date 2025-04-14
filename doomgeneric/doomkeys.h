//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//       Key definitions
//

#ifndef __DOOMKEYS__
#define __DOOMKEYS__

//
// DOOM keyboard definition.
// This is the stuff configured by Setup.Exe.
// Most key data are simple ascii (uppercased).
//
#define DG_KEY_RIGHTARROW	0xae
#define DG_KEY_LEFTARROW	0xac
#define DG_KEY_UPARROW		0xad
#define DG_KEY_DOWNARROW	0xaf
#define DG_KEY_STRAFE_L	0xa0
#define DG_KEY_STRAFE_R	0xa1
#define DG_KEY_USE			0xa2
#define DG_KEY_FIRE		0xa3
#define DG_KEY_ESCAPE		27
#define DG_KEY_ENTER		13
#define DG_KEY_TAB			9
#define DG_KEY_F1			(0x80+0x3b)
#define DG_KEY_F2			(0x80+0x3c)
#define DG_KEY_F3			(0x80+0x3d)
#define DG_KEY_F4			(0x80+0x3e)
#define DG_KEY_F5			(0x80+0x3f)
#define DG_KEY_F6			(0x80+0x40)
#define DG_KEY_F7			(0x80+0x41)
#define DG_KEY_F8			(0x80+0x42)
#define DG_KEY_F9			(0x80+0x43)
#define DG_KEY_F10			(0x80+0x44)
#define DG_KEY_F11			(0x80+0x57)
#define DG_KEY_F12			(0x80+0x58)

#define DG_KEY_BACKSPACE	0x7f
#define DG_KEY_PAUSE	0xff

#define DG_KEY_EQUALS	0x3d
#define DG_KEY_MINUS	0x2d

#define DG_KEY_RSHIFT	(0x80+0x36)
#define DG_KEY_RCTRL	(0x80+0x1d)
#define DG_KEY_RALT	(0x80+0x38)

#define DG_KEY_LALT	DG_KEY_RALT

// new keys:

#define DG_KEY_CAPSLOCK    (0x80+0x3a)
#define DG_KEY_NUMLOCK     (0x80+0x45)
#define DG_KEY_SCRLCK      (0x80+0x46)
#define DG_KEY_PRTSCR      (0x80+0x59)

#define DG_KEY_HOME        (0x80+0x47)
#define DG_KEY_END         (0x80+0x4f)
#define DG_KEY_PGUP        (0x80+0x49)
#define DG_KEY_PGDN        (0x80+0x51)
#define DG_KEY_INS         (0x80+0x52)
#define DG_KEY_DEL         (0x80+0x53)

#define DG_KEYP_0          0
#define DG_KEYP_1          DG_KEY_END
#define DG_KEYP_2          DG_KEY_DOWNARROW
#define DG_KEYP_3          DG_KEY_PGDN
#define DG_KEYP_4          DG_KEY_LEFTARROW
#define DG_KEYP_5          '5'
#define DG_KEYP_6          DG_KEY_RIGHTARROW
#define DG_KEYP_7          DG_KEY_HOME
#define DG_KEYP_8          DG_KEY_UPARROW
#define DG_KEYP_9          DG_KEY_PGUP

#define DG_KEYP_DIVIDE     '/'
#define DG_KEYP_PLUS       '+'
#define DG_KEYP_MINUS      '-'
#define DG_KEYP_MULTIPLY   '*'
#define DG_KEYP_PERIOD     0
#define DG_KEYP_EQUALS     DG_KEY_EQUALS
#define DG_KEYP_ENTER      DG_KEY_ENTER

#endif          // __DOOMKEYS__

