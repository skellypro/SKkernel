/*
 * cr2.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Nov 8, 2024
 *
 * Description:
 */

#pragma once

#include<stddef.h>
#include<stdint.h>

#include<systemk/arch/i686/cr2.h>

namespace sk {
	namespace arch {

		union AMD64_cr2_t {
			uint64_t pfva;			//Page-Fault Virtual Address
			struct {
				i686_cr2_t	lower;
				uint32_t	upper;
			};
		};

	}
}
