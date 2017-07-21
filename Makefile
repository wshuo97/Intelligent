#############################################################################
# Makefile for building: Intelligent
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Jul 21 04:04:16 2017
# Project:  Intelligent.pro
# Template: app
# Command: /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake -spec /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -o Makefile Intelligent.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -I. -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtNetwork -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I/opt/QtSDK/Desktop/Qt/4.8.1/gcc/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -lQtGui -L/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		serialservice.cpp \
		qextserialbase.cpp \
		posix_qextserialport.cpp \
		enddevice.cpp \
		motor.cpp \
		temp_humi_ligh.cpp \
		camerainit.cpp \
		video.cpp \
		pwm.cpp \
		smoke.cpp \
		pir.cpp moc_mainwindow.cpp \
		moc_serialservice.cpp \
		moc_qextserialbase.cpp \
		moc_enddevice.cpp \
		moc_video.cpp
OBJECTS       = main.o \
		mainwindow.o \
		serialservice.o \
		qextserialbase.o \
		posix_qextserialport.o \
		enddevice.o \
		motor.o \
		temp_humi_ligh.o \
		camerainit.o \
		video.o \
		pwm.o \
		smoke.o \
		pir.o \
		moc_mainwindow.o \
		moc_serialservice.o \
		moc_qextserialbase.o \
		moc_enddevice.o \
		moc_video.o
DIST          = /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		Intelligent.pro
QMAKE_TARGET  = Intelligent
DESTDIR       = 
TARGET        = Intelligent

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_video.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Intelligent.pro  /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++/qmake.conf /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl \
		/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtNetwork.prl
	$(QMAKE) -spec /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -o Makefile Intelligent.pro
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/release.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
/opt/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -o Makefile Intelligent.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Intelligent1.0.0 || $(MKDIR) .tmp/Intelligent1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Intelligent1.0.0/ && $(COPY_FILE) --parents mainwindow.h serialservice.h qextserialbase.h posix_qextserialport.h enddevice.h motor.h constant.h temp_humi_ligh.h camerainit.h video.h constant.h pwm.h smoke.h pir.h .tmp/Intelligent1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp serialservice.cpp qextserialbase.cpp posix_qextserialport.cpp enddevice.cpp motor.cpp temp_humi_ligh.cpp camerainit.cpp video.cpp pwm.cpp smoke.cpp pir.cpp .tmp/Intelligent1.0.0/ && $(COPY_FILE) --parents mainwindow.ui video.ui .tmp/Intelligent1.0.0/ && (cd `dirname .tmp/Intelligent1.0.0` && $(TAR) Intelligent1.0.0.tar Intelligent1.0.0 && $(COMPRESS) Intelligent1.0.0.tar) && $(MOVE) `dirname .tmp/Intelligent1.0.0`/Intelligent1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Intelligent1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_serialservice.cpp moc_qextserialbase.cpp moc_enddevice.cpp moc_video.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_serialservice.cpp moc_qextserialbase.cpp moc_enddevice.cpp moc_video.cpp
moc_mainwindow.cpp: posix_qextserialport.h \
		qextserialbase.h \
		temp_humi_ligh.h \
		enddevice.h \
		serialservice.h \
		camerainit.h \
		motor.h \
		video.h \
		mainwindow.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_serialservice.cpp: posix_qextserialport.h \
		qextserialbase.h \
		serialservice.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) serialservice.h -o moc_serialservice.cpp

moc_qextserialbase.cpp: qextserialbase.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) qextserialbase.h -o moc_qextserialbase.cpp

moc_enddevice.cpp: enddevice.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) enddevice.h -o moc_enddevice.cpp

moc_video.cpp: camerainit.h \
		video.h
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) video.h -o moc_video.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_video.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_video.h
ui_mainwindow.h: mainwindow.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_video.h: video.ui
	/opt/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic video.ui -o ui_video.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		temp_humi_ligh.h \
		enddevice.h \
		serialservice.h \
		camerainit.h \
		motor.h \
		video.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		posix_qextserialport.h \
		qextserialbase.h \
		temp_humi_ligh.h \
		enddevice.h \
		serialservice.h \
		camerainit.h \
		motor.h \
		video.h \
		ui_mainwindow.h \
		constant.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

serialservice.o: serialservice.cpp serialservice.h \
		posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serialservice.o serialservice.cpp

qextserialbase.o: qextserialbase.cpp qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialbase.o qextserialbase.cpp

posix_qextserialport.o: posix_qextserialport.cpp posix_qextserialport.h \
		qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o posix_qextserialport.o posix_qextserialport.cpp

enddevice.o: enddevice.cpp enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o enddevice.o enddevice.cpp

motor.o: motor.cpp motor.h \
		enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o motor.o motor.cpp

temp_humi_ligh.o: temp_humi_ligh.cpp temp_humi_ligh.h \
		enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o temp_humi_ligh.o temp_humi_ligh.cpp

camerainit.o: camerainit.cpp camerainit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camerainit.o camerainit.cpp

video.o: video.cpp video.h \
		camerainit.h \
		ui_video.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o video.o video.cpp

pwm.o: pwm.cpp pwm.h \
		enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pwm.o pwm.cpp

smoke.o: smoke.cpp smoke.h \
		enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o smoke.o smoke.cpp

pir.o: pir.cpp pir.h \
		enddevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pir.o pir.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_serialservice.o: moc_serialservice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serialservice.o moc_serialservice.cpp

moc_qextserialbase.o: moc_qextserialbase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qextserialbase.o moc_qextserialbase.cpp

moc_enddevice.o: moc_enddevice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_enddevice.o moc_enddevice.cpp

moc_video.o: moc_video.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_video.o moc_video.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

