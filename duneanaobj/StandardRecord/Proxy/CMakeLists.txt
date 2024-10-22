GenSRProxy(
  HEADER duneanaobj/StandardRecord/StandardRecord.h
  OUTPUT_NAME SRProxy
  TARGETNAME caf::StandardRecord
  PROLOG ${CMAKE_CURRENT_SOURCE_DIR}/Prolog.h
  EPILOG_FWD ${CMAKE_CURRENT_SOURCE_DIR}/EpilogFwd.h
  EPILOG ${CMAKE_CURRENT_SOURCE_DIR}/Epilog.h
  INCLUDE_DIRS ${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS}
  DEPENDENCIES ${SR_HEADER_FILE_FQPS})

add_library(duneanaobj_StandardRecordProxy SHARED SRProxy.cxx)
target_link_libraries(duneanaobj_StandardRecordProxy PUBLIC SRProxy_BasicTypes)
target_include_directories(duneanaobj_StandardRecordProxy PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)

install(TARGETS duneanaobj_StandardRecordProxy EXPORT duneanaobj_targets DESTINATION lib)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/SRProxy.h 
              ${CMAKE_CURRENT_BINARY_DIR}/FwdDeclare.h 
        DESTINATION include/duneanaobj/StandardRecord/Proxy)

add_library(duneanaobj::StandardRecordProxy ALIAS duneanaobj_StandardRecordProxy)
