
#ifndef INTERFACE_CLI_H_
#define INTERFACE_CLI_H_

extern int cli_interface_init(void);

#define ___interface_init_fn

/*============================================================================*
 * Exported Interface                                                         *
 *============================================================================*/

    /**
	 * Database start
	 */

	int interface_init(void) {
        return cli_interface_init();
    }


#endif  /* INTERFACE_CLI_H_ */