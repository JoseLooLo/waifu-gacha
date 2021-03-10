
#ifndef WAIFU_INTERFACE_H_
#define WAIFU_INTERFACE_H_

	/* Interface Implementation */
	#include "waifu/interface/_interface.h"

/*============================================================================*
 * Interface Implementation Checking                                           *
 *============================================================================*/

#ifdef __check_interface__

	#ifndef ___interface_conta_cl
	#error "___interface_conta_cl class wasn't defined"
	#endif

	#ifndef ___interface_init_fn
	#error "___interface_init_fn class wasn't defined"
	#endif

#endif

/*============================================================================*
 * Interface                                                                  *
 *============================================================================*/

	/**
	 * Database start
	 */

	extern int interface_init(void);

#endif  /* WAIFU_DATABASE_H_ */