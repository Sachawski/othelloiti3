#include "TADcoup.h"
#include "TADpion.h"
#include "TADcoup.h"
#include "TADposition.h"

CP_Coup CP_coup(PN_Pion pion, POS_Position position) {
    CP_Coup cp;

    cp.pion = pion;
    cp.position = position;
}

PN_Pion CP_pion(CP_Coup coup) {
    return coup.pion;
}

POS_Position CP_position(CP_Coup coup) {
    return coup.position;
}
