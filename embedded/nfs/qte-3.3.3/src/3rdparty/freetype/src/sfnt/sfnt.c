/***************************************************************************/
/*                                                                         */
/*  sfnt.c                                                                 */
/*                                                                         */
/*    Single object library component.                                     */
/*                                                                         */
/*  Copyright 1996-2000 by                                                 */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


#define FT_MAKE_OPTION_SINGLE_OBJECT


#ifdef FT_FLAT_COMPILE

#include "ttload.c"
#include "ttcmap.c"
#include "sfobjs.c"

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#include "ttsbit.c"
#endif

#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#include "ttpost.c"
#endif

#include "sfdriver.c"

#else /* FT_FLAT_COMPILE */

#include <sfnt/ttload.c>
#include <sfnt/ttcmap.c>
#include <sfnt/sfobjs.c>

#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#include <sfnt/ttsbit.c>
#endif

#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#include <sfnt/ttpost.c>
#endif

#include <sfnt/sfdriver.c>

#endif   /* FT_FLAT_COMPILE */


/* END */
