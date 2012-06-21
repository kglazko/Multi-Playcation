#############################################################################
# Makefile for building: logic
# Generated by qmake (2.01a) (Qt 4.6.2) on: Thu Jun 21 13:59:27 2012
# Project:  logic.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile logic.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

SOURCES       = buck.cpp \
		bush.cpp \
		coin.cpp \
		gropaga.cpp \
		inglip.cpp \
		kitten.cpp \
		main.cpp \
		multboard.cpp \
		multwindow.cpp \
		present.cpp \
		rain.cpp \
		sball.cpp \
		sled.cpp \
		sman.cpp \
		tree.cpp moc_multboard.cpp \
		moc_multwindow.cpp
OBJECTS       = buck.o \
		bush.o \
		coin.o \
		gropaga.o \
		inglip.o \
		kitten.o \
		main.o \
		multboard.o \
		multwindow.o \
		present.o \
		rain.o \
		sball.o \
		sled.o \
		sman.o \
		tree.o \
		moc_multboard.o \
		moc_multwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		logic.pro
QMAKE_TARGET  = logic
DESTDIR       = 
TARGET        = logic

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: logic.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile logic.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile logic.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/logic1.0.0 || $(MKDIR) .tmp/logic1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/logic1.0.0/ && $(COPY_FILE) --parents buck.h bush.h coin.h gropaga.h inglip.h kitten.h multboard.h multwindow.h present.h rain.h sball.h sled.h sman.h tree.h .tmp/logic1.0.0/ && $(COPY_FILE) --parents buck.cpp bush.cpp coin.cpp gropaga.cpp inglip.cpp kitten.cpp main.cpp multboard.cpp multwindow.cpp present.cpp rain.cpp sball.cpp sled.cpp sman.cpp tree.cpp .tmp/logic1.0.0/ && (cd `dirname .tmp/logic1.0.0` && $(TAR) logic1.0.0.tar logic1.0.0 && $(COMPRESS) logic1.0.0.tar) && $(MOVE) `dirname .tmp/logic1.0.0`/logic1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/logic1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_multboard.cpp moc_multwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_multboard.cpp moc_multwindow.cpp
moc_multboard.cpp: gropaga.h \
		inglip.h \
		kitten.h \
		buck.h \
		rain.h \
		sman.h \
		sball.h \
		sled.h \
		present.h \
		coin.h \
		tree.h \
		bush.h \
		multboard.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) multboard.h -o moc_multboard.cpp

moc_multwindow.cpp: multboard.h \
		gropaga.h \
		inglip.h \
		kitten.h \
		buck.h \
		rain.h \
		sman.h \
		sball.h \
		sled.h \
		present.h \
		coin.h \
		tree.h \
		bush.h \
		multwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) multwindow.h -o moc_multwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

buck.o: buck.cpp buck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o buck.o buck.cpp

bush.o: bush.cpp present.h \
		inglip.h \
		tree.h \
		bush.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bush.o bush.cpp

coin.o: coin.cpp present.h \
		inglip.h \
		coin.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o coin.o coin.cpp

gropaga.o: gropaga.cpp gropaga.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gropaga.o gropaga.cpp

inglip.o: inglip.cpp inglip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o inglip.o inglip.cpp

kitten.o: kitten.cpp kitten.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kitten.o kitten.cpp

main.o: main.cpp multwindow.h \
		multboard.h \
		gropaga.h \
		inglip.h \
		kitten.h \
		buck.h \
		rain.h \
		sman.h \
		sball.h \
		sled.h \
		present.h \
		coin.h \
		tree.h \
		bush.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

multboard.o: multboard.cpp multboard.h \
		gropaga.h \
		inglip.h \
		kitten.h \
		buck.h \
		rain.h \
		sman.h \
		sball.h \
		sled.h \
		present.h \
		coin.h \
		tree.h \
		bush.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o multboard.o multboard.cpp

multwindow.o: multwindow.cpp multwindow.h \
		multboard.h \
		gropaga.h \
		inglip.h \
		kitten.h \
		buck.h \
		rain.h \
		sman.h \
		sball.h \
		sled.h \
		present.h \
		coin.h \
		tree.h \
		bush.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o multwindow.o multwindow.cpp

present.o: present.cpp present.h \
		inglip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o present.o present.cpp

rain.o: rain.cpp rain.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rain.o rain.cpp

sball.o: sball.cpp sball.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sball.o sball.cpp

sled.o: sled.cpp sled.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sled.o sled.cpp

sman.o: sman.cpp sman.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sman.o sman.cpp

tree.o: tree.cpp present.h \
		inglip.h \
		tree.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tree.o tree.cpp

moc_multboard.o: moc_multboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_multboard.o moc_multboard.cpp

moc_multwindow.o: moc_multwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_multwindow.o moc_multwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

