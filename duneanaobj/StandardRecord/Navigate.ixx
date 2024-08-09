#include "duneanaobj/StandardRecord/Navigate.h"
#include "duneanaobj/StandardRecord/SREnums.h"

#include <stdexcept>

namespace caf
{
  template <typename TruthBranchType, typename TrueParticleIDType>
  const typename std::conditional<std::is_same_v<TruthBranchType, SRTruthBranch>, SRTrueParticle, SRTrueParticleProxy>::type *
  FindParticle(const TruthBranchType & truth, const TrueParticleIDType &id)
  {
    if (id.type == TrueParticleID::kUnknown || id.ixn < 0 || id.part < 0)
      return nullptr;

    if (id.type == TrueParticleID::PartType::kPrimary)
      return &truth.nu[id.ixn].prim[id.part];
    else if (id.type == TrueParticleID::PartType::kPrimaryBeforeFSI)
      return &truth.nu[id.ixn].prefsi[id.part];
    else if (id.type == TrueParticleID::PartType::kSecondary)
      return &truth.nu[id.ixn].sec[id.part];
    else
      throw std::domain_error("Unknown PartType: " + std::to_string(id.type));
  }


}
