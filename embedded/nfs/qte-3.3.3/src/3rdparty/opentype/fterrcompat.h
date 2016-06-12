
#ifndef FTERRCOMPAT_H
#define FTERRCOMPAT_H

#ifdef HAVE_FREETYPE_2_0_3
#include <freetype/internal/tterrors.h>
#else
#define TT_Err_Ok FT_Err_Ok
#define TT_Err_Invalid_Argument FT_Err_Invalid_Argument
#define TT_Err_Invalid_Face_Handle FT_Err_Invalid_Face_Handle
#define TT_Err_Table_Missing FT_Err_Table_Missing
#endif /* HAVE_FREETYPE_2_0_3 */

/* Compat macros for name changes in FreeType 2.1.0
 */
#if (FREETYPE_MAJOR == 2) && (FREETYPE_MINOR >= 1)

#define FILE_Pos()             FT_STREAM_POS()
#define FILE_Seek( position ) FT_STREAM_SEEK( position)

#define ACCESS_Frame( size ) FT_FRAME_ENTER( size )
#define FORGET_Frame() FT_FRAME_EXIT()

#define GET_Char()      FT_GET_CHAR()
#define GET_Byte()      FT_GET_BYTE()
#define GET_Short()     FT_GET_SHORT()
#define GET_UShort()    FT_GET_USHORT()
#define GET_Offset()    FT_GET_OFF3()
#define GET_UOffset()   FT_GET_UOFF3()
#define GET_Long()      FT_GET_LONG()
#define GET_ULong()     FT_GET_ULONG()
#define GET_Tag4()      FT_GET_TAG4()

#define ALLOC_ARRAY( _pointer_, _count_, _type_ ) \
  FT_SET_ERROR (FT_MEM_ALLOC_ARRAY( _pointer_, _count_, _type_))

/* FT_MEM_REALLOC macro broken in 2.1.0 */
#define REALLOC_ARRAY( _pointer_, _old_, _new_, _type_ ) \
  FT_SET_ERROR ( FT_MEM_REALLOC( _pointer_, (_old_) * sizeof ( _type_ ),   \
		(_new_) * sizeof ( _type_ ) ) )

#define ALLOC( _pointer_, _size_ ) FT_ALLOC( _pointer_, _size_ )
#define FREE( _pointer_ )          FT_FREE( _pointer_ )

#define MEM_Copy( dest, source, count ) FT_MEM_COPY( dest, source, count )

#endif /* >= 2.1.0 */

#endif /* FTERRCOMPAT_H */
