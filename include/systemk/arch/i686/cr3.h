/*
 * cr3.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Nov 8, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_I686_CR3_H_
#define INCLUDE_ARCH_I686_CR3_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {

	class i686_cr3_C {
	public:
	private:
		union i686_cr3_t {
			uint32_t value;
			struct PAE {					//PAE Paging enabled
				unsigned	/*reserved*/ : 3,	//system reserved
							pwt : 1,		//
							pcd : 1,		//
							pdptba : 27;	//Page-Directory-Pointer-Table Base Address
			};
			struct NON_PAE {				//PAE Paging not enabled
				unsigned	/*reseved*/ : 3,	//
							pwt : 1,		//
							pcd : 1,		//
							/*reserved*/ : 7,	//
							pdba : 20;		//Page-Directory-Table Base Address
			};
		}__attribute__((packed));
	};

}

#endif /* INCLUDE_ARCH_I686_CR3_H_ */
