internal void 
clear_screen(u32* color) {
   unsigned int* pixel = (unsigned int)buffer_memory;
           for (int y = 0; y < buffer_height; y++) {
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = color;
                 }
           }
}

internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {

   x0 = clamp(0, x0, buffer_width)
   x1 = clamp(0, x1, buffer_width)
   y0 = clamp(0, y0, buffer_height)
   y1 = clamp(0, y1, buffer_height)
   
   
   for (int y = 0; y < buffer_height; y++) {
      u32* pixel = (u32*)buffer_memory + x0 + y*buffer_width;
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = 0xff00ff;
                 }
           }
}

global_variable float render_scale = 0.01f;

internal void 
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color) {

   x *= buffer_height * render_scale;
   y *= buffer_height * render_scale;
   half_size_x *= buffer_height * render_scale;
   half_size_y *= buffer_height * render_scale;
   
   x += buffer_width / 2.f;
   y += buffer_height / 2.f;
   
   // Change to pixels
   int x0 = x - half_size_x;
   int x1 = x + half_size_x;
   int y0 = y - half_size_y;
   int y1 = y + half_size_y;
   
   draw_rect_in_pixels(x0, y0, x1, y1, color)
}
