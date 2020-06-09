#include "font.h"

#define X 0xFF,
#define _ 0x00,

static const character_t character32 = {
    ' ',
    14,
    8,
    {
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
    }
};
static const character_t character33 = {
    '!',
    14,
    2,
    {
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        _ _
        _ _
        X X
        X X
    }
};
static const character_t character34 = {
    '\"',
    14,
    6,
    {
        X X _ _ X X
        X X _ _ X X
        X X _ _ X X
        X X _ _ X X
        X X _ _ X X
        X X _ _ X X
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
    }
};
static const character_t character35 = {
    '#',
    14,
    10,
    {
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
    }
};
static const character_t character36 = {
    '$',
    14,
    10,
    {
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ X X X X X X X X
        _ X X X X X X X X X
        X X _ _ X X _ _ _ _
        X X _ _ X X _ _ _ _
        _ X X X X X X X _ _
        _ _ X X X X X X X _
        _ _ _ _ X X _ _ X X
        _ _ _ _ X X _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character37 = {
    '%',
    14,
    10,
    {
        X X X X _ _ _ _ _ _
        X X X X _ _ _ _ _ _
        X X X X _ _ _ _ X X
        X X X X _ _ _ X X X
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X _ _ _
        _ _ _ X X X _ _ _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X _ _ _ X X X X
        X X _ _ _ _ X X X X
        _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ X X X X
    }
};
static const character_t character38 = {
    '&',
    14,
    10,
    {
        _ _ X X _ _ _ _ _ _
        _ X X X X _ _ _ _ _
        X X _ _ X X _ _ _ _
        X X _ _ X X _ _ _ _
        X X _ _ X X _ _ _ _
        X X _ _ X X _ _ _ _
        _ X X X X _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        X X _ _ X X _ _ X X
        X X _ _ X X _ X X X
        X X _ _ _ _ X X X _
        X X _ _ _ X X X _ _
        _ X X X X X X _ X X
        _ _ X X X X _ _ X X
    }
};
static const character_t character39 = {
    '\'',
    14,
    4,
    {
        _ _ X X
        _ _ X X
        _ _ X X
        _ X X X
        X X X _
        X X _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
    }
};
static const character_t character40 = {
    '(',
    14,
    6,
    {
        _ _ _ _ X X
        _ _ _ X X _
        _ _ X X _ _
        _ X X _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        _ X X _ _ _
        _ _ X X _ _
        _ _ _ X X _
        _ _ _ _ X X
    }
};
static const character_t character41 = {
    ')',
    14,
    6,
    {
        X X _ _ _ _
        _ X X _ _ _
        _ _ X X _ _
        _ _ _ X X _
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ X X _
        _ _ X X _ _
        _ X X _ _ _
        X X _ _ _ _
    }
};
static const character_t character42 = {
    '*',
    14,
    10,
    {
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        X X _ _ X X _ _ X X
        X X X _ X X _ X X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X X _ X X _ X X X
        X X _ _ X X _ _ X X
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character43 = {
    '+',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
    }
};
static const character_t character44 = {
    ',',
    14,
    4,
    {
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ _ _
        _ _ X X
        _ _ X X
        _ _ X X
        _ X X X
        X X X _
        X X _ _
    }
};
static const character_t character45 = {
    '-',
    14,
    8,
    {
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        X X X X X X X X
        X X X X X X X X
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
    }
};
static const character_t character46 = {
    '.',
    14,
    2,
    {
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        _ _
        X X
        X X
    }
};
static const character_t character47 = {
    '/',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ X X X
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X _ _ _
        _ _ _ X X X _ _ _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
    }
};
static const character_t character48 = {
    '0',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character49 = {
    '1',
    14,
    6,
    {
        _ _ X X _ _
        _ X X X _ _
        X X X X _ _
        X X X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        X X X X X X
        X X X X X X
    }
};
static const character_t character50 = {
    '2',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ X X X X X _
        _ _ _ X X X X X _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character51 = {
    '3',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ X X X X _ _
        _ _ _ _ X X X X _ _
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character52 = {
    '4',
    14,
    10,
    {
        _ _ _ _ _ _ X X _ _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X X _ _
        _ _ _ X X X X X _ _
        _ _ X X X _ X X _ _
        _ X X X _ _ X X _ _
        X X X _ _ _ X X _ _
        X X _ _ _ _ X X _ _
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ _ _ X X _ _
        _ _ _ _ _ _ X X _ _
        _ _ _ _ _ _ X X _ _
        _ _ _ _ _ _ X X _ _
    }
};
static const character_t character53 = {
    '5',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X _ _
        X X X X X X X X X _
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character54 = {
    '6',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character55 = {
    '7',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ X X X
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X _ _ _
        _ _ _ X X X _ _ _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
    }
};
static const character_t character56 = {
    '8',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character57 = {
    '9',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X X
        _ _ X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character58 = {
    ':',
    14,
    6,
    {
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
    }
};
static const character_t character59 = {
    ';',
    14,
    6,
    {
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        X X _ _ _ _
        X X _ _ _ _
    }
};
static const character_t character60 = {
    '<',
    14,
    8,
    {
        _ _ _ _ _ _ X X
        _ _ _ _ _ X X X
        _ _ _ _ X X X _
        _ _ _ X X X _ _
        _ _ X X X _ _ _
        _ X X X _ _ _ _
        X X X _ _ _ _ _
        X X X _ _ _ _ _
        _ X X X _ _ _ _
        _ _ X X X _ _ _
        _ _ _ X X X _ _
        _ _ _ _ X X X _
        _ _ _ _ _ X X X
        _ _ _ _ _ _ X X
    }
};
static const character_t character61 = {
    '=',
    14,
    8,
    {
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        X X X X X X X X
        X X X X X X X X
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        X X X X X X X X
        X X X X X X X X
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
    }
};
static const character_t character62 = {
    '>',
    14,
    8,
    {
        X X _ _ _ _ _ _
        X X X _ _ _ _ _
        _ X X X _ _ _ _
        _ _ X X X _ _ _
        _ _ _ X X X _ _
        _ _ _ _ X X X _
        _ _ _ _ _ X X X
        _ _ _ _ _ X X X
        _ _ _ _ X X X _
        _ _ _ X X X _ _
        _ _ X X X _ _ _
        _ X X X _ _ _ _
        X X X _ _ _ _ _
        X X _ _ _ _ _ _
    }
};
static const character_t character63 = {
    '?',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ X X X
        _ _ _ _ X X X X X _
        _ _ _ _ X X X X _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character64 = {
    '@',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ X X X _ X X
        X X _ _ X _ X _ X X
        X X _ _ X _ X _ X X
        X X _ _ X _ X _ X X
        X X _ _ X _ X X X _
        X X _ _ X X X X _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        _ X X X X X X X _ _
        _ _ X X X X X _ _ _
    }
};
static const character_t character65 = {
    'A',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character66 = {
    'B',
    14,
    10,
    {
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ X X X
        X X X X X X X X X _
        X X X X X X X X X _
        X X _ _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ X X X
        X X X X X X X X X _
        X X X X X X X X _ _
    }
};
static const character_t character67 = {
    'C',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X X _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ X X
        X X X _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character68 = {
    'D',
    14,
    10,
    {
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
    }
};
static const character_t character69 = {
    'E',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X _ _
        X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character70 = {
    'F',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X _ _
        X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
    }
};
static const character_t character71 = {
    'G',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ X X X X _
        X X _ _ _ X X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character72 = {
    'H',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character73 = {
    'I',
    14,
    6,
    {
        X X X X X X
        X X X X X X
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        _ _ X X _ _
        X X X X X X
        X X X X X X
    }
};
static const character_t character74 = {
    'J',
    14,
    8,
    {
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        _ X X X X X X _
        _ _ X X X X _ _
    }
};
static const character_t character75 = {
    'K',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ X X X
        X X _ _ _ _ X X X _
        X X _ _ _ X X X _ _
        X X _ _ X X X _ _ _
        X X _ X X X _ _ _ _
        X X X X X _ _ _ _ _
        X X X X X _ _ _ _ _
        X X _ X X X _ _ _ _
        X X _ _ X X X _ _ _
        X X _ _ _ X X X _ _
        X X _ _ _ _ X X X _
        X X _ _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character76 = {
    'L',
    14,
    10,
    {
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character77 = {
    'M',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X _ _ X X X X
        X X X X _ _ X X X X
        X X _ X X X X _ X X
        X X _ _ X X _ _ X X
        X X _ _ X X _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character78 = {
    'N',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X _ _ _ _ _ X X
        X X X X _ _ _ _ X X
        X X X X X _ _ _ X X
        X X _ X X X _ _ X X
        X X _ _ X X X _ X X
        X X _ _ _ X X X X X
        X X _ _ _ _ X X X X
        X X _ _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character79 = {
    'O',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character80 = {
    'P',
    14,
    10,
    {
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
    }
};
static const character_t character81 = {
    'Q',
    14,
    10,
    {
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ X X _ _ X X
        X X _ _ X X X _ X X
        X X _ _ _ X X X X _
        X X _ _ _ _ X X _ _
        _ X X X X X X X X X
        _ _ X X X X _ _ X X
    }
};
static const character_t character82 = {
    'R',
    14,
    10,
    {
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
        X X _ _ X X _ _ _ _
        X X _ _ X X X _ _ _
        X X _ _ _ X X X _ _
        X X _ _ _ _ X X X _
        X X _ _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character83 = {
    'S',
    14,
    10,
    {
        _ _ X X X X X X X X
        _ X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X _
        _ X X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
    }
};
static const character_t character84 = {
    'T',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character85 = {
    'U',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character86 = {
    'V',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X _ _ _ _ X X _
        _ _ X X _ _ X X _ _
        _ _ _ X X X X _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character87 = {
    'W',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ X X _ _ X X
        X X _ _ X X _ _ X X
        X X _ X X X X _ X X
        X X X X _ _ X X X X
        X X X X _ _ X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character88 = {
    'X',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X _ _ _ _ X X _
        _ _ X X _ _ X X _ _
        _ _ _ X X X X _ _ _
        _ _ _ X X X X _ _ _
        _ _ X X _ _ X X _ _
        _ X X _ _ _ _ X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character89 = {
    'Y',
    14,
    10,
    {
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X _ _ _ _ X X X
        _ X X X _ _ X X X _
        _ _ X X X X X X _ _
        _ _ _ X X X X _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character90 = {
    'Z',
    14,
    10,
    {
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ X X X
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X _ _ _
        _ _ _ X X X _ _ _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character91 = {
    '[',
    14,
    6,
    {
        X X X X X X
        X X X X X X
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X X X X X
        X X X X X X
    }
};
static const character_t character92 = {
    '\\',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        _ X X X _ _ _ _ _ _
        _ _ X X X _ _ _ _ _
        _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _
        _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ _ _ X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
    }
};
static const character_t character93 = {
    ']',
    14,
    6,
    {
        X X X X X X
        X X X X X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        _ _ _ _ X X
        X X X X X X
        X X X X X X
    }
};
static const character_t character94 = {
    '^',
    14,
    10,
    {
        _ _ _ _ X X _ _ _ _
        _ _ _ X X X X _ _ _
        _ _ X X _ _ X X _ _
        _ X X X _ _ X X X _
        X X X _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
    }
};
static const character_t character95 = {
    '_',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character96 = {
    '`',
    14,
    6,
    {
        X X _ _ _ _
        X X X _ _ _
        _ X X X _ _
        _ _ X X X _
        _ _ _ X X X
        _ _ _ _ X X
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
        _ _ _ _ _ _
    }
};
static const character_t character97 = {
    'a',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X _ _
        _ _ X X X X X X X _
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ X X X X X X X X
        _ X X X X X X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X X
        _ _ X X X X X X X X
    }
};
static const character_t character98 = {
    'b',
    14,
    10,
    {
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ X X X X _ _
        X X _ X X X X X X _
        X X X X _ _ _ _ X X
        X X X X _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
    }
};
static const character_t character99 = {
    'c',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X
        _ X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        _ X X X X X X X X X
        _ _ X X X X X X X X
    }
};
static const character_t character100 = {
    'd',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ X X X X _ _ X X
        _ X X X X X X _ X X
        X X _ _ _ _ X X X X
        X X _ _ _ _ X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X X
        _ _ X X X X X X X X
    }
};
static const character_t character101 = {
    'e',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        _ X X X X X X X _ _
        _ _ X X X X X X _ _
    }
};
static const character_t character102 = {
    'f',
    14,
    10,
    {
        _ _ _ _ X X X X _ _
        _ _ _ X X X X X X _
        _ _ X X _ _ _ _ X X
        _ _ X X _ _ _ _ X X
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        X X X X X X X _ _ _
        X X X X X X X _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
    }
};
static const character_t character103 = {
    'g',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X X
        _ _ X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character104 = {
    'h',
    14,
    10,
    {
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ X X X X _ _
        X X _ X X X X X X _
        X X X X _ _ _ _ X X
        X X X X _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character105 = {
    'i',
    14,
    2,
    {
        _ _
        _ _
        X X
        X X
        _ _
        _ _
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
    }
};
static const character_t character106 = {
    'j',
    14,
    8,
    {
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        _ X X X X X X _
        _ _ X X X X _ _
    }
};
static const character_t character107 = {
    'k',
    14,
    8,
    {
        X X _ _ _ _ _ _
        X X _ _ _ _ _ _
        X X _ _ _ _ _ _
        X X _ _ _ _ _ _
        X X _ _ _ _ X X
        X X _ _ _ X X X
        X X _ _ X X X _
        X X _ X X X _ _
        X X X X X _ _ _
        X X X X X _ _ _
        X X _ X X X _ _
        X X _ _ X X X _
        X X _ _ _ X X X
        X X _ _ _ _ X X
    }
};
static const character_t character108 = {
    'l',
    14,
    6,
    {
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        X X _ _ _ _
        _ X X X X X
        _ _ X X X X
    }
};
static const character_t character109 = {
    'm',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X _ _ X X _ _
        _ X X X X X X X X _
        X X _ _ X X _ _ X X
        X X _ _ X X _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character110 = {
    'n',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X _ _
        X X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character111 = {
    'o',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X _ _
        _ X X X X X X X X _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X _
        _ _ X X X X X X _ _
    }
};
static const character_t character112 = {
    'p',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ X X X X _ _
        X X _ X X X X X X _
        X X X X _ _ _ _ X X
        X X X X _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X X X X X X X _
        X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
    }
};
static const character_t character113 = {
    'q',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X X _ _ X X
        _ X X X X X X _ X X
        X X _ _ _ _ X X X X
        X X _ _ _ _ X X X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        _ X X X X X X X X X
        _ _ X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
    }
};
static const character_t character114 = {
    'r',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ X X X X _ _
        X X _ X X X X X X _
        X X X X _ _ _ _ X X
        X X X X _ _ _ _ X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
    }
};
static const character_t character115 = {
    's',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ X X X X X X X X X
        X X X X X X X X X X
        X X _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _
        X X X X X X X X X _
        _ X X X X X X X X X
        _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ X X
        X X X X X X X X X X
        X X X X X X X X X _
    }
};
static const character_t character116 = {
    't',
    14,
    10,
    {
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        X X X X X X _ _ _ _
        X X X X X X _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ _ _
        _ _ X X _ _ _ _ X X
        _ _ X X _ _ _ _ X X
        _ _ _ X X X X X X _
        _ _ _ _ X X X X _ _
    }
};
static const character_t character117 = {
    'u',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ X X X X
        X X _ _ _ X X X X X
        X X X X X X X _ X X
        _ X X X X X _ _ X X
    }
};
static const character_t character118 = {
    'v',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X X _ _ _ _ X X X
        _ _ X X _ _ X X _ _
        _ _ X X _ _ X X _ _
        _ _ _ X X X X _ _ _
        _ _ _ _ X X _ _ _ _
    }
};
static const character_t character119 = {
    'w',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ X X
        X X _ _ X X _ _ X X
        X X _ X X X X _ X X
        _ X X X _ _ X X X _
        _ _ X X _ _ X X _ _
    }
};
static const character_t character120 = {
    'x',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ X X
        X X X _ _ _ _ X X X
        _ X X X _ _ X X X _
        _ _ X X _ _ X X _ _
        _ _ _ X X X X _ _ _
        _ _ _ X X X X _ _ _
        _ _ X X _ _ X X _ _
        _ X X X _ _ X X X _
        X X X _ _ _ _ X X X
        X X _ _ _ _ _ _ X X
    }
};
static const character_t character121 = {
    'y',
    14,
    8,
    {
        _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        _ X X X X X X X
        _ _ X X X X X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        X X _ _ _ _ X X
        X X _ _ _ _ X X
        _ X X X X X X _
        _ _ X X X X _ _
    }
};
static const character_t character122 = {
    'z',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
        _ _ _ _ _ _ X X X _
        _ _ _ _ _ X X X _ _
        _ _ _ _ X X X _ _ _
        _ _ _ X X X _ _ _ _
        _ _ X X X _ _ _ _ _
        _ X X X _ _ _ _ _ _
        X X X X X X X X X X
        X X X X X X X X X X
    }
};
static const character_t character123 = {
    '{',
    14,
    8,
    {
        _ _ _ _ X X X X
        _ _ _ X X X X X
        _ _ X X _ _ _ _
        _ _ X X _ _ _ _
        _ _ X X _ _ _ _
        _ X X _ _ _ _ _
        X X _ _ _ _ _ _
        X X _ _ _ _ _ _
        _ X X _ _ _ _ _
        _ _ X X _ _ _ _
        _ _ X X _ _ _ _
        _ _ X X _ _ _ _
        _ _ _ X X X X X
        _ _ _ _ X X X X
    }
};
static const character_t character124 = {
    '|',
    14,
    2,
    {
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
        X X
    }
};
static const character_t character125 = {
    '}',
    14,
    8,
    {
        X X X X _ _ _ _
        X X X X X _ _ _
        _ _ _ _ X X _ _
        _ _ _ _ X X _ _
        _ _ _ _ X X _ _
        _ _ _ _ _ X X _
        _ _ _ _ _ _ X X
        _ _ _ _ _ _ X X
        _ _ _ _ _ X X _
        _ _ _ _ X X _ _
        _ _ _ _ X X _ _
        _ _ _ _ X X _ _
        X X X X X _ _ _
        X X X X _ _ _ _
    }
};
static const character_t character126 = {
    '~',
    14,
    10,
    {
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ X X
        _ X X X X X _ X X X
        X X X _ X X X X X _
        X X _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _
    }
};
const font_t font14x10 = {
    .name                  = "Fonte 14x10",
    .height                = 14,
    .width               = 10,
    .character_spacing = 2,
    .line_spacing     = 2,
    .characters_quantity = 95,
    .first_character    = 32,
    .last_character      = 126,
    .characters            = {
        &character32,
        &character33,
        &character34,
        &character35,
        &character36,
        &character37,
        &character38,
        &character39,
        &character40,
        &character41,
        &character42,
        &character43,
        &character44,
        &character45,
        &character46,
        &character47,
        &character48,
        &character49,
        &character50,
        &character51,
        &character52,
        &character53,
        &character54,
        &character55,
        &character56,
        &character57,
        &character58,
        &character59,
        &character60,
        &character61,
        &character62,
        &character63,
        &character64,
        &character65,
        &character66,
        &character67,
        &character68,
        &character69,
        &character70,
        &character71,
        &character72,
        &character73,
        &character74,
        &character75,
        &character76,
        &character77,
        &character78,
        &character79,
        &character80,
        &character81,
        &character82,
        &character83,
        &character84,
        &character85,
        &character86,
        &character87,
        &character88,
        &character89,
        &character90,
        &character91,
        &character92,
        &character93,
        &character94,
        &character95,
        &character96,
        &character97,
        &character98,
        &character99,
        &character100,
        &character101,
        &character102,
        &character103,
        &character104,
        &character105,
        &character106,
        &character107,
        &character108,
        &character109,
        &character110,
        &character111,
        &character112,
        &character113,
        &character114,
        &character115,
        &character116,
        &character117,
        &character118,
        &character119,
        &character120,
        &character121,
        &character122,
        &character123,
        &character124,
        &character125,
        &character126
    }
};

#undef X
#undef _
