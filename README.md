# Wakaama

Wakaama (formerly liblwm2m) is an implementation of the Open Mobile
Alliance's LightWeight M2M protocol (LWM2M).

Use the official GIT of Wakaama to do your development. This GIT
provides a Wakaama version with predefined objects for water meters
and it is for experimental use. This GIT has its focus on the lwm2m
client.

## Source Layout

    -+- core                   (the LWM2M engine)
     |
     +- coap                   (CoAP stack adaptation)
     |    |
     |    +- er-coap-13        (Modified Erbium's CoAP engine from
     |                          https://web.archive.org/web/20180316172739/http://people.inf.ethz.ch/mkovatsc/erbium.php)
     |
     +- data                   (data formats serialization/deserialization)
     |
     +- tests                  (test cases)
     |    |
     |    +- integration       (pytest based integration tests implementing the OMA-ETS-LightweightM2M-V1_1-20190912-D specification
     |                          https://www.openmobilealliance.org/release/LightweightM2M/ETS/OMA-ETS-LightweightM2M-V1_1-20190912-D.pdf)
     +- examples
          |
          +- bootstrap_server  (a command-line LWM2M bootstrap server)
          |
          +- client            (a command-line LWM2M client with several test objects)
          |
          +- lightclient       (a very simple command-line LWM2M client with several test objects)
          |
          +- server            (a command-line LWM2M server)
          |
          +- shared            (utility functions for connection handling and command-
                                line interface)

## Installation

On a Raspberry-Pi clone the git to /home/pi

### Dependencies and Tools

Add the following software on the R-Pi:

  - apt-get update -y
  - apt-get install cmake
  - apt-get install autoconf  
  - apt-get install automake  
  - apt-get install sqlite3
  - apt-get install libsqlite3-dev
  - pip install psutil

## Compiling

Wakaama is not a library but files to be built with an application.
Wakaama uses CMake >= 3.13. Look at examples/server/CMakeLists.txt for an
example of how to include it.
Several compilation switches are used:
 - LWM2M_BIG_ENDIAN if your target platform uses big-endian format.
 - LWM2M_LITTLE_ENDIAN if your target platform uses little-endian format.
 - LWM2M_CLIENT_MODE to enable LWM2M Client interfaces.
 - LWM2M_SERVER_MODE to enable LWM2M Server interfaces.
 - LWM2M_BOOTSTRAP_SERVER_MODE to enable LWM2M Bootstrap Server interfaces.
 - LWM2M_BOOTSTRAP to enable LWM2M Bootstrap support in a LWM2M Client.
 - LWM2M_SUPPORT_TLV to enable TLV payload support (implicit except for LWM2M 1.1 clients)
 - LWM2M_SUPPORT_JSON to enable JSON payload support (implicit when defining LWM2M_SERVER_MODE)
 - LWM2M_SUPPORT_SENML_JSON to enable SenML JSON payload support (implicit for LWM2M 1.1 or greater when defining LWM2M_SERVER_MODE or LWM2M_BOOTSTRAP_SERVER_MODE)
 - LWM2M_OLD_CONTENT_FORMAT_SUPPORT to support the deprecated content format values for TLV and JSON.
 - LWM2M_VERSION to specify which version of the LWM2M spec to support.
   Clients will support only that version. Servers will support that version and below.
   By default the latest version is supported. To specify version 1.0, for example, pass
   -DLWM2M_VERSION="1.0" to cmake.
 - LWM2M_RAW_BLOCK1_REQUESTS For low memory client devices where it is not possible to keep a large post or put request in memory to be parsed (typically a firmware write).
   This option enable each unprocessed block 1 payload to be passed to the application, typically to be stored to a flash memory. 
 - LWM2M_COAP_DEFAULT_BLOCK_SIZE CoAP block size used by CoAP layer when performing block-wise transfers. Possible values: 16, 32, 64, 128, 256, 512 and 1024. Defaults to 1024.

Depending on your platform, you need to define LWM2M_BIG_ENDIAN or LWM2M_LITTLE_ENDIAN.
LWM2M_CLIENT_MODE and LWM2M_SERVER_MODE can be defined at the same time.

## Build Examples

Install the lightweight-iot-client on ``/home/pi``

``git clone https://github.com/nokia/lightweight-iot-client.git``

``cd lightweight-iot-client``

``cd examples/shared``

``mv tinydtls org-tinydtls``

``git clone https://github.com/eclipse/tinydtls.git``

``cd ../..``

``cmake  ./examples/client``

``make``

When you want to add parameters during compilation, use ``cmake`` with
``-D`` parameters. Please refer to the Wakaama distribution for details.

Example:

``cmake -DLWM2M_BOOTSTRAP=1  -DLOG -DLWM2M_WITH_LOGS -DWITH_LOGS -DLWM2M_VERSION=1.0 -DLWM2M_SUPPORT_SENML_JSON=0 -DLWM2M_SUPPORT_JSON=0 -DDTLS=1 examples/client``

If you would execute a a ``make clean``, then you might experience
issues with the DTLS portion. Go to examples/shared and remove the
tinydtls and clone tinydtls again as above. Better is to avoid a ``make
clean``.


## Wamaama objects

The lwm2mclient features 9 standard LWM2M objects:

 - Security Object (id: 0)
 - Server Object (id: 1)
 - Access Control Object (id: 2) as a skeleton
 - Device Object (id: 3) containing hard-coded values from the Example LWM2M
 Client of Appendix E of the LWM2M Technical Specification.
 - Connectivity Monitoring Object (id: 4) as a skeleton
 - Firmware Update Object (id: 5) as a skeleton.
 - Location Object (id: 6) as a skeleton.
 - Connectivity Statistics Object (id: 7) as a skeleton.
 - Test Object (id: 31024) with the following description:

                           Multiple
          Object |  ID   | Instances | Mandatory |
           Test  | 31024 |    Yes    |    No     |

           Resources:
                       Supported    Multiple
           Name | ID | Operations | Instances | Mandatory |  Type   | Range |
           test |  1 |    R/W     |    No     |    Yes    | Integer | 0-255 |
           exec |  2 |     E      |    No     |    Yes    |         |       |
           dec  |  3 |    R/W     |    No     |    Yes    |  Float  |       |

The lwm2mclient features 2 LWM2M objects for temperature and pressure:

 - Object: 3303    Instances: 1  Resourcelist: 5601,5602,5603,5604,5605,5700,5701
 - Object: 3304    Instances: 1  Resourcelist: 5601,5602,5603,5604,5605,5700,5701

The lwm2mclient features 19 LWM2M objects related to water meters

 - Object: 10266   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10267   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10268   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10269   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10270   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10271   Instances: 1  Resourcelist: 6000 - 6010,6026,6027,6028,6029
 - Object: 10272   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10273   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10274   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10275   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10276   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10277   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10278   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10279   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10280   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10281   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10282   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10283   Instances: 1  Resourcelist: 6011 - 6025
 - Object: 10284   Instances: 1  Resourcelist: 6011 - 6025

## Sensor data

Visit the directory sqlite3 where you will find the file structure_db.
The default serial number is urn:H2O:meter-1. Please change this
serial to your preferred device identity.  
Run the create_db in this direcoty to generate a new local sqlite3
database.

## Sensor gets a trigger based on a database change

This client reads from the local sqlite3 database. The client checks
for any database entry where the flag 'upd' of a record is set to '1'.
If so, the client reads the data and resets the value back to '0'.
The client will then submit the change to the lwm2m server if there is
a subscription for this object resource.

## Generate sensor data

In the directory ./python, you will find the script called gen_data.  Edit this
script when the default serial number must be updated.  This script
reads the R-Pi cpu temperature, cpu occupation, virtual memory and
generate some parameters based on random values. Its just to make
changes to the database as mentioned in the previous section.  

Run the 'gen_data' separately. In practice, such a script will read your real sensors instead of artificial data.

## The Concept of Sensor, database and the Wakaama client

The following images shows the concept:

![Alt text](images/Wakaama-rpi.png?raw=true "Title")


## Wakaama example

``SERIALNUMBER=urn:H2O:meter-1``

``./lwm2mclient  -4  -n  ${SERIALNUMBER}  -h  leshan.eclipseprojects.io  -p   5683  -l  14250``

``Check your device on https://leshan.eclipseprojects.io``









