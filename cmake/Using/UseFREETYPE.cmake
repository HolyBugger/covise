MACRO(USE_FREETYPE)
  FIND_PACKAGE(Freetype)
  IF ((NOT FREETYPE_FOUND) AND (${ARGC} LESS 1))
    USING_MESSAGE("Skipping because of missing Freetype")
    RETURN()
  ENDIF((NOT FREETYPE_FOUND) AND (${ARGC} LESS 1))
  USING_MESSAGE("found Freetype")
  USING_MESSAGE(${FREETYPE_LIBRARIES})
  USING_MESSAGE(${FREETYPE_INCLUDE_DIRS})
  IF(NOT FREETYPE_USED AND FREETYPE_FOUND)
    SET(FREETYPE_USED TRUE)
    INCLUDE_DIRECTORIES(${FREETYPE_INCLUDE_DIRS})
    SET(EXTRA_LIBS ${EXTRA_LIBS} ${FREETYPE_LIBRARIES})
  ENDIF()
ENDMACRO(USE_FREETYPE)
