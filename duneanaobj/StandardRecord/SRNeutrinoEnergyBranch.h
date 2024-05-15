////////////////////////////////////////////////////////////////////////
/// \file    SRNeutrinoEnergyBranch.h
/// \brief   Reconstructed neutrino energies
/// \author  J. Wolcott <jwolcott@fnal.gov>

#ifndef DUNEANAOBJ_SRNEUTRINOENERGYBRANCH_H
#define DUNEANAOBJ_SRNEUTRINOENERGYBRANCH_H

#include <limits>

namespace caf
{

  class SRNeutrinoEnergyBranch
  {
    private:
      static constexpr float NaN = std::numeric_limits<float>::signaling_NaN();

    public:
      float calo     = NaN;  ///< Calorimetric estimate using all hits
      float lep_calo = NaN;  ///< Lepton (longest track or largest shower) + calorimetric estimate from remaining hits
      float mu_range = NaN;  ///< Muon (longest track) using the stopping range + calorimetric estimate from the remaining hits
      float mu_mcs   = NaN;  ///< Muon (longest track) using the Multiple Coulomb Scattering + calorimetric estimate from the remaining hits
      float e_calo   = NaN;  ///< Electron (highest energy shower) + calorimetric estimate from the remaining hits
      float regcnn   = NaN;  ///< Regression CNN (assumes nue hypothesis)
  };

} // caf

#endif //DUNEANAOBJ_SRNEUTRINOENERGYBRANCH_H
