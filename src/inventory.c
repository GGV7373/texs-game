#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "noun.h"
#include "move.h"

void executeGet(const char *noun)
{
    OBJECT *obj = getVisibleObject("what you want to get",noun);
    if (obj == NULL)
    {
        // dont need this message, getVisibleObject already printed it
    }
    else if (obj == player)
    {
        printf("You shoudn not be doing that to yourself.\n");
    }
    else if (obj->location == player)
    {
        printf("You already have the %s.\n", obj->description);
    }
    else if (obj->player == guard)
    {
        printf("You should aks %s nicely.\n", obj->location->description);
    }
    else
    {
        moveObject(obj, player);
        printf("You now have the %s.\n", obj->description);
    }
}

void executeDrop(const char *noun)
{
   moveObject(getPossession(player, "drop", noun), player->location);
}
void executeAsk(const char *noun)
{
   moveObject(getPossession(actorHere(), "ask", noun), player);
}
void executeGive(const char *noun)
{
   moveObject(getPossession(player, "give", noun), actorHere());
}
void executeInventory(void)
{
   if (listObjectsAtLocation(player) == 0)
   {
      printf("You are empty-handed.\n");
   }
}