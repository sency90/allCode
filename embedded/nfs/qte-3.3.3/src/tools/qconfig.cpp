/* Install paths from configure */

static const char QT_INSTALL_PREFIX      [267] = "qt_nstpath=/mnt/nfs/qte-3.3.3";
static const char QT_INSTALL_BINS        [267] = "qt_binpath=/mnt/nfs/qte-3.3.3/bin";
static const char QT_INSTALL_DOCS        [267] = "qt_docpath=/mnt/nfs/qte-3.3.3/doc";
static const char QT_INSTALL_HEADERS     [267] = "qt_hdrpath=/mnt/nfs/qte-3.3.3/include";
static const char QT_INSTALL_LIBS        [267] = "qt_libpath=/mnt/nfs/qte-3.3.3/lib";
static const char QT_INSTALL_PLUGINS     [267] = "qt_plgpath=/mnt/nfs/qte-3.3.3/plugins";
static const char QT_INSTALL_DATA        [267] = "qt_datpath=/mnt/nfs/qte-3.3.3";
static const char QT_INSTALL_TRANSLATIONS[267] = "qt_trnpath=/mnt/nfs/qte-3.3.3/translations";
static const char QT_INSTALL_SYSCONF     [267] = "qt_cnfpath=/mnt/nfs/qte-3.3.3/etc/settings";

/* strlen( "qt_xxxpath=" ) == 11 */
const char *qInstallPath()             { return QT_INSTALL_PREFIX       + 11; }
const char *qInstallPathDocs()         { return QT_INSTALL_DOCS         + 11; }
const char *qInstallPathHeaders()      { return QT_INSTALL_HEADERS      + 11; }
const char *qInstallPathLibs()         { return QT_INSTALL_LIBS         + 11; }
const char *qInstallPathBins()         { return QT_INSTALL_BINS         + 11; }
const char *qInstallPathPlugins()      { return QT_INSTALL_PLUGINS      + 11; }
const char *qInstallPathData()         { return QT_INSTALL_DATA         + 11; }
const char *qInstallPathTranslations() { return QT_INSTALL_TRANSLATIONS + 11; }
const char *qInstallPathSysconf()      { return QT_INSTALL_SYSCONF      + 11; }
