////////////////////////////////////////////////////////////////////////
/// \file    SRCVNScoreBranch.h
/// \brief   Collections of reconstructed neutrino candidates
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRCVNSCOREBRANCH_H
#define DUNEANAOBJ_SRCVNSCOREBRANCH_H

#include <limits>

namespace caf
{
  class SRCVNScoreBranch
  {
    private:
      static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      float isnubar = NaN;

      float nue   = NaN;
      float numu  = NaN;
      float nutau = NaN;
      float nc    = NaN;

      float protons0 = NaN;
      float protons1 = NaN;
      float protons2 = NaN;
      float protonsN = NaN;

      float chgpi0 = NaN;
      float chgpi1 = NaN;
      float chgpi2 = NaN;
      float chgpiN = NaN;

      float pizero0 = NaN;
      float pizero1 = NaN;
      float pizero2 = NaN;
      float pizeroN = NaN;

      float neutron0 = NaN;
      float neutron1 = NaN;
      float neutron2 = NaN;
      float neutronN = NaN;
  };
}

#endif //DUNEANAOBJ_SRCVNSCOREBRANCH_H
