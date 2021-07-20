cmake_minimum_required (VERSION 3.0)

project (lwm2mclient C)

option(DTLS "Enable DTLS" OFF)

include(${CMAKE_CURRENT_LIST_DIR}/../../core/wakaama.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../../coap/coap.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../../data/data.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../shared/shared.cmake)

add_definitions(-DLWM2M_CLIENT_MODE -DLWM2M_BOOTSTRAP)
if(LWM2M_VERSION VERSION_GREATER "1.0") 
    add_definitions(-DLWM2M_SUPPORT_SENML_JSON)
else()
    add_definitions(-DLWM2M_SUPPORT_JSON)
endif()

if(LWM2M_RAW_BLOCK1_REQUESTS)
    add_definitions(-DLWM2M_RAW_BLOCK1_REQUESTS)
endif()

add_definitions(${SHARED_DEFINITIONS} ${WAKAAMA_DEFINITIONS})

include_directories (${WAKAAMA_HEADERS_DIR} ${COAP_HEADERS_DIR} ${DATA_HEADERS_DIR} ${WAKAAMA_SOURCES_DIR} ${SHARED_INCLUDE_DIRS})

SET(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/lwm2mclient.c
    ${CMAKE_CURRENT_LIST_DIR}/lwm2mclient.h
    ${CMAKE_CURRENT_LIST_DIR}/system_api.c
    ${CMAKE_CURRENT_LIST_DIR}/object_security.c
    ${CMAKE_CURRENT_LIST_DIR}/object_server.c
    ${CMAKE_CURRENT_LIST_DIR}/object_device.c
    ${CMAKE_CURRENT_LIST_DIR}/object_firmware.c
    ${CMAKE_CURRENT_LIST_DIR}/object_location.c
    ${CMAKE_CURRENT_LIST_DIR}/object_connectivity_moni.c
    ${CMAKE_CURRENT_LIST_DIR}/object_connectivity_stat.c
    ${CMAKE_CURRENT_LIST_DIR}/object_access_control.c
    ${CMAKE_CURRENT_LIST_DIR}/sensor_driver.c
    ${CMAKE_CURRENT_LIST_DIR}/object_test.c    
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_1.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_2.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_3.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_4.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_5.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_6.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_7.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_8.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_9.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_10.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_11.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_12.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_13.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_14.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_15.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_16.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_17.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_18.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_19.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_20.c
    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_21.c    

)

add_executable(${PROJECT_NAME} ${SOURCES} ${WAKAAMA_SOURCES} ${COAP_SOURCES} ${DATA_SOURCES} ${SHARED_SOURCES})


# Dirk
TARGET_LINK_LIBRARIES(lwm2mclient pthread m sqlite3)

# Add WITH_LOGS to debug variant
set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:WITH_LOGS>)

SOURCE_GROUP(wakaama FILES ${WAKAAMA_SOURCES})


#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_5.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_6.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_7.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_8.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_9.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_10.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_11.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_12.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_13.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_14.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_15.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_16.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_17.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_18.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_19.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_20.c
#    ${CMAKE_CURRENT_LIST_DIR}/object_mysql_21.c
