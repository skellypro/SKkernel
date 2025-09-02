/*
 * efer.h
 *
 *  Created on: Nov 8, 2024
 *      Author: sean
 * Last Change:	Dec 17, 2024
 *
 * Description:
 */

#ifndef INCLUDE_ARCH_AMD64_EFER_H_
#define INCLUDE_ARCH_AMD64_EFER_H_

#include<stddef.h>
#include<stdint.h>

namespace assembly {
	class efer_C {
	public:
		efer_C();
		~efer_C();

		int getsce();
		int getlme();
		int getlma();
		int getnxe();
		int getsvme();
		int getlmsle();
		int gettce();
		int getmcommit();
		int getintwb();
		int getuaie();
		int getaibrse();

		int setsce(register uint8_t = -1);
		int setlme(register uint8_t = -1);
		int setlma(register uint8_t = -1);
		int setnxe(register uint8_t = -1);
		int setsvme(register uint8_t = -1);
		int setlmsle(register uint8_t = -1);
		int settce(register uint8_t = -1);
		int setmcommit(register uint8_t = -1);
		int setintwb(register uint8_t = -1);
		int setuaie(register uint8_t = -1);
		int setaibrse(register uint8_t = -1);
	private:
		union efer_t {
			uint64_t value;
			struct {
				unsigned		sce : 1,		//System Call Extensions
							/*reserved*/ : 7,	//system reserved
							lme : 1,		//Long Mode Enable
							/*reserved*/ : 1,	//system reserved
							lma : 1,		//Long Mode Activate
							nxe : 1,		//No-Execute Enable
							svme : 1,		//Secure Virtual Machine Enable
							lmsle : 1,		//Long Mode Segment Limit Enable
							tce : 1,		//Translation Cache Extension
							/*reserved*/ : 1,	//system reserved
							mcommit : 1,	//Enable MCOMMIT instruction
							intwb : 1,		//Interruptible WBINVD/WBNOINVD enable
							/*reserved*/ : 1,	//system reserved
							uaie : 1,		//Upper Address Ignore Enable
							aibrse : 1,		//Aumatic IBRS Enable
							/*reserved*/ : 10;	//system reserved
				uint32_t		reserved;		//system reserved
			};
		}__attribute__((packed));

		static inline uint64_t getEFER() {
			register uint64_t temp;
			//TODO:	move EFER to the accumulator, then store it in temp
			__asm__ volatile ("mov %efer, %0": "=r"(temp));
			return temp;
		}

		//TODO: put the new value for EFER into the accumulator, then move it to EFER
		static inline void setEFER(register uint64_t v) {
			__asm__ volatile ("mov %0, efer"::"r"(v));
		}
	};
}

#endif /* INCLUDE_ARCH_AMD64_EFER_H_ */
