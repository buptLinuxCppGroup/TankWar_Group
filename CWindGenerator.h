/*
  CWindGenerator.h - thank you Klasker :)
  http://irrlicht.sourceforge.net/phpBB2/viewtopic.php?t=10762&start=15
*/

#include "IWindGenerator.h"

namespace irr
{
namespace scene
{

  class CWindGenerator : public IWindGenerator
  {
    private:
      f32 Strength;
      f32 Regularity;
 
    public:
      void setStrength( f32 strength );
      f32  getStrength();
      
      void setRegularity( f32 regularity );
      f32  getRegularity();

      core::vector2df getWind( const core::vector3df& position, u32 timeMs );
  }; 

  //void CWindGenerator::setStrength    ( f32 strength   ) { Strength   = strength;   }
  //f32  CWindGenerator::getStrength()  { return Strength; }
  //void CWindGenerator::setRegularity  ( f32 regularity ) { Regularity = regularity; }
  //f32  CWindGenerator::getRegularity(){ return Regularity; }

  f32 rndGenerator(s32 x);

  f32 cosInterpolater(f32 a, f32 b, f32 x);

  f32 windSmoother(s32 x);

  f32 noiseInterpolate( f32 x );

  f32 noise( f32 x );

  //core::vector2df CWindGenerator::getWind( const core::vector3df& position, u32 timeMs );

  IWindGenerator* createWindGenerator( f32 strength, f32 regularity );

} // namespace scene
} // namespace irr

