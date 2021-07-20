set(USERS_HEADERS
  IUserHandler.h
)

set(USERS_SRC
  IUserHandler.cpp
)

appendingfiles(SYMUCORE_SRC USERS_SRC)

install(FILES ${USERS_HEADERS} DESTINATION include/SymuCore/Users)
