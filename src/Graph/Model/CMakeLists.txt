add_subdirectory("Driving")
add_subdirectory("PublicTransport")

set(MODEL_HEADERS
  AbstractPenalty.h
  Cost.h
  Graph.h
  Link.h
  ListTimeFrame.h
  MultiLayersGraph.h
  Node.h
  NullPattern.h
  NullPenalty.h
  Pattern.h
  PatternsSwitch.h
  Penalty.h
)

set(MODEL_SRC
  AbstractPenalty.cpp
  Cost.cpp
  Graph.cpp
  Link.cpp
  ListTimeFrame.cpp
  MultiLayersGraph.cpp
  Node.cpp
  NullPattern.cpp
  NullPenalty.cpp
  Pattern.cpp
  PatternsSwitch.cpp
  Penalty.cpp
)

appendingfiles(SYMUCORE_SRC MODEL_SRC)

install(FILES ${MODEL_HEADERS} DESTINATION include/SymuCore/Graph/Model)
