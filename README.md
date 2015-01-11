# octave-debug-text-renderer
OCT-file to access the text rendering engine and help debugging text rendering issues

## font rendering bugs from savannah:

https://savannah.gnu.org/bugs/?31468
    Printing of multi-line text objects (FLTK)
    Scheint in gl2ps (glps_renderer::draw_text) verloren zu gehen

https://savannah.gnu.org/bugs/?33118
    FLTK text rotation fails for angles other than 90 deg
    Da ist ja momentan pixels transpose usw. fest kodiert.

    Man sollte in ft-eng-ft.cc
    FT_UInt
    ft_render::process_character (FT_ULong code, FT_UInt previous)
    {
      FT_Face face = font.get_face ();
      FT_UInt glyph_index = 0;

    //by andy. Versuch zu rotieren
    //das klappt auch allerdings nur die einzelnen zeichen
    //http://www.freetype.org/freetype2/docs/tutorial/step1.html
    //zeigt wie man das mit pen und slot->advance.x macht
    //~ FT_Matrix matrix;
    //~ double angle = 0.2;
    //~ matrix.xx = (FT_Fixed)( cos( angle ) * 0x10000L );
    //~ matrix.xy = (FT_Fixed)(-sin( angle ) * 0x10000L );
    //~ matrix.yx = (FT_Fixed)( sin( angle ) * 0x10000L );
    //~ matrix.yy = (FT_Fixed)( cos( angle ) * 0x10000L );
    //~ 
      //~ FT_Set_Transform (face, &matrix, NULL);
      

    //~ error = FT_Set_Transform(
              //~ face,       /* target face object    */
              //~ &matrix,    /* pointer to 2x2 matrix */
              //~ &delta );   /* pointer to 2d vector  */

https://savannah.gnu.org/bugs/?43907
    bug #43907 OpenGL render code called even when gnuplot is graphics_toolkit

Ein sehr langer bugreport:
    bug #43651 special character (diameter sign) in plot produces warning or doesn't show up
