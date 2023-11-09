////////////////////////////////////////////////////////////////////////
/// \file    SRShower.h
/// \brief   Reconstructed shower object
/// \author  J. Wolcott <jwolcott@fnal.gov>
/// \date    Sept. 2021
////////////////////////////////////////////////////////////////////////

#ifndef DUNEANAOBJ_SRSHOWER_H
#define DUNEANAOBJ_SRSHOWER_H

#include "duneanaobj/StandardRecord/SRVector3D.h"
#include "duneanaobj/StandardRecord/SRTrueParticle.h"

namespace caf
{
  class SRShower
  {
    public:
      SRVector3D start;      ///< Shower 3D start point [cm]
      SRVector3D direction;  ///< Shower 3D end point [cm]
      float Evis = -999.;    ///< Visible energy in voxels corresponding to this shower

      std::vector<TrueParticleID> truth;              ///< Associated SRTrueParticle(s), if relevant (use SRTruthBranch::Particle() with these IDs to grab them)
      std::vector<float>   truthOverlap;              ///< Fractional overlap between this shower and true particle
  };

}

#endif //DUNEANAOBJ_SRSHOWER_H
