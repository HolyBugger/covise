# - Find osgCal
# Find the alut includes and library
#
#  OSGEARTH_INCLUDE_DIR - Where to find osgEarth includes
#  OSGEARTH_LIBRARIES   - List of libraries when using osgEarth
#  OSGEARTH_FOUND       - True if osgEarth was found

IF(OSGEARTH_INCLUDE_DIR)
  SET(OSGEARTH_FIND_QUIETLY TRUE)
ENDIF(OSGEARTH_INCLUDE_DIR)

FIND_PATH(OSGEARTH_INCLUDE_DIR "osgEarth/TerrainOptions"
  PATHS
  $ENV{OSGEARTH_HOME}/include
  $ENV{EXTERNLIBS}/osgEarth/include
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
  DOC "osgEarth - Headers"
)

SET(OSGEARTH_NAMES osgEarth)
SET(OSGEARTH_DBG_NAMES osgEarthd)
SET(OSGEARTHS_NAMES osgEarthSymbology)
SET(OSGEARTHS_DBG_NAMES osgEarthSymbologyd)
SET(OSGEARTHU_NAMES osgEarthUtil)
SET(OSGEARTHU_DBG_NAMES osgEarthUtild)
SET(OSGEARTHF_NAMES osgEarthFeatures)
SET(OSGEARTHF_DBG_NAMES osgEarthFeaturesd)
SET(OSGEARTHA_NAMES osgEarthAnnotation)
SET(OSGEARTHA_DBG_NAMES osgEarthAnnotationd)

FIND_LIBRARY(OSGEARTH_LIBRARY NAMES ${OSGEARTH_NAMES}
  PATHS
  $ENV{OSGEARTH_HOME}
  $ENV{EXTERNLIBS}/osgEarth
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
  PATH_SUFFIXES lib lib64
  DOC "osgEarth - Library"
)
FIND_LIBRARY(OSGEARTHANNOTATION_LIBRARY NAMES ${OSGEARTHA_NAMES}
  PATHS
  $ENV{OSGEARTH_HOME}
  $ENV{EXTERNLIBS}/osgEarth
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
  PATH_SUFFIXES lib lib64
  DOC "osgEarth - Library"
)
FIND_LIBRARY(OSGEARTHUTIL_LIBRARY NAMES ${OSGEARTHU_NAMES}
  PATHS
  $ENV{OSGEARTH_HOME}
  $ENV{EXTERNLIBS}/osgEarth
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
  PATH_SUFFIXES lib lib64
  DOC "osgEarth - Library"
)
FIND_LIBRARY(OSGEARTHFEATURES_LIBRARY NAMES ${OSGEARTHF_NAMES}
  PATHS
  $ENV{OSGEARTH_HOME}
  $ENV{EXTERNLIBS}/osgEarth
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
  PATH_SUFFIXES lib lib64
  DOC "osgEarth - Library"
)
FIND_LIBRARY(OSGEARTHSYMBOLOGY_LIBRARY NAMES ${OSGEARTHS_NAMES}
  PATHS
  $ENV{OSGEARTH_HOME}
  $ENV{EXTERNLIBS}/osgEarth
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw
  /opt/local
  /opt/csw
  /opt
  PATH_SUFFIXES lib lib64
  DOC "osgEarth - Library"
)

INCLUDE(FindPackageHandleStandardArgs)

IF(MSVC)
  # VisualStudio needs a debug version
  FIND_LIBRARY(OSGEARTH_LIBRARY_DEBUG NAMES ${OSGEARTH_DBG_NAMES}
    PATHS
    $ENV{OSGEARTH_HOME}/lib
    $ENV{EXTERNLIBS}/osgEarth/lib
    DOC "osgEarth - Library (Debug)"
  )
  FIND_LIBRARY(OSGEARTHUTIL_LIBRARY_DEBUG NAMES ${OSGEARTHU_DBG_NAMES}
    PATHS
    $ENV{OSGEARTH_HOME}/lib
    $ENV{EXTERNLIBS}/osgEarth/lib
    DOC "osgEarth - Library (Debug)"
  )
  FIND_LIBRARY(OSGEARTHANNOTATION_LIBRARY_DEBUG NAMES ${OSGEARTHA_DBG_NAMES}
    PATHS
    $ENV{OSGEARTH_HOME}/lib
    $ENV{EXTERNLIBS}/osgEarth/lib
    DOC "osgEarth - Library (Debug)"
  )
  FIND_LIBRARY(OSGEARTHFEATURES_LIBRARY_DEBUG NAMES ${OSGEARTHF_DBG_NAMES}
    PATHS
    $ENV{OSGEARTH_HOME}/lib
    $ENV{EXTERNLIBS}/osgEarth/lib
    DOC "osgEarth - Library (Debug)"
  )
  FIND_LIBRARY(OSGEARTHSYMBOLOGY_LIBRARY_DEBUG NAMES ${OSGEARTHS_DBG_NAMES}
    PATHS
    $ENV{OSGEARTH_HOME}/lib
    $ENV{EXTERNLIBS}/osgEarth/lib
    DOC "osgEarth - Library (Debug)"
  )
  
  IF(OSGEARTH_LIBRARY_DEBUG AND OSGEARTH_LIBRARY)
    SET(OSGEARTH_LIBRARIES optimized ${OSGEARTH_LIBRARY} debug ${OSGEARTH_LIBRARY_DEBUG} optimized ${OSGEARTHANNOTATION_LIBRARY} debug ${OSGEARTHANNOTATION_LIBRARY_DEBUG} optimized ${OSGEARTHUTIL_LIBRARY} debug ${OSGEARTHUTIL_LIBRARY_DEBUG} optimized ${OSGEARTHFEATURES_LIBRARY} debug ${OSGEARTHFEATURES_LIBRARY_DEBUG} optimized ${OSGEARTHSYMBOLOGY_LIBRARY} debug ${OSGEARTHSYMBOLOGY_LIBRARY_DEBUG})
  ENDIF(OSGEARTH_LIBRARY_DEBUG AND OSGEARTH_LIBRARY)

  FIND_PACKAGE_HANDLE_STANDARD_ARGS(OSGEARTH DEFAULT_MSG OSGEARTH_LIBRARY OSGEARTH_LIBRARY_DEBUG OSGEARTH_INCLUDE_DIR)

  MARK_AS_ADVANCED(OSGEARTH_LIBRARY OSGEARTH_LIBRARY_DEBUG OSGEARTH_INCLUDE_DIR)
  
ELSE(MSVC)
  # rest of the world
  SET(OSGEARTH_LIBRARIES ${OSGEARTH_LIBRARY} ${OSGEARTHANNOTATION_LIBRARY} ${OSGEARTHUTIL_LIBRARY} ${OSGEARTHFEATURES_LIBRARY} ${OSGEARTHSYMBOLOGY_LIBRARY})

  FIND_PACKAGE_HANDLE_STANDARD_ARGS(OSGEARTH DEFAULT_MSG OSGEARTH_LIBRARY OSGEARTH_INCLUDE_DIR)
  
  MARK_AS_ADVANCED(OSGEARTH_LIBRARY OSGEARTH_INCLUDE_DIR)
  
ENDIF(MSVC)

IF(OSGEARTH_FOUND)
  SET(OSGEARTH_INCLUDE_DIRS ${OSGEARTH_INCLUDE_DIR})
ENDIF(OSGEARTH_FOUND)