#include "font.h"

#define X 0xFF,
#define _ 0x00,

static const character_t character32 = {
    ' ',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character33 = {
    '!',
    7,
    1,
    {
        X
        X
        X
        X
        X
        _
        X
    }
};
static const character_t character34 = {
    '"',
    7,
    5,
    {
        _ X _ X _
        _ X _ X _
        _ X _ X _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character35 = {
    '#',
    7,
    5,
    {
        _ X _ X _
        _ X _ X _
        X X X X X
        _ X _ X _
        X X X X X
        _ X _ X _
        _ X _ X _
    }
};
static const character_t character36 = {
    '$',
    7,
    5,
    {
        _ _ X _ _
        _ X X X X
        X _ X _ _
        _ X X X _
        _ _ X _ X
        X X X X _
        _ _ X _ _
    }
};
static const character_t character37 = {
    '%',
    7,
    5,
    {
        X X _ _ _
        X X _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X _ _ X X
        _ _ _ X X
    }
};
static const character_t character38 = {
    '&',
    7,
    5,
    {
        _ X X _ _
        X _ _ X _
        X _ X _ _
        _ X _ _ _
        X _ X _ X
        X _ _ X _
        _ X X _ X
    }
};
static const character_t character39 = {
    '\'',
    7,
    5,
    {
        _ X X _ _
        _ _ X _ _
        _ X _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character40 = {
    '(',
    7,
    5,
    {
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        _ X _ _ _
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
    }
};
static const character_t character41 = {
    ')',
    7,
    5,
    {
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
        _ _ _ X _
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
    }
};
static const character_t character42 = {
    '*',
    7,
    5,
    {
        _ _ _ _ _
        _ X _ X _
        _ _ X _ _
        X X X X X
        _ _ X _ _
        _ X _ X _
        _ _ _ _ _
    }
};
static const character_t character43 = {
    '+',
    7,
    5,
    {
        _ _ _ _ _
        _ _ X _ _
        _ _ X _ _
        X X X X X
        _ _ X _ _
        _ _ X _ _
        _ _ _ _ _
    }
};
static const character_t character44 = {
    ',',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ X X _ _
        _ _ X _ _
        _ X _ _ _
    }
};
static const character_t character45 = {
    '-',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        X X X X X
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character46 = {
    '.',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ X X _ _
        _ X X _ _
    }
};
static const character_t character47 = {
    '/',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character48 = {
    '0',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ X X
        X _ X _ X
        X X _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character49 = {
    '1',
    7,
    5,
    {
        _ _ X _ _
        _ X X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ X X X _
    }
};
static const character_t character50 = {
    '2',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X X X X X
    }
};
static const character_t character51 = {
    '3',
    7,
    5,
    {
        X X X X X
        _ _ _ X _
        _ _ X _ _
        _ _ _ X _
        _ _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character52 = {
    '4',
    7,
    5,
    {
        _ _ _ X _
        _ _ X X _
        _ X _ X _
        X _ _ X _
        X X X X X
        _ _ _ X _
        _ _ _ X _
    }
};
static const character_t character53 = {
    '5',
    7,
    5,
    {
        X X X X X
        X _ _ _ _
        X X X X _
        _ _ _ _ X
        _ _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character54 = {
    '6',
    7,
    5,
    {
        _ _ X X _
        _ X _ _ _
        X _ _ _ _
        X X X X _
        X _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character55 = {
    '7',
    7,
    5,
    {
        X X X X X
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        _ X _ _ _
        _ X _ _ _
    }
};
static const character_t character56 = {
    '8',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character57 = {
    '9',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        _ X X X X
        _ _ _ _ X
        _ _ _ X _
        _ X X _ _
    }
};
static const character_t character58 = {
    ':',
    7,
    5,
    {
        _ _ _ _ _
        _ X X _ _
        _ X X _ _
        _ _ _ _ _
        _ X X _ _
        _ X X _ _
        _ _ _ _ _
    }
};
static const character_t character59 = {
    ';',
    7,
    5,
    {
        _ _ _ _ _
        _ X X _ _
        _ X X _ _
        _ _ _ _ _
        _ X X _ _
        _ _ X _ _
        _ X _ _ _
    }
};
static const character_t character60 = {
    '<',
    7,
    5,
    {
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
        _ _ _ _ X
    }
};
static const character_t character61 = {
    '=',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X X X X X
        _ _ _ _ _
        X X X X X
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character62 = {
    '>',
    7,
    5,
    {
        X _ _ _ _
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X _ _ _ _
    }
};
static const character_t character63 = {
    '?',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ _ _ _ _
        _ _ X _ _
    }
};
static const character_t character64 = {
    '@',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        _ _ _ _ X
        _ X X _ X
        X _ X _ X
        X _ X _ X
        _ X X X _
    }
};
static const character_t character65 = {
    'A',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X X X X X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character66 = {
    'B',
    7,
    5,
    {
        X X X X _
        X _ _ _ X
        X _ _ _ X
        X X X X _
        X _ _ _ X
        X _ _ _ X
        X X X X _
    }
};
static const character_t character67 = {
    'C',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character68 = {
    'D',
    7,
    5,
    {
        X X X _ _
        X _ _ X _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ X _
        X X X _ _
    }
};
static const character_t character69 = {
    'E',
    7,
    5,
    {
        X X X X X
        X _ _ _ _
        X _ _ _ _
        X X X X _
        X _ _ _ _
        X _ _ _ _
        X X X X X
    }
};
static const character_t character70 = {
    'F',
    7,
    5,
    {
        X X X X X
        X _ _ _ _
        X _ _ _ _
        X X X _ _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
    }
};
static const character_t character71 = {
    'G',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ _
        X _ _ _ _
        X _ _ X X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character72 = {
    'H',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X X X X X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character73 = {
    'I',
    7,
    5,
    {
        _ X X X _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ X X X _
    }
};
static const character_t character74 = {
    'J',
    7,
    5,
    {
        _ _ X X X
        _ _ _ X _
        _ _ _ X _
        _ _ _ X _
        _ _ _ X _
        X _ _ X _
        _ X X _ _
    }
};
static const character_t character75 = {
    'K',
    7,
    5,
    {
        X _ _ _ X
        X _ _ X _
        X _ X _ _
        X X _ _ _
        X _ X _ _
        X _ _ X _
        X _ _ _ X
    }
};
static const character_t character76 = {
    'L',
    7,
    5,
    {
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
        X X X X X
    }
};
static const character_t character77 = {
    'M',
    7,
    5,
    {
        X _ _ _ X
        X X _ X X
        X _ X _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character78 = {
    'N',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        X X _ _ X
        X _ X _ X
        X _ _ X X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character79 = {
    'O',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character80 = {
    'P',
    7,
    5,
    {
        X X X X _
        X _ _ _ X
        X _ _ _ X
        X X X X _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
    }
};
static const character_t character81 = {
    'Q',
    7,
    5,
    {
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ X _ X
        X _ _ X _
        _ X X _ X
    }
};
static const character_t character82 = {
    'R',
    7,
    5,
    {
        X X X X _
        X _ _ _ X
        X _ _ _ X
        X X X X _
        X _ X _ _
        X _ _ X _
        X _ _ _ X
    }
};
static const character_t character83 = {
    'S',
    7,
    5,
    {
        _ X X X X
        X _ _ _ _
        X _ _ _ _
        _ X X X _
        _ _ _ _ X
        _ _ _ _ X
        X X X X _
    }
};
static const character_t character84 = {
    'T',
    7,
    5,
    {
        X X X X X
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
    }
};
static const character_t character85 = {
    'U',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character86 = {
    'V',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        _ X _ X _
        _ _ X _ _
    }
};
static const character_t character87 = {
    'W',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ X _ X
        X _ X _ X
        X X _ X X
        X _ _ _ X
    }
};
static const character_t character88 = {
    'X',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        _ X _ X _
        _ _ X _ _
        _ X _ X _
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character89 = {
    'Y',
    7,
    5,
    {
        X _ _ _ X
        X _ _ _ X
        _ X _ X _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
    }
};
static const character_t character90 = {
    'Z',
    7,
    5,
    {
        X X X X X
        _ _ _ _ X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X _ _ _ _
        X X X X X
    }
};
static const character_t character91 = {
    '[',
    7,
    5,
    {
        _ _ X X X
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X X X
    }
};
static const character_t character92 = {
    '\\',
    7,
    5,
    {
        _ _ _ _ _
        X _ _ _ _
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
        _ _ _ _ X
        _ _ _ _ _
    }
};
static const character_t character93 = {
    ']',
    7,
    5,
    {
        X X X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        X X X _ _
    }
};
static const character_t character94 = {
    '^',
    7,
    5,
    {
        _ _ X _ _
        _ X _ X _
        X _ _ _ X
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character95 = {
    '_',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        X X X X X
    }
};
static const character_t character96 = {
    '`',
    7,
    5,
    {
        _ X _ _ _
        _ _ X _ _
        _ _ _ X _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
    }
};
static const character_t character97 = {
    'a',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X _
        _ _ _ _ X
        _ X X X X
        X _ _ _ X
        _ X X X X
    }
};
static const character_t character98 = {
    'b',
    7,
    5,
    {
        X _ _ _ _
        X _ _ _ _
        X _ X X _
        X X _ _ X
        X _ _ _ X
        X _ _ _ X
        X X X X _
    }
};
static const character_t character99 = {
    'c',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X _
        X _ _ _ _
        X _ _ _ _
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character100 = {
    'd',
    7,
    5,
    {
        _ _ _ _ X
        _ _ _ _ X
        _ X X _ X
        X _ _ X X
        X _ _ _ X
        X _ _ _ X
        _ X X X X
    }
};
static const character_t character101 = {
    'e',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X _
        X _ _ _ X
        X X X X X
        X _ _ _ _
        _ X X X _
    }
};
static const character_t character102 = {
    'f',
    7,
    5,
    {
        _ _ X X _
        _ X _ _ X
        _ X _ _ _
        X X X _ _
        _ X _ _ _
        _ X _ _ _
        _ X _ _ _
    }
};
static const character_t character103 = {
    'g',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X X
        X _ _ _ X
        _ X X X X
        _ _ _ _ X
        _ _ X X _
    }
};
static const character_t character104 = {
    'h',
    7,
    5,
    {
        X _ _ _ _
        X _ _ _ _
        X _ X X _
        X X _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character105 = {
    'i',
    7,
    5,
    {
        _ _ X _ _
        _ _ _ _ _
        _ X X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ X X X _
    }
};
static const character_t character106 = {
    'j',
    7,
    5,
    {
        _ _ _ X _
        _ _ _ _ _
        _ _ X X _
        _ _ _ X _
        _ _ _ X _
        X _ _ X _
        _ X X _ _
    }
};
static const character_t character107 = {
    'k',
    7,
    5,
    {
        _ X _ _ _
        _ X _ _ _
        _ X _ _ X
        _ X _ X _
        _ X X _ _
        _ X _ X _
        _ X _ _ X
    }
};
static const character_t character108 = {
    'l',
    7,
    5,
    {
        _ X X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ X X X _
    }
};
static const character_t character109 = {
    'm',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X X _ X _
        X _ X _ X
        X _ X _ X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character110 = {
    'n',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ X X _
        X X _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
    }
};
static const character_t character111 = {
    'o',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        _ X X X _
    }
};
static const character_t character112 = {
    'p',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X X X X _
        X _ _ _ X
        X X X X _
        X _ _ _ _
        X _ _ _ _
    }
};
static const character_t character113 = {
    'q',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X _ X
        X _ _ X X
        _ X X X X
        _ _ _ _ X
        _ _ _ _ X
    }
};
static const character_t character114 = {
    'r',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ X X _
        X X _ _ X
        X _ _ _ _
        X _ _ _ _
        X _ _ _ _
    }
};
static const character_t character115 = {
    's',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ X X X _
        X _ _ _ _
        _ X X X _
        _ _ _ _ X
        X X X X _
    }
};
static const character_t character116 = {
    't',
    7,
    5,
    {
        _ X _ _ _
        _ X _ _ _
        X X X _ _
        _ X _ _ _
        _ X _ _ _
        _ X _ _ X
        _ _ X X _
    }
};
static const character_t character117 = {
    'u',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        X _ _ X X
        _ X X _ X
    }
};
static const character_t character118 = {
    'v',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ _ _ X
        X _ _ _ X
        X _ _ _ X
        _ X _ X _
        _ _ X _ _
    }
};
static const character_t character119 = {
    'w',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ _ _ X
        X _ _ _ X
        X _ X _ X
        X _ X _ X
        _ X _ X _
    }
};
static const character_t character120 = {
    'x',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ _ _ X
        _ X _ X _
        _ _ X _ _
        _ X _ X _
        X _ _ _ X
    }
};
static const character_t character121 = {
    'y',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X _ _ _ X
        X _ _ _ X
        _ X X X X
        _ _ _ _ X
        _ X X X _
    }
};
static const character_t character122 = {
    'z',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        X X X X X
        _ _ _ X _
        _ _ X _ _
        _ X _ _ _
        X X X X X
    }
};
static const character_t character123 = {
    '{',
    7,
    5,
    {
        _ _ _ X _
        _ _ X _ _
        _ _ X _ _
        _ X _ _ _
        _ _ X _ _
        _ _ X _ _
        _ _ _ X _
    }
};
static const character_t character124 = {
    '|',
    7,
    5,
    {
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
        _ _ X _ _
    }
};
static const character_t character125 = {
    '}',
    7,
    5,
    {
        _ X _ _ _
        _ _ X _ _
        _ _ X _ _
        _ _ _ X _
        _ _ X _ _
        _ _ X _ _
        _ X _ _ _
    }
};
static const character_t character126 = {
    '~',
    7,
    5,
    {
        _ _ _ _ _
        _ _ _ _ _
        _ _ _ _ _
        _ X _ _ X
        X _ X X _
        _ _ _ _ _
        _ _ _ _ _
    }
};
const font_t font7x5 = {
    .name                  = "Fonte 7x5",
    .height                = 7,
    .width               = 5,
    .character_spacing = 1,
    .line_spacing     = 1,
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