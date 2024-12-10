
////////////////////////////////////////////////////////////////////////
/// \file    SRDirectionBranch.h
/// \brief   Various hypotheses for reconstructed direction of interaction parent
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRDIRECTIONBRANCH_H
#define DUNEANAOBJ_SRDIRECTIONBRANCH_H

#include "duneanaobj/StandardRecord/SRVector3D.h"

namespace caf
{

  class SRDirectionBranch
  {
    public:
      SRVector3D lngtrk;       ///< Direction reconstructed using the longest track
      SRVector3D heshw;        ///< Direction reconstructed using the highest-energy shower
      SRVector3D sandreco_mom; ///< Direction reconstructed using sandreco

      // add others as needed
  };

} // caf

#endif //DUNEANAOBJ_SRDIRECTIONBRANCH_H
