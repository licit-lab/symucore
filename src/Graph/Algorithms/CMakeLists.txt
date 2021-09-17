set(ALGO_HEADERS
  Dijkstra.h
  KShortestPaths.h
  ShortestPathsComputer.h
)

set(ALGO_SRC
  Dijkstra.cpp
  KShortestPaths.cpp
  ShortestPathsComputer.cpp
)

appendingfiles(SYMUCORE_SRC ALGO_SRC)

install(FILES ${ALGO_HEADERS} DESTINATION include/SymuCore/Graph/Algorithms)
