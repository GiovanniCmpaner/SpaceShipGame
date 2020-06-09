#include "font.h"

#define X 0xFF,
#define _ 0x00,

static const character_t character32 =  {
    ' ',
    20,
    14,
    {
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character33 = {
    '!',                      
    20,                       
    4,                        
    {                         
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        X X X X               
        _ _ _ _               
        _ _ _ _               
        _ _ _ _               
        X X X X               
        X X X X               
        X X X X               
    }                         
};                            
static const character_t character34 = {
    '"',                      
    20,                       
    6,                        
    {                         
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        X X X _ _ _ X X X     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
        _ _ _ _ _ _ _ _ _     
    }                         
};                            
static const character_t character35 = {
    '#',                      
    20,                       
    14,                       
    {                         
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
    }                         
};                            
static const character_t character36 = {
    '$',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ X X X X X X X X X X X X
        _ X X X X X X X X X X X X X
        X X X X _ X X X X _ _ _ _ _
        X X X _ _ X X X X _ _ _ _ _
        X X X _ _ X X X X _ _ _ _ _
        X X X X _ X X X X _ _ _ _ _
        _ X X X X X X X X X X X _ _
        _ _ X X X X X X X X X X X _
        _ _ _ _ _ X X X X _ X X X X
        _ _ _ _ _ X X X X _ _ X X X
        _ _ _ _ _ X X X X _ _ X X X
        _ _ _ _ _ X X X X _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character37 =  {
    '%',                      
    20,                       
    14,                       
    {                         
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X X X _ _ _ _ _ _ _ _
        X X X X X X _ _ _ _ _ _ _ _
        X X X X X X _ _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ _ X X X X X X
        _ _ _ _ _ _ _ _ X X X X X X
        _ _ _ _ _ _ _ _ X X X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
    }                         
};                            
static const character_t character38 = {
    '&',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X _ _ _ _ _
        _ X X X X X X X X X _ _ _ _
        X X X X _ _ _ X X X X X _ _
        X X _ _ _ _ _ _ _ X X X _ _
        X X _ _ _ _ _ _ _ X X X _ _
        X X _ _ _ _ _ _ _ X X X _ _
        X X _ _ _ _ _ X X X X X _ _
        X X _ _ _ X X X X X _ _ _ _
        X X X X X X X X X _ _ _ _ _
        _ X X X X X X _ _ _ _ _ _ _
        _ X X X X X X _ _ _ _ _ _ X
        X X X X X X X X X _ _ _ X X
        X X _ _ _ X X X X X _ _ X X
        X X _ _ _ _ _ X X X _ _ X X
        X X _ _ _ _ _ _ _ X X X X _
        X X _ _ _ _ _ _ _ X X X X _
        X X _ _ _ _ _ X X X _ _ X X
        X X X X _ X X X X X _ _ X X
        _ X X X X X X X X _ _ _ X X
        _ _ X X X X X _ _ _ _ _ _ X
    }                         
};                            
static const character_t character39 = {
    '\'',                     
    20,                       
    5,                        
    {                         
        X X X X X X X         
        X X X X X X X         
        _ _ _ _ X X X         
        _ _ _ _ X X X         
        _ _ _ _ X X X         
        _ _ X X X X X         
        _ X X X X _ _         
        X X X X _ _ _         
        X X _ _ _ _ _         
        _ _ _ _ _ _ _         
        _ _ _ _ _ _ _         
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
static const character_t character40 = {
    '(',                      
    20,                       
    7,                        
    {                         
        _ _ _ _ _ X X X X X   
        _ _ _ _ X X X X X _   
        _ _ X X X X X _ _ _   
        _ _ X X X _ _ _ _ _   
        _ X X X X _ _ _ _ _   
        _ X X X _ _ _ _ _ _   
        X X X X _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X _ _ _ _ _ _ _   
        X X X X _ _ _ _ _ _   
        _ X X X _ _ _ _ _ _   
        _ X X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X X X _ _ _   
        _ _ _ _ X X X X X _   
        _ _ _ _ _ X X X X X   
    }                         
};                            
static const character_t character41 = {
    ')',                      
    20,                       
    7,                        
    {                         
        X X X X _ _ _ _ _ _   
        X X X X X _ _ _ _ _   
        _ _ X X X X X _ _ _   
        _ _ _ _ X X X _ _ _   
        _ _ _ _ X X X X X _   
        _ _ _ _ _ X X X X _   
        _ _ _ _ _ X X X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ X X X X X   
        _ _ _ _ _ X X X X _   
        _ _ _ _ X X X X X _   
        _ _ _ _ X X X _ _ _   
        _ _ X X X X X _ _ _   
        X X X X X _ _ _ _ _   
        X X X X _ _ _ _ _ _   
    }                         
};                            
static const character_t character42 = {
    '*',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ X X X _ _ _ _ _ _ X X X _
        _ X X X X _ _ _ _ X X X X _
        _ _ X X X X X X X X X X _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X _ _ _ _ X X X X _
        _ X X X _ _ _ _ _ _ X X X _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character43 = {
    '+',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character44 = {
    ',',                      
    20,                       
    5,                        
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
        _ _ _ _ _ _ _         
        _ X X X X _ _         
        X X X X X X X         
        X X X X X X X         
        X X X X X X X         
        _ X X X X X X         
        _ _ _ _ X X X         
        _ _ _ _ X X X         
        _ _ X X X _ _         
        _ X X X _ _ _         
        X X _ _ _ _ _         
    }                         
};                            
static const character_t character45 = {
    '-',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character46 = {
    '.',                      
    20,                       
    6,                        
    {                         
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ _ _ _ _ _        
        _ X X X X _        
        X X X X X X        
        X X X X X X        
        X X X X X X        
        _ X X X X _        
    }                         
};                            
static const character_t character47 = {
    '/',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character48 = {
    '0',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ X X X X X
        X X _ _ _ _ _ X X X X X X X
        X X _ _ _ X X X X X _ _ X X
        X X _ _ X X X X X _ _ _ X X
        X X X X X X X _ _ _ _ _ X X
        X X X X X _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character49 = {
    '1',                      
    20,                       
    11,                        
    {                         
        _ _ _ _ X X X _ _ _ _
        _ _ X X X X X _ _ _ _
        _ X X X X X X _ _ _ _
        X X X X X X X _ _ _ _
        X X _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        X X X X X X X X X X X
        X X X X X X X X X X X
    }                         
};                            
static const character_t character50 = {
    '2',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character51 = {
    '3',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X X X X X X _ _
        _ _ _ _ X X X X X X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character52 = {
    '4',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ X X X X _ _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ _ X X X X X X _ _
        _ _ _ _ _ X X X _ X X X _ _
        _ _ _ _ X X X _ _ X X X _ _
        _ _ _ X X X _ _ _ X X X _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ X X X _ _ _ _ _ X X X _ _
        X X X _ _ _ _ _ _ X X X _ _
        X X _ _ _ _ _ _ _ X X X _ _
        X X _ _ _ _ _ _ _ X X X _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ X X X _ _
        _ _ _ _ _ _ _ _ _ X X X _ _
    }                         
};                            
static const character_t character53 = {
    '5',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character54 = {
    '6',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character55 = {
    '7',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _ _ _
    }                         
};                            
static const character_t character56 = {
    '8',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        _ X X X _ _ _ _ _ _ X X X _
        _ _ X X X X X X X X X X _ _
        _ _ X X X X X X X X X X _ _
        _ X X X _ _ _ _ _ _ X X X _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character57 = {
    '9',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character58 = {
    ':',                      
    20,                       
    6,                        
    {                         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ X X X X _         
        X X X X X X         
        X X X X X X         
        X X X X X X         
        _ X X X X _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ X X X X _         
        X X X X X X         
        X X X X X X         
        X X X X X X         
        _ X X X X _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
        _ _ _ _ _ _         
    }                         
};                            
static const character_t character59 = {
    ';',                      
    20,                       
    6,                       
    {                         
        _ _ _ _ _ _          
        _ _ _ _ _ _          
        _ _ _ _ _ _          
        _ X X X X _          
        X X X X X X          
        X X X X X X          
        X X X X X X          
        _ X X X X _          
        _ _ _ _ _ _          
        _ _ _ _ _ _          
        _ X X X X _          
        X X X X X X          
        X X X X X X          
        X X X X X X          
        _ X X X X X          
        _ _ _ _ X X          
        _ _ _ _ X X          
        _ _ X X X _          
        _ X X X _ _          
        X X _ _ _ _          
    }                         
};                            
static const character_t character60 = {
    '<',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ _ X
    }                         
};                            
static const character_t character61 = {
    '=',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character62 = {
    '>',                      
    20,                       
    14,                       
    {                         
        X _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character63 = {
    '?',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character64 = {
    ',',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ X X X _ X _ _ X X
        X X _ _ X _ _ _ X X _ _ X X
        X X _ _ X _ _ _ _ X _ _ X X
        X X _ _ X _ _ _ _ X _ _ X X
        X X _ _ X _ _ _ _ X _ _ X X
        X X _ _ X _ _ _ _ X _ _ X X
        X X _ _ X _ _ _ _ X _ _ X X
        X X _ _ X _ _ _ _ X _ X X _
        X X _ _ _ X X X X X X X _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X X X X X X X X _ _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character65 = {
    'A',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character66 = {
    'B',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X _
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _ X X X _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
    }                         
};                            
static const character_t character67 = {
    'C',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character68 = {
    'D',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
    }                         
};                            
static const character_t character69 = {
    'E',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character70 = {
    'F',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X _ _ _ _ _
        X X X X X X X X X _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character71 = {
    'G',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ X X X X X X X
        X X _ _ _ _ _ X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character72 = {
    'H',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character73 = {
    'I',                      
    20,                       
    11,                        
    {                         
        X X X X X X X X X X X
        X X X X X X X X X X X
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        _ _ _ _ X X X _ _ _ _
        X X X X X X X X X X X
        X X X X X X X X X X X
    }                         
};                            
static const character_t character74 = {
    'J',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        _ _ _ _ _ _ _ X X X _ _ _ _
        X X _ _ _ _ _ X X X _ _ _ _
        X X _ _ _ _ _ X X X _ _ _ _
        X X X X _ X X X X X _ _ _ _
        _ X X X X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
    }                         
};                            
static const character_t character75 = {
    'K',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ _ X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ X X X X _
        X X _ _ _ _ _ X X X X X _ _
        X X _ _ _ X X X X X _ _ _ _
        X X _ _ X X X X X _ _ _ _ _
        X X X X X X X _ _ _ _ _ _ _
        X X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X X X X _ _ _ _ _ _ _ _ _
        X X X X X X X _ _ _ _ _ _ _
        X X _ _ X X X X X _ _ _ _ _
        X X _ _ _ X X X X X _ _ _ _
        X X _ _ _ _ _ X X X X X _ _
        X X _ _ _ _ _ _ _ X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ _ X
    }                         
};                            
static const character_t character76 = {
    'L',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character77 = {
    'M',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        X X X X X _ _ _ _ X X X X X
        X X X X X X X X X X X X X X
        X X _ _ X X X X X X _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character78 = {
    'N',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X X X X _ _ _ _ _ _ _ X X
        X X _ X X X _ _ _ _ _ _ X X
        X X _ _ X X X _ _ _ _ _ X X
        X X _ _ _ X X X _ _ _ _ X X
        X X _ _ _ _ X X X _ _ _ X X
        X X _ _ _ _ _ X X X _ _ X X
        X X _ _ _ _ _ _ X X X _ X X
        X X _ _ _ _ _ _ _ X X X X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character79 = {
    'O',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character80 = {
    'P',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character81 = {
    'Q',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ X X X _ _ _ _ _ X X
        X X _ _ X X X X X _ _ _ X X
        X X _ _ _ X X X X X _ _ X X
        X X _ _ _ _ _ X X X X X _ _
        X X X X _ _ _ _ _ X X X X _
        _ X X X X X X X X _ X X X X
        _ _ X X X X X X X _ _ _ X X
    }                         
};                            
static const character_t character82 = {
    'R',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
        X X X X X _ _ _ _ _ _ _ _ _
        X X X X X X X _ _ _ _ _ _ _
        X X _ _ X X X X X _ _ _ _ _
        X X _ _ _ X X X X X _ _ _ _
        X X _ _ _ _ _ X X X X X _ _
        X X _ _ _ _ _ _ _ X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ _ X
    }                         
};                            
static const character_t character83 = {
    'S',                      
    20,                       
    14,                       
    {                         
        _ _ X X X X X X X X X X X X
        _ X X X X X X X X X X X X X
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X X X X X X X X _ _
        _ _ X X X X X X X X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
    }                         
};                            
static const character_t character84 = {
    'T',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character85 = {
    'U',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character86 = {
    'V',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X _ _ _ _ X X X X _
        _ _ X X X X X X X X X X _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character87 = {
    'W',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ X X X X X X _ _ X X
        X X X X X X X X X X X X X X
        X X X X X _ _ _ _ X X X X X
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character88 = {
    'X',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X _ _ _ _ X X X X _
        _ _ X X X X X X X X X X _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X _ _ _ _ X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character89 = {
    'Y',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X _ _ _ _ X X X X _
        _ _ X X X X X X X X X X _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character90 = {
    'Z',                      
    20,                       
    14,                       
    {                         
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character91 = {
    '[',                      
    20,                       
    7,                        
    {                         
        X X X X X X X X X X   
        X X X X X X X X X X   
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
        X X _ _ _ _ _ _ _ _   
        X X _ _ _ _ _ _ _ _   
        X X _ _ _ _ _ _ _ _   
        X X _ _ _ _ _ _ _ _   
        X X X X X X X X X X   
        X X X X X X X X X X   
    }                         
};                            
static const character_t character92 = {
    '\\',                     
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ _ X
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character93 = {
    ']',                      
    20,                       
    10,                        
    {                         
        X X X X X X X X X X   
        X X X X X X X X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        X X X X X X X X X X   
        X X X X X X X X X X   
    }                         
};                            
static const character_t character94 = {
    '^',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X _ _ _ _ X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X _ _ _ _ _ _ _ _ _ _ _ _ X
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character95 = {
    '_',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character96 = {
    '`',                      
    20,                       
    10,                        
    {                         
        X X _ _ _ _ _ _ _ _
        X X X _ _ _ _ _ _ _
        _ X X X _ _ _ _ _ _
        _ _ X X X X _ _ _ _
        _ _ _ X X X X _ _ _
        _ _ _ _ _ X X X X _
        _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ X X
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
    }                         
};                            
static const character_t character97 = {
    'a',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ _ X X X X X X X X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ X X X X X X X X X X X X
        _ X X X X X X X X X X X X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
    }                         
};                            
static const character_t character98 = {
    'b',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ X X X X X X X _ _
        X X _ _ X X X X X X X X X _
        X X X X X X X _ _ _ X X X X
        X X X X X _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
    }                         
};                            
static const character_t character99 = {
    'c',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character100 = {
    'd',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ X X X X X X X _ _ _ X X
        _ X X X X X X X X X _ _ X X
        X X X X _ _ _ X X X X X X X
        X X _ _ _ _ _ _ _ X X X X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
    }                         
};                            
static const character_t character101 = {
    'e',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X X X X X X X X _ _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character102 = {
    'f',                      
    20,                       
    9,                        
    {                         
        _ _ _ _ _ X X X X X _ _ _
        _ _ _ _ X X X X X X X X _
        _ _ X X X X X _ _ X X X X
        _ _ X X X _ _ _ _ _ X X X
        _ _ X X X _ _ _ _ _ X X X
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        X X X X X X X X X _ _ _ _
        X X X X X X X X X _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
        _ _ X X X _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character103 = {
    'g',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X X X
        _ X X X X X X X X X X X X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ X X X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
    }                         
};                            
static const character_t character104 = {
    'h',                      
    20,                       
    14,                       
    {                         
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ X X X X X X X _ _
        X X _ _ X X X X X X X X X _
        X X X X X X X _ _ _ X X X X
        X X X X X _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character105 = {
    'i',                      
    20,                       
    12,                        
    {                         
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X _ _ _ _ _
        X X X X X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        X X X X X X X X X X X X
        X X X X X X X X X X X X
    }                         
};                            
static const character_t character106 = {
    'j',                      
    20,                       
    9,                        
    {                         
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ _ _ _   
        _ _ _ _ _ _ _ _ _ _   
        _ _ _ _ _ _ _ _ _ _   
        _ _ _ _ X X X X X X   
        _ _ _ _ X X X X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        _ _ _ _ _ _ _ X X X   
        X X _ _ _ _ _ X X X   
        X X _ _ _ _ _ X X X   
        X X X X _ _ X X X X   
        _ X X X X X X X X _   
        _ _ X X X X X X _ _   
    }                         
};                            
static const character_t character107 = {
    'k',                      
    20,                       
    9,                        
    {                         
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X
        X X _ _ _ _ _ _ _ _ X X X
        X X _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ X X X X X _
        X X _ _ _ X X X X X _ _ _
        X X X X X X X X X _ _ _ _
        X X X X X X X _ _ _ _ _ _
        X X X X X _ _ _ _ _ _ _ _
        X X X X X X X _ _ _ _ _ _
        X X _ _ X X X X X _ _ _ _
        X X _ _ _ X X X X X _ _ _
        X X _ _ _ _ _ X X X X X _
        X X _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ X X X
    }                         
};                            
static const character_t character108 = {
    'l',                      
    20,                       
    12,                        
    {                         
        _ X X X X X X _ _ _ _ _
        _ X X X X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        _ _ _ _ X X X _ _ _ _ _
        X X X X X X X X X X X X
        X X X X X X X X X X X X
    }                         
};                            
static const character_t character109 = {
    'm',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X _ _ _ _ X X X _ _
        X X X X X X _ _ X X X X X _
        X X _ _ X X X X X X X X X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character110 = {
    'n',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ X X X X X X X _ _
        X X _ _ X X X X X X X X X _
        X X X X X X X _ _ _ X X X X
        X X X X X _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character111 = {
    'o',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X _ _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character112 = {
    'p',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X _ _
        X X X X X X X X X X X X X _
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character113 = {
    'q',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X X X
        _ X X X X X X X X X X X X X
        X X X X _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character114 = {
    'r',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ X X X X X X X _ _
        X X _ _ X X X X X X X X X _
        X X X X X X X _ _ _ X X X X
        X X X X X _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
    }                         
};                            
static const character_t character115 = {
    's',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X X X X X X X _
        _ X X X X X X X X X X X X _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        _ X X X X X X X X X X X _ _
        _ _ X X X X X X X X X X X _
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        X X X X X X X X X X X X X _
        X X X X X X X X X X X X _ _
    }                         
};                            
static const character_t character116 = {
    't',                      
    20,                       
    11,                        
    {                         
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        X X X X X X X X _ _ _
        X X X X X X X X _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ _ _
        _ _ _ X X _ _ _ _ X X
        _ _ _ X X _ _ _ _ X X
        _ _ _ X X X _ _ X X X
        _ _ _ X X X X X X X _
        _ _ _ _ X X X X X _ _
    }                         
};                            
static const character_t character117 = {
    'u',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ X X X X
        X X _ _ _ _ _ _ _ X X X X X
        X X X X _ _ _ X X X X X X X
        _ X X X X X X X X X _ _ X X
        _ _ X X X X X X X _ _ _ X X
    }                         
};                            
static const character_t character118 = {
    'v',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X _ _ _ _ X X X X _
        _ _ X X X X X X X X X X _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
    }                         
};                            
static const character_t character119 = {
    'w',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X _ _ _ X X X X _ _ _ X X
        X X X X X X X X X X X X X X
        _ X X X X X X X X X X X X _
        _ _ X X X _ _ _ _ X X X _ _
    }                         
};                            
static const character_t character120 = {
    'x',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X _ _ _ _ _ _ _ _ _ _ _ _ X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X _ _ _ _ _ _ _ _ X X X
        _ X X X _ _ _ _ _ _ X X X _
        _ _ X X X _ _ _ _ X X X _ _
        _ _ _ X X X _ _ X X X _ _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ _ X X X X _ _ _ _ _
        _ _ _ _ X X X X X X _ _ _ _
        _ _ _ X X X _ _ X X X _ _ _
        _ _ X X X _ _ _ _ X X X _ _
        _ X X X _ _ _ _ _ _ X X X _
        X X X _ _ _ _ _ _ _ _ X X X
        X X _ _ _ _ _ _ _ _ _ _ X X
    }                         
};                            
static const character_t character121 = {
    'y',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X _ _ _ _ _ _ _ _ _ _ X X
        X X X X _ _ _ _ _ _ X X X X
        _ X X X X X X X X X X X X X
        _ _ X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ X X X X X X X X X X X _
        _ _ X X X X X X X X X X _ _
    }                         
};                            
static const character_t character122 = {
    'z',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
        _ _ _ _ _ _ _ _ _ _ _ _ X X
        _ _ _ _ _ _ _ _ _ _ X X X X
        _ _ _ _ _ _ _ _ _ X X X X _
        _ _ _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ X X X X X _ _ _ _
        _ _ _ _ X X X X X _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ _ _
        _ X X X X _ _ _ _ _ _ _ _ _
        X X X X _ _ _ _ _ _ _ _ _ _
        X X _ _ _ _ _ _ _ _ _ _ _ _
        X X X X X X X X X X X X X X
        X X X X X X X X X X X X X X
    }                         
};                            
static const character_t character123 = {
    '{',                      
    20,                       
    10,                        
    {                         
        _ _ _ _ _ X X X X X   
        _ _ _ _ X X X X X X   
        _ _ X X X X X _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        X X X X _ _ _ _ _ _   
        X X X X _ _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X _ _ _ _ _   
        _ _ X X X X X _ _ _   
        _ _ _ _ X X X X X X   
        _ _ _ _ _ X X X X X   
    }                         
};                            
static const character_t character124 = {
    '|',                      
    20,                       
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
    20,                       
    10,                        
    {                         
        X X X X X _ _ _ _ _   
        X X X X X X _ _ _ _   
        _ _ _ X X X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ _ X X X X   
        _ _ _ _ _ _ X X X X   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ _ _ X X X _ _   
        _ _ _ X X X X X _ _   
        X X X X X X _ _ _ _   
        X X X X X _ _ _ _ _   
    }                         
};                            
static const character_t character126 = {
    '~',                      
    20,                       
    14,                       
    {                         
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ X X X X X _ _ _ _ _ X X
        _ X X X X X X X X _ X X X X
        X X X X _ X X X X X X X X _
        X X _ _ _ _ _ X X X X X _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
        _ _ _ _ _ _ _ _ _ _ _ _ _ _
    }
};

const font_t font20x14 = {
    .name                  = "Fonte 20x14",
    .height                = 20,
    .width               = 14,
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