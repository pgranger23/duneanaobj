#include "SRProxy.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>

using namespace caf;

int main(int argc, char const *argv[]) {

  TFile fin(argv[1], "READ");

  TTree *tin = fin.Get<TTree>("caf");

  StandardRecordProxy srp(tin, "StandardRecord");

  Long64_t ents = tin->GetEntries();
  std::cout << "Input tree has " << ents << " entries." << std::endl;

  for (Long64_t i = 0; i < ents; ++i) {
    tin->GetEntry(i);

    std::cout << "Entry: " << i << std::endl;

    std::cout << "\tsrp.duneanaobj_gitshorthash: "
              << srp.duneanaobj_gitshorthash.GetValue() << std::endl;
    std::cout << "\tsrp.duneanaobj_version: " << srp.duneanaobj_version[0]
              << ", " << srp.duneanaobj_version[1] << ", "
              << srp.duneanaobj_version[2] << std::endl;

    std::cout << "\tsrp.nd.LArID: " << srp.nd.LArID.GetValue() << std::endl;
    std::cout << "\tsrp.nd.TMSID: " << srp.nd.TMSID.GetValue() << std::endl;
    std::cout << "\tsrp.nd.Residual: " << srp.nd.Residual.GetValue()
              << std::endl;
    std::cout << "\tsrp.nd.cosTheta: " << srp.nd.cosTheta.GetValue()
              << std::endl;
  }
}