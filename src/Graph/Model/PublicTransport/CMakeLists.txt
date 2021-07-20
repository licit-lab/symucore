set(PUBLIC_TRANSPORT_HEADERS
  PublicTransportLine.h
  PublicTransportPattern.h
  WalkingPattern.h
)

set(PUBLIC_TRANSPORT_SRC
  PublicTransportLine.cpp
  PublicTransportPattern.cpp
  WalkingPattern.cpp
)

appendingfiles(SYMUCORE_SRC PUBLIC_TRANSPORT_SRC)

install(FILES ${PUBLIC_TRANSPORT_HEADERS} DESTINATION include/SymuCore/Graph/Model/PublicTransport)
