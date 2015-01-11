// Copyright (C) 2015 Andreas Weber <andy.weber.aw@gmail.com>
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, see <http://www.gnu.org/licenses/>.

#include <octave/oct.h>
#include <octave/txt-eng.h>
#include <octave/txt-eng-ft.h>

DEFUN_DLD(render_text, args, nargout,
          "-*- texinfo -*-\n\
@deftypefn {Loadable Function} {@var{img}  =} render_text (@var{S}, @var{INTERPRETER})\n\
render text using FreeType.\n\
\n\
@end deftypefn")
{
  octave_value_list retval;

  int nargin = args.length ();

  if (nargin != 2)
    {
      print_usage ();
      return retval;
    }
  
  if (!args(0).is_string ())
    {
      error ("S is no string");
      return retval;
    }

  if (!args(1).is_string ())
    {
      error ("INTERPRETER is no string");
      return retval;
    }
    
  std::string s = args(0).string_value ();
  //valid: none, tex, latex (not yet implemented?)
  std::string interpreter = args(1).string_value ();
  
  text_element *elt;
  ft_render text_renderer;
  Matrix box;

  //interpreter wird nur auf "text" geprüft, alles andere wird mit
  //text_parser_none verarbeitet
  elt = text_parser::parse (s, interpreter);

  text_renderer.set_font ("*", //get_fontname (),
                          "normal", //get_fontweight (),
                          "normal", //get_fontangle (),
                          15);//get_fontsize ());

//  box = text_renderer.get_extent (elt, 0);
//  std::cout << "box = " << box << std::endl;
  
  //aus txt-eng-ft.cc
  //~ ft_render::text_to_pixels (const std::string& txt,
                           //~ uint8NDArray& pixels_, Matrix& box,
                           //~ int _halign, int valign, double rotation,
                           //~ const caseless_str& interpreter)
  
  int rot_mode = ft_render::ROTATION_0;                 
  Matrix bbox;
  uint8NDArray pixels = text_renderer.render (elt, bbox, rot_mode);
  
  std::cout << "bbox = " << bbox << std::endl;
  delete elt;
  
  
  return octave_value (pixels);
}
