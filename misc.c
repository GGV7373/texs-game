#include "misc.h"
#include <stdio.h>
#include "object.h"

int listObjectsAtLocation(OBJECT *locatio) {
    int count = 0;
    OBJECT *obj;
    for (obj =objs; obj < endOfbjs; obj++) {
        if (obj != player && obj->location == locatio) {
            if(count++ == 0) {
                printf("You see:\n");
            }
            printf("%s\n", obj->description);
        }
    }
    return count;
}
