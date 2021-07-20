set(DRIVING_HEADERS
  DrivingPattern.h
  DrivingPenalty.h
)

set(DRIVING_SRC
  DrivingPattern.cpp
  DrivingPenalty.cpp
)

appendingfiles(SYMUCORE_SRC DRIVING_SRC)

install(FILES ${DRIVING_HEADERS} DESTINATION include/SymuCore/Graph/Model/Driving)
