set(DEMAND_HEADERS
  DefaultMacroType.h
  DefaultPopulation.h
  Destination.h
  MacroType.h
  Motive.h
  Origin.h
  Path.h
  Population.h
  Populations.h
  PredefinedPath.h
  SubPopulation.h
  Trip.h
  ValuetedPath.h
  VehicleType.h
)

set(DEMAND_SRC
  DefaultMacroType.cpp
  DefaultPopulation.cpp
  Destination.cpp
  MacroType.cpp
  Motive.cpp
  Origin.cpp
  Path.cpp
  Population.cpp
  Populations.cpp
  PredefinedPath.cpp
  SubPopulation.cpp
  Trip.cpp
  ValuetedPath.cpp
  VehicleType.cpp
)

appendingfiles(SYMUCORE_SRC DEMAND_SRC)

install(FILES ${DEMAND_HEADERS} DESTINATION include/SymuCore/Demand)
