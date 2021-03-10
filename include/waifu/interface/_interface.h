#ifndef _WAIFU_INTERFACE_H_
#define _WAIFU_INTERFACE_H_

    #if (defined(__interface__cli__))

        #include <interface/cli.h>
        #include <interface/cli/interface_conta.h>
    
    #else
        #error "unknown interface"

    #endif


#endif  /* WAIFU_INTERFACE_H_ */
