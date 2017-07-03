AUTOMAKE_OPTIONS=gnu
SUBDIRS=crc32 minigzip resource
CURRENTPATH=$(shell /bin/pwd)
export $CURRENTPATH
INCLUDES=-I$(CURRENTPATH)/include -I$(CURRENTPATH)/crc32/ -I$(CURRENTPATH)/minigzip/ -I$(CURRENTPATH)/resource/
dist_data_DATA=include
bin_PROGRAMS = pngtools

pngtools_SOURCES = main.cpp \
          pngtools.cpp \
          pngtools.h

pngtools_LDADD = crc32/libcrc32.a minigzip/libminigzip.a resource/libresources.a
