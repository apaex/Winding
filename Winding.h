#pragma once 

#include <EEPROM.h>

template< typename T > void EEPROM_save( int idx, const T &t ){
    T v = 0;
    EEPROM.get(idx, v);
    if (t != v)
      EEPROM.put(idx, t);
}


struct Winding
{
  uint16_t turns=0;
  uint8_t step=0;
  uint8_t speed=30;    
  uint8_t layers=0;
  bool dir=1;
  static const byte version = 5;

  void Load(int &p)
  {
    EEPROM.get(p, turns);        p+=2;
    EEPROM.get(p, step);         p+=1;
    EEPROM.get(p, speed);        p+=1;  
    EEPROM.get(p, layers);       p+=1;
    EEPROM.get(p, dir);          p+=1;   
  }

  void Save(int &p)
  {
    EEPROM_save(p, turns);        p+=2;
    EEPROM_save(p, step);         p+=1;
    EEPROM_save(p, speed);        p+=1;
    EEPROM_save(p, layers);       p+=1;
    EEPROM_save(p, dir);          p+=1;   
  }
};


struct Settings 
{
  bool stopPerLayer = 0;
  uint8_t shaftStep = 1;
  uint8_t layerStep = 1;
  int shaftPos = 0;
  int layerPos = 0;


  void Load(int &p)
  {
    EEPROM.get(p, stopPerLayer);        p+=1;
  }

  void Save(int &p)
  {
    EEPROM_save(p, stopPerLayer);        p+=1; 
  }
};