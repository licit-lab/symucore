set(UTILS_HEADERS
  EmissionUtils.h
  Point.h
  RobustTravelIndicatorsHelper.h
  RobustTravelTimesHelper.h
  SpatialMarginalsHelper.h
  SymuCoreConstants.h
  TravelIndicatorClass.h
  TravelTimeClass.h
  TravelTimeUtils.h)


set(UTILS_SRC
  EmissionUtils.cpp
  Point.cpp
  RobustTravelIndicatorsHelper.cpp
  RobustTravelTimesHelper.cpp
  SpatialMarginalsHelper.cpp
  SymuCoreConstants.cpp
  TravelIndicatorClass.cpp
  TravelTimeClass.cpp
  TravelTimeUtils.cpp)

appendingfiles(SYMUCORE_SRC UTILS_SRC)

install(FILES ${UTILS_HEADERS} DESTINATION include/SymuCore/Utils)
