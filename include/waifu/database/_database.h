#ifndef _WAIFU_DATABASE_H_
#define _WAIFU_DATABASE_H_

    #if (defined(__database__sqlite3__))

        #include <database/sqlite3.h>
    
    #else
        #error "unknown database"

    #endif


#endif  /* WAIFU_DATABASE_H_ */
