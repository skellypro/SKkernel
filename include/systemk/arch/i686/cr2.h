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
/*************************************************************************
* TODO: CHANGE THE arch NAMESPACE TO arch WITHIN THE arch DIRECTORY
*	MAKE CR CLASSES MORE UNIVERSAL TO REDUCE LINES OF CODE
**************************************************************************/
namespace sk {
	namespace arch {

		typedef class cr2_C {
		public:
			cr2_C();

			uint32_t getPFVA();
		private:
			void* pfva; //Page Fault Virtual Address
		} cr2;
	}
}
