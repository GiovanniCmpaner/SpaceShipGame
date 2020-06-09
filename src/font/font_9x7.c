#include "font.h"

#define X 0xFF,
#define _ 0x00,

static const character_t character32 = {
    ' ',
    9,
    7,
    {
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
    }                
};                  
 static const character_t character33 = {
    '!',            
    9,              
    2,              
    {               
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
    '"',            
    9,              
    5,              
    {               
        X X _ X X   
        X X _ X X   
        X X _ X X   
        X X _ X X   
        _ _ _ _ _   
        _ _ _ _ _   
        _ _ _ _ _   
        _ _ _ _ _   
        _ _ _ _ _   
    }               
};                  
 static const character_t character35 = {
    '#',            
    9,              
    7,              
    {               
        _ _ X _ X _ _
        _ _ X _ X _ _
        X X X X X X X
        _ _ X _ X _ _
        _ _ X _ X _ _
        X X X X X X X
        _ _ X _ X _ _
        _ _ X _ X _ _
        _ _ X _ X _ _
    }               
};                  
 static const character_t character36 = {
    '$',            
    9,              
    7,              
    {               
        _ _ _ X _ _ _
        _ X X X X X X
        X _ _ X _ _ _
        X _ _ X _ _ _
        _ X X X X X _
        _ _ _ X _ _ X
        _ _ _ X _ _ X
        X X X X X X _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character37 = {
    '%',            
    9,              
    7,              
    {               
        _ X _ _ _ _ _
        X X X _ _ _ _
        _ X _ _ _ X X
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ X _ _ _ X _
        X _ _ _ X X X
        _ _ _ _ _ X _
    }               
};                  
 static const character_t character38 = {
    '&',            
    9,              
    7,              
    {               
        _ X X X _ _ _
        X _ _ _ X _ _
        X _ _ _ X _ _
        X _ _ X _ _ _
        _ X X _ _ _ _
        X _ _ X _ _ _
        X _ _ _ X _ X
        X _ _ _ X X _
        _ X X X _ _ X
    }               
};                  
 static const character_t character39 = {
    '\'',           
    9,              
    3,              
    {               
        X X X       
        _ _ X       
        _ X _       
        X _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
    }               
};                  
 static const character_t character40 = {
    '(',            
    9,              
    3,              
    {               
        _ _ X       
        _ X _       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        _ X _       
        _ _ X       
    }               
};                  
 static const character_t character41 = {
    ')',            
    9,              
    3,              
    {               
        X _ _       
        _ X _       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ X _       
        X _ _       
    }               
};                  
 static const character_t character42 = {
    '*',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
        X X X X X X X
        _ _ _ X _ _ _
        _ _ X _ X _ _
        _ X _ _ _ X _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character43 = {
    '+',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        X X X X X X X
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character44 = {
    ',',            
    9,              
    3,              
    {               
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        X X X       
        _ _ X       
        _ X _       
        X _ _       
    }               
};                  
 static const character_t character45 = {
    '-',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X X X X X
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character46 = {
    '.',            
    9,              
    3,              
    {               
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ X _       
        X X X       
        _ X _       
    }               
};                  
 static const character_t character47 = {
    '/',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ X _ _ _ _ _
        X _ _ _ _ _ _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character48 = {
    '0',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ X X
        X _ _ _ X _ X
        X _ _ X _ _ X
        X _ X _ _ _ X
        X X _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character49 = {
    '1',            
    9,              
    5,              
    {               
        _ _ X _ _   
        _ X X _ _   
        X _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        X X X X X   
    }               
};                  
 static const character_t character50 = {
    '2',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ X _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character51 = {
    '3',            
    9,              
    7,              
    {               
        X X X X X X X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X X X X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character52 = {
    '4',            
    9,              
    7,              
    {               
        _ _ _ _ X _ _
        _ _ _ X X _ _
        _ _ X _ X _ _
        _ X _ _ X _ _
        X _ _ _ X _ _
        X X X X X X X
        _ _ _ _ X _ _
        _ _ _ _ X _ _
        _ _ _ _ X _ _
    }               
};                  
 static const character_t character53 = {
    '5',            
    9,              
    7,              
    {               
        X X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character54 = {
    '6',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character55 = {
    '7',            
    9,              
    7,              
    {               
        X X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ _ X _ _ _ _
        _ _ X _ _ _ _
        _ _ X _ _ _ _
    }               
};                  
 static const character_t character56 = {
    '8',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character57 = {
    '9',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character58 = {
    ':',            
    9,              
    3,              
    {               
        _ _ _       
        _ X _       
        X X X       
        _ X _       
        _ _ _       
        _ X _       
        X X X       
        _ X _       
        _ _ _       
    }               
};                  
 static const character_t character59 = {
    ';',            
    9,              
    7,              
    {               
        _ _ _       
        _ X _       
        X X X       
        _ X _       
        _ _ _       
        X X X       
        _ _ X       
        _ X _       
        X _ _       
    }               
};                  
 static const character_t character60 = {
    '<',            
    9,              
    5,              
    {               
        _ _ _ _ X   
        _ _ _ X _   
        _ _ X _ _   
        _ X _ _ _   
        X _ _ _ _   
        _ X _ _ _   
        _ _ X _ _   
        _ _ _ X _   
        _ _ _ _ X   
    }               
};                  
 static const character_t character61 = {
    '=',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X X X X X
        _ _ _ _ _ _ _
        X X X X X X X
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character62 = {
    '>',            
    9,              
    5,              
    {               
        X _ _ _ _   
        _ X _ _ _   
        _ _ X _ _   
        _ _ _ X _   
        _ _ _ _ X   
        _ _ _ X _   
        _ _ X _ _   
        _ X _ _ _   
        X _ _ _ _   
    }               
};                  
 static const character_t character63 = {
    '?',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ X X _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ _ _ _ _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character64 = {
    ',',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ X X X _ X
        X X _ _ X _ X
        X X _ _ X _ X
        X _ X X X X X
        X _ _ _ _ _ _
        _ X X X X X X
    }               
};                  
 static const character_t character65 = {
    'A',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character66 = {
    'B',            
    9,              
    7,              
    {               
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
    }               
};                  
 static const character_t character67 = {
    'C',            
    9,              
    7,              
    {               
        _ X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X X X X X X
    }               
};                  
 static const character_t character68 = {
    'D',            
    9,              
    7,              
    {               
        X X X X X _ _
        X _ _ _ _ X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ X _
        X X X X X _ _
    }               
};                  
 static const character_t character69 = {
    'E',            
    9,              
    7,              
    {               
        X X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character70 = {
    'F',            
    9,              
    7,              
    {               
        X X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
    }               
};                  
 static const character_t character71 = {
    'G',            
    9,              
    7,              
    {               
        _ X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character72 = {
    'H',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character73 = {
    'I',            
    9,              
    5,              
    {               
        X X X X X   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        X X X X X   
    }               
};                  
 static const character_t character74 = {
    'J',            
    9,              
    7,              
    {               
        _ _ X X X X X
        _ _ _ _ X _ _
        _ _ _ _ X _ _
        _ _ _ _ X _ _
        _ _ _ _ X _ _
        _ _ _ _ X _ _
        X _ _ _ X _ _
        X _ _ _ X _ _
        _ X X X _ _ _
    }               
};                  
 static const character_t character75 = {
    'K',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ X _
        X _ _ _ X _ _
        X _ _ X _ _ _
        X X X _ _ _ _
        X _ _ X _ _ _
        X _ _ _ X _ _
        X _ _ _ _ X _
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character76 = {
    'L',            
    9,              
    7,              
    {               
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character77 = {
    'M',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X X _ _ _ X X
        X _ X _ X _ X
        X _ _ X _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character78 = {
    'N',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X _ _ _ _ X
        X _ X _ _ _ X
        X _ _ X _ _ X
        X _ _ _ X _ X
        X _ _ _ _ X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character79 = {
    'O',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character80 = {
    'P',            
    9,              
    7,              
    {               
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
    }               
};                  
 static const character_t character81 = {
    'Q',            
    9,              
    7,              
    {               
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ X _ _ X
        X _ _ _ X _ X
        X _ _ _ _ X _
        _ X X X X _ X
    }               
};                  
 static const character_t character82 = {
    'R',            
    9,              
    7,              
    {               
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
        X _ _ X _ _ _
        X _ _ _ X _ _
        X _ _ _ _ X _
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character83 = {
    'S',            
    9,              
    7,              
    {               
        _ X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X X X X X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        X X X X X X _
    }               
};                  
 static const character_t character84 = {
    'T',            
    9,              
    7,              
    {               
        X X X X X X X
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character85 = {
    'U',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character86 = {
    'V',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character87 = {
    'W',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ X _ _ X
        X _ X _ X _ X
        X X _ _ _ X X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character88 = {
    'X',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
        _ _ X _ X _ _
        _ X _ _ _ X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character89 = {
    'Y',            
    9,              
    7,              
    {               
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character90 = {
    'Z',            
    9,              
    7,              
    {               
        X X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ X _ _ _ _ _
        X _ _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character91 = {
    '[',            
    9,              
    3,              
    {               
        X X X       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        X _ _       
        X X X       
    }               
};                  
 static const character_t character92 = {
    '\\',           
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X _ _ _ _ _
        _ _ X _ _ _ _
        _ _ _ X _ _ _
        _ _ _ _ X _ _
        _ _ _ _ _ X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character93 = {
    ']',            
    9,              
    3,              
    {               
        X X X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        _ _ X       
        X X X       
    }               
};                  
 static const character_t character94 = {
    '^',            
    9,              
    7,              
    {               
        _ _ _ X _ _ _
        _ _ X _ X _ _
        _ X _ _ _ X _
        X _ _ _ _ _ X
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
    }               
};                  
 static const character_t character95 = {
    '_',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character96 = {
    '`',            
    9,              
    3,              
    {               
        X _ _       
        _ X _       
        _ _ X       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
        _ _ _       
    }               
};                  
 static const character_t character97 = {
    'a',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ X X X X X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X X
    }               
};                  
 static const character_t character98 = {
    'b',            
    9,              
    7,              
    {               
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ X X X X _
        X X _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
    }               
};                  
 static const character_t character99 = {
    'c',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X X X X X X
    }               
};                  
 static const character_t character100 = {
    'd',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ X X X X _ X
        X _ _ _ _ X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X X
    }               
};                  
 static const character_t character101 = {
    'e',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X X X X X _
    }               
};                  
 static const character_t character102 = {
    'f',            
    9,              
    6,              
    {               
        _ _ X X X _
        _ X _ _ _ X
        _ X _ _ _ _
        _ X _ _ _ _
        X X X _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
    }               
};                  
 static const character_t character103 = {
    'g',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ _ _ X X X _
    }               
};                  
 static const character_t character104 = {
    'h',            
    9,              
    7,              
    {               
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        X _ X X X X _
        X X _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character105 = {
    'i',            
    9,              
    5,              
    {               
        _ _ X _ _   
        _ _ _ _ _   
        X X X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        X X X X X   
    }               
};                  
 static const character_t character106 = {
    'j',            
    9,              
    6,              
    {               
        _ _ _ _ X _
        _ _ _ _ _ _
        _ _ _ X X X
        _ _ _ _ X _
        _ _ _ _ X _
        _ _ _ _ X _
        _ _ _ _ X _
        X _ _ _ X _
        _ X X X _ _
    }               
};                  
 static const character_t character107 = {
    'k',            
    9,              
    6,              
    {               
        X _ _ _ _ _
        X _ _ _ _ _
        X _ _ _ _ X
        X _ _ _ X _
        X _ _ X _ _
        X X X _ _ _
        X X X _ _ _
        X _ _ X _ _
        X _ _ _ X _
    }               
};                  
 static const character_t character108 = {
    'l',            
    9,              
    5,              
    {               
        _ X X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        _ _ X _ _   
        X X X X X   
    }               
};                  
 static const character_t character109 = {
    'm',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X _ X X _
        X _ X _ X _ X
        X _ _ X _ _ X
        X _ _ X _ _ X
        X _ _ X _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character110 = {
    'n',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ X X X X _
        X X _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character111 = {
    'o',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character112 = {
    'p',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X X X X _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X X X X X X _
        X _ _ _ _ _ _
        X _ _ _ _ _ _
    }               
};                  
 static const character_t character113 = {
    'q',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
    }               
};                  
 static const character_t character114 = {
    'r',            
    9,              
    6,              
    {               
        _ _ _ _ _ _
        _ _ _ _ _ _
        X _ X X X _
        X X _ _ _ X
        X _ _ _ _ _
        X _ _ _ _ _
        X _ _ _ _ _
        X _ _ _ _ _
        X _ _ _ _ _
    }               
};                  
 static const character_t character115 = {
    's',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X X X X X
        X _ _ _ _ _ _
        X _ _ _ _ _ _
        _ X X X X X _
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        X X X X X X _
    }               
};                  
 static const character_t character116 = {
    't',            
    9,              
    6,              
    {               
        _ X _ _ _ _
        _ X _ _ _ _
        X X X _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
        _ X _ _ _ _
        _ X _ _ _ X
        _ _ X X X _
    }               
};                  
 static const character_t character117 = {
    'u',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ X X
        _ X X X X _ X
    }               
};                  
 static const character_t character118 = {
    'v',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
    }               
};                  
 static const character_t character119 = {
    'w',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ X _ _ X
        X _ _ X _ _ X
        X _ _ X _ _ X
        _ X X _ X X _
    }               
};                  
 static const character_t character120 = {
    'x',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ _ _ _ _ X
        _ X _ _ _ X _
        _ _ X _ X _ _
        _ _ _ X _ _ _
        _ _ X _ X _ _
        _ X _ _ _ X _
        X _ _ _ _ _ X
    }               
};                  
 static const character_t character121 = {
    'y',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        X _ _ _ _ _ X
        _ X X X X X X
        _ _ _ _ _ _ X
        _ _ _ _ _ _ X
        _ X X X X X _
    }               
};                  
 static const character_t character122 = {
    'z',            
    9,              
    7,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        X X X X X X X
        _ _ _ _ _ X _
        _ _ _ _ X _ _
        _ _ _ X _ _ _
        _ _ X _ _ _ _
        _ X _ _ _ _ _
        X X X X X X X
    }               
};                  
 static const character_t character123 = {
    '{',            
    9,              
    4,              
    {               
        _ _ X X     
        _ X _ _     
        _ X _ _     
        _ X _ _     
        X _ _ _     
        _ X _ _     
        _ X _ _     
        _ X _ _     
        _ _ X X     
    }               
};                  
 static const character_t character124 = {
    '|',            
    9,              
    1,              
    {               
        X           
        X           
        X           
        X           
        X           
        X           
        X           
        X           
        X           
    }               
};                  
 static const character_t character125 = {
    '}',            
    9,              
    4,              
    {               
        X X _ _     
        _ _ X _     
        _ _ X _     
        _ _ X _     
        _ _ _ X     
        _ _ X _     
        _ _ X _     
        _ _ X _     
        X X _ _     
    }               
};                  
 static const character_t character126 = {
    '~',            
    9,              
    6,              
    {               
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ X X _ _ X X
        X _ _ X X _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
        _ _ _ _ _ _ _
    }
};

const font_t font9x7 = {
    .name                = "Fonte 9x7",
    .height              = 9,
    .width               = 7,
    .character_spacing   = 1,
    .line_spacing        = 1,
    .characters_quantity = 95,
    .first_character     = 32,
    .last_character      = 126,
    .characters          = {
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