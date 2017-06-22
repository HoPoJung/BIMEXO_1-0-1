#############################################################################
# Makefile for building: BIMEXO_1-0-1
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  BIMEXO_1-0-1.pro
# Template: app
# Command: E:\Qt\5.5\msvc2013\bin\qmake.exe -spec win32-msvc2013 "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile BIMEXO_1-0-1.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = E:\Qt\5.5\msvc2013\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: BIMEXO_1-0-1.pro E:\Qt\5.5\msvc2013\mkspecs\win32-msvc2013\qmake.conf E:\Qt\5.5\msvc2013\mkspecs\features\spec_pre.prf \
		E:\Qt\5.5\msvc2013\mkspecs\common\msvc-desktop.conf \
		E:\Qt\5.5\msvc2013\mkspecs\qconfig.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcollision.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcollision_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcore.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcore_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dinput.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dinput_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dlogic.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dlogic_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquick.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquick_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquickrenderer.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquickrenderer_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3drenderer.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3drenderer_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axbase.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axbase_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axcontainer.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axcontainer_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axserver.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axserver_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bluetooth.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bluetooth_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bootstrap_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_clucene_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_concurrent.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_concurrent_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_core.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_core_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_dbus.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_dbus_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_declarative.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_declarative_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designer.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designer_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designercomponents_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_enginio.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_enginio_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_gui.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_gui_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_help.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_help_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_location.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_location_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimedia.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimedia_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimediawidgets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_network.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_network_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_nfc.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_nfc_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_opengl.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_opengl_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_openglextensions.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_openglextensions_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_platformsupport_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_positioning.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_positioning_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_printsupport.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_printsupport_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qml.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qml_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmltest.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmltest_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quick.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quick_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickparticles_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickwidgets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_script.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_script_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_scripttools.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_scripttools_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sensors.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sensors_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_serialport.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_serialport_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sql.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sql_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_svg.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_svg_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_testlib.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_testlib_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uiplugin.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uitools.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uitools_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webchannel.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webchannel_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webengine.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webengine_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginecore.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginecore_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginewidgets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkit.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkit_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkitwidgets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkitwidgets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_websockets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_websockets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_widgets.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_widgets_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_winextras.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_winextras_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xml.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xml_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xmlpatterns.pri \
		E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		E:\Qt\5.5\msvc2013\mkspecs\features\qt_functions.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\qt_config.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\win32\qt_config.prf \
		E:\Qt\5.5\msvc2013\mkspecs\win32-msvc2013\qmake.conf \
		E:\Qt\5.5\msvc2013\mkspecs\features\spec_post.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\exclusive_builds.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\default_pre.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\win32\default_pre.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\resolve_config.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\exclusive_builds_post.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\default_post.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\qml_debug.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\win32\rtti.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\c++11.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\precompile_header.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\warn_on.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\qt.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\resources.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\moc.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\win32\opengl.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\uic.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\win32\windows.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\testcase_targets.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\exceptions.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\yacc.prf \
		E:\Qt\5.5\msvc2013\mkspecs\features\lex.prf \
		BIMEXO_1-0-1.pro \
		E:/Qt/5.5/msvc2013/lib/qtmaind.prl \
		E:/Qt/5.5/msvc2013/lib/Qt5PrintSupport.prl \
		E:/Qt/5.5/msvc2013/lib/Qt5Widgets.prl \
		E:/Qt/5.5/msvc2013/lib/Qt5Gui.prl \
		E:/Qt/5.5/msvc2013/lib/Qt5Core.prl
	$(QMAKE) -spec win32-msvc2013 "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile BIMEXO_1-0-1.pro
E:\Qt\5.5\msvc2013\mkspecs\features\spec_pre.prf:
E:\Qt\5.5\msvc2013\mkspecs\common\msvc-desktop.conf:
E:\Qt\5.5\msvc2013\mkspecs\qconfig.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcollision.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcollision_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcore.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dcore_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dinput.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dinput_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dlogic.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dlogic_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquick.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquick_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquickrenderer.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3dquickrenderer_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3drenderer.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_3drenderer_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axbase.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axbase_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axcontainer.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axcontainer_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axserver.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_axserver_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bluetooth.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bluetooth_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_bootstrap_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_clucene_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_concurrent.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_concurrent_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_core.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_core_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_dbus.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_dbus_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_declarative.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_declarative_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designer.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designer_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_designercomponents_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_enginio.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_enginio_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_gui.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_gui_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_help.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_help_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_location.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_location_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimedia.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimedia_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimediawidgets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_network.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_network_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_nfc.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_nfc_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_opengl.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_opengl_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_openglextensions.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_openglextensions_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_platformsupport_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_positioning.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_positioning_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_printsupport.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_printsupport_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qml.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qml_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmldevtools_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmltest.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qmltest_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quick.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quick_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickparticles_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickwidgets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_quickwidgets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_script.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_script_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_scripttools.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_scripttools_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sensors.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sensors_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_serialport.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_serialport_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sql.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_sql_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_svg.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_svg_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_testlib.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_testlib_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uiplugin.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uitools.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_uitools_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webchannel.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webchannel_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webengine.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webengine_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginecore.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginecore_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginewidgets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkit.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkit_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkitwidgets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_webkitwidgets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_websockets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_websockets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_widgets.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_widgets_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_winextras.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_winextras_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xml.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xml_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xmlpatterns.pri:
E:\Qt\5.5\msvc2013\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
E:\Qt\5.5\msvc2013\mkspecs\features\qt_functions.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\qt_config.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\win32\qt_config.prf:
E:\Qt\5.5\msvc2013\mkspecs\win32-msvc2013\qmake.conf:
E:\Qt\5.5\msvc2013\mkspecs\features\spec_post.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\exclusive_builds.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\default_pre.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\win32\default_pre.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\resolve_config.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\exclusive_builds_post.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\default_post.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\qml_debug.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\win32\rtti.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\c++11.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\precompile_header.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\warn_on.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\qt.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\resources.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\moc.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\win32\opengl.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\uic.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\win32\windows.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\testcase_targets.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\exceptions.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\yacc.prf:
E:\Qt\5.5\msvc2013\mkspecs\features\lex.prf:
BIMEXO_1-0-1.pro:
E:/Qt/5.5/msvc2013/lib/qtmaind.prl:
E:/Qt/5.5/msvc2013/lib/Qt5PrintSupport.prl:
E:/Qt/5.5/msvc2013/lib/Qt5Widgets.prl:
E:/Qt/5.5/msvc2013/lib/Qt5Gui.prl:
E:/Qt/5.5/msvc2013/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2013 "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile BIMEXO_1-0-1.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
	-$(DEL_FILE) BIMEXO_1-0-1.exp
	-$(DEL_FILE) BIMEXO_1-0-1.ilk
	-$(DEL_FILE) BIMEXO_1-0-1.idb
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) BIMEXO_1-0-1.lib BIMEXO_1-0-1.pdb

debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile