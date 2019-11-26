/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file: fpga_header.h
 *
 *       \author kp
 *
 *        \brief Layout of FPGA header to be put at the beginning of FPGA
 *				 code images
 *
 *     \switches -
 */
/*
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

#ifndef _FPGA_HEADER_H
#define _FPGA_HEADER_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
#define FPGA_HEADER_MAGIC 0x8E26D451	 /**< Magic number for original header */
#define FPGA_LONGHEADER_MAGIC 0x8E26D452 /**< Magic number for long header */

#define FPGA_SIZE_HEADER_SHORT 0x030	/**< length of original FPGA header */
#define FPGA_SIZE_HEADER_LONG  0x100    /**< length of long FPGA header */
/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/

/** Original header to be put in front of FPGA netto data (48 bytes) */
/*!
 * All 32 bit fields are in big endian format!
 * Strings are null-terminated ASCII strings.
 * header size must always be a multiple of 4
 */
typedef struct {
	u_int32 magic;				/**< magic word (see above: FPGA_HEADER_MAGIC) */
	char 	fileName[16];		/**< file name of org. FPGA file */
	char 	fpgaType[16];		/**< identifier for FPGA HW type */
	u_int32 size;				/**< size in bytes of FPGA netto data */
	u_int32 chksum;				/**< 32 bit XOR checksum over FPGA netto data */
	u_int32 rsvd[1];			/**< for future use */
} FPGA_HEADER;
/* FPGA netto data follows here. Must be padded to 4 bytes boundary */

/** Long header to be put in front of FPGA netto data (256 bytes) */
/*!
 * This header is mainly used, if FPGA configuration can be / is updated
 * with the FPGA_LOAD tool
 *
 * All 32 bit fields are in big endian format!
 * Strings are null-terminated ASCII strings.
 * header size must always be a multiple of 4
 */
typedef struct {
	u_int32 magic;			/**< magic word (see above: FPGA_LONGHEADER_MAGIC) */
	char 	fileName[28];	/**< file name of org. FPGA file */
	char 	fpgaType[16];	/**< identifier for FPGA HW type */
	u_int32 size;			/**< size in bytes of FPGA netto data */
	u_int32 chksum;			/**< 32 bit XOR checksum over FPGA netto data */
 	u_int32 date[2];		/**< date/time of creation of binary input file
								 e.g. 0x07 d7 07 13  0f 26 00 00
   								   =    2007 . 7.19  15:38 Uhr */

	char 	boardType[16];	/**< identifier for BOARD type,
							 *<br> !! fully compared before update !! */
	u_int32 offset[4];		/**< offset of FPGA configurations in the Flash */
							/*!< offset[0-3] is only used for boards which are
							 *   programmed through the fpga_load tool, and
							 *   are only meaningful in the header of the
							 *   fallback FPGA file.
							 *   The fallback fpga configuration is not to be
							 *   listed in this offsets. 0ffset[0] is the first
							 *   regular FPGA configuration. */
	u_int32 rsvd1[40];		/**< for future use */
} FPGA_LONGHEADER;
/* FPGA netto data follows here. Must be padded to 4 bytes boundary */

/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
/* none */


#ifdef __cplusplus
	}
#endif

#endif	/* _FPGA_HEADER_H */

