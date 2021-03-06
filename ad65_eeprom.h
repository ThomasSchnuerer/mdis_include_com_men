/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ad65_eeprom.h
 *
 *       Author: ub
 *
 *  Description: Layout of MEN AD65 carrier board's serial EEPROM
 *
 *     Switches: -
 *
 *---------------------------------------------------------------------------
 * Copyright 2002-2019, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _AD65_EEPROM_H
#define _AD65_EEPROM_H

#include <MEN/eeprod.h>

/* the entire structure covers 0x200 Byte (512 Byte) */

typedef struct {
    /*--- offset 0x0: production data, hardware information (16 byte) ---*/
	EEPROD pd;

    /*--- offset 0x10: MENMON parameters (??? bytes) ---*/
    struct ad65_menm_parms {
        u_int8      mm_id;			/* struct ID (0x5) and parity */
        u_int8		mm_resvd[3];
        struct {					/* touch panel calibration data */
        	u_int32 xoffset;
        	u_int32 xscale;
        	u_int32 yoffset;
        	u_int32 yscale;
        } tcal;

		u_int8		mm_resvd2[12];
    } menm;

	/*--- offset 0x30:  Available to user ---*/
    u_int8 	user[0x200-0x30];

} AD65_EEPROM;

#define AD65_EEID_MENM    0x5

#endif /* _AD65_EEPROM_H */


