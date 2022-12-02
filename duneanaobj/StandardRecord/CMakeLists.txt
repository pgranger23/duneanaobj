
include_directories(${CMAKE_SOURCE_DIR})

ROOT_GENERATE_DICTIONARY(StandardRecordDict StandardRecord.h
  LINKDEF classes_def.xml)

SET(SR_IMPL_FILES
  SRFD.cxx
  SRGlobal.cxx
  SRMINERvA.cxx
  SRNDLAr.cxx
  SRTrack.cxx
  SRVector3D.cxx
  StandardRecord.cxx
  SRGArTrack.cxx
  SRLorentzVector.cxx
  SRMeta.cxx
  SRSystParamHeader.cxx
  SRTruthBranch.cxx
  SRWeightGlobal.cxx
  ${CMAKE_CURRENT_BINARY_DIR}/StandardRecordDict.cxx
)

SET(SR_HEADER_FILES
  SRBeamBranch.h
  SREnums.h
  SRGArTrack.h
  SRMINERvA.h
  SRNDShowerAssn.h
  SRRecoParticle.h
  SRTMS.h
  SRVector3D.h
  SRCVNScoreBranch.h
  SRFD.h
  SRGlobal.h
  SRMeta.h
  SRNDTrackAssn.h
  SRRecoParticlesBranch.h
  SRTrack.h
  SRWeightGlobal.h
  SRCommonRecoBranch.h
  SRFDBranch.h
  SRInteraction.h
  SRNDAssnBranch.h
  SRNeutrinoEnergyBranch.h
  SRSAND.h
  SRTrueInteraction.h
  StandardRecord.h
  SRDetectorMetaBranch.h
  SRGAr.h
  SRInteractionBranch.h
  SRNDBranch.h
  SRNeutrinoHypothesisBranch.h
  SRShower.h
  SRTrueParticle.h
  SRDirectionBranch.h
  SRGArECAL.h
  SRLorentzVector.h
  SRNDLAr.h
  SROpticalFlash.h
  SRSystParamHeader.h
  SRTruthBranch.h
)

add_library(duneanaobj_StandardRecord SHARED ${SR_IMPL_FILES})
target_link_libraries(duneanaobj_StandardRecord PUBLIC ROOT::MathCore)
target_include_directories(duneanaobj_StandardRecord PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS duneanaobj_StandardRecord DESTINATION lib)
install(FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/libStandardRecordDict_rdict.pcm 
    ${CMAKE_CURRENT_BINARY_DIR}/libStandardRecordDict.rootmap 
  DESTINATION lib)

# get the location of these to allow the code generation scripts to properly set up
# dependencies
SET(SR_HEADER_FILE_FQPS)
foreach(HDR ${SR_HEADER_FILES})
  LIST(APPEND SR_HEADER_FILE_FQPS ${CMAKE_CURRENT_SOURCE_DIR}/${HDR})
endforeach()

add_subdirectory(Proxy)
add_subdirectory(Flat)